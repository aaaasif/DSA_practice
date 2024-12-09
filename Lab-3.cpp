#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E; // V = number of vertices, E = number of edges
    vector<Edge> edges;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find the parent (with path compression)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform the union of two subsets
void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparison function to sort edges based on weight
bool compareEdges(Edge a, Edge b) {
    if (a.weight == b.weight) {
        if (a.src == b.src)
            return a.dest < b.dest;
        return a.src < b.src;
    }
    return a.weight < b.weight;
}

// Function to find MST using Kruskal's algorithm
void KruskalMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result; // To store the resultant MST
    int e = 0; // Number of edges in the MST

    // Step 1: Sort all edges in non-decreasing order of weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    // Allocate memory for subsets
    Subset* subsets = new Subset[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 2: Pick the smallest edge and check if it forms a cycle
    for (Edge& edge : graph.edges) {
        if (e == V - 1) break; // MST will have V-1 edges

        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        // If including this edge does not form a cycle
        if (x != y) {
            result.push_back(edge);
            Union(subsets, x, y);
            e++;
        }
    }

    // Print the resulting MST
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    int totalWeight = 0;
    for (auto& edge : result) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    delete[] subsets;
}

int main() {
    // Create the graph given in the problem
    Graph graph;
    graph.V = 6; // Number of vertices
    graph.E = 9; // Number of edges

    // Add edges (src, dest, weight)
    graph.edges = {
        {1, 4, 1}, {4, 5, 1}, {1, 3, 2}, {0, 1, 3},
        {2, 5, 3}, {3, 4, 4}, {0, 3, 5}, {1, 2, 9}
    };

    // Find the MST using Kruskal's algorithm
    KruskalMST(graph);

    return 0;
}