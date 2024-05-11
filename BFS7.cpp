#include <iostream> 
#include <vector> 
#include <queue>
using namespace std;
void BFS(vector<vector<int>>& graph, int startVertex) { 
int V = graph.size();
vector<bool> visited(V, false); 
vector<int> distances(V, -1);
visited[startVertex] = true; 
distances[startVertex] = 0;
queue<int> q; 
q.push(startVertex);
while (!q.empty()) {
int currentVertex = q.front(); 
q.pop();
for (int neighbor : graph[currentVertex]) { 
if (!visited[neighbor]) {
visited[neighbor] = true;
distances[neighbor] = distances[currentVertex] + 1; 
q.push(neighbor);
}
}
}
cout << "Shortest distances from vertex " << startVertex << ":\n"; 
for (int i = 0; i < V; ++i) {
cout << "Vertex " << i << ": "; 
if (distances[i] == -1) {
cout << "Not reachable\n";
} else {
cout << distances[i] << " units away\n";
}
}
}
int main() {
cout<<"Shudhanshu arya GCS —>2140155"<<endl;
vector<vector<int>> graph = {
{1, 2},
{0, 3, 4},
{0, 4},
{1},
{1, 2}
};
int startVertex = 0; 
BFS(graph, startVertex);
return 0;
}