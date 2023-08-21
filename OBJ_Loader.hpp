#pragma once
#ifndef OBJ_NAMESPACE_HPP
#define OBJ_NAMESPACE_HPP

#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<array>

#include<glfw/glfw3.h>
/* Forward Declaration */
namespace obj
{
	class Handler;
	class File;
}

/* Parses .obj file data and distributes related info */
namespace obj
{
	class Handler
	{
	private:
		std::vector<obj::File> loadedFiles;

	public:
		void loadFile(const std::string filename);
		obj::File getFile(const std::string filename);
		void unloadFile(const std::string filename);
		bool isFileLoaded(const std::string filename);
		std::vector<obj::File> getLoadedFiles() { return loadedFiles; }
	};

	class File
	{
	private:
		std::string filename;
		std::vector<GLfloat> vertices;
		std::vector<GLuint> indices;

	public:
		File(std::string filename)
		{
			this->filename = filename;
		}
		~File()
		{

		}

		bool isValid();

		void setName(std::string filename) { this->filename = filename; }
		std::string getName() const { return filename; }

		void setVertices(std::vector<GLfloat> vertices) { this->vertices = vertices; }
		std::vector<GLfloat> getVertices() const { return vertices; }
		//std::vector<GLfloat> getTexCoords();
		//std::vector<GLfloat> getVerticeNormals();
		void setIndices(std::vector<GLuint> indices) { this->indices = indices; }
		std::vector<GLuint> getIndices() const { return indices; };
	};

	namespace util
	{
		void separateInt(std::string input, std::string sep, GLuint* val1, GLuint* val2);
	}
}

#endif