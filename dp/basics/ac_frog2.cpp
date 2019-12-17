#include<iostream>
using namespace std;

int dp[100005];
int h[100005];
int inf=1e9;

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>h[i];
	dp[1]=0;
	for(int i=2;i<=n;++i){
		dp[i]=inf;
		for(int j=1;j<=k;++j)
			if(i-j>0){
				int cost=dp[i-j]+abs(h[i]-h[i-j]);
				dp[i]=min(dp[i],cost);
			}
	}
	cout<<dp[n]<<endl;
	return 0;
}
