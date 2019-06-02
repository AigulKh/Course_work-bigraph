#include <string>
#include <iostream>
#include <vector>
using namespace std;

template  <typename T>
class Vertex {
    private:    
        size_t name;
        bool part;
        T machine_type;

    public:
        Vertex(size_t name, bool part, T machine_type) {
            this->name = name;
            this->part = part;
            this->machine_type = machine_type;
        }
        
        Vertex() { }

        ~Vertex() { }

        size_t getName() {
            return this->name;
        }

        void setName(size_t name) {
            this->name = name;
        }

        bool getPart() {
            return this->part;
        }

        void setPart(bool part) {
            this->part = part;
        }

        T getType() {
            return this->machine_type;
        }

        void setType(T machine_type) {
            this->machine_type = machine_type;
        }

        bool operator==(Vertex <T> v) {
            return (this->name == v.getName() && this->part == v.getPart() && this->machine_type == v.getType());
        }
};