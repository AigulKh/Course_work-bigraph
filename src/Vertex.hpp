#include <string>
#include <iostream>
#include <vector>
using namespace std;

template  <typename T, typename R>
class Vertex {
    private:    
        T name;
        bool part;
        R machine_type;
        vector <Vertex> adjacent_vertices;

    public:
        Vertex(T name, bool part, R machine_type) {
            this->name = name;
            this->part = part;
            this->machine_type = machine_type;
        }
        
        Vertex() { }

        ~Vertex() { 
            if (!this->adjacent_vertices.empty())
                this->adjacent_vertices.clear();
        }

        T getName() {
            return this->name;
        }

        void setName(T name) {
            this->name = name;
        }

        bool getPart() {
            return this->part;
        }

        void setPart(bool part) {
            this->part = part;
        }

        R getType() {
            return this->machine_type;
        }

        void setType(R machine_type) {
            this->machine_type = machine_type;
        }

        void addAdjacentVertex(Vertex a) {
            this->adjacent_vertices.insert(this->adjacent_vertices.end(), a);
        }

        vector <Vertex> getAdjacentVertex() {
            return this->adjacent_vertices;
        }
};