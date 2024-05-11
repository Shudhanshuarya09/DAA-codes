#include <iostream> 
#include <vector> 
#include <queue> 
#include <unordered_set>
using namespace std;
void BFS(vector<vector<int>>& graph, int startVertex, 
unordered_set<int>& component) {
int V = graph.size(); 
vector<bool> visited(V, false); 
queue<int> q; 
visited[startVertex] = true; 
q.push(startVertex);
while (!q.empty()) {
int currentVertex = q.front(); 
q.pop(); 
component.insert(currentVertex);
for (int neighbor : graph[currentVertex]) { 
if (!visited[neighbor]) {
visited[neighbor] = true; 
q.push(neighbor);
}
}
}
}
vector<unordered_set<int>> findConnectedComponents(vector<vector<int>>& 
graph) {
int V = graph.size(); 
vector<bool> visited(V, false);
vector<unordered_set<int>> connectedComponents; 
for (int i = 0; i < V; ++i) {
if (!visited[i]) { 
unordered_set<int> component; 
BFS(graph, i, component);
for (int v : component) visited[v] = true; 
connectedComponents.push_back(component);
}
}
return connectedComponents;
}
int main() {
cout<<" Shudhanshu arya GCS —>2140155"<<endl; 
vector<vector<int>> graph = {
{1, 2},
{0, 3, 4},
{0, 4},
{1},
{1, 2},
{6},
{5}
};
vector<unordered_set<int>> connectedComponents = 
findConnectedComponents(graph);
cout << "Connected Components:\n";
for (size_t i = 0; i < connectedComponents.size(); ++i) { 
cout << "Component " << i + 1 << ": ";
for (int vertex : connectedComponents[i]) { 
cout << vertex << " ";
}
cout << endl;
}
return 0;
}
