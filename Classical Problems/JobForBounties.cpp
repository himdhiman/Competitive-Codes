#include <bits/stdc++.h>
using namespace std;

int JobForBounties(string s){
    int n = s.length();
    vector<int> output;
    int maximum = 0;
    output.push_back(0);
    for(int i = 1; i < n; i++){
        if(s[i] == '('){
            output.push_back(0);
        }else{
            if(s[i-1] == '('){
                if(i-2 >= 0){
                    output.push_back(output[i-2] + 2);
                }else{
                    output.push_back(2);
                }
                maximum = max(maximum, output[output.size()-1]);
            }
            if(s[i-1] == ')' && s[i - output[i-1] - 1] == '('){
                if(i-output[i-1]-1 >= 0){
                    output.push_back(output[i-1]+2 + output[i - output[i-1] - 2]);
                }else{
                    output.push_back(0);
                }
                maximum = max(maximum, output[output.size()-1]);
            }
        }
    }
    return maximum;
}

int main() {
    string s;
    getline(cin, s);
    cout<<JobForBounties(s);
}
