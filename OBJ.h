#pragma once
#ifndef OBJ_NAMESPACE_H
#define OBJ_NAMESPACE_H

#include<fstream>
#include<string>
#include<vector>
#include<sstream>

#include<glfw/glfw3.h>

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
		std::vector<GLfloat[3]> verticies;
		std::vector<int[3]> indicies;

	public:
		File(std::string filename)
		{
			filename = this->filename;
		}
		~File()
		{

		}

		bool isValid();

		void setName(std::string filename) { this->filename = filename; }
		std::string getName() const { return filename; }

		void setVerticies(std::vector<GLfloat[3]> verticies) { this->verticies = verticies; }
		std::vector<GLfloat[3]> getVerticies() const { return verticies; }
		//std::vector<GLfloat[3]> getTexCoords();
		//std::vector<GLfloat[3]> getVerticeNormals();
		void setIndicies(std::vector<int[3]> indicies) { this->indicies = indicies; }
		std::vector<int[3]> getIndicies() const { return indicies; };
	};

	namespace util
	{
		void separateInt(std::string input, std::string sep, int* val1, int* val2)
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