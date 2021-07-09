#include<bits/stdc++.h>
using namespace std;

int BirthdayParadox(float p){
    float compliment = (1.0-p);
    int start = 1;
    while(true){
        float temp = 1.0; 
        for(int i = 0; i < start; i++){
            temp = temp*((365-i)/365.0);
        }
        if(temp < compliment){
            break;
        }
        start++;
    }
    return start;
}

int main() {
	float p;
	cin>>p;
	cout<<BirthdayParadox(p);
}