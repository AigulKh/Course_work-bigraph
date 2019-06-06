#pragma once

#include "Bigraph.h"

namespace BigraphProject
{
	template <typename T, typename Allocator>
	class Bigraph;

    template <typename T>
    class IteratorOutOfBoundsException;

	template <typename T, typename Allocator = std::allocator<T> >
	class Iterator
	{
	private:
		Vertex<T>* iter;
		Bigraph<T, Allocator>& bigraph;
		std::vector<int> ids;

		Vertex<T>* first(Vertex<T>*);

	public:
		Iterator(Bigraph<T, Allocator>& bi, Vertex<T>* i) : bigraph(bi), iter(i)
		{
			if (iter != nullptr)
				ids.push_back(iter->getId());
		};
		~Iterator() {};

		// пре
		Iterator<T, Allocator>& operator++()
        {
			if (iter == nullptr)
			{
                throw IteratorOutOfBoundsException<T>(iter);
			}

			// ищем первое вхождение
			iter = first(iter);
			if (iter != nullptr)
			{
				ids.push_back(iter->getId());
			}

			return *this;
		};

		// пост
		Iterator<T, Allocator> operator++(int)
		{
			if (iter == nullptr)
			{
                throw IteratorOutOfBoundsException<T>(iter);
			}

			Iterator<T, Allocator> tmp(*this);
			// ищем первое вхождение
			iter = first(iter);
			if (iter != nullptr)
			{
				ids.push_back(iter->getId());
			}

			return tmp;
		};

		Vertex<T> operator*()
		{
			if (iter == nullptr)
				throw IteratorOutOfBoundsException<T>(iter);

			return *iter;
		};

		Vertex<T> operator->()
		{
			if (iter == nullptr)
				throw IteratorOutOfBoundsException<T>(iter);

			return *iter;
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

	template<typename T, typename Allocator>
	Vertex<T>* Iterator<T, Allocator>::first(Vertex<T>* init)
	{
		// реализовать
		std::vector<Edge<T> > next_edges;
        typename std::vector<Edge<T> >::iterator i = bigraph.E.begin();
		while ((i = std::find_if(i, bigraph.E.end(),
			[&init](Edge<T> e) { return e.getX().getId() == init->getId(); })) != bigraph.E.end())
		{
			if (std::find(ids.begin(), ids.end(), (*i).getY().getId()) == ids.end())
				next_edges.push_back((*i));

			i++;
		}

		if (next_edges.empty())
		{
			std::vector<Edge<T> > back_edges;
            typename std::vector<Edge<T> >::iterator i = bigraph.E.begin();
			while ((i = std::find_if(i, bigraph.E.end(),
				[&init](Edge<T> e) { return e.getY().getId() == init->getId(); })) != bigraph.E.end())
			{
				back_edges.push_back((*i));
				i++;
			}

			if (back_edges.empty())
				return nullptr;

            typename std::vector<Edge<T> >::iterator back_edge = std::min_element(back_edges.begin(), back_edges.end(),
				[](Edge<T> x, Edge<T> y) {  return x.getX().getId() < y.getX().getId(); });

            typename std::vector<Vertex<T> >::iterator prev = std::find_if(bigraph.V.begin(), bigraph.V.end(),
				[&back_edge](Vertex<T>& v) { return v.getId() == (*back_edge).getX().getId(); });

			return first(&(*prev));
		}

        typename std::vector<Edge<T> >::iterator next_edge = std::min_element(next_edges.begin(), next_edges.end(),
			[](Edge<T> x, Edge<T> y) {  return x.getY().getId() < y.getY().getId(); });

        typename std::vector<Vertex<T> >::iterator next = std::find_if(bigraph.V.begin(), bigraph.V.end(),
			[&next_edge](Vertex<T>& v) { return v.getId() == (*next_edge).getY().getId(); });

		return &(*next);
	}
}

