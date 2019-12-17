#include<iostream>
using namespace std;

long long w[109];
long long v[109];
long long dp[109][100005];

int main(){
	int n,c;
	cin>>n>>c;
	for(int i=1;i<=n;++i)
		cin>>w[i]>>v[i];
	for(int i=0;i<=n;++i){
		for(int wt=0;wt<=c;++wt){
			if(i==0||wt==0){
				dp[i][wt]=0;
				continue;
			}
			dp[i][wt]=dp[i-1][wt];
			if(wt-w[i]>=0)
				dp[i][wt]=max(dp[i][wt],dp[i-1][wt-w[i]]+v[i]);
		}
	}
	cout<<dp[n][c]<<endl;
	return 0;
}
