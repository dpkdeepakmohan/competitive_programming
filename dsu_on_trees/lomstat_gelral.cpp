#include<iostream>
#include<vector>
using namespace std;

const int max_n=100005;
int color[max_n];
int color_cnt[max_n];
int sz[max_n];
long long ans[max_n];
vector<int>g[max_n];
vector<int> *children[max_n];
long long max_color_cnt=0,sum=0;

void calc_size(int nd,int p){
	++sz[nd];
	for(auto ch:g[nd]){
		if(ch!=p){
			calc_size(ch,nd);
			sz[nd]+=sz[ch];
		}
	}
}

void update_ans(int clr){
	if(color_cnt[clr]>max_color_cnt){
		max_color_cnt=color_cnt[clr];
		sum=clr;
		/*
		cout<<"Max updated to:"<<max_color_cnt<<endl;
		cout<<"Color:"<<clr<<endl;
		cout<<"Sum:"<<sum<<endl;
		*/
	}
	else if(color_cnt[clr]==max_color_cnt){
		sum+=clr;
		/*
		cout<<"New dominant found:"<<clr<<endl;
		cout<<"Sum:"<<sum<<endl;
		*/
	}
}

void trick_dfs(int nd,int p,bool keep){

	//find the child with largest size
	int big_child=-1;
	int mx_size=-1;
	for(auto ch:g[nd]){
		if(ch!=p){
			if(mx_size<sz[ch]){
				mx_size=sz[ch];
				big_child=ch;
			}
		}
	}

	//cout<<"Big of "<<nd<<" :"<<big_child<<endl;
	
	//do dfs first for small children 
	for(auto ch:g[nd]){
		if(ch!=p&&ch!=big_child){
			trick_dfs(ch,nd,false);
		}	
	}

	//do dfs for big_child after all small children
	if(big_child!=-1){
		trick_dfs(big_child,nd,true);
		children[nd]=children[big_child];
	}
	else{
		//this is a leaf node create a vector of children for this node
		children[nd]=new vector<int>();
	}

	//add myself to the list of children
	children[nd]->push_back(nd);
	++color_cnt[color[nd]];
	update_ans(color[nd]);

	//merge children vector of small children
	for(auto ch:g[nd]){
		if(ch!=p&&ch!=big_child){
			for(auto v:*children[ch]){
				children[nd]->push_back(v);
				++color_cnt[color[v]];
				update_ans(color[v]);
			}
		}		
	}

	//at this point you have answer for this subtree
	ans[nd]=sum;
	//cout<<"Ans for "<<nd<<":"<<sum<<endl;	
	//clear the property if this is not a big child
	if(!keep){
		//reset the ans 
		//cout<<"Clearing for "<<nd<<endl;
		max_color_cnt=0;
		sum=0;

		//remove contribution of this subtree from ans
		for(auto ch:*children[nd])
			--color_cnt[color[ch]];
	}
}

int main(){

	int n=0;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>color[i];
	for(int i=1;i<n;++i){
		int u=0,v=0;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	calc_size(1,-1);
	trick_dfs(1,-1,false);
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
