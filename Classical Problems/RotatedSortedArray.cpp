#include <bits/stdc++.h>
using namespace std;

int getIndex(vector<int> v, int start, int end, int n){
    if(start >= end){
        return 0;
    }
    int mid = (end-start)/2 + start;
    int prev = (mid-1)%n;
    int next = (mid+1)%n;
    if(v[mid] < v[next] && v[mid] < v[prev]){
        return mid;
    }
    if(v[start] < v[mid]){
        return getIndex(v, mid+1, end, n);
    }
    if(v[mid] < v[end]){
        return getIndex(v, start, mid-1, n);
    }
    return -1;
}

int main() {
    vector<int> v = {5, 6, 7, 0, 1, 2, 3, 4};
    int n = v.size();
    cout<<getIndex(v, 0, n-1, n);
}
