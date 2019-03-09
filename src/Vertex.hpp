#include <string>
#include <iostream>
using namespace std;

class Vertex {
    private:    
        size_t index;
        bool driver;
        string machine_type;
        bool baby_chair;

    public:
        Vertex(size_t index, bool driver, string machine_type, bool baby_chair) {
            this->index = index;
            this->driver = driver;
            this->machine_type = machine_type;
            this->baby_chair = baby_chair;
        }
        
        Vertex() { }

        ~Vertex() { }

        size_t getIndex() {
            return index;
        }

        void setIndex(size_t index) {
            this->index = index;
        }

        bool getDriver() {
            return driver;
        }

        void setDriver(bool driver) {
            this->driver = driver;
        }

        string getType() {
            return machine_type;
        }

        void setType(string machine_type) {
            this->machine_type = machine_type;
        }

        bool getChair() {
            return baby_chair;
        }

        void setChair(bool baby_chair) {
            this->baby_chair = baby_chair;
        }
};