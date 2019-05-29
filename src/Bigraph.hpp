#include <fstream>
#include "Edge.hpp"
using namespace std;

template <typename T, typename R>
class Bigraph {
    private:    
        vector <Vertex <T, R>> V;
        vector <Edge <T, R>> E;
    public:
        Bigraph() {
        }

        ~Bigraph() {
            if (!V.empty())
                V.clear();
            if (!E.empty())
                E.clear();
        }

        void showBigraph() {
            for (size_t i = 0; i < V.size(); i++)
                cout << V[i].getName() << ", " << V[i].getPart() << ", " << V[i].getType() << ", " << endl;
            for (size_t i = 0; i < E.size(); i++)
                cout << E[i].getX().getName() << " - " << E[i].getY().getName() << ": " << E[i].getWeight() << endl;
        }

        Vertex <T, R> getVertex(size_t i) {
            return V[i];
        }

        Edge <T, R> getEdge(size_t i) {
            return E[i];
        }

        void addVertex(Vertex <T, R> v) {
            V.push_back(v);
        }
        
        void delVertex(Vertex <T, R> v) {
            for (size_t j = 0; j < E.size(); j++) {
                for (size_t i = 0; i < E.size(); i++) {
                    if (v.getName() == E[i].getX().getName() || v.getName() == E[i].getY().getName())
                        E.erase(E.begin() + i);
                }
            }

            for (size_t i = 0; i < V.size(); i++) {
                if (V[i].getName() == v.getName())
                    V.erase(V.begin() + i);
            }
        }

        void addEdge(Edge <T, R> e) {
            E.push_back(e);
        }

        void delEdge(Edge <T, R> e) {
            for (size_t i = 0; i < E.size(); i++) {
                if (E[i].getX().getName() == e.getX().getName() && E[i].getY().getName() == e.getY().getName())
                    E.erase(E.begin() + i);
            }
        }

        bool isBigraph_() {
            for (size_t i = 0; i < E.size(); i++) {
                if (E[i].getX().getPart() == E[i].getY().getPart())
                    return false;
            }
            return true;
        }

        bool checkEdge(Vertex <T, R> a, Vertex <T, R> b) {
            for (size_t i = 0; i < E.size(); i++) {
                if (E[i].getX().getName() == a.getName() && E[i].getY().getName() == b.getName())
                    return true;
            }
            return false;
        }

        bool checkVertex(vector <Vertex <T, R>> vec, Vertex <T, R> v) {
            for (size_t i = 0; i < vec.size(); i++) {
                if (vec[i].getName() == v.getName())
                    return true;
            }
            return false;
        }

        void buildGraph() {
            for (size_t i = 0; i < V.size(); i++) {
                for (size_t j = 0; j < V.size(); j++) {
                    if (V[i].getType() == V[j].getType() && V[i].getPart() != V[j].getPart())
                        if (!checkEdge(V[i], V[j]) && !checkEdge(V[j], V[i])) {
                            Edge <T, R> e(V[i], V[j]);
                            addEdge(e);
                        }
                }
            }
        }

        vector <Vertex <T, R>> deleteVertex_(Vertex <T, R> v, vector <Vertex <T, R>> white) {
            for (size_t i = 0; i < white.size(); i++) {
                if (white[i].getName() == v.getName())
                    white.erase(white.begin() + i);
            }
            return white;
        }

        void markVertex(vector <Vertex <T, R>> white, vector <Vertex <T, R>> &even, vector <Vertex <T, R>> &odd, Vertex <T, R> v) {
            if (white.size() % 2 == 0) 
                even.push_back(v);
            else
                odd.push_back(v);
        }

        void DFS(Vertex <T, R> v, vector <Vertex <T, R>> &white, vector <Vertex <T, R>> &even, vector <Vertex <T, R>> &odd) { 
            for (size_t i = 0; i < E.size(); i++) {
                if (E[i].getX().getName() == v.getName() && checkVertex(white, E[i].getY())) {
                    markVertex(white, even, odd, E[i].getY());
                    white = deleteVertex_(E[i].getY(), white);
                    DFS(E[i].getY(), white, even, odd);
                }
                if (E[i].getY().getName() == v.getName() && checkVertex(white, E[i].getX())) {
                    markVertex(white, even, odd, E[i].getX());
                    white = deleteVertex_(E[i].getX(), white);
                    DFS(E[i].getX(), white, even, odd);
                }
            }
        }

        bool isBigraph() {
            vector <Vertex <T, R>> white;            
            vector <Vertex <T, R>> even;            
            vector <Vertex <T, R>> odd;            
            for (size_t i = 0; i < V.size(); i++)
                white.push_back(V[i]);

            while (!white.empty()) {
                if (checkVertex(white, white[0])) {
                    Vertex <T, R> v = white[0];
                    markVertex(white, even, odd, v);
                    white = deleteVertex_(v, white);
                    DFS(v, white, even, odd);
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
};