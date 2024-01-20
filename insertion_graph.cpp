#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(NULL) {}
};

class DirectedGraph {
private:
    int vertex;
    Node** list;

public:
    DirectedGraph(int numvertex) : vertex(numvertex) {
        list = new Node*[vertex];
        for (int i = 0; i < vertex; i++) {
            list[i] = NULL;
        }
    }

    void addEdge(int from, int to) {
        Node* newNode = new Node(to);
        newNode->next = list[from];
        list[from] = newNode;
    }

    void print() {
        for (int i = 0; i < vertex; i++) {
            cout << "Vertex " << i << " is connected to:";
            Node* current = list[i];
            while (current) {
                cout << " " << current->data;
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    DirectedGraph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(0, 4);
    graph.addEdge(0, 5);

    graph.print();

    return 0;
}
