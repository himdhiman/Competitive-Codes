#include <bits/stdc++.h>
using namespace std;

int Helper(vector<int> input, int value){
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < input.size(); i++){
        if(sum + input[i] <= value){
            sum += input[i];
        }
        else{
            sum = 0;
            sum += input[i];
            cnt++;
        }
    }
    cnt++;
    return cnt;
}

int BookAllocation(vector<int> input, int m){
    int start = input[input.size()-1], end = 0, ans = -1;
    for(int i = 0; i < input.size(); i++){
        end+=input[i];
    }
    while(start <= end){
        int mid = (start+end)/2;
        if(Helper(input, mid) > m){
            start = mid+1;
        }
        else if(Helper(input, mid) <= m){
            end = mid - 1;
            ans = mid;
        }
    }
    return ans;
}



int main() {
    vector<int> input = {10, 20, 30, 40};
    int m = 2;
    cout<<BookAllocation(input, m);
    return 0;
}
