#include"VAO.hpp"

/* Generates a VAO ID */
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

/*	Links a VBO to the VAO using the layout 
	Stride = byte size between two vertex attributes of the same type (i.e. XYZ, RGB, etc.) */
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset); // lossy conversion from GLsizeiptr to GLsizei
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}