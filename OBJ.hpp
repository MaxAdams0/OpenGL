#pragma once
#ifndef OBJ_NAMESPACE_HPP
#define OBJ_NAMESPACE_HPP

#include<fstream>
#include<string>
#include<vector>
#include<sstream>

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
		std::vector<GLfloat[3]> vertices;
		std::vector<GLuint[3]> indices;

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

		void setVertices(std::vector<GLfloat[3]> vertices) { this->vertices = vertices; }
		std::vector<GLfloat[3]> getVertices() const { return vertices; }
		//std::vector<GLfloat[3]> getTexCoords();
		//std::vector<GLfloat[3]> getVerticeNormals();
		void setIndices(std::vector<GLuint[3]> indices) { this->indices = indices; }
		std::vector<GLuint[3]> getIndices() const { return indices; };
	};

	namespace util
	{
		void separateInt(std::string input, std::string sep, GLuint* val1, GLuint* val2)
		{
			std::size_t sepPos = input.find(sep);
			std::string str1 = input.substr(0, sepPos);
			std::string str2 = input.substr(sepPos + sep.length());
			*val1 = std::stoi(str1);
			*val2 = std::stoi(str2);
		}
	}
}

#endif