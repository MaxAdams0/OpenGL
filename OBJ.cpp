#include"OBJ.h"

void obj::Handler::loadFile(const std::string filename)
{
	obj::File objData(filename);

	std::ifstream objFile;
	objFile.open(filename);
	if (!objFile.is_open()); // add return later

	std::stringstream ssfile;
	ssfile << objFile.rdbuf();

	std::vector<GLfloat[3]> verticies;
	std::vector<int[3]> indicies;
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
			verticies.emplace_back(new GLfloat[3]{ x, y, z });
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
			int vx, vnx;
			util::separateInt(vpairx, "//", &vx, &vnx);
			int vy, vny;
			util::separateInt(vpairy, "//", &vy, &vny);
			int vz, vnz;
			util::separateInt(vpairz, "//", &vz, &vnz);

			indicies.emplace_back(new int[3] { vx, vy, vz });
		}
	}
	objFile.close();

	objData.setVerticies(verticies);
	objData.setIndicies(indicies);
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
	if (getVerticies().empty()) { return false; }
	//if (file->getTexCoords().empty()) { return false; }
	//if (file->getVerticeNormals().empty()) { return false; }
	if (getIndicies().empty()) { return false; }

	return true;
}