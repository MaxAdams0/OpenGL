/* Installed using vcpkg https://vcpkg.io/en/ Files not included in git repo */
#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<stb_include.h>
/* Engine */
#include"Camera.hpp"
#include"Texture.hpp"
#include"Shader.hpp"
#include"VAO.hpp"
#include"VBO.hpp"
#include"EBO.hpp"
#include"Clock.hpp"
#include"OBJ.hpp"


/*
	A lot of the basic core functions in the engine are derived from
	https://www.youtube.com/watch?v=45MIykWJ-C4&t=237s Thanks Cherno!
	The listed below are 100% my own work, and others may still be modified
	OBH.h, Clock.h
*/

GLfloat lightVertices[] =
{ //     COORDINATES     //
	-0.1f, -0.1f,  0.1f,
	-0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f,  0.1f,
	-0.1f,  0.1f,  0.1f,
	-0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f,  0.1f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

const unsigned int winResW = 800;
const unsigned int winResH = 800;

int main(void)
{
	/* Initialize glfw, glad, window, & parameters */
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	GLFWwindow* window = glfwCreateWindow(winResW, winResH, "OpenGL Render Window", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, winResW, winResH);

	/* ========== IM SORRY FILELOADING WILL BE LESS MESSY LATER ========== */
	obj::Handler objHandler;
	objHandler.loadFile("Peach.obj");
	if (!objHandler.getFile("Peach.obj").isValid()) { return -1; }

	/* Convert std::vector<GLfloat[3]> to GLfloat* (vertices) */
	std::vector<GLfloat> verticeVertex;
	size_t elemCountV = verticeVertex.size() * 3;
	/* A type followed by a pointer is alled a dynamic array */
	GLfloat* vertices = new GLfloat[elemCountV];
	/* Copy data from the vector to array */
	size_t iV = 0;
	for (const auto& vertex : verticeVertex) {
		std::copy(vertex, vertex + 3, vertices + iV);
		iV += 3;
	}

	/* Convert std::vector<GLfloat[3]> to GLfloat* (vertices) */
	std::vector<GLuint> indiceVertex;
	size_t elemCountI = indiceVertex.size() * 3;
	/* A type followed by a pointer is alled a dynamic array */
	GLuint* indices = new GLuint[elemCountI];
	/* Copy data from the vector to array */
	size_t iI = 0;
	for (const auto& index : indiceVertex) {
		std::copy(index, index + 3, indices + iI);
		iI += 3;
	}

	Shader shaderProgram("default.vert", "default.frag");
	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));
	/* Links VBO attributes (i.e. coord, color, texture coords, etc.) */
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	/* Unbind to prevent accidental manipulation */
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	Shader lightShader("light.vert", "light.frag");
	VAO lightVAO;
	lightVAO.Bind();
	VBO lightVBO(lightVertices, sizeof(lightVertices));
	EBO lightEBO(lightIndices, sizeof(lightIndices));
	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 objectPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 objectModel = glm::mat4(1.0f);
	objectModel = glm::translate(objectModel, objectPos);

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	Texture plankDiff("planks.png", GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE);
	plankDiff.texUnit(shaderProgram, "tex0", 0);
	Texture plankSpec("planksSpec.png", GL_TEXTURE_2D, 1, GL_RED, GL_UNSIGNED_BYTE);
	plankSpec.texUnit(shaderProgram, "tex1", 1);

	glEnable(GL_DEPTH_TEST);
	/* Screen width & height, starting position */
	Camera camera(winResW, winResH, glm::vec3(0.0f, 0.5f, 3.0f));

	//testing
	Clock clock;
	std::cout << clock.getTime() << '\n';

	while (!glfwWindowShouldClose(window))
	{
		/* Background color */
		glClearColor(0.04f, 0.10f, 0.22f, 1.0f);
		/* Clear the back buffer and assign new color */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.Inputs(window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);
		/* Identify shader */
		shaderProgram.Activate();
		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		camera.Matrix(shaderProgram, "camMatrix");
		/* make a better comment here */
		plankDiff.Bind();
		plankSpec.Bind();
		VAO1.Bind();
		/* Geometrical primitive, indices count, datatype of indices, index of indices */
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

		lightShader.Activate();
		camera.Matrix(lightShader, "camMatrix");
		lightVAO.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		/* don't really know what this does */
		glfwSwapBuffers(window);

		/* Monitor GLFW events (like close window) */
		glfwPollEvents();
	}

	/* RIP AND TEAR UNTIL ALL OF THE MEMORY IS DESTROYED */
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	plankDiff.Delete();
	plankSpec.Delete();
	shaderProgram.Delete();
	lightVAO.Delete();
	lightVBO.Delete();
	lightEBO.Delete();
	lightShader.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}