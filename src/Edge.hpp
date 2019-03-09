#include "Vertex.hpp"
#include <random>

class Edge {
    private:
        Vertex x;
        Vertex y;
        int weight;
    public:
        Edge(Vertex x, Vertex y) {
            this->x = x;
            this->y = y;
            this->weight = 1 + rand() % 100;
        }

        ~Edge() { }

        Vertex getX() {
            return this->x;
        }

        Vertex getY() {
            return this->y;
        }

        int getWeight() {
            return this->weight;
        }
};