// Container.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Bigraph.h"
#include "Vertex.h"
#include "AllocatorContainer.h"

using namespace BigraphProject;

int _tmain(int argc, _TCHAR* argv[])
{
	Bigraph<std::string, AllocatorContainer<std::string>> *bi = new Bigraph<std::string, AllocatorContainer<std::string>>();
	int id1 = bi->addVertex(Vertex<std::string>("data", true));
	int id2 = bi->addVertex(Vertex<std::string>("data32", false));
	try
	{
		bi->addEdge(bi->getVertexById(id1), bi->getVertexById(id2));
	}
	catch (BelongToOnePart part)
	{
		cout << "part";
	}
	catch (SameVertex same)
	{
		cout << "same vertex";
	}

	
	//bi->delVertex(id1);
	Vertex<std::string> v = bi->getVertexById(id2);

	/*for (auto it = bi->begin(); it != bi->end(); it++)
		std::cout << "\nIterator: " << (*it).getType();
	std::cout << std::endl;*/

	/*std::ofstream jsonfile;
	jsonfile.open("bigraphContainer.json");
	jsonfile << *bi;
	jsonfile.close();*/

	try
	{
		std::ifstream myfile2;
		myfile2.open("bigraphContainer.json");
		Bigraph<std::string, AllocatorContainer<std::string> > *bi2;
		myfile2 >> &bi2;
		myfile2.close();
		cout << bi2->isBigraph_();
	}
	catch(ParsingJsonException json)
	{
		cout << json.getJson();
	}
	return 0;
}

