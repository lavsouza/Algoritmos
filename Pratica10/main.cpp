
#include <iostream>
#include "graph.cpp"

using namespace std;

ostream & operator <<(ostream &out, const list<int> &l) {
	for (int i : l) out << i << " ";
	return out;
}

int main() {

	Graph graph1(6);		// Connected
	graph1.edge(0, 1, 4);
	graph1.edge(0, 2, 2);
	graph1.edge(1, 2, 5);
	graph1.edge(1, 3, 10);
	graph1.edge(2, 4, 3);
	graph1.edge(4, 3, 4);
	graph1.edge(3, 5, 11);

	Graph graph2(9);		// Connected
	graph2.edge(0, 1, 4);
	graph2.edge(0, 7, 8);
	graph2.edge(1, 2, 8);
	graph2.edge(1, 7, 11);
	graph2.edge(2, 3, 7);
	graph2.edge(2, 5, 4);
	graph2.edge(2, 8, 2);
	graph2.edge(3, 4, 9);
	graph2.edge(3, 5, 14);
	graph2.edge(4, 5, 10);
	graph2.edge(5, 6, 2);
	graph2.edge(6, 7, 1);
	graph2.edge(6, 8, 6);
	graph2.edge(7, 8, 7);

	Graph graph3(6);		// Not connected
	graph3.edge(0, 1, 12);
	graph3.edge(0, 2, 2);
	graph3.edge(3, 4, 1);
	graph3.edge(4, 5, 10);

	// Pr�tica 19
	cout << "Graph1 is connected? " << (graph1.isConnected()?"YES":"NO") << endl; // YES
	graph1.print();
	cout << endl;

	cout << "Graph2 is connected? " << (graph2.isConnected()?"YES":"NO") << endl; // YES
	graph2.print();
	cout << endl;

	cout << "Graph3 is connected? " << (graph3.isConnected()?"YES":"NO") << endl; // NO
	graph3.print();
	cout << endl;

	// Pr�tica 11

	cout << endl;

	cout << "Graph1: " << endl;
	cout << "DFS: " << graph1.dfs(0) << endl; // 0 1 2 4 3 5
	cout << "BFS: " << graph1.bfs(0) << endl; // 0 1 2 3 4 5
	cout << "SPF: " << graph1.spf(0, 5) << endl; // 0 2 4 3 5

	cout << "Graph2: " << endl;
	cout << "DFS: " << graph2.dfs(0) << endl; // 0 1 2 3 4 5 6 7 8
	cout << "BFS: " << graph2.bfs(0) << endl; // 0 1 7 2 8 3 5 4 6
	cout << "SPF: " << graph2.spf(0, 5) << endl; // 0 1 2 5

	cout << "Graph3: " << endl;
	cout << "DFS: " << graph3.dfs(0) << endl; // 0 1 2
	cout << "BFS: " << graph3.bfs(0) << endl; // 0 1 2
	cout << "SPF: " << graph3.spf(0, 5) << endl; // 5 ou vazio
}


