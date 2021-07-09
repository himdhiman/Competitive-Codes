#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int &index, int n){
    int left = 2*index;
    int right = 2*index+1;
    int current = v[index];
    int minIndex = index;

    if(left < n && v[left] < current){
        minIndex = left;
    }
    if(right < n && v[right] < v[minIndex]){
        minIndex = right;
    }
    swap(v[index], v[minIndex]);
    if(minIndex != index){
        heapify(v,minIndex,n);
    }
}

void createHeap(vector<int> &v){
    for(int i = v.size()/2; i > 0; i--){
        heapify(v, i, v.size());
    }

}

void HeapSort(vector<int> &v){
    for(int i = 1; i < v.size(); i++){
        int index = 1;
        swap(v[1], v[v.size()-i]);
        heapify(v, index, v.size()-i);
    }
}


int main() {
    vector<int> v = {-1, 5, 4, 3, 2, 1};
    createHeap(v);
    for(auto it = v.begin()+1; it != v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    HeapSort(v);
    for(auto it = v.begin()+1; it != v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
