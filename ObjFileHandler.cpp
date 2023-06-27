#include"ObjFileHandler.h"

ObjFileHandler::ObjFileHandler()
{

}

ObjFileHandler::~ObjFileHandler()
{

}

std::vector<std::string> ObjFileHandler::getLoadedFiles()
{
	std::vector<std::string> names;
	for (ObjFile obj : ObjFileHandler::loadedFiles) {
		names.emplace_back(obj.getName());
	}

	return names;
}

void ObjFileHandler::loadFile(const std::string filename)
{
	ObjFile objData;

	std::ifstream objFile;
	objFile.open(filename);
	if (!objFile.is_open());

	std::vector<GLfloat[3]> verticies;
	std::string line;
	while (std::getline(objFile, line))
	{
		std::string id;
		std::istringstream iss(line);

		iss >> id;

		if (id == "o") {
			objData.setName(line.substr(2, line.find_first_of('_')));
		}
		else if (id == "v") {
			GLfloat x, y, z;
			iss >> x >> y >> z;
			verticies.emplace_back(new GLfloat[3]{ x, y, z });
		}
		else if (id == "f") {
			// short for vertex pair _, pair of vertex and vertex normal xyz's
			std::string vpairx, vpairy, vpairz;
			iss >> vpairx >> vpairy >> vpairz;
		}
	}

	objFile.close();
}

void ObjFileHandler::unloadFile(const std::string filename)
{

}

bool ObjFileHandler::isFileLoaded(const std::string filename)
{

}