/*
https://codeforces.com/problemset/problem/977/F
*/

#include<iostream>
#include<map>
using namespace std;
int a[200005];

int main(){
	
	int n;
	cin>>n;

	for(int i=1;i<=n;++i)
		cin>>a[i];

	map<int,int>len;
	int last_num=0,mx_len=0;
	for(int i=1;i<=n;++i){
		int cur_len=0;
		if(len.find(a[i]-1)==len.end()){
			cur_len=1;
		}	
		else{
			cur_len=len[a[i]-1]+1;
		}
		len[a[i]]=cur_len;
		if(cur_len>mx_len){
			mx_len=cur_len;
			last_num=a[i];
		}
	}
	cout<<mx_len<<"\n";
	int num=last_num-mx_len+1;
	for(int i=1;i<=n;++i){
		if(a[i]==num){
			cout<<i<<" ";
			if(num==last_num)
				break;
			else
				++num;
		}	
	}
	cout<<"\n";
}
