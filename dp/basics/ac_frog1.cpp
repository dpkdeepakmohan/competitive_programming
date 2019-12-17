#include<iostream>
using namespace std;


int dp[100005];
int h[100005];

int abs(int x){
	if(x<0)
		return -x;
	return x;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>h[i];
	dp[1]=0;
	dp[2]=abs(h[1]-h[2]);	
	for(int i=3;i<=n;++i){
		int prev=dp[i-1]+abs(h[i]-h[i-1]);
		int pprev=dp[i-2]+abs(h[i]-h[i-2]);
		dp[i]=min(prev,pprev);
	}	
	cout<<dp[n]<<endl;
	return 0;
}
