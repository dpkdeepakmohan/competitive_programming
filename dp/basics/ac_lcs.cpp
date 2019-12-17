#include<iostream>
#include<algorithm>
using namespace std;

int dp[3009][3009];
string ans="";
string s,t;

void get_lcs(int i,int j){

	if(i==0||j==0)
		return;

	if(s[i]==t[j]){
		ans+=s[i];
		get_lcs(i-1,j-1);	
	}
	else{
		if(dp[i-1][j]>dp[i][j-1])
			get_lcs(i-1,j);
		else
			get_lcs(i,j-1);
	}
}

int main(){
	cin>>s>>t;
	s=" "+s;
	t=" "+t;

	for(int i=1;i<s.length();++i){
		for(int j=1;j<t.length();++j){
			if(s[i]==t[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else 
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	get_lcs(s.length()-1,t.length()-1);
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;	
	return 0;
}
