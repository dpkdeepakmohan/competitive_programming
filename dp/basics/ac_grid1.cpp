#include<iostream>
using namespace std;

long long mod=1e9+7;
string grid[1005];
long long dp[1005][1005];

int main(){
	int h,w;
	cin>>h>>w;
	for(int i=1;i<=h;++i){
		cin>>grid[i];
		grid[i]=" "+grid[i];
	}

	dp[1][1]=1;
	for(int i=1;i<=h;++i)
		for(int j=1;j<=w;++j){
			if(grid[i][j]=='#')
				continue;
			dp[i][j]+=dp[i-1][j]+dp[i][j-1];
			dp[i][j]%=mod;
		}
	cout<<dp[h][w]<<endl;	
		
	return 0;
}
