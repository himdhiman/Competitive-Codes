#include <bits/stdc++.h>
using namespace std;

void GenerateSubsets(vector<int> input, vector<int> &output, vector<vector<int> > &result, int i){
    result.push_back(output);
    for(int j = i; j < input.size(); j++){
        output.push_back(input[j]);
        GenerateSubsets(input, output, result, j+1);
        output.pop_back();
    }
    return;
}

int main() {
    vector<int> input = {1, 2, 3};
    vector<vector<int> > result;
    vector<int> output;
    GenerateSubsets(input, output, result, 0);
    for(auto x : result){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
