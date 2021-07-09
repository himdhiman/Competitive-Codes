#include <bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int, list<int> > m;

public:

    void AddEdge(int u, int v){
        m[u].push_back(v);
        // m[v].push_back(u);
        return; 
    }

    void Print(){
        for(auto x : m){
            cout<<x.first<<" --> ";
            for(auto y : x.second){
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }
    bool Helper(int source, unordered_map<int, bool> &visited, int parent){
        visited[source] = true;
        for(auto x : m[source]){
            if(visited[x] == false){
                bool isCycle = Helper(x, visited, source);
                if(isCycle){
                    return true;
                }
            }else if(x != parent){
                return true;
            }
        }
        return false;
    }

    bool DetectCycle(int source){
        unordered_map<int, bool> visited;
        for(auto x : m){
            visited[x.first] = false;
        }
        return Helper(source, visited, -1);
    }
};

int main() {
    Graph g;
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);
    g.AddEdge(4, 5);
    g.AddEdge(5, 3);
    g.Print();
    cout<<g.DetectCycle(1);
}
