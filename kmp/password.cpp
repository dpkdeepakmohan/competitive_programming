#include<iostream>
#include<vector>
using namespace std;

vector<int> prefix_function(string s){
	
	vector<int> pi{0};
	for(int i=1;i<s.size();++i){
		int j=pi[i-1];
		while(j>0&&s[i]!=s[j])
			j=pi[j-1];
		if(s[i]==s[j])
			j++;
		pi.push_back(j);
	}
	return pi;
}

int main(){
	string s;
	cin>>s;
	for(auto v:prefix_function(s))
		cout<<v<<" ";
	cout<<endl;
	return 0;
}
