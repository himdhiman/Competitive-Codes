#include <bits/stdc++.h>
using namespace std;

vector<int> Partners(vector<int> v){
    stack<pair<int, int> > x, y;
    vector<int> vx, vy;
    int n = v.size();
    for(int i = 0; i < n; i++){
        if(x.empty()){
            vx.push_back(-1);
            x.push(make_pair(v[i], i+1));
        }else{
            pair<int, int> curr = x.top();
            if(curr.first >= v[i]){
                vx.push_back(curr.second);
                x.push(make_pair(v[i], i+1));
            }else{
                while(true && !x.empty()){
                    pair<int, int> curr = x.top();
                    if(curr.first < v[i]){
                        x.pop();
                    }else{
                        break;
                    }
                }
                if(x.empty()){
                    vx.push_back(-1);
                    x.push(make_pair(v[i], i+1));
                }else{
                    pair<int, int> curr = x.top();
                    if(curr.first >= v[i]){
                        vx.push_back(curr.second);
                        x.push(make_pair(v[i], i+1));
                    }
                }

            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(y.empty()){
            vy.push_back(-1);
            y.push(make_pair(v[i], i+1));
        }else{
            pair<int, int> curr = y.top();
            if(curr.first >= v[i]){
                vy.push_back(curr.second);
                y.push(make_pair(v[i], i+1));
            }else{
                while(true && !y.empty()){
                    pair<int, int> curr = y.top();
                    if(curr.first < v[i]){
                        y.pop();
                    }else{
                        break;
                    }
                }
                if(y.empty()){
                    vy.push_back(-1);
                    y.push(make_pair(v[i], i+1));
                }else{
                    pair<int, int> curr = y.top();
                    if(curr.first >= v[i]){
                        vy.push_back(curr.second);
                        y.push(make_pair(v[i], i+1));
                    }
                }

            }
        }
    }
    reverse(vy.begin(), vy.end());
    vector<int> result;

    for(int i = 0; i < n; i++){
        result.push_back(vx[i]+vy[i]);
    }
    result.resize(n);
    return result;
}

int main() {
    int n, val;
    cin>>n;
    vector<int> input;
    for(int i = 0; i < n; i++){
        cin>>val;
        input.push_back(val);
    }
    input.resize(n);
    vector<int> result = Partners(input);
    for(auto x : result){
        cout<<x<<" ";
    }
    return 0;
}
