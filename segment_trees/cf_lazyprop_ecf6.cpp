#include<iostream>
#include<vector>
using namespace std;

const int mx_sz=400005;
int n,q;
int color[mx_sz];
vector<int> g[mx_sz];


//dfs to flatten the tree
//each subtree of the tree is now represented by a range 
int flat_tree[mx_sz];
int s[mx_sz],en[mx_sz];
int timer=0;

void dfs(int v,int p){
	s[v]=++timer;
	flat_tree[timer]=v;
	for(auto ch:g[v])
		if(ch!=p){
			dfs(ch,v);
		}
	en[v]=timer;
}

//segment tree with lazy propogation
long long st[4*mx_sz];
bool lazy[4*mx_sz];

void gather(int nd){
	st[nd]=st[2*nd]|st[2*nd+1];
}

void push(int nd){
	if(lazy[nd]){
		st[2*nd]=st[nd];
		st[2*nd+1]=st[nd];
		lazy[2*nd]=true;
		lazy[2*nd+1]=true;
		lazy[nd]=false;
	}
}

void build_tree(int nd,int l,int r){

	if(l==r){
		st[nd]=1LL<<color[flat_tree[l]];
		return;
	}
	int mid=(l+r)/2;
	build_tree(2*nd,l,mid);
	build_tree(2*nd+1,mid+1,r);
	gather(nd);
}

void update_tree(int nd,int l,int r,int ql,int qr,int nc){
	if(l>qr||r<ql)
		return;
	if(l>=ql&&r<=qr){
		//node range inside query range
		st[nd]=1LL<<nc;
		lazy[nd]=true;
		return;
	}
	push(nd);//will only be called for non leaf nodes
	int mid=(l+r)/2;
	update_tree(2*nd,l,mid,ql,qr,nc);
	update_tree(2*nd+1,mid+1,r,ql,qr,nc);
	gather(nd);
}

long long query_tree(int nd,int l,int r,int ql,int qr){
	if(r<ql||l>qr)
		return 0;
	if(l>=ql&&r<=qr)
		return st[nd];
	push(nd);//will only be called for non leaf nodes
	int mid=(l+r)/2;
	long long res=query_tree(2*nd,l,mid,ql,qr);
	res|=query_tree(2*nd+1,mid+1,r,ql,qr);
	gather(nd);
	return res;
}

//count bits
int count_bits(long long x){
	if(x==0)
		return 0;
	if(x&1LL)
		return 1+count_bits(x/2);
	return count_bits(x/2);
}

int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);	
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>color[i];
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);	
	}

	dfs(1,-1);
	build_tree(1,1,n);

	for(int i=1;i<=q;++i){
		int t,v,c;
		cin>>t;
		if(t==1){
			cin>>v>>c;
			update_tree(1,1,n,s[v],en[v],c);						
		}
		else{
			cin>>v;
			long long mask=query_tree(1,1,n,s[v],en[v]);
			cout<<count_bits(mask)<<"\n";
		}
	}
	
	return 0;
}
