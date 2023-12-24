#include <algorithm>
#include <iostream>
#include <vector>

#define WeightedEdge std::pair<int, int>

class Graph 
{
public:
    Graph(int vertices)
    {
        parent = new int[vertices];
        for (int i = 0; i < vertices; i++)
        {
            parent[i] = i;
        }

        InitialGraph.clear();
        MST.clear();
    }
    
    void AddEdge(int edge, int vertex, int weight)
    {
        InitialGraph.push_back(make_pair(weight, WeightedEdge(edge, vertex)));
    }

    int find_set(int i) { return (i == parent[i] ? i : find_set(parent[i])); };
    void union_set(int edge, int vertex) { parent[edge] = parent[vertex]; };
    
    void Kruskal();
    void PrintMST();

private:
    std::vector<std::pair<int, WeightedEdge> > InitialGraph;
    std::vector<std::pair<int, WeightedEdge> > MST;
    
    int* parent;
    int vertices;
};

void 
Graph::Kruskal() 
{
    int edgeRepeat = 0; 
    int vertexRepeat = 0;
    
    sort(InitialGraph.begin(), InitialGraph.end());

    for (auto i = 0; i < InitialGraph.size(); i++) 
    {
        edgeRepeat = find_set(InitialGraph[i].second.first);
        vertexRepeat = find_set(InitialGraph[i].second.second);
        if (edgeRepeat != vertexRepeat)
        {
            MST.push_back(InitialGraph[i]);
            union_set(edgeRepeat, vertexRepeat);
        }
    }
}

void 
Graph::PrintMST() 
{
    int MSTWeight = 0;
    for (auto i = 0; i < MST.size(); i++) 
    {
        std::cout << "Edge : "     << MST[i].second.first 
                  << " - "         << MST[i].second.second 
                  << " --> "       << " Weight: "
                  << MST[i].first  << "\n";

        MSTWeight += MST[i].first;
    }

    std::cout << "\nWeight of the Minimum Spanning Tree: " << MSTWeight << "\n";
}

int main() 
{
    Graph MyGraph(9);

    MyGraph.AddEdge(0, 4, 3);
    MyGraph.AddEdge(0, 6, 9);
    MyGraph.AddEdge(0, 1, 4);
    MyGraph.AddEdge(1, 0, 4);
    MyGraph.AddEdge(1, 5, 10);
    MyGraph.AddEdge(1, 2, 7);
    MyGraph.AddEdge(2, 1, 7);
    MyGraph.AddEdge(2, 3, 1);
    MyGraph.AddEdge(3, 2, 1);
    MyGraph.AddEdge(3, 4, 4);
    MyGraph.AddEdge(3, 6, 6);
    MyGraph.AddEdge(4, 0, 3);
    MyGraph.AddEdge(4, 3, 4);
    MyGraph.AddEdge(4, 7, 5);
    MyGraph.AddEdge(4, 8, 8);
    MyGraph.AddEdge(4, 5, 2);
    MyGraph.AddEdge(5, 4, 2);
    MyGraph.AddEdge(5, 1, 10);
    MyGraph.AddEdge(5, 6, 5);
    MyGraph.AddEdge(5, 8, 7);
    MyGraph.AddEdge(6, 3, 6);
    MyGraph.AddEdge(6, 0, 9);
    MyGraph.AddEdge(6, 5, 5);
    MyGraph.AddEdge(6, 7, 9);
    MyGraph.AddEdge(6, 8, 9);
    MyGraph.AddEdge(7, 4, 5);
    MyGraph.AddEdge(7, 6, 9);
    MyGraph.AddEdge(7, 8, 4);
    MyGraph.AddEdge(8, 7, 4);
    MyGraph.AddEdge(8, 4, 8);
    MyGraph.AddEdge(8, 5, 7);
    MyGraph.AddEdge(8, 6, 9);

    MyGraph.Kruskal();
    MyGraph.PrintMST();

    return 0;
}