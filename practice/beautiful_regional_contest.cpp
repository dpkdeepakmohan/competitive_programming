/*
https://codeforces.com/contest/1264/problem/A
*/
#include<iostream>
#include<set>
using namespace std;
int p[400005];

int main(){
	
	int t;
	cin>>t;

	while(t--){
	
		int n;
		cin>>n;

		for(int i=1;i<=n;++i)
			cin>>p[i];

		int mx=0;
		for(int j=n/2;j>0;--j){
			if(p[j]>p[j+1]){
				mx=j;
				break;
			}
		}
		
		if(mx<3){
			cout<<"0 0 0\n";
			continue;
		}

		int state=0;
		int g=0,s=0,b=0,sc=0;
		for(int i=1;i<=mx;++i){
			if(state==0){
				if(p[i]>p[i+1]){
					g=i;
					state=1;
					continue;
				}
			}
			else if(state==1){
				++sc;
				if(p[i]>p[i+1]&&sc>g){
					s=i-g;
					state=2;
					continue;
				}
			}
			else if(state==2){
				++b;
			}
		}

		if(s>g&&b>g){
			cout<<g<<" "<<s<<" "<<b<<"\n";
		}
		else{
			cout<<"0 0 0\n";
		}

	}
	
}
