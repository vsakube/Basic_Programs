#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <set>
#include <random>
#include <fstream>


using namespace std;

typedef char V;
typedef int W;

unordered_map<V, vector<pair<V, W>>> adj_list;

void printGraph() {

       for (const auto& vertex : adj_list) {
           cout << "Adjacency list of vertex " << vertex.first << ": ";
           for (const auto& neighbor : vertex.second) {
               auto dest = neighbor.first;
               auto weight = neighbor.second;
               cout << dest << " (" << weight << ") ";
           }
           cout << endl;
       }
}

int dj(){

	return 0;
}

void drawGraph(const string& filename) {
        ofstream file(filename);

        if (!file.is_open()) {
            cout << "Failed to open file." << endl;
            return;
        }

        file << "graph {" << endl;

        // Iterate over vertices and their neighbors
        for (const auto& vertex : adj_list) {
            auto source = vertex.first;

            // Iterate over neighbors of each vertex
            for (const auto& neighbor : vertex.second) {
                auto destination = neighbor.first;
                int weight = neighbor.second;

                // Add an edge to the DOT file
                file << "  " << source << " -- " << destination;
                file << "  " << weight <<  endl;
            }
        }

        file << "}" << endl;
        file.close();

        cout << "Graph visualization created: " << filename << endl;
}

void dfs(int source, int destination, set<vector<V>>& paths, vector<V>& current_path) {

        current_path.push_back(source);
        vector<bool> visited(adj_list.size(), false);
	visited[source] = true;

        if (source == destination) {
            paths.insert(current_path);
        }
        else {
		for (const auto& neighbor : adj_list[source]) {
			int next_vertex = neighbor.first;
			if (!visited[next_vertex]){
				dfs(next_vertex, destination, paths, current_path);
			}
			visited[source] = false;
			current_path.pop_back();
		}
	}
}

    // Find all possible paths between any two nodes
set<vector<V>> findAllPaths(V source, V destination){
	set<vector<V>> paths;
        vector<V> current_path;
        vector<bool> visited(adj_list.size(), false);
        dfs(source, destination, paths, current_path);
	for(auto p:paths){
		for(auto c:p) cout << c << "  " ;
		cout << endl;
	}
	cout << endl;
	return paths;
}


void create_graph(){

	adj_list['A']={{'B',5},{'C',3}, {'D',6}, {'F',10}};
	adj_list['B']={{'E',4},{'C',7}};
	adj_list['E']={{'D',9},{'C',7}};
	adj_list['F']={{'E',9},{'H',7}};
}

int main(){

	create_graph();
	printGraph();

        // drawGraph("graph.dot");
//	findAllPaths('A', 'E');
        vector<vector<vector<int>>> memo(adj_list.size(), vector<vector<int>>(adj_list.size()));
	set<vector<V>> paths = findAllPaths('A', 'E');
	return 0;
}

