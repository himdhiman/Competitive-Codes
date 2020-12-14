#include<bits/stdc++.h>
#define int long long
#define MAX 256 
using namespace std;


bool compare(char arr1[], char arr2[]) 
{ 
    for (int i=0; i<MAX; i++) 
        if (arr1[i] != arr2[i]) 
            return false; 
    return true; 
} 
  
void search(char *pat, char *txt) 
{ 
    int M = strlen(pat), N = strlen(txt); 
  
    // countP[]:  Store count of all characters of pattern 
    // countTW[]: Store count of current window of text 
    char countP[MAX] = {0}, countTW[MAX] = {0}; 
    for (int i = 0; i < M; i++) 
    { 
        (countP[pat[i]])++; 
        (countTW[txt[i]])++; 
    } 
  
    // Traverse through remaining characters of pattern 
    for (int i = M; i < N; i++) 
    { 
        // Compare counts of current window of text with 
        // counts of pattern[] 
        if (compare(countP, countTW)) 
            cout << (i - M) << endl; 
  
        // Add current character to current window 
        (countTW[txt[i]])++; 
  
        // Remove the first character of previous window 
        countTW[txt[i-M]]--; 
    } 
  
    // Check for the last window in text 
    if (compare(countP, countTW)) 
        cout << (N - M) << endl; 
} 

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 


	// int n;
	// while((scanf("%lld", &n)) != EOF){

		
	// }
	char txt[100];
    char pat[100];

    cin>>txt;
    cin>>pat;
    search(pat, txt); 

	return 0;
}