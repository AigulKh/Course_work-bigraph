#include <random>
#include "Vertex.hpp"

template  <typename T, typename R>
class Edge {
    private:
        Vertex <T, R> x;
        Vertex <T, R> y;
        int weight;
    public:
        Edge(Vertex <T, R> x, Vertex <T, R> y) {
            this->x = x;
            this->y = y;
            this->weight = 1 + rand() % 100;
        }

        ~Edge() { }

        Vertex <T, R> getX() {
            return this->x;
        }

        Vertex <T, R> getY() {
            return this->y;
        }

        int getWeight() {
            return this->weight;
        }

        bool operator==(Edge <T, R> e) {
            return ((this->x == e.getX() && this->y == e.getY()) || (this->x == e.getY() && this->y == e.getX()));
        }

};