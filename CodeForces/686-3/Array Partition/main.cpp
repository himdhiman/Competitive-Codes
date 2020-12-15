#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

// Range min query

struct SparseTable{
	vector<vector<int> > RangeMin;
	vector<vector<int> > RangeMax;

	int n, m;

	SparseTable(int _n, int _m){
		n = _n;
		m = _m;
		RangeMin.resize(n);
		RangeMax.resize(n);
		for(int i = 0; i < n; i++){
			RangeMin[i].resize(m);
			RangeMax[i].resize(m);
		}
	}

	void build(int arr[]){
		for(int i = 0; i < n; i++){
			 RangeMin[i][0] = arr[i];
			 RangeMax[i][0] = arr[i];
		}
		for(int j = 1; j < m; j++){
			for(int i = 0; i + (1<<j) - 1 < n; i++){
				RangeMin[i][j] = min(RangeMin[i][j-1], RangeMin[i+(1<<(j-1))][j-1]);
				RangeMax[i][j] = max(RangeMax[i][j-1], RangeMax[i+(1<<(j-1))][j-1]);
			}
		}
		return;
	}

	int query(int l, int r, string type){
		if(type == "min"){
			int ans = INT_MAX;
			for(int i = n; i >= 0; i--){
				if(i < 20 and l + (1<<i) - 1 <= r){
					ans = min(ans, RangeMin[l][i]);
					 l += (1<<i);
				}
			}
			return ans;	
		}else if(type == "max"){
			int ans = INT_MIN;
			for(int i = n; i >= 0; i--){
				if(i < 20 and l + (1<<i) - 1 <= r){
					ans = max(ans, RangeMax[l][i]);
					l += (1<<i);
				}
			}
			return ans;
		}
		return -90;
	}
};

// Range Max query

// struct RangeMax{
// 	vector<vector<int> > mat;
// 	int n, m;

// 	RangeMax(int _n, int _m){
// 		n = _n; 
// 		m = _m;
// 		mat.resize(n);
// 		for(int i = 0; i < n; i++) mat[i].resize(m);
// 	}

// 	void build(int arr[]){
// 		for(int i = 0; i < n; i++) mat[i][0] = arr[i];
// 		for(int j = 1; j < m; j++){
// 			for(int i = 0; i + (1<<j) - 1 < n; i++){
// 				mat[i][j] = max(mat[i][j-1], mat[i+(1<<(j-1))][j-1]);
// 			}
// 		}
// 		return;
// 	}

	// int query(int l, int r){
	// 	int ans = INT_MIN;
	// 	for(int i = n; i >= 0; i--){
	// 		if(i < 20 and l + (1<<i) - 1 <= r){
	// 			ans = max(ans, mat[l][i]);
	// 			l += (1<<i);
	// 		}
	// 	}
	// 	return ans;
	// }
// };



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int m = ceil(log2(n))+1;
		SparseTable s(n, m);
		s.build(arr);
		int start = 1;
		int end = n-2;
		int state = false;
		for(int i = start; i <= end; i++){
			for(int j = start; j <= end; j++){
				if(s.query(0, i-1, "max") == s.query(i, j, "min") and s.query(i, j, "min") == s.query(j+1, n-1, "max")){
					cout<<"YES"<<endl;
					cout<<i<<" "<<j-i+1<<" "<<n-j-1<<endl;
					state = true;
					break;
				}
			}
			if(state){
				break;
			}
		}
		if(!state){
			cout<<"NO"<<endl;
		}

	}

	


	return 0;
}