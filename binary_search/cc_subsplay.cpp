#include<iostream>
#include<string>
using namespace std;

int len;
string s;
int left_pos[100009];
int mx[30];

void find_left(){

	for(int i=0;i<30;++i)
		mx[i]=-1;

	for(int i=0;i<len;++i){
		int idx=s[i]-'a';
		left_pos[i]=mx[idx];
		mx[idx]=i;		
	}
}

bool is_possible(int seq_len){

	for(int i=0;i<len;++i){
		if(left_pos[i]==-1)
			continue;
		if(len-i-1+left_pos[i]>=seq_len-1)
			return true;
	}
	return false;
}

int main(){
	int tc;
	cin>>tc;
	for(int t=0;t<tc;++t){
		cin>>len;
		cin>>s;

		find_left();
		
		//binary search for the last 
		int l=0,r=len;
		while(l<r){
			int mid=(l+r+1)/2;
			if(is_possible(mid))
				l=mid;
			else
				r=mid-1;
		}
		if(l==r)
			cout<<l<<endl;
		else 
			cout<<0<<endl;
		
	} 
	return 0;
}
