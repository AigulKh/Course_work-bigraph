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

		Vertex(T type, bool part)
		{
			this->type = type;
			this->part = part;
			this->id = counter++;
		};
		Vertex(T type, bool part, int id)
		{
			this->type = type;
			this->part = part;
			this->id = id;
		};
		~Vertex(void){};

		T getType() { return this->type; };

		void setType(T type)
		{
			this->type = type;
		};

		bool getPart() { return this->part; };

		void setPart(bool part)
		{
			this->part = part;
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


