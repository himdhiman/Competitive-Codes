#include<bits/stdc++.h>
#define int long long
using namespace std;


string findSum(string str1, string str2){ 

    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    string str = ""; 
  
    int n1 = str1.length(), n2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        carry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) 
        str.push_back(carry+'0'); 
   
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string getStr(vector<int> v){
	string res = "";
	for(int i = 0; i < v.size(); i++){
		res += to_string(v[i]);
	}
	return res;
}

vector<int> getVect(string s){
	vector<int> v(100, 0);
	for(int i = 0; i < s.length(); i++){
		v[i] = (s[i]-48);
	}
	return v;
}

int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	vector<int> a(100, 0), b(100, 0), c(100, 0);
	b[99] = 1;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		c = getVect(findSum(getStr(a), getStr(b)));
		a = b;
		b = c;
	}
	for(int i = 0; i < c.size(); i++){
		cout<<c[i];
	}




	return 0;
}