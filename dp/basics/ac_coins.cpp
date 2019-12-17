#include<iostream>
using namespace std;

double p[3000];
double dp[3000][3000];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>p[i];
	//dp[number of coins][number of heads]
	dp[1][0]=1-p[1];
	dp[1][1]=p[1];

	for(int i=2;i<=n;++i){
		for(int h=0;h<=i;++h){
			dp[i][h]=dp[i-1][h]*(1-p[i]);
			if(h-1>=0)
				dp[i][h]+=dp[i-1][h-1]*p[i];			
		}
	}
	double ans=0;
	for(int h=n/2+1;h<=n;++h)
		ans+=dp[n][h];
	cout<<fixed<<setprecision(15)<<ans<<endl;		
	return 0;
}
