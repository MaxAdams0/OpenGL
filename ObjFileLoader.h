#ifndef OBJ_FILE_LOADER_CLASS_H
#define OBJ_FILE_LOADER_CLASS_H

#include <string>
#include <vector>

class ObjFileLoader
{
	struct Vertex {
		float position[3];
		float texCoord[2];
		float normal[3];
	};

	public:
		/* File name / destination */
		std::string fileName;
		/* All different data points */
		std::vector<float[3]> positions; // v
		std::vector<float[2]> texCoords; // vt
		std::vector<float[3]> normals;   // vn
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		/*  */
};

#endif