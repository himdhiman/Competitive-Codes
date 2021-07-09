#include <bits/stdc++.h>
using namespace std;




int main() {
    string s = "12543";
    int i = s.length()-1;
    while(s[i] < s[i-1]){
        i--;
    }
    int pos = i-1;
    int min = 100;
    int temp = pos;
    for(int j = temp+1; j < s.length(); j++){
        if(s[j]-s[pos] < min){
            min = s[j]-s[pos];
            temp = j;
        }
    }
    swap(s[temp], s[pos]);
    reverse(s.begin()+pos+1, s.end());
    cout<<s;
}
