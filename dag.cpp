#include <iostream>
#include <list>
#include <vector>
#include <queue>

class Graph
{
public:
	Graph(int vertices)
	{
		this->vertices = vertices;
		adjacent_list = new std::list<int>[vertices];
	}

	void edge(int ed, int vertex);
	void topologicalSort();

private:
	int vertices;
	std::list<int>* adjacent_list;
};

void
Graph::edge(int ed, int vertex)
{
	adjacent_list[ed].push_back(vertex);
}

void
Graph::topologicalSort()
{
	std::vector<int> in_degree(vertices, 0);

	for (int ed = 0; ed < vertices; ed++)
	{
		for (auto itr = adjacent_list[ed].begin(); itr != adjacent_list[ed].end(); itr++)
		{
			in_degree[*itr]++;
		}
	}

	std::queue<int> q;
	for (int ed = 0; ed < vertices; ed++)
	{
		if (in_degree[ed] == 0)
		{
			q.push(ed);
		}
	}

	int cnt = 0;
	std::vector<int> topological_order;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		topological_order.push_back(u);

		for (auto itr = adjacent_list[u].begin(); itr != adjacent_list[u].end(); itr++)
		{
			if (--in_degree[*itr] == 0)
			{
				q.push(*itr);
			}
		}

		cnt++;
	}

	if (cnt != vertices)
	{
		std::cout << "Graph is not acyclic\n";
		return;
	}

	for (int i = 0; i < topological_order.size(); i++)
	{
		std::cout << topological_order[i] << " ";
	}

	std::cout << "\n";
}

int main()
{
	Graph myGraph(9);

	myGraph.edge(2, 1);
	myGraph.edge(2, 0);
	myGraph.edge(2, 7);
	myGraph.edge(3, 0);
	myGraph.edge(3, 8);
	myGraph.edge(1, 4);
	myGraph.edge(1, 0);
	myGraph.edge(1, 5);
	myGraph.edge(7, 6);
	myGraph.edge(4, 8);
	myGraph.edge(0, 8);
	myGraph.edge(6, 5);
	myGraph.edge(5, 8);

	std::cout << "Topological sort of DAG\n";
	myGraph.topologicalSort();

	return 0;
}
