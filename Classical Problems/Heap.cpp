#include <bits/stdc++.h>
using namespace std;

class Heap{
    vector<int> v;

    void Heapify(int index){
        int left = 2*index;
        int right = 2*index+1;
        int current = v[index];
        int minIndex = index;

        if(left < v.size() && v[left] < current){
            minIndex = left;
        }
        if(right < v.size() && v[right] < v[minIndex]){
            minIndex = right;
        }
        swap(v[index], v[minIndex]);
        if(index != minIndex){
            Heapify(minIndex);
        }
        return;
    }

public:
    Heap(){
        v.push_back(-1);
    }

    int Size(){
        if(v.size() == 1){
            return 0;
        }
        return v.size()-1;
    }
    void AddElement(int data){
        v.push_back(data);
        int index = v.size()-1;
        while(index > 1 && v[index] < v[index/2]){
            swap(v[index], v[index/2]);
            index = index/2;
        }
        return;
    }
    int ExtractMin(){
        int min = v[1];
        v[1] = v[v.size()-1];
        v.pop_back();
        Heapify(1);
        return min;
    }

    void print(){
        for(int i = 1; i < v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

};

int main() {
    Heap h;
    h.AddElement(1);
    h.AddElement(8);
    h.AddElement(20);
    h.AddElement(11);
    h.AddElement(15);
    h.AddElement(13);
    h.AddElement(19);
    h.AddElement(10);
    h.print();
    cout<<h.ExtractMin()<<endl;
    h.print();
    cout<<h.ExtractMin()<<endl;
    h.print();cout<<h.ExtractMin()<<endl;
    h.print();
}
