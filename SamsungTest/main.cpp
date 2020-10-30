#include<iostream>
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long sum = 0;
	int hash[100002], k, a[100002], maximum, x, n, i;
	cin>>n>>k;
	long long var = n*(n+1)/2;
	for(i = 0; i < n; i++){
		cin>>a[i];
	}
	for (i = 0; i < 100002; i++)
        hash[i] = -1;
    int p1, p2=0, pair=-1;
    maximum = 0;
    for (p1=0; p1<n; p1++)
    {
        while(pair<p1)
        {
            if(a[p2]>maximum)
				maximum=a[p2];
			hash[a[p2]]=p2;
			p2++;
            if(p2==n)
            {
                sum = sum + ((long long)n-p1)*(n-p1+1)/2;
                // printf("%lld",var-sum);
                cout<<var-sum;
				return 0;
            }
            if(a[p2]>k)
            {
                for(x=k; x<=maximum; x+=a[p2])
                {
                    if(hash[x]!=-1&&pair<hash[x]&&hash[x]>=p1)
                        pair=hash[x];
                }
            }
        }
        sum = sum + p2-p1;  
    }
    return 0;
}