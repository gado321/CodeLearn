#include <iostream>
#include <vector>

using namespace std;

const int MAX_VERTEX = 100;
bool seen[MAX_VERTEX];

vector<vector<int>> adj(MAX_VERTEX);

void dfs(int u) {
    seen[u] = true;
    for (auto v : adj[u]) {
        if (!seen[v]) {
            dfs(v);
        }
    }
}

int count_connected_components(int no_vertex) {
    int cnt = 0;
    // for all vertex that has not been visited
    for (int v = 0; v < no_vertex; ++v) {
        if (!seen[v]) {
            // increase the number of components
            cnt++;
            // visit
            dfs(v);
        }
    }
    return cnt;
}

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(3, 4);
    add_edge(4, 5);
    std::cout << count_connected_components(6) << std::endl;
    return 0;
}
