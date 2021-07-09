#include <bits/stdc++.h>
using namespace std;

void GenerateBrackets(int n, vector<char> &output, vector<vector<char> > &result, int open, int close, int i){
    if(i == 2*n){
        result.push_back(output);
        return;
    }
    if(open < n){
        output.push_back('(');
        GenerateBrackets(n, output, result, open+1, close, i+1);
        output.pop_back();
    }
    if(close < open){
        output.push_back(')');
        GenerateBrackets(n, output, result, open, close+1, i+1);
        output.pop_back();
    }
    return;
}

int main() {
    int n = 2;
    vector<vector<char> > result;
    vector<char> output;
    GenerateBrackets(n, output, result, 0, 0, 0);
    for(auto x : result){
        for(auto y : x){
            cout<<y;
        }
        cout<<endl;
    }
    return 0;
}
