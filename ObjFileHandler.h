#pragma once
#ifndef OBJFILEHANDLER_CLASS_H
#define OBJFILEHANDLER_CLASS_H

#include<fstream>
#include<string>
#include<vector>
#include<sstream>

#include<glfw/glfw3.h>

/* Parses .obj file data and distributes related info */
class ObjFileHandler 
{
	private:
		std::vector<ObjFile> loadedFiles;
		void loadFile(const std::string filename);
		void unloadFile(const std::string filename);
		bool isFileLoaded(const std::string filename);

	public:
		ObjFileHandler();
		~ObjFileHandler();
		std::vector<std::string> getLoadedFiles();
};

class ObjFile 
{
	private:
		std::string name;
		std::vector<GLfloat[3]> verticies;
		std::vector<int[3]> indicies;

	public:
		void setName(std::string name) { name = this->name; }
		std::string getName() const { return name; }

		void setVerticies(std::vector<GLfloat[3]> verticies) { verticies = this->verticies; }
		std::vector<GLfloat[3]> getVerticies() const { return verticies; }
		//std::vector<GLfloat[3]> getTexCoords();
		//std::vector<GLfloat[3]> getVerticeNormals();
		void setIndicies(std::vector<int[3]> indicies) { indicies = this->indicies; }
		std::vector<int[3]> getIndicies() const { return indicies; };
};


#endif