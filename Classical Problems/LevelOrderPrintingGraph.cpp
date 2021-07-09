#include <bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<int, list<int> > m;

public:
    void addEdge(int u, int v){
        //directed graph
        m[u].push_back(v);
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
        return;
    }

    void TS(){
        unordered_map<int, int> indegree;
        set<pair<int, int> > out;
        for(auto x : m){
            for(auto y : x.second){
                indegree[y]++;
            }
        }
        for(auto x : m){
            if(indegree.find(x.first) == indegree.end()){
                indegree.insert(make_pair(x.first, 0));
            }
        }
        queue<int> q1;
        queue<int> q2;
        for(auto x : indegree){
            if(x.second == 0){
                q1.push(x.first);
            }
        }
        int cnt = 1;
        while(!q1.empty() || !q2.empty()){
            while(!q1.empty()){
                int curr = q1.front();
                q1.pop();
                cout<<curr<<" ";
                out.insert(make_pair(curr,cnt));
                for(auto x : m[curr]){
                    indegree[x]--;
                    if(indegree[x] == 0){
                        q2.push(x);
                    }
                }
            }
            cnt++;
            cout<<endl;
            while(!q2.empty()){
                int curr = q2.front();
                q2.pop();
                cout<<curr<<" ";
                out.insert(make_pair(curr,cnt));
                for(auto x : m[curr]){
                    indegree[x]--;
                    if(indegree[x] == 0){
                        q1.push(x);
                    }
                }
            }
            cnt++;
            cout<<endl;
        }
        cout<<endl;
        for(auto x : out){
            cout<<x.second<<" ";
        }
        return;
    }
};

int main() {
    Graph g;
    g.addEdge(1, 3); 
    g.addEdge(1, 4); 
    g.addEdge(1, 5); 
    g.addEdge(2, 3); 
    g.addEdge(2, 8); 
    g.addEdge(2, 9); 
    g.addEdge(3, 6); 
    g.addEdge(4, 6); 
    g.addEdge(4, 8); 
    g.addEdge(5, 8); 
    g.addEdge(6, 7); 
    g.addEdge(7, 8); 
    g.addEdge(8, 10);
    g.Print();
    g.TS();
}
