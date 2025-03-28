#include <queue>
#include <set>

#include "graph.h"

Graph::Graph(int nVert) : adj(nVert) {
    if (nVert < 0) throw std::runtime_error("Numero invalido!");
}

int Graph::size() {
    return (int)adj.size();
}

// Cria��o da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
	if (src < 0 || src >= adj.size() || dst < 0 || dst >= adj.size())
		throw std::runtime_error("Vértice inválido!");

	adj[src].emplace_back(src, dst, w);
}

int Graph::degree(int vtx) {
	if (vtx < 0 || vtx >= adj.size())
		throw std::runtime_error("Vértice inválido!");

	return (int)adj[vtx].size();
}

list<int> Graph::neighbors(int vtx) {
	if (vtx < 0 || vtx >= adj.size())
		throw std::runtime_error("Vértice inválido!");

	list<int> result;
	for (const Edge &edge : adj[vtx]) {
		result.push_back(edge.dst);
	}
	return result;
}

int Graph::weight(int src, int dst) {
	if (src < 0 || src >= nVert || dst < 0 || dst >= nVert) {
		throw std::out_of_range("Vértice inválido!");
	}

	for (const auto& edge : adj[src]) {
		if (edge.dst == dst) {
			return edge.weight; // Retorna o peso da aresta
		}
	}

	throw std::invalid_argument("Aresta não existe entre os vértices fornecidos.");
}


void Graph::print() {
	for (int i = 0; i < this->size(); i++) {
		int d = this->degree(i);

		cout << i << "(" << d << "): ";

		list<int> nei = this->neighbors(i);
		for (int dst : nei) {
			int w = this->weight(i, dst);
			cout << dst << "[" << w << "]; ";
		}

		cout << endl;
	}
}

bool Graph::isConnected() {
	if (adj.empty()) return true;

	vector<int> group(adj.size());
	for (int i = 0; i < adj.size(); i++) {
		group[i] = i;
	}

	for (int src = 0; src < adj.size(); src++) {
		for (const Edge &edge : adj[src]) {
			int dst = edge.dst;
			int srcGroup = group[src];
			int dstGroup = group[dst];

			if (srcGroup != dstGroup) {
				for (int &g : group) {
					if (g == dstGroup) {
						g = srcGroup;
					}
				}
			}
		}
	}

	int firstGroup = group[0];
	for (int g : group) {
		if (g != firstGroup) {
			return false;
		}
	}
	return true;
}


// -------- PRAT 10 --------------//

// Busca em profundidade
list<int> Graph::dfs(int src) {
    if (src < 0 || src >= this->size())
        throw std::runtime_error("Src inv�lido");

	list<int> result;
	vector<bool> visited(adj.size(), false);

	DFS(src, visited, result);

	return result;
}

// Busca em profundidade
void Graph::DFS(int src, vector<bool> &visited, list<int> &result) {
	visited[src] = true; // Marca o vértice como visitado
	result.push_back(src); // Adiciona o nó à lista de resultados

	// Percorre todos os vizinhos do nó atual
	for (const Edge &edge : adj[src]) {
		if (!visited[edge.dst]) { // Se o nó ainda não foi visitado, faz chamada recursiva
			DFS(edge.dst, visited, result);
		}
	}
}

// Busca em largura
list<int> Graph::bfs(int src) {
    if (src < 0 || src >= this->size())
        throw std::runtime_error("Src inv�lido");

    list<int> result;
    vector<bool> visited(adj.size(), false);

    BFS(src, visited, result);

    return result;
}

// Busca em largura
void Graph::BFS(int src, vector<bool> &visited, list<int> &result) {
	queue<int> q; // Fila para auxiliar na busca em largura
	visited[src] = true; // Marca o vértice de início como visitado
	q.push(src); // Coloca o vértice inicial na fila

	while (!q.empty()) {
		int current = q.front(); // Obtém o vértice da frente da fila
		q.pop(); // Remove o vértice da fila
		result.push_back(current); // Adiciona o vértice à lista de resultados

		// Percorre todos os vizinhos do vértice atual
		for (const Edge &edge : adj[current]) {
			if (!visited[edge.dst]) { // Se o vizinho ainda não foi visitado
				visited[edge.dst] = true; // Marca como visitado
				q.push(edge.dst); // Coloca o vizinho na fila
			}
		}
	}
}

list<int> Graph::spf(int src, int dst) {
    if (src < 0 || src >= this->size())
        throw std::runtime_error("Src inv�lido");

    if (dst < 0 || dst >= this->size())
        throw std::runtime_error("Dst inv�lido");

    vector<int> prev(adj.size(), -1);     // v�rtices anteriores
    vector<long> dist(adj.size(), 99999);     // dist�ncias acumuladas; 99999 = INF

    dijkstra(src, prev, dist);

    list<int> result;                         // retorno menor caminho

    path(dst, prev, result);		      // extrair caminho em result

    return result;
}


void Graph::dijkstra(int src, vector<int> &prev, vector<long> &dist) {
    set<pair<int, long>> pq; // Usando set para simular PQ c/ opera��es O(logN).

    dist[src] = 0;
    pq.emplace(src, dist[src]);

    while (!pq.empty()) {
        int curr = pq.begin()->first;
        long d_acc = pq.begin()->second;
        pq.erase(pq.begin());

        for ( auto & [_src, dst, d] : adj[curr]) {
            if (dist[dst] > (d_acc + d)) {
                pq.erase(make_pair(dst, dist[dst]));
                dist[dst] = d_acc + d;
                prev[dst] = curr;
                pq.emplace(dst, dist[dst]);
            }
        }
    }
}

void Graph::path(int dst, const vector<int> &prev, list<int> &result) {
	if (dst == -1) {
		return;
	}

	// Reconstrução do caminho na ordem inversa
	int current = dst;
	while (current != -1) {
		result.push_front(current); // Coloca o nó no início da lista para inverter a ordem
		current = prev[current]; // Segue o caminho para o nó anterior
	}
}

