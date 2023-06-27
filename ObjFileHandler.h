#pragma once
#ifndef OBJFILEHANDLER_CLASS_H
#define OBJFILEHANDLER_CLASS_H

#include<fstream>
#include<string>
#include<vector>

#include<glfw/glfw3.h>

/* Parses .obj file data and distributes related info */
class ObjFileHandler 
{
	private:
		std::vector<ObjFile> loadedFiles;


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
		std::vector<int> indicies;

	public:
		void loadFile(const std::string filename);
		void unloadFile(const std::string filename);
		bool isFileLoaded(const std::string filename);

		std::vector<GLfloat[3]> getVerticies();
		//std::vector<GLfloat[3]> getTexCoords();
		//std::vector<GLfloat[3]> getVerticeNormals();
		std::vector<int> getIndicies();
};


#endif