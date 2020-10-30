#include<bits/stdc++.h>
#define int long long
using namespace std;

// vector<vector<int> > multiply(vector<vector<int> > A, vector<vector<int> > B){
//     vector<vector<int> >C(A.size(), vector<int>(A.size()));
//     for(int i = 0; i < A.size(); i++){
//         for(int j = 0; j < A.size(); j++){
//             int sum = 0;
//             for(int x = 0; x < A.size(); x++){
//                 sum = sum + (A[i][x]*B[x][j]%1000000007)%1000000007;
//             }
//             C[i][j] = sum;
//         }
//     }
//     return C;
// }

// vector<vector<int> > Pow(vector<vector<int> > T, int n){
//     if(n == 1){
//         return T;
//     }
//     if(n & 1){
//         return multiply(T, Pow(T, n-1));
//     }
//     vector<vector<int> > temp = Pow(T, n/2);
//     return multiply(temp, temp);
// }


// int MatrixExpo(vector<int> first_k, int k, int A){
//     vector<vector<int> >T(k, vector<int>(k));
//     T[0][0] = 0;
//     T[0][1] = T[1][0] = T[1][1] = 1;
//     vector<vector<int> > result = Pow(T, A-1);
//     int ans = 0;
//     for(int i = 0; i < k; i++){
//         ans = (ans + result[k-1][i]*first_k[i]%1000000007)%1000000007;
//     }
//     return ans;
// }

// int solve(int A) {
//     int k = 2;
//     if(A == 0 || A == 1){
//     	return A;
//     }
//     vector<int> first_k;
//     first_k.push_back(0);
//     first_k.push_back(1);
//     int ans = MatrixExpo(first_k, k, A);
//     return ans;
// }

int solve(int n){
    if(n == 0 || n == 1){
        return n;
    }
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int solution(int n){
	int ans1 = solve(n);
	int ans2 = solve(n+1);
	return ans1 + ans2;
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	for(int i = 0; i < n; i++){
		if(n == 0) cout<<"#"<<i+1<<" : "<<0<<endl;
		else cout<<"#"<<v[i]<<" : "<<solution(v[i])<<endl;
	}
	return 0;
}