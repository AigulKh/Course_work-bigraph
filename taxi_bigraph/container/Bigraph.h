#pragma once

#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Iterator.h"
#include "Exceptions.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

namespace BigraphProject 
{
	template <typename T, typename Allocator>
	class Iterator;

	template <typename T, typename Allocator = std::allocator<T> >
	class Bigraph
	{
	private:

		std::vector<Vertex<T>, Allocator> V;
		std::vector<Edge<T>, Allocator> E;

        template <typename U, typename Allocator_>
		friend class Iterator;

	public:
        Bigraph(void) {}
        ~Bigraph(void) {}

        std::vector<Vertex<T>, Allocator> getVertexes() { return this->V; }
        std::vector<Edge<T>, Allocator> getEdges() { return this->E; }

		Iterator<T, Allocator> begin()
		{
			int firstId = 0;

            typename std::vector<Vertex<T> >::iterator firstIt = std::min_element(V.begin(), V.end(),
				[](Vertex<T>& x, Vertex<T>& y) {  return x.getId() < y.getId(); });

			return Iterator<T, Allocator>(*this, &(*firstIt));
		}

		Iterator<T, Allocator> end()
		{
			return Iterator<T, Allocator>(*this, nullptr);
		}

        bool isEmpty(){
            return V.size() == 0;
        }

		int addVertex(Vertex<T> vertex)
		{
			V.push_back(vertex);
			return vertex.getId();
        }

		Vertex<T> getVertexById(int id) throw(VertexNotFoundException)
		{
			for (auto i = V.begin(); i != V.end(); ++i)
			{
				if ((*i).getId() == id)
					return (*i);
			}
			throw VertexNotFoundException(id);
        }

		std::vector<int> delVertex(int id)
		{
			std::vector<int> removeEdge;

            // удаляем ребра
            for(auto it = E.begin(); it != E.end(); it++){
                if((*it).getX().getId() == id || (*it).getY().getId() == id)
                    it = E.erase(it);
            }
            /*E.erase(
                std::remove_if(E.begin(), E.end(),
                            [&id](Edge<T> edge)
                            { return edge.getX().getId() == id || edge.getY().getId() == id; }),
                    E.end());*/

			// удаляем узел
            /*V.erase(std::remove_if(V.begin(), V.end(),
								[&id](Vertex<T> vertex)
								{ return vertex.getId() == id; }),
                    V.end());*/
            for(auto it = V.begin(); it != V.end(); it++){
                if((*it).getId() == id){
                    it = V.erase(it);
                    break;
                }
            }
        }


		int addEdge(Edge<T> edge)
		{
			E.push_back(edge);
			return edge.getId();
        }

		int addEdge(Vertex<T> x, Vertex<T> y) throw(BelongToOnePart, SameVertex)
		{
			if (x.getId() == y.getId())
			{
				throw SameVertex(x.getId());
			}

			if (x.getPart() == y.getPart())
			{
				throw BelongToOnePart(x.getPart());
			}

			Edge<T>* ed = new Edge<T>(x, y);
			E.push_back(*ed);
			return (*ed).getId();
        }

		bool isBigraph_() {
			for (size_t i = 0; i < E.size(); i++) {
				if (E[i].getX().getPart() == E[i].getY().getPart())
					return false;
			}
			return true;
		}

		bool checkEdge(Vertex <T> a, Vertex <T> b) {
			for (size_t i = 0; i < E.size(); i++) {
				if (E[i].getX() == a && E[i].getY() == b)
					return true;
			}
			return false;
		}

		bool checkEdge_(vector <Edge <T>> e, Edge <T> e_) {
			for (size_t i = 0; i < e.size(); i++) {
				if (e[i] == e_)
					return true;
			}
			return false;
		}

		bool checkVertex(vector <Vertex <T>> vec, Vertex <T> v) {
			for (size_t i = 0; i < vec.size(); i++) {
				if (vec[i] == v)
					return true;
			}
			return false;
		}

        void clear(){
            V.clear();
            E.clear();
        }

		void buildGraph() {
			for (size_t i = 0; i < V.size(); i++) {
				for (size_t j = 0; j < V.size(); j++) {
					if (V[i].getType() == V[j].getType() && V[i].getPart() != V[j].getPart())
						if (!checkEdge(V[i], V[j]) && !checkEdge(V[j], V[i])) {
							Edge<T> e(V[i], V[j]);
							addEdge(e);
						}
				}
			}
		}

		vector <Vertex <T>> deleteVertex_(Vertex <T> v, vector <Vertex <T>> white) {
			white.erase(remove(white.begin(), white.end(), v), white.end());
			return white;
		}

		void markVertex(size_t counter, vector <Vertex <T>> &even, vector <Vertex <T>> &odd, Vertex <T> v) {
			if (counter % 2 == 0)
				even.push_back(v);
			else
				odd.push_back(v);
		}

		void DFS(Vertex <T> v, vector <Vertex <T>> &white, vector <Vertex <T>> &even, vector <Vertex <T>> &odd, size_t counter) {
			for (size_t i = 0; i < E.size(); i++) {
				if (E[i].getX() == v && checkVertex(white, E[i].getY())) {
					markVertex(counter, even, odd, E[i].getY());
					white = deleteVertex_(E[i].getY(), white);
					DFS(E[i].getY(), white, even, odd, counter + 1);
				}
				if (E[i].getY() == v && checkVertex(white, E[i].getX())) {
					markVertex(counter, even, odd, E[i].getX());
					white = deleteVertex_(E[i].getX(), white);
					DFS(E[i].getX(), white, even, odd, counter + 1);
				}
			}
		}

		bool isBigraph() {
			vector <Vertex <T>> white;
			vector <Vertex <T>> even;
			vector <Vertex <T>> odd;
			for (size_t i = 0; i < V.size(); i++)
				white.push_back(V[i]);

			size_t counter = 0;
			while (!white.empty()) {
				if (checkVertex(white, white[0])) {
					Vertex <T> v = white[0];
					markVertex(counter, even, odd, v);
					white = deleteVertex_(v, white);
					DFS(v, white, even, odd, counter + 1);
				}
			}

			for (size_t i = 0; i < E.size(); i++) {
				if (checkVertex(even, E[i].getX()) && checkVertex(even, E[i].getY()))
					return false;
				if (checkVertex(odd, E[i].getX()) && checkVertex(odd, E[i].getY()))
					return false;
			}
			return true;
		}

		bool checkFreeVertex(Vertex <T> v, vector <Vertex <T>> free_) {
			for (size_t i = 0; i < free_.size(); i++) {
				if (v == free_[i] && v.getPart()) {
					cout << "finded puth to " << v.getId() << endl;
					return true;
				}
			}
			return false;
		}

		bool checkGoForward(Vertex <T> v, vector <Edge <T>> uncolor) {
			for (size_t i = 0; i < uncolor.size(); i++) {
				if (v == uncolor[i].getX())
					return true;
			}
			return false;
		}

		vector <Edge <T>> goForward(Vertex <T> v, vector <Edge <T>> uncolor, vector <Edge <T>> color, vector <Vertex <T>> free_, vector <Edge <T>> puth, bool &flag) {
			vector <Edge <T>> new_puth = puth;
			if (checkGoForward(v, uncolor)) {
				for (size_t i = 0; i < uncolor.size(); i++) {
					if (v == uncolor[i].getX()) {
						Edge <T> e = uncolor[i];
						Vertex <T> v_ = uncolor[i].getY();
						vector <Edge <T>> uncolor_ = uncolor;
						vector <Edge <T>> puth_ = puth;
						puth_.push_back(e);
						uncolor_.erase(remove(uncolor_.begin(), uncolor_.end(), e), uncolor_.end());
						if (!checkFreeVertex(v_, free_)) {
							if (!flag) new_puth = goBack(v_, uncolor_, color, free_, puth_, flag);
						}
						else {
							flag = !flag;
							return puth_;
						}
					}
					if (flag) break;
				}
			}
			return new_puth;
		}

		bool checkGoBack(Vertex <T> v, vector <Edge <T>> color) {
			for (size_t i = 0; i < color.size(); i++) {
				if (v == color[i].getY())
					return true;
			}
			return false;
		}

		vector <Edge <T>> goBack(Vertex <T> v, vector <Edge <T>> uncolor, vector <Edge <T>> color, vector <Vertex <T>> free_, vector <Edge <T>> puth, bool &flag) {
			vector <Edge <T>> new_puth = puth;
			if (checkGoBack(v, color)) {
				for (size_t i = 0; i < color.size(); i++) {
					if (v == color[i].getY()) {
						Edge <T> e = color[i];
						Vertex <T> v_ = color[i].getX();
						vector <Edge <T>> color_ = color;
						color_.erase(remove(color_.begin(), color_.end(), e), color_.end());
						vector <Edge <T>> puth_ = puth;
						puth_.push_back(e);
						if (!checkFreeVertex(v_, free_)) {
							if (!flag) new_puth = goForward(v_, uncolor, color_, free_, puth_, flag);
						}
						else {
							flag = !flag;
							return puth_;
						}
					}
					if (flag) break;
				}
			}
			return new_puth;
		}

		Bigraph<T> maximumMatching() {
			vector <Vertex <T>> v;
			vector <Edge <T>> e;
			vector <Vertex <T>> free_;
			vector <Edge <T>> color;

			v = V;
			free_ = v;
			for (size_t j = 0; j < E.size(); j++) {
				if (!checkEdge_(color, E[j]) && (checkVertex(free_, E[j].getX()) && checkVertex(free_, E[j].getY()))) {
					color.push_back(E[j]);
					free_ = deleteVertex_(E[j].getX(), free_);
					free_ = deleteVertex_(E[j].getY(), free_);
				}
			}
			e = color;
			size_t count = 0;
			size_t count_ = 0;
			for (size_t i = 0; i < free_.size(); i++) {
				if (free_[i].getPart())
					count++;
				if (!free_[i].getPart())
					count_++;
			}
			if (count != 0 && count_ != 0) {
				e.clear();
				vector <Edge <T>> uncolor;
				for (size_t i = 0; i < E.size(); i++) {
					if (!checkEdge_(color, E[i]))
						uncolor.push_back(E[i]);
				}
				for (size_t i = 0; i < free_.size(); i++) {
					vector <Vertex <T>> free__ = free_;
					vector <Edge <T>> puth;
					bool flag = 0;
					free__.erase(remove(free__.begin(), free__.end(), free_[i]), free__.end());
					puth = goForward(free_[i], uncolor, color, free__, puth, flag);
					if (!puth.empty()) {
						for (size_t k = 0; k < puth.size(); k++) {
							e.push_back(puth[k]);
						}
					}
				}
				vector <Edge <T>> e_;
				for (size_t i = 0; i < e.size(); i++) {
					if (i % 2 == 0)
						e_.push_back(e[i]);
				}
				e = e_;
				for (size_t i = 0; i < color.size(); i++) {
					for (size_t j = 0; j < e.size(); j++) {
						if (color[i].getX() == e[j].getX() || color[i].getY() == e[j].getY())
							break;
						if (j == e.size() - 1)
							e.push_back(color[i]);
					}
				}
			}

			Bigraph <T> graph(v, e);
			return graph;
		}

		std::string toJson()
		{
			json j;
			json v;
			json e;
			for (auto i = V.begin(); i != V.end(); ++i)
			{
				json vertex;
				vertex["type"] = (*i).getType();
				vertex["id"] = (*i).getId();
				vertex["part"] = (*i).getPart();
				v.push_back(vertex);
			}

			for (auto i = E.begin(); i != E.end(); ++i)
			{
				json edge;
				edge["id"] = (*i).getId();
				edge["xId"] = (*i).getX().getId();
				edge["yId"] = (*i).getY().getId();
				e.push_back(edge);
			}

			j["counterVertex"] = Vertex<T>::counter;
			j["counterEdge"] = Edge<T>::counter;
			j["vertexes"] = v;
			j["edges"] = e;

			return j.dump();
		}

		static Bigraph<T, Allocator>* fromJson(std::string str) throw(ParsingJsonException)
		{
			try
			{
				json jsonObj = json::parse(str);

				Bigraph<T, Allocator> *bigraph = new Bigraph<T, Allocator>();
				Vertex<T>::counter = jsonObj["counterVertex"];
				Edge<T>::counter = jsonObj["counterEdge"];
				for (json::iterator i = jsonObj["vertexes"].begin(); i != jsonObj["vertexes"].end(); ++i)
				{
					bigraph->addVertex(Vertex<T>((*i)["type"], (*i)["part"], (*i)["id"]));
				}

				for (json::iterator i = jsonObj["edges"].begin(); i != jsonObj["edges"].end(); ++i)
				{
					Vertex<T> x = bigraph->getVertexById((*i)["xId"]);
					Vertex<T> y = bigraph->getVertexById((*i)["yId"]);
					bigraph->addEdge(Edge<T>(x, y, (*i)["id"]));
				}

				return bigraph;
			}
			catch (...)
			{
				throw ParsingJsonException(str);
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const Bigraph<T, Allocator>& bigraph)
		{
			os << const_cast<Bigraph<T, Allocator>*>(&bigraph)->toJson() << std::endl;
			return os;
        }

		friend std::istream& operator>>(std::istream& is, Bigraph<T, Allocator>** bigraph) throw(ParsingJsonException)
		{
			std::string str;
			is >> str;
			*bigraph = Bigraph<T, Allocator>::fromJson(str);
			return is;
        }
	};
}

