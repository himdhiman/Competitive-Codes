#include<bits/stdc++.h>
using namespace std;

vector<vector<long long int> > multiply(vector<vector<long long int> > A, vector<vector<long long int> > B){
    vector<vector<long long int> >C(A.size(), vector<long long int>(A.size()));
    for(long long int i = 0; i < A.size(); i++){
        for(long long int j = 0; j < A.size(); j++){
            long long int sum = 0;
            for(long long int x = 0; x < A.size(); x++){
                sum = sum + (A[i][x]*B[x][j]%1000000007)%1000000007;
            }
            C[i][j] = sum;
        }
    }
    return C;
}

vector<vector<long long int> > Pow(vector<vector<long long int> > T, long long int n){
    if(n == 1){
        return T;
    }
    if(n & 1){
        return multiply(T, Pow(T, n-1));
    }
    vector<vector<long long int> > temp = Pow(T, n/2);
    return multiply(temp, temp);
}


int MatrixExpo(vector<int> first_k, long long int k, long long int A){
    vector<vector<long long int> >T(k, vector<long long int>(k));
    T[0][0] = 0;
    T[0][1] = T[1][0] = T[1][1] = 1;
    vector<vector<long long int> > result = Pow(T, A-1);
    long long int ans = 0;
    for(long long int i = 0; i < k; i++){
        ans = (ans + result[k-1][i]*first_k[i]%1000000007)%1000000007;
    }
    return ans;
}

int solve(int A) {
    int k = 2;
    vector<int> first_k;
    first_k.push_back(0);
    first_k.push_back(1);
    int ans = MatrixExpo(first_k, k, A);
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}

// 0 1 1 2 3 5 8 13 21 34