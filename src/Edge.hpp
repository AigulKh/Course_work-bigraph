#include "Vertex.hpp"

template  <typename T>
class Edge {
    private:
        Vertex <T> x;
        Vertex <T> y;
    public:
        Edge(Vertex <T> x, Vertex <T> y) {
            this->x = x;
            this->y = y;
        }

        ~Edge() {}

        Vertex <T> getX() {
            return this->x;
        }

        Vertex <T> getY() {
            return this->y;
        }

        bool operator==(Edge <T> e) {
            return ((this->x == e.getX() && this->y == e.getY()) || (this->x == e.getY() && this->y == e.getX()));
        }
};