// This program has been implemented with knowledge of c++ built-in data structure, list iterator
// and with ideas of adjacency list implementation grasped from internet.
#include <iostream>
#include <list>
#define INF 1000000
using namespace std;
class Graph{
    int V;
    int *minDistance;
    list<int> *adjacency;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void printGraph();
    void printDistance();
};
Graph::Graph(int V) {
    this->V=V;
    adjacency = new list<int>[V];
    minDistance = new int[V];
    for (int i = 0; i <V ; ++i) {
        minDistance[i]=INF;
    }
}
void Graph::addEdge(int v, int w) {
    adjacency[v].push_back(w);
    adjacency[w].push_back(v);
}
void Graph::printGraph() {
    list<int>::iterator i;
    for (int j = 0; j < V; ++j) {
        cout << j << " ----> ";
        for (i = adjacency[j].begin() ; i != adjacency[j].end() ; ++i) {
            cout <<" "<< *i;
        }
        cout<<" Min Distance= "<<minDistance[j];
        cout<<endl;
    }
}
void Graph::printDistance() {
    list<int>::iterator i;
    for (int j = 1; j < V; ++j) {
        cout << minDistance[j];
        cout << endl;
    }
}
void Graph::BFS(int front) {
    bool *visited= new bool[V];
    int level;
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    list<int> queue;
    visited[front]= true;
    minDistance[front]=-1;
    queue.push_back(front);
    while (!queue.empty()){
        front=queue.front();
        queue.pop_front();
        list<int>::iterator i;
        level=minDistance[front]+1;
        for(i=adjacency[front].begin(); i!=adjacency[front].end(); i++){
            if (visited[*i]!=true) {
                visited[*i] = true;
                minDistance[*i]=level<minDistance[*i]?level:minDistance[*i];
                queue.push_back(*i);
            }
        }
    }
}
int main() {
    int vertices,edges,k,v,w;
    cin>>vertices>>edges;
    vertices=vertices+1;
    cin>>k;
    Graph g(vertices);
    for (int j = 0; j < k; ++j) {
        int temp;
        cin>>temp;
        g.addEdge(0,temp);
    }
    for (int i = 0; i < edges; ++i) {
        cin >> v >> w;
        g.addEdge(v,w);
    }
    g.BFS(0);
    g.printDistance();
}
