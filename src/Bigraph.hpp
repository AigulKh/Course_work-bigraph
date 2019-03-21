#include <fstream>
#include <string>
#include <iostream>
#include "Edge.hpp"
#include <vector>
using namespace std;

class Bigraph {
    private:    
        vector<Vertex> V;
        vector<Edge> E;

    public:
        Bigraph() {
            ifstream input("1.txt");
            string machine_type;
            int driver, baby_chair;
            size_t count = 0;
            if (!input.eof())
                while (input >> driver && (driver == 0 || driver == 1)) {
                    input >> machine_type;
                    input >> baby_chair;
                    count++;
                    Vertex v(count, (bool)driver, machine_type, (bool)baby_chair);
                    V.insert(V.end(), v);
                }
            if (!input.eof()) {
                size_t a = driver;
                size_t b;
                input >> b;
                if (V[a].getDriver() != V[b].getDriver()) {
                    Edge e(V[a], V[b]);
                    E.insert(E.end(), e);
                }

                while(input >> a && input >> b)
                    if (V[a].getDriver() != V[b].getDriver()) {
                        Edge e(V[a], V[b]);
                
                        E.insert(E.end(), e);
                    }            
            }
            input.close();
        }

        ~Bigraph() { }
};