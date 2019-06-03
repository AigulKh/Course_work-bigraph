#include <fstream>
#include <algorithm>
#include "Edge.hpp"
using namespace std;

template <typename T>
class Bigraph {
    private:    
        vector <Vertex <T>> V;
        vector <Edge <T>> E;
    public:
        Bigraph() { }

        Bigraph(vector <Vertex <T>> V, vector <Edge <T>> E) { 
            this->V = V;
            this->E = E;
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
                cout << E[i].getX().getName() << " - " << E[i].getY().getName() << endl;
        }

        Vertex <T> getVertex(size_t i) {
            return V[i];
        }

        Edge <T> getEdge(size_t i) {
            return E[i];
        }

        void addVertex(Vertex <T> v) {
            V.push_back(v);
        }
        
        void delVertex(Vertex <T> v) {            
            for (size_t i = 0; i < E.size(); i++) {
                if (E[i].getX() == v || E[i].getY() == v) {
                    E.erase(remove(E.begin(), E.end(), E[i]), E.end());
                    i--;
                }
            }
            V.erase(remove(V.begin(), V.end(), v), V.end());
        }

        void addEdge(Edge <T> e) {
            if (e.getX().getPart() == e.getY().getPart())
                return;
            if (e.getX().getType() != e.getY().getType())
                return;
            E.push_back(e);
        }

        void delEdge(Edge <T> e) {
            E.erase(remove(E.begin(), E.end(), e), E.end());
        }

        bool isBigraph_() {
            for (size_t i = 0; i < E.size(); i++) {
                if (E[i].getX().getPart() == E[i].getY().getPart())
                    return false;
            }
            return true;
        }

        bool checkEdge(Vertex <T> a, Vertex <T> b) {
            for (size_t i = 0; i < E.size(); i++) {
                if (E[i].getX() == a && E[i].getY() == b)
                    return true;
            }
            return false;
        }

        bool checkEdge_(vector <Edge <T>> e, Edge <T> e_) {
            for (size_t i = 0; i < e.size(); i++) {
                if (e[i] == e_)
                    return true;
            }            
            return false;
        }

        bool checkVertex(vector <Vertex <T>> vec, Vertex <T> v) {
            for (size_t i = 0; i < vec.size(); i++) {
                if (vec[i] == v)
                    return true;
            }
            return false;
        }

        void buildGraph() {
            for (size_t i = 0; i < V.size(); i++) {
                for (size_t j = 0; j < V.size(); j++) {
                    if (V[i].getType() == V[j].getType() && V[i].getPart() != V[j].getPart())
                        if (!checkEdge(V[i], V[j]) && !checkEdge(V[j], V[i])) {
                            Edge <T> e(V[i], V[j]);
                            addEdge(e);
                        }
                }
            }
        }

        vector <Vertex <T>> deleteVertex_(Vertex <T> v, vector <Vertex <T>> white) {
            white.erase(remove(white.begin(), white.end(), v), white.end());
            return white;
        }

        void markVertex(size_t counter, vector <Vertex <T>> &even, vector <Vertex <T>> &odd, Vertex <T> v) {
            if (counter % 2 == 0) 
                even.push_back(v);
            else
                odd.push_back(v);
        }

        void DFS(Vertex <T> v, vector <Vertex <T>> &white, vector <Vertex <T>> &even, vector <Vertex <T>> &odd, size_t counter) {
            for (size_t i = 0; i < E.size(); i++) {
                if (E[i].getX() == v && checkVertex(white, E[i].getY())) {
                    markVertex(counter, even, odd, E[i].getY());
                    white = deleteVertex_(E[i].getY(), white);
                    DFS(E[i].getY(), white, even, odd, counter + 1);
                }
                if (E[i].getY() == v && checkVertex(white, E[i].getX())) {
                    markVertex(counter, even, odd, E[i].getX());
                    white = deleteVertex_(E[i].getX(), white);
                    DFS(E[i].getX(), white, even, odd, counter + 1);
                }
            }
        }

        bool isBigraph() {
            vector <Vertex <T>> white;            
            vector <Vertex <T>> even;            
            vector <Vertex <T>> odd;            
            for (size_t i = 0; i < V.size(); i++)
                white.push_back(V[i]);

            size_t counter = 0;
            while (!white.empty()) {
                if (checkVertex(white, white[0])) {
                    Vertex <T> v = white[0];
                    markVertex(counter, even, odd, v);
                    white = deleteVertex_(v, white);
                    DFS(v, white, even, odd, counter + 1);
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

        bool checkFreeVertex(Vertex <T> v, vector <Vertex <T>> free_) {
            for (size_t i = 0; i < free_.size(); i++) {
                if (v == free_[i] && v.getPart()) {
                    cout << "finded puth to " << v.getName() << endl;
                    return true;
                }
            }
            return false;
        }

        bool checkGoForward(Vertex <T> v, vector <Edge <T>> uncolor) {
            for (size_t i = 0; i < uncolor.size(); i++) {
                if (v == uncolor[i].getX())
                    return true;
            }
            return false;
        }

        vector <Edge <T>> goForward(Vertex <T> v, vector <Edge <T>> uncolor, vector <Edge <T>> color, vector <Vertex <T>> free_, vector <Edge <T>> puth, bool &flag) {
            vector <Edge <T>> new_puth = puth;
            if (checkGoForward(v, uncolor)) {
                for (size_t i = 0; i < uncolor.size(); i++) {
                    if (v == uncolor[i].getX()) {
                        Edge <T> e = uncolor[i];
                        Vertex <T> v_ = uncolor[i].getY();
                        vector <Edge <T>> uncolor_ = uncolor;
                        vector <Edge <T>> puth_ = puth;
                        puth_.push_back(e);
                        uncolor_.erase(remove(uncolor_.begin(), uncolor_.end(), e), uncolor_.end());
                        if (!checkFreeVertex(v_, free_)) {
                            if (!flag) new_puth = goBack(v_, uncolor_, color, free_, puth_, flag);
                        }
                        else {
                            flag = !flag;
                            return puth_;
                        }
                    }
                    if (flag) break;
                }
            }
            return new_puth;
        }

        bool checkGoBack(Vertex <T> v, vector <Edge <T>> color) {
            for (size_t i = 0; i < color.size(); i++) {
                if (v == color[i].getY())
                    return true;
            }
            return false;
        }

        vector <Edge <T>> goBack(Vertex <T> v, vector <Edge <T>> uncolor, vector <Edge <T>> color, vector <Vertex <T>> free_, vector <Edge <T>> puth, bool &flag) {
            vector <Edge <T>> new_puth = puth;
            if (checkGoBack(v, color)) {
                for (size_t i = 0; i < color.size(); i++) {
                    if (v == color[i].getY()) {
                        Edge <T> e = color[i];
                        Vertex <T> v_ = color[i].getX();
                        vector <Edge <T>> color_ = color;
                        color_.erase(remove(color_.begin(), color_.end(), e), color_.end());
                        vector <Edge <T>> puth_ = puth;
                        puth_.push_back(e);
                        if (!checkFreeVertex(v_, free_)) {
                            if (!flag) new_puth = goForward(v_, uncolor, color_, free_, puth_, flag);
                        }
                        else {
                            flag = !flag;
                            return puth_;
                        }
                    }
                    if (flag) break;
                }
            }
            return new_puth;
        }

        Bigraph <T> maximumMatching() {
            vector <Vertex <T>> v;
            vector <Edge <T>> e;
            vector <Vertex <T>> free_;
            vector <Edge <T>> color;

            v = V;
            free_ = v;
            for (size_t j = 0; j < E.size(); j++) {
                if (!checkEdge_(color, E[j]) && (checkVertex(free_, E[j].getX()) && checkVertex(free_, E[j].getY()))) {
                    color.push_back(E[j]);
                    free_ = deleteVertex_(E[j].getX(), free_);
                    free_ = deleteVertex_(E[j].getY(), free_);
                }
            }
            e = color;
            size_t count = 0;
            size_t count_ = 0;
            for (size_t i = 0; i < free_.size(); i++) {
                if (free_[i].getPart())
                    count++;
                if (!free_[i].getPart())
                    count_++;
            }
            if (count != 0 && count_ != 0) {
                e.clear();
                vector <Edge <T>> uncolor;
                for (size_t i = 0; i < E.size(); i++) {
                    if (!checkEdge_(color, E[i]))
                        uncolor.push_back(E[i]);
                }
                for (size_t i = 0; i < free_.size(); i++) {
                    vector <Vertex <T>> free__ = free_;
                    vector <Edge <T>> puth;
                    bool flag = 0;
                    free__.erase(remove(free__.begin(), free__.end(), free_[i]), free__.end());
                    puth = goForward(free_[i], uncolor, color, free__, puth, flag);
                    if (!puth.empty()) {
                        for (size_t k = 0; k < puth.size(); k++) {
                            e.push_back(puth[k]);
                        }
                    }
                }
                vector <Edge <T>> e_;
                for (size_t i = 0; i < e.size(); i++) {
                    if (i % 2 == 0)
                        e_.push_back(e[i]);
                }
                e = e_;
                for (size_t i = 0; i < color.size(); i++) {
                    for (size_t j = 0; j < e.size(); j++) {
                        if (color[i].getX() == e[j].getX() || color[i].getY() == e[j].getY())
                            break;
                        if (j == e.size() - 1)
                            e.push_back(color[i]);
                    }
                }
            }

            Bigraph <T> graph(v, e);
            return graph;
        }
};