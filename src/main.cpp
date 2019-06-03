#include "Bigraph.hpp"

int main() {
    srand(0);
    Bigraph <string> a;

    ifstream input("1.txt");
    if (!input.eof()) {
        size_t part;
        string type;
        size_t counter = 0;
        while (input >> part && (part == 0 || part == 1)) {
            input >> type;
            counter++;
            Vertex <string> b(counter, part, type);
            a.addVertex(b);
        }
        
        size_t n = part, b;
        input >> b;
        do {
            Edge <string> e(a.getVertex(n - 1), a.getVertex(b - 1));
            a.addEdge(e);
        } while (input >> n && input >> b);
    }
    input.close();
/*
    if (a.isBigraph_())
        a.showBigraph();
    cout << "___________\n";*/

/*    Vertex <size_t, string> b(6, 0, "Economy");
    Vertex <size_t, string> b_(5, 0, "Economy");
    Vertex <size_t, string> c(2, 0, "Economy");

    Edge <size_t, string> e(b, b_);*/
//    Edge <size_t, string> e_(b_, b_);
//    Edge <size_t, string> e__(b_, b);

//    a.buildGraph();
    a.showBigraph();

//    a.delEdge(e);
//    a.delVertex(c);
//    a.delVertex(b_);
    cout << "___________\n";
    a.maximumMatching().showBigraph();

/*    if (a.isBigraph())
        a.showBigraph();
*/
//    a.DFS();
    /*Vertex <size_t, string> b(2, 0, "Economy");
    Vertex <size_t, string> b_(9, 1, "Economy");

    Edge <size_t, string> e(a.getVertex(50 - 1), a.getVertex(6 - 1));

    a.delVertex(b);
    a.delVertex(b_);
    a.delEdge(e);

    if (a.isBigraph())
        a.showBigraph();*/

    return 0;
}