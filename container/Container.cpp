// Container.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Bigraph.h"
#include "Vertex.h"
#include "AllocatorContainer.h"

using namespace BigraphProject;

int _tmain(int argc, _TCHAR* argv[])
{
	Bigraph<std::string, AllocatorContainer<std::string>> *bi = new Bigraph<std::string, AllocatorContainer<std::string>>();
	int id = bi->addVertex(Vertex<std::string>("data", true));
	id = bi->addVertex(Vertex<std::string>("data", false));
	return 0;
}

