#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

struct Point{ 
    int x, y; 
}; 

bool doOverlap(Point l1, Point r1, Point l2, Point r2) { 
    if (l1.x >= r2.x || l2.x >= r1.x) 
        return false; 
  
    if (l1.y <= r2.y || l2.y <= r1.y) 
        return false; 
  
    return true; 
} 



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	vector<int> R1(4, 0), R2(4, 0);
	for(int i = 0; i < 4; i++){
		cin>>R1[i];
	}
	for(int i = 0; i < 4; i++){
		cin>>R2[i];
	}

	Point l1 = {R1[0], R1[1]};
	Point r1 = {R1[2], R1[3]};
	Point l2 = {R2[0], R2[1]};
	Point r2 = {R2[2], R2[3]};

	if(doOverlap(l1, r1, l2, r2)){
		cout<<abs(R1[0]-R1[2])*abs(R1[1]- R1[3]) + abs(R2[0]-R2[2])*abs(R2[1]- R2[3]);
	}else{
		int x1 = min(R1[0], min(R1[2], min(R2[0], R2[2])));
		int x2 = max(R1[0], max(R1[2], max(R2[0], R2[2])));
		int y1 = min(R1[1], min(R1[3], min(R2[1], R2[3])));
		int y2 = max(R1[1], max(R1[3], max(R2[1], R2[3])));
		cout<<abs(x1-x2)*abs(y1-y2);
	}


	


	return 0;
}