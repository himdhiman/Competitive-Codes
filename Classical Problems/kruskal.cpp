#include <bits/stdc++.h>
using namespace std;

class DSU{
    int * parent;
    int * rank;
public:
    DSU(int v){
        parent = new int[v];
        rank = new int[v];

        for(int i = 0; i < v; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] == -1){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
        return;
    }
};

class Graph{
    int v;
    vector<vector<int> > edgeList;
public:
    Graph(int v){
        this->v = v;
    }
    void AddEdge(int x, int y, int w){
        edgeList.push_back({w, x, y});
    }
    int Kruskals(){
        sort(edgeList.begin(), edgeList.end());
        DSU d(v);

        int ans = 0;
        for(auto i : edgeList){
            int x = i[1];
            int y = i[2];
            int w = i[0];

            int s1 = d.find(x);
            int s2 = d.find(y);
            if(s1 != s2){
                d.unite(s1, s2);
                ans += w;
            }
        }
        return ans;
    }
};

int main() {
    Graph g(4);
    g.AddEdge(0, 1, 1);
    g.AddEdge(1, 3, 3);
    g.AddEdge(2, 3, 4);
    g.AddEdge(2, 0, 2);
    g.AddEdge(0, 3, 2);
    g.AddEdge(1, 2, 2);

    cout<<g.Kruskals();



}
