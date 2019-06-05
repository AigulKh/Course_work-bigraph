#pragma once

#include "Vertex.h"

namespace BigraphProject
{
	template <typename T>
	class Edge
	{

	private:
		Vertex<T> x;
        Vertex<T> y;
		int id;

	public:
		static int counter;

		Edge(Vertex <T> x, Vertex <T> y)
		{
			this->x = x;
            this->y = y;
			this->id = counter++;
		};
		Edge(Vertex <T> x, Vertex <T> y, int id)
		{
			this->x = x;
			this->y = y;
			this->id = id;
		};
		~Edge(void) {};

		Vertex<T> getX() { return this->x };
		Vertex<T> getY() { return this->y };

		int getId() { return this->id };

		bool operator == (Edge<T> e)
		{
			return ((this->x == e.getX() && this->y == e.getY()) || (this->x == e.getY() && this->y == e.getX()));
		};
	};

	template <typename T>
	int Edge<T>::counter = 0;
}

