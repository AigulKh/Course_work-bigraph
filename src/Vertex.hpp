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

    public:
        Vertex(T name, bool part, R machine_type) {
            this->name = name;
            this->part = part;
            this->machine_type = machine_type;
        }
        
        Vertex() { }

        ~Vertex() { }

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
};