#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
private:
	// Aresta
	struct Edge {
		int src;		// Origem  da aresta
		int dst;		// Destino da aresta (n� vizinho)
		int weight;		// Peso da aresta
		Edge(int src, int dst, int weight) : src(src), dst(dst), weight(weight) {}
	};

	vector<int> group;
    int nVert;			// N�mero de v�rtices
	vector<list<Edge>> adj;	// Array de listas de adjac�ncia (list da STL)

public:
	explicit Graph(int nVert);
	~Graph() = default;

	int size();	// retorna n�mero de v�rtices

	// Pr�tica 09 - TODO
	void edge(int src, int dst, int w);	// Cria src -> dst com peso w
	int degree(int vtx); // retorna grau de um v�rtice
        list<int> neighbors(int vtx);	// retorna lista de vertices ligados a src
        int weight(int src, int dst);	// retorna peso da aresta de src para dst
	bool isConnected();

	// Pr�tica 10 - TODO (abaixo)
	list<int> dfs(int src); // Busca em profundidade
	list<int> bfs(int src); // Busca em largura
	list<int> spf(int src, int dst); // Menor caminho entre src e dst

	void print(); // Exibe o grafo

private:
	int findGroup(int v);
	void unionGroups(int v1, int v2);

	// Pr�tica 11 - TODO
	void DFS(int src, vector<bool> &visited, list<int> &result); // DFS de fato
	void BFS(int src, vector<bool> &visited, list<int> &result); // BFS de fato

        // Pr�tica 11 - TODO
        void dijkstra(int src, vector<int> &prev, vector<long> &dist);  // acha os menores caminhos
        void path(int src, const vector<int> &prev, list<int> &result); // extrai menor caminho de prev
};




