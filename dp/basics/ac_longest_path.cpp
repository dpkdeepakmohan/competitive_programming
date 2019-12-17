#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<int> g[100005];
int dp[100005];
int visited[100005];
int mx=0;

void dfs(int node){

	if(visited[node])
		return;	

	visited[node]=1;	
	dp[node]=0;
	for(auto child:g[node]){
		dfs(child);
		dp[node]=max(dp[node],dp[child]+1);
	}
	mx=max(mx,dp[node]);
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int from,to;
		cin>>from>>to;
		g[from].push_back(to);
	}
	for(int i=1;i<=n;++i)
		if(!visited[i])
			dfs(i);
	cout<<mx<<endl;
	return 0;
}
