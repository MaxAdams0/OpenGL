#ifndef SHADER_CLASS_HPP
#define SHADER_CLASS_HPP

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string getFileContents(const char* filename);

class Shader
{
	public:
		/* Reference ID */
		GLuint ID;
		/* Constructor which compiles, wraps, and deletes shaders */
		Shader(const char* vertFile, const char* fragFile);

		void Activate();
		void Delete();
		/* Checks if the selected shader has compiled properly */
		void compileErrors(unsigned int shader, const char* type);
};

#endif