/*
Given a tree with each vertex having a color
Given a vertex v and color c,find number of vertices in subtree of v having color c.
O(nlogn) sln
*/



vector<int> *vec[maxn];//each element is a pointer to a vector
int cnt[maxn];//maxn is the max number of colors

void dfs(int v, int p, bool keep){
	
	//find the child having biggest subtree
	int mx = -1, bigChild = -1;
    	for(auto u : g[v])
       		if(u != p && sz[u] > mx)
           		mx = sz[u], bigChild = u;
	
	//do dfs for all others except largest with keep=0
	for(auto u : g[v])
       		if(u != p && u != bigChild)
           		dfs(u, v, 0);

	
    	if(bigChild != -1){
        	//non leaf,do dfs with keep=1
		dfs(bigChild, v, 1)
		//initialize vector with vector of bigChild
		vec[v] = vec[bigChild];
	}
    	else
        	vec[v] = new vector<int> ();//leaf node
    	
	//add yourself to subtree,add your color 
	vec[v]->push_back(v);
    	cnt[ col[v] ]++;
		
	//for children except bigChild
    	for(auto u : g[v])
       		if(u != p && u != bigChild)
           		for(auto x : *vec[u]){
               			cnt[ col[x] ]++;
               			vec[v] -> push_back(x);
           		}

    	//now (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    	// note that in this step *vec[v] contains all of the subtree of vertex v.
    	if(keep == 0)
        	for(auto u : *vec[v])
            		cnt[ col[u] ]--;
}

