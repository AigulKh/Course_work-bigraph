#pragma once

#include "Bigraph.h"
#include "Vertex.h"

namespace BigraphProject
{
	template <typename T, typename Allocator>
	class Bigraph;

	template <typename T, typename Allocator = std::allocator<T> >
	class Iterator
	{
	private:
		Vertex<T>* iter;
		Bigraph<T, Allocator>& bigraph;
		std::vector<int> ids;

		Vertex<T>* first(Vertex<T>*);

	public:
		Iterator(Bigraph<T, Allocator>& bigraph, Vertex<T>* iter)
		{
			this->bigraph = bigraph;
			this->iter = iter;
			ids.push_back(iter->getId());
		};
		~Iterator() {};

		// пре
		Iterator<T, Allocator>& operator++()
		{
			if (iter == nullptr)
			{
				//TODO кидаем исключение
			}

			// ищем первое вхождение

			return *this;
		};

		// пост
		Iterator<T, Allocator> operator++(int)
		{
			if (iter == nullptr)
			{
				//TODO кидаем исключение
			}

			Iterator<T, Allocator> tmp(*this);
			// ищем первое вхождение

			return *tmp;
		};

		template<class type>
		bool operator==(Iterator<type, Allocator>& it)
		{
			return iter == it.iter;
		};

		template<class type>
		bool operator!=(Iterator<type, Allocator>& it)
		{
			return iter != it.iter;
		};
	};

	template <typename T, typename Allocator>
	Vertex<T>* Iterator<T, Allocator>::first(Vertex<T>* init)
	{
		// реализовать
	}
}

