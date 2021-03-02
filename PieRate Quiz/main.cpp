#include<bits/stdc++.h>
#define int long long
#define MOD 107
using namespace std;

const int N = 100005;
int sieve[N] = {0};

void Sieve(){
	sieve[0] = sieve[1] = 1;
	for(int i = 2; i*i < N; i++){
		if(sieve[i] == 0){
			for(int j = i*i; j < N; j += i){
				sieve[j] = 1;
			}
		}
	}
}


int Task1(int l, int r){
	Sieve();
	int ans = 0;
	for(int i = l; i <= r; i++){
		int n = 0;
		int temp = i;
		while(temp > 0){
			int rem = temp % 10;
			n += rem;
			temp = (temp - rem)/10;
		}
		if(sieve[n] == 0 and sieve[i] == 0){
			ans = (ans % MOD + i % MOD) % MOD;
		}
	}
	return ans;
}



int nCr(int n, int k){
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
 
int Task2(int n){
    int c = nCr(2 * n, n);
    return c / (n + 1);
}


int tree[N];

void build(vector<int> arr, int node, int start, int end){
	if(start == end){
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	build(arr, 2*node, start, mid);
	build(arr, 2*node+1, mid+1, end);
	tree[node] = __gcd(tree[2*node], tree[2*node+1]);
	return;
}

int query(int node, int start, int end, int l, int r){
	if(end < l or start > end or r < start){
		return 0;
	}
	if(l <= start and r >= end){
		return tree[node];
	}
	int mid = (start + end)/2;
	int left = query(2*node, start, mid, l, r);
	int right = query(2*node+1, mid+1, end, l, r);
	return __gcd(left, right);
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int l, r;
	cin>>l>>r;
	int task1 = Task1(l, r);
	// cout<<task1<<endl;
	int task2 = Task2(task1-2);
	// cout<<task2<<endl;
	int temp = task2;
	vector<int> arr;
	while(temp > 0){
		int rem = temp%10;
		arr.push_back(rem);
		temp = (temp-rem)/10;
	} 
	arr.push_back(0);
	reverse(arr.begin(), arr.end());
	int n = arr.size()-1;
	build(arr, 1, 1, n);
	int task3 = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(query(1, 1, n, i, j) == 1){
				task3++;
			}
		}
	}
	cout<<task3<<endl;

	return 0;
}