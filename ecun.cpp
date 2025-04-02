#include <iostream>

using namespace std;

class Graph{
public:
    int numVertices;
    int** list;

    Graph(int verticies){
        numVertices = verticies;
        list = new int*[verticies];

        for(int i = 0; i < verticies; i++){
            list[i] = new int[verticies];
            for (int j = 0; j < verticies; j++){
                list[i][j] = -1;
            }
        }
    }

    void addEdge(int u, int v){
        int i = 0;

        while(list[u][i] != -1){
            i++;
        }

        list[u][i] = v;
    }

    void printG(){
        for(int i = 0; i < numVertices; i++){
            cout << i << ": ";
            int j = 0;
            while(list[i][j] != -1){
                cout << list[i][j] << " ";
                j++;
            }
            cout << endl;
        }
    }

    ~Graph(){
        for(int i = 0; i < numVertices; i++){
            delete[] list[i];
        }
        delete[] list;
    }

};


int main(){
    int verticies;
    cin >> verticies;

    Graph graph(verticies);

    int edges;
    cin >> edges;

    int count = 0;

    while(count < edges){
        int u, v;

        cin >> u >> v;
        graph.addEdge(u,v);

        count++;
    }

    graph.printG();

    return 0;
}