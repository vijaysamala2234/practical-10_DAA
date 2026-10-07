#include <iostream>
using namespace std;

int main() {

    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    // u, v, weight
    int edges[20][3];

    cout << "Enter edges (vertex1 vertex2 weight):\n";

    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {

            if (edges[j][2] > edges[j + 1][2]) {

                // Swap vertex 1
                int temp = edges[j][0];
                edges[j][0] = edges[j + 1][0];
                edges[j + 1][0] = temp;

                // Swap vertex 2
                temp = edges[j][1];
                edges[j][1] = edges[j + 1][1];
                edges[j + 1][1] = temp;

                // Swap weight
                temp = edges[j][2];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][2] = temp;
            }
        }
    }

    int parent[20];

    // Initially, every vertex is its own parent
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int total = 0;
    int count = 0;

    cout << "\nEdges in MST:\n";

    // Check edges one by one
    for (int i = 0; i < e && count < n - 1; i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        // Find parent of u
        int parentU = u;
        while (parent[parentU] != parentU) {
            parentU = parent[parentU];
        }

        // Find parent of v
        int parentV = v;
        while (parent[parentV] != parentV) {
            parentV = parent[parentV];
        }

        // If parents are different, no cycle is formed
        if (parentU != parentV) {

            cout << u << " - " << v << " = " << weight << endl;

            total = total + weight;
            count++;

            // Join the two vertices
            parent[parentU] = parentV;
        }
    }

    cout << "\nTotal cost = " << total << endl;

    return 0;
}
