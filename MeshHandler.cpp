#include"MeshHandler.h"

MeshHandler::MeshHandler(std::vector<std::string> meshNames) : bufferSize(0) {
	for (std::string name : meshNames) {
		bufferSize += sizeof(name);
	}

	meshNames = this->meshNames;
}

