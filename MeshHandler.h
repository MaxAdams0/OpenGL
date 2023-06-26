#pragma once
#ifndef MESHHANDLER_CLASS_H
#define MESHHANDLER_CLASS_H

#include<vector>
#include<string>

#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
/* https://github.com/Bly7/OBJ-Loader */
#include"OBJ_Loader.h" 

class MeshHandler
{
	private:
		std::vector<std::string> meshNames;
		int bufferSize;
	
	protected:
		objl::Loader objLoader;

	public:
		MeshHandler(std::vector<std::string> meshNames);
};

#endif