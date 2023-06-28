#include"OBJ.hpp"

void obj::Handler::loadFile(const std::string filename)
{
	obj::File objData(filename);

	std::ifstream objFile;
	objFile.open(filename);
	//if (!objFile.is_open())

	std::stringstream ssfile;
	ssfile << objFile.rdbuf();

	std::vector<GLfloat[3]> vertices;
	std::vector<GLuint[3]> indices;
	//std::vector<int[3]> verticeNormals;
	std::string line;
	while (std::getline(objFile, line))
	{
		std::string id;
		std::istringstream iss(line);

		iss >> id;

		/*if (id == "o") {
			objData.setName(line.substr(2, line.find_first_of('_')));
		}*/
		if (id == "v") {
			GLfloat x, y, z;
			iss >> x >> y >> z;
			vertices.emplace_back(new GLfloat[3]{ x, y, z });
		}
		/*else if (id == "vn") {
			GLfloat x, y, z;
			iss >> x >> y >> z;
			verticeNormals.emplace_back(new GLfloat[3]{ x, y, z });
		}*/
		else if (id == "f") {
			// short for vertex pair _, pair of vertex and vertex normal xyz's
			std::string vpairx, vpairy, vpairz;
			iss >> vpairx >> vpairy >> vpairz;
			GLuint vx, vnx;
			util::separateInt(vpairx, "//", &vx, &vnx);
			GLuint vy, vny;
			util::separateInt(vpairy, "//", &vy, &vny);
			GLuint vz, vnz;
			util::separateInt(vpairz, "//", &vz, &vnz);

			indices.emplace_back(new GLuint[3] { vx, vy, vz });
		}
	}
	objFile.close();

	objData.setVertices(vertices);
	objData.setIndices(indices);
	//objData.setVerticeNormals(verticeNormals);
}

obj::File obj::Handler::getFile(const std::string filename)
{
	for (int i = 0; i < obj::Handler::getLoadedFiles().size(); i++)
	{
		if (obj::Handler::getLoadedFiles()[i].getName() == filename) {
			return obj::Handler::getLoadedFiles()[i];
		}
	}

	return obj::File(filename);
}

void obj::Handler::unloadFile(const std::string filename)
{

}

bool obj::Handler::isFileLoaded(const std::string filename)
{

}

bool obj::File::isValid()
{
	if (getName().empty()) { return false; }
	if (getVertices().empty()) { return false; }
	//if (file->getTexCoords().empty()) { return false; }
	//if (file->getVerticeNormals().empty()) { return false; }
	if (getIndices().empty()) { return false; }

	return true;
}