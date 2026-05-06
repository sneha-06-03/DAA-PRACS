#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INT_MAX;
        }
    }

    int s;
    cout << "Enter source vertex: ";
    cin >> s;

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1, minDist = INT_MAX;

        // Find minimum distance unvisited node
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        visited[u] = true;

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != INT_MAX &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    cout << "Shortest distances from node " << s << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
    }

    return 0;
}

// INPUT

//Enter number of vertices: 4
//Enter cost matrix:
//0 1 4 0
//1 0 2 6
//4 2 0 3
//0 6 3 0
//Enter source vertex: 0

// OUTPUT

//Shortest distances from node 0:
//To 0 = 0
//To 1 = 1
//To 2 = 3
//To 3 = 6