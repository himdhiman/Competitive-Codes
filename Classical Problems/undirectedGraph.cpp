#include <bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int, list<int> >AdjList;
public:
    void AddEdge(int u, int v, bool bidir = true){
        AdjList[u].push_back(v);
        if(bidir){
            AdjList[v].push_back(u);
        }
    }

    void Print(){
        for(auto x : AdjList){
            cout<<x.first<< " --> ";
            for(auto y : x.second){
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(int source){
        unordered_map<int, bool> visited;
        for(auto x : AdjList){
            visited[x.first] = false;
        }
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";
            for(auto x : AdjList[curr]){
                if(visited[x] == false){
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
        cout<<endl;

    }

    void DFS_Helper(int source, unordered_map<int, bool> &visited){
        visited[source] = true;
        cout<<source<<" ";
        for(auto x : AdjList[source]){
            if(visited[x] == false){
                DFS_Helper(x, visited);
            }
        }
    }

    void DFS(int source){
        unordered_map<int, bool> visited;
        DFS_Helper(source, visited);
        cout<<endl;
    }

    void SSSP(int source){
        unordered_map<int, int> distance;
        for(auto x : AdjList){
            distance[x.first] = INT_MAX;
        }
        queue<int> q;
        distance[source] = 0;
        q.push(source);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto x : AdjList[curr]){
                if(distance[x] == INT_MAX){
                    q.push(x);
                    distance[x] = distance[curr]+1;
                }
            }
        }
        for(auto x : distance){
            cout<<source<<" --> "<<x.first<<" -------- "<<x.second<<endl;
        }

    }
};

int main() {
    Graph g;
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);
    g.AddEdge(4, 1);
    g.AddEdge(4, 5);
    g.Print();
    g.BFS(1);
    g.DFS(1);
    g.SSSP(1);
}
