#include <bits/stdc++.h>
using namespace std;

int Merge(vector<int> &v, int start1, int start2, int end){
    int s1 = start1, e1 = start2-1, s2 = start2, e2 = end;
    int cnt = 0;
    int temp[100];
    int k = 0;
    while(s1 <= e1 && s2 <= e2){
        if(v[s1] > v[s2]){
            temp[k++] = v[s2++];
            cnt += (start2-s1);
        }else{
            temp[k++] = v[s1++];
        }
    }
    while(s1 <= e1){
        temp[k++] = v[s1++];
    }
    while(s2 <= e2){
        temp[k++] = v[s2++];
    }
    k = 0;
    for(int i = 0; i <= end; i++){
        v[i] = temp[k++];
    }
    return cnt;
}

int MergeSort(vector<int> v, int start, int end){
    if(start >= end){
        return 0;
    }
    int mid = (start + end)/2;
    int inv_cnt = 0;
    inv_cnt += MergeSort(v, start, mid);
    inv_cnt += MergeSort(v, mid+1, end);
    inv_cnt += Merge(v, start, mid+1, end);
    return inv_cnt;
}



int main() {
    vector<int> v = {1, 2, 4, 3};
    cout<<MergeSort(v, 0, v.size()-1);
}
