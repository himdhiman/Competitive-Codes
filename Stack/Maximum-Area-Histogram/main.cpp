#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> NSL(vector<int> v){
	stack<pair<int, int> > s;
	vector<int> out;
	for(int i = 0; i < v.size(); i++){
		if(s.empty()){
			out.push_back(-1);
		}else{
			while(!s.empty() and s.top().first >= v[i]){
				s.pop();
			}
			if(s.empty()){
				out.push_back(-1);
			}else{
				out.push_back(s.top().second);
			}
		}
		s.push(make_pair(v[i], i));
	}
	return out;
}

vector<int> NSR(vector<int> v){
	vector<int> out;
	stack<pair<int, int> > s;
	for(int i = v.size()-1; i >= 0; i--){
		if(s.empty()){
			out.push_back(-1);
		}else{
			while(!s.empty() and s.top().first >= v[i]){
				s.pop();
			}
			if(s.empty()){
				out.push_back(-1);
			}else{
				out.push_back(s.top().second);
			}
		}
		s.push(make_pair(v[i], i));
	}
	reverse(out.begin(), out.end());
	return out;
}

int MAH(vector<int> input){
	vector<int> nsl = NSL(input);
	vector<int> nsr = NSR(input);
	int ans = 0;
	for(int i = 0; i < input.size(); i++){
		int temp = (nsr[i]-nsl[i]-1)*input[i];
		ans = max(ans, temp);
	}
	cout<<ans;
	return 0;
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	
	int n;
	cin>>n;
	vector<int> input(n, 0);
	for(int i = 0; i < n; i++){
		cin>>input[i];
	}

	MAH(input);

	return 0;
}