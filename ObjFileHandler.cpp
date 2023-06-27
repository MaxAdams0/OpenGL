#include"ObjFileHandler.h"

ObjFileHandler::ObjFileHandler()
{

}

ObjFileHandler::~ObjFileHandler()
{

}

std::vector<std::string> ObjFileHandler::getLoadedFiles()
{

}

// ==========================================================================

void ObjFile::loadFile(const std::string filename)
{
	std::ifstream objfile;
	objfile.open(filename);
	if (!objfile.is_open());

	std::string line;
	while (std::getline(objfile, line)) {
		if (line[0] == 'o') {

		}
	}

	objfile.close();
}

void ObjFile::unloadFile(const std::string filename)
{

}

bool ObjFile::isFileLoaded(const std::string filename)
{

}

std::vector<GLfloat[3]> ObjFile::getVerticies()
{

}

std::vector<int> ObjFile::getIndicies()
{

}