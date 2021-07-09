#include <bits/stdc++.h>
using namespace std;


bool Comp(string a, string b){
    string ab = a.append(b);
    string ba = b.append(a);
    if(ab.compare(ba) > 0){
        return 1;
    }else{
        return 0;
    }
}

string BigestNumber(vector<string> input){
    string ans = "";
    sort(input.begin(), input.end(), Comp);
    for(int i = 0; i < input.size(); i++){
        ans+=input[i];
    }
    return ans;
}


int main() {
    // int n, temp;
    // cin>>n;
    // vector<int> input;
    // for(int i = 0; i < n; i++){
    //     cin>>temp;
    //     input.push_back(temp);
    // }
    vector<string> input = {"54", "546", "548", "60"};
    cout<<BigestNumber(input);
}
