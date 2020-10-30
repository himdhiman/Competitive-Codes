#include<bits/stdc++.h>
using namespace std;

class Point{
public:
	int x, y;
	Point(){

	}
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

class compare{
public:
	bool operator()(Point p1, Point p2){
		if(p1.x == p2.x){
			return p1.y < p2.y;
		}
		return p1.x < p2.x;
	}
};

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n, x, y;
	cin>>n;
	set<Point, compare> s;
	for(int i = 0; i < n; i++){
		cin>>x>>y;
		Point p(x, y);
		s.insert(p);
	}
	int ans = 0;
	for(auto it = s.begin(); it != prev(s.end()); it++){
		for(auto jt = next(it); jt != s.end(); jt++){
			Point p1 = *it;
			Point p2 = *jt; 
			if(p1.x == p2.x || p1.y == p2.y){
				continue;
			}
			Point p3(p1.x, p2.y);
			Point p4(p2.x, p1.y);
			if(s.find(p3) != s.end() and s.find(p4) != s.end()){
				ans++;
			}
		}
	}
	ans /= 2;
	cout<<ans;
	return 0;
}