#pragma once
#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include<string>

#include"MeshHandler.h"

class Mesh : protected MeshHandler 
{
	public:
		std::string name;
		bool visible;

		Mesh(std::string name)

		bool isInView();
		void load();
};

#endif