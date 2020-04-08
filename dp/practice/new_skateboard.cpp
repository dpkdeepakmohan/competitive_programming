#include<iostream>
#include<string>
using namespace std;
long long dp[300005];

int main(){
	
	string s;
	cin>>s;
	int len=s.size();
	
	long long ans=0;
	if(s[0]=='4'||s[0]=='0'||s[0]=='8'){
		ans=1;
	}
	for(int i=1;i<len;++i){
		int last=s[i]-'0';
		int sec_last=s[i-1]-'0';
		int check=sec_last*10+last;
		if(check%4==0){
			ans+=i;
		}
		if(last%4==0)
			ans+=1;
	}
	cout<<ans<<endl;
	
}
