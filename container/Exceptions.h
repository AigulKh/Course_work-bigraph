#pragma once

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"


namespace BigraphProject
{
	class VertexNotFoundException
	{
	private:
		int id;

	public:
		VertexNotFoundException(int id) { this->id = id; };
		int getId() { return id; }
	};

	template <typename T>
	class IteratorOutOfBoundsException
	{
	private:
		Vertex<T>* iter;

	public:
		IteratorOutOfBoundsException(Vertex<T>* iter) { this->iter = iter; };
		Vertex<T>* getIter() { return iter; }
	};

	class ParsingJsonException {
	private:
		std::string json;

	public:
		ParsingJsonException(std::string json) { this->json = json; };

		std::string getJson() { return json; }
	};

	class BelongToOnePart {
	private:
		bool part;
	public:
		BelongToOnePart(bool part) { this->part = part; };

		bool getPart() { return this->part; }
	};

	class SameVertex {
	private:
		int id;
	public:
		SameVertex(int id) { this->id = id; };

		int getid() { return this->id; }
	};
}
