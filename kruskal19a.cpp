#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
struct Edge {
int source, destination, weight;
};
struct Subset {
int parent, rank;
};
class Graph { 
//graph concept applied
int V;
vector<Edge> edges;
public:
Graph(int V) : V(V) {}
void addEdge(int source, int destination, int weight) { 
edges.push_back({source, destination, weight});
}
int find(vector<Subset>& subsets, int i) { 
if (subsets[i].parent != i)
subsets[i].parent = find(subsets, subsets[i].parent); 
return subsets[i].parent;
}
void unionSets(vector<Subset>& subsets, int x, int y) { 
int xroot = find(subsets, x);
int yroot = find(subsets, y);
if (subsets[xroot].rank < subsets[yroot].rank) 
subsets[xroot].parent = yroot;
else if (subsets[xroot].rank > subsets[yroot].rank) 
subsets[yroot].parent = xroot;
else {
subsets[yroot].parent = xroot; 
subsets[xroot].rank++;
}
}
void kruskalMST() {
vector<Edge> result; 
int e = 0;
int i = 0;
sort(edges.begin(), edges.end(), [](Edge a, Edge b) { 
return a.weight < b.weight;
});
vector<Subset> subsets(V); 
for (int v = 0; v < V; ++v) {
subsets[v].parent = v; 
subsets[v].rank = 0;
}
while (e < V - 1 && i < edges.size()) { 
Edge next_edge = edges[i++];
int x = find(subsets, next_edge.source);
int y = find(subsets, next_edge.destination);
if (x != y) {
result.push_back(next_edge); 
unionSets(subsets, x, y);
++e;
}
}
cout << "Edges in the Minimum Spanning Tree:" << endl; 
for (auto& edge : result) {
cout << edge.source << " - " << edge.destination << " : "
<< edge.weight << endl;
}
}
};
int main() {
cout<<" Shudhanshu arya GCS —>2140155"<<endl; 
Graph graph(4);
graph.addEdge(0, 1, 10);
graph.addEdge(0, 2, 6);
graph.addEdge(0, 3, 5);
graph.addEdge(1, 3, 15);
graph.addEdge(2, 3, 4);
graph.kruskalMST(); 
return 0;
}