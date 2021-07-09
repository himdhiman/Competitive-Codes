#include <iostream>
using namespace std;

void multiply(int *arr, int &pos, int num){

    int carry = 0;
    for(int i = 0; i < pos; i++){
        int product = arr[i] * num + carry;
        arr[i] = product % 10;
        carry = product / 10;
    }
    while(carry){
        arr[pos] = carry;
        carry = carry/10;
        pos++;
    }
}


void BigFactorial(int n){
    int *arr = new int[1000];

    for(int i = 0; i < 1000; i++){
        arr[i] = 0;
    }

    arr[0] = 1;
    int pos = 1;

    for(int i = 2; i <= n; i++){
        multiply(arr, pos, i);
    }

    for(int i = pos-1; i >= 0; i--){
        cout<<arr[i];
    }
    return ;
}

int main() {
    BigFactorial(100);
}
