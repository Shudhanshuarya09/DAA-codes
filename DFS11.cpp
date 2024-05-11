#include <iostream> 
#include <vector>
using namespace std;
void DFS(vector<vector<int>>& graph, int currentVertex, vector<bool>& 
visited) {
visited[currentVertex] = true;
for (int neighbor : graph[currentVertex]) { 
if (!visited[neighbor]) {
DFS(graph, neighbor, visited);
}
}
}
bool isConnected(vector<vector<int>>& graph) { 
int V = graph.size();
vector<bool> visited(V, false); 
DFS(graph, 0, visited);
for (bool isVisited : visited) { 
if (!isVisited) {
return false;
}
}
return true;
}
int main() {
cout<<" Shudhanshu arya GCS —>2140155"<<endl; 
vector<vector<int>> graph = {
{1, 2},
{0, 2},
{0, 1}
};
if (isConnected(graph))
cout << "The graph is connected.\n";
else
cout << "The graph is not connected.\n";
return 0;
}
