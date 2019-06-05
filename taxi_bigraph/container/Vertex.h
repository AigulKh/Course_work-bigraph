#pragma once

namespace BigraphProject
{
	template <typename T>
	class Vertex
	{
	private:
		T type;
		int id;
		bool part;

	public:
		static int counter;

		Vertex()
		{
		};

		Vertex(T _type, bool _part)
		{
			this->type = _type;
			this->part = _part;
			this->id = counter++;
		};

		Vertex(T _type, bool _part, int _id)
		{
			this->type = _type;
			this->part = _part;
			this->id = _id;
		};

		~Vertex(void){};

		T getType() { return this->type; };

		void setType(T _type)
		{
			this->type = _type;
		};

		bool getPart() { return this->part; };

		void setPart(bool _part)
		{
			this->part = _part;
		};

		int getId() { return this->id; };

		bool operator == (Vertex<T> v)
		{
			return this->id == v.getId();
		};
	};

	template <typename T>
	int Vertex<T>::counter = 0;
}


