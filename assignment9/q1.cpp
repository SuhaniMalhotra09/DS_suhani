#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;   
    vector<tuple<int,int,int>> edges;    // for Kruskal

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w, bool undirected = true) {
        adj[u].push_back({v, w});
        if (undirected) {
            adj[v].push_back({u, w});
        }
        edges.push_back({w, u, v});
    }

    
    // BFS
    
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while(!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";

            for(auto &nbr : adj[node]) {
                int v = nbr.first;
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    
    // DFS 
   
    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for(auto &nbr : adj[node]) {
            int v = nbr.first;
            if(!visited[v])
                DFSUtil(v, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    
    // Kruskal's MST
    
    int findSet(int v, vector<int> &parent) {
        if(v == parent[v]) return v;
        return parent[v] = findSet(parent[v], parent);
    }

    void unionSet(int a, int b, vector<int> &parent, vector<int> &rank) {
        a = findSet(a, parent);
        b = findSet(b, parent);

        if(a != b) {
            if(rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
        }
    }

    void KruskalMST() {
        sort(edges.begin(), edges.end()); 

        vector<int> parent(V), rank(V, 0);
        for(int i=0; i<V; i++) parent[i] = i;

        int mst_cost = 0;
        cout << "Kruskal MST edges:\n";

        for(auto &[w, u, v] : edges) {
            if(findSet(u, parent) != findSet(v, parent)) {
                cout << u << " - " << v << "  (weight " << w << ")\n";
                mst_cost += w;
                unionSet(u, v, parent, rank);
            }
        }

        cout << "Total MST Cost (Kruskal): " << mst_cost << endl;
    }

    
    // Prim's MST
    
    void PrimMST(int start) {
        vector<int> key(V, 1e9);
        vector<bool> inMST(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        key[start] = 0;
        pq.push({0, start});

        int mst_cost = 0;

        cout << "Prim MST edges:\n";

        while(!pq.empty()) {
            auto [weight, u] = pq.top(); pq.pop();

            if(inMST[u]) continue;
            inMST[u] = true;
            mst_cost += weight;

            cout << "Include node: " << u << " with cost " << weight << endl;

            for(auto &nbr : adj[u]) {
                int v = nbr.first;
                int w = nbr.second;

                if(!inMST[v] && w < key[v]) {
                    key[v] = w;
                    pq.push({w, v});
                }
            }
        }

        cout << "Total MST Cost (Prim): " << mst_cost << endl;
    }

    
    // Dijkstra's Shortest Path
    
    void Dijkstra(int start) {
        vector<int> dist(V, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            for(auto &nbr : adj[u]) {
                int v = nbr.first;
                int w = nbr.second;

                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra (shortest distances from " << start << "):\n";
        for(int i=0;i<V;i++) {
            cout << "Node " << i << " -> " << dist[i] << endl;
        }
    }
};
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v w):\n";
    for(int i=0;i<E;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w, true);  
    }

    cout << "\n----- MENU -----\n";
    cout << "1. BFS\n2. DFS\n3. Kruskal MST\n4. Prim MST\n5. Dijkstra\n";
    cout << "Enter choice: ";
    int ch; cin >> ch;

    int start;
    if(ch == 1 || ch == 2 || ch == 4 || ch == 5) {
        cout << "Enter starting vertex: ";
        cin >> start;
    }

    switch(ch) {
        case 1: g.BFS(start); break;
        case 2: g.DFS(start); break;
        case 3: g.KruskalMST(); break;
        case 4: g.PrimMST(start); break;
        case 5: g.Dijkstra(start); break;
        default: cout << "Invalid choice!"; 
    }

    return 0;
}
