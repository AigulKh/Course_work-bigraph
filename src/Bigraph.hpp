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
            srand(0);
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

        vector <Vertex <T, R>> getVertexVector() {
            return V;
        }

        vector <Edge <T, R>> getEdgeVector() {
            return E;
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
};