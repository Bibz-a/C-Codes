#include <iostream>
#include <vector>
using namespace std;

class Graph {
    vector<vector<int>> mat;

public:
    Graph(int V) {
        mat.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        mat[u][v] = 1;
        mat[v][u] = 1;   // undirected
    }

    void deleteEdge(int u, int v) {
        mat[u][v] = 0;
        mat[v][u] = 0;
    }

    // ✅ Add vertex (very easy)
    void addVertex() {
        int V = mat.size();

        // add column
        for (auto &row : mat) {
            row.push_back(0);
        }

        // add row
        mat.push_back(vector<int>(V + 1, 0));
    }

    // ✅ Delete vertex
    void deleteVertex(int v) {
        // remove row
        mat.erase(mat.begin() + v);

        // remove column
        for (auto &row : mat) {
            row.erase(row.begin() + v);
        }
    }

    void print() {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.size(); j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};
