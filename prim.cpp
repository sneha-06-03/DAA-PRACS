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
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX; // treat as no edge
        }
    }

    vector<bool> visited(n, false);
    visited[0] = true; // start from vertex 0

    int edges = 0, minCost = 0;

    cout << "Edges in MST:\n";

    while (edges < n - 1) {
        int min = INT_MAX, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            cout << u << " - " << v << " : " << min << endl;
            minCost += min;
            visited[v] = true;
            edges++;
        }
    }

    cout << "Minimum Cost = " << minCost << endl;

    return 0;
}

// INPUT

//Enter number of vertices: 4
//Enter cost matrix:
//0 2 0 6
//2 0 3 8
//0 3 0 0
//6 8 0 0

// OUTPUT

//Edges in MST:
//0 - 1 : 2
//1 - 2 : 3
//0 - 3 : 6
//Minimum Cost = 11