#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to perform DFS
void dfs(int node, int n, unordered_map<int, vector<int>>& graph, vector<int>& path, vector<vector<int>>& result, vector<bool>& visited) {
    // Add current node to the path
    path.push_back(node);
    
    // If we've reached the last intersection (node n), record the path
    if (node == n) {
        result.push_back(path);
    } else {
        // Mark the node as visited
        visited[node] = true;
        
        // Recur for all the connected nodes that are not visited
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, n, graph, path, result, visited);
            }
        }
        
        // Backtrack: unmark the current node as visited
        visited[node] = false;
    }
    
    // Remove the current node from the path to explore other possibilities
    path.pop_back();
}

int main() {
    int t;
    cin >> t; // number of test cases
    
    while (t--) {
        int n, m;
        cin >> n >> m; // number of intersections (nodes) and number of roads (edges)
        
        // Adjacency list to represent the graph
        unordered_map<int, vector<int>> graph;
        
        // Reading the edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u); // because roads are bidirectional
        }
        
        vector<vector<int>> result; // To store the paths
        vector<int> path;          // To store the current path
        vector<bool> visited(n + 1, false); // To mark visited intersections
        
        // Start DFS from intersection 1
        dfs(1, n, graph, path, result, visited);
        
        // Print all the paths from intersection 1 to intersection n
        for (const auto& p : result) {
            for (int intersection : p) {
                cout << intersection << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}