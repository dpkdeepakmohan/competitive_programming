#include<iostream>
using namespace std;

int a[100005],b[100005],c[100005];
int dpa[100005],dpb[100005],dpc[100005];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i]>>c[i];
	}	

	dpa[1]=a[1];
	dpb[1]=b[1];
	dpc[1]=c[1];
	for(int i=2;i<=n;++i){
		dpa[i]=max(dpb[i-1],dpc[i-1])+a[i];
		dpb[i]=max(dpa[i-1],dpc[i-1])+b[i];
		dpc[i]=max(dpa[i-1],dpb[i-1])+c[i];
	}
	cout<<max(dpa[n],max(dpb[n],dpc[n]))<<endl;
	return 0;
}
