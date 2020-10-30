#include<bits/stdc++.h>
using namespace std;

struct job{
	string Skill;
	int prior;
	int time;
	int jobId;

	job(string Skill, int prior, int time, int jobId){
		this->Skill = Skill;
		this->prior = prior;
		this->time = time;
		this->jobId = jobId;
	}
};

struct Emp{
	string Id;
	string Skill;

	Emp(string Id, string Skill){
		this->Id = Id;
		this->Skill = Skill;
	}
};

struct CompareEmp {
	bool operator()(Emp const& e1, Emp const& e2){
		if(e1.Skill == e2.Skill){
			return e1.Id > e2.Id;		}
		return e1.Skill > e2.Skill;
	}
};

struct Comparejob {
	bool operator()(job const& j1, job const& j2){
		if(j1.prior == j2.prior){
			if(j1.Skill == j2.Skill){
				return j1.time < j2.time;
			}else{
				return j1.Skill < j2.Skill;
			}
		}
		return j1.prior > j2.prior;
	}
};


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input3.txt", "r", stdin);
		freopen("output3.txt", "w", stdout);
	#endif 

	int n, m;
	set<Emp,CompareEmp> E;
	set<job, Comparejob> J;
	string s;
	cin>>n;
	getline(cin, s);
	for(int i = 0; i < n; i++){
		vector<string> temp;
		getline(cin, s);
		int n = s.length(); 
    	char char_array[n + 1]; 
    	strcpy(char_array, s.c_str()); 
		char * tok = strtok(char_array, "#");
		while(tok != NULL){
			string v = "";
			for(int i = 0; tok[i] != '\0'; i++){
				v += tok[i];
			}
			temp.push_back(v);
			tok = strtok(NULL, "#");
		}
		Emp e(temp[0], temp[1]);
		E.insert(e);
	}
	cin>>m;
	getline(cin, s);
	for(int i = 0; i < m; i++){
		vector<string> temp;
		getline(cin, s);
		int n = s.length(); 
    	char char_array[n + 1]; 
    	strcpy(char_array, s.c_str()); 
		char * tok = strtok(char_array, "#");
		while(tok != NULL){
			string v = "";
			for(int i = 0; tok[i] != '\0'; i++){
				v += tok[i];
			}
			temp.push_back(v);
			tok = strtok(NULL, "#");
		}
		job j(temp[0], stoi(temp[1]), stoi(temp[2]), stoi(temp[3]));
		J.insert(j);
	}

	for(auto it = E.begin(); it != E.end(); it++){
		Emp e = *it;
		cout<<e.Id<<" "<<e.Skill<<endl;
	}
	for(auto it = J.begin(); it != J.end(); it++){
		job j = *it;
		cout<<j.Skill<<" "<<j.prior<<" "<<j.time<<" " <<j.jobId<<endl;
	}
	return 0;
}