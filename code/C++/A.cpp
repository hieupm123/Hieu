#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
const int M = 2e5 + 100;
vector<int> adj[M],A,vis(M),B(M), T(M),C(M),tree(4 * M),sub(M);
void dfs(int a){
	vis[a] = 1;
	for(int i = 0; i < (int)adj[a].size(); ++i){
		int b = adj[a][i];
		if(!vis[b]){
			T[b] = T[a] + 1;
			dfs(b);
			sub[a] = b;
		}
	}
	if(!sub[a]) sub[a] = a;
	A.push_back(a);
}
void build(int l, int r, int cnt){
	if(l == r){
		tree[cnt] = A[l];
	}else{
		int mid = (l + r) / 2;
		build(l,mid,2 * cnt);
		build(mid + 1,r,2 * cnt + 1);
		tree[cnt] = tree[2 * cnt] + tree[2 * cnt + 1];
	}
}
void up(int l, int r, int cnt, int a, int b){
	if(a < l || a > r){
		return;
	}
	if(l == r){
		tree[cnt] = b;
		return;
	}
	int mid = (l + r) / 2;
	up(l,mid,2 * cnt,a,b);
	up(mid + 1,r,2 * cnt + 1,a,b);
	tree[cnt] = tree[2 * cnt] + tree[2 * cnt + 1];
}
int query(int l, int r, int cnt, int a, int b){
	if(b < l || a > r){
		return 0;
	}
	if(a <= l && b >= r){
		return tree[cnt];
	}
	int mid = (l + r) / 2;
	return query(l,mid,2 * cnt,a,b) + query(mid + 1,r,2 * cnt + 1,a,b);
}
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n,q; cin>>n>>q;
   for(int i = 1; i <= n; ++i){
   	int a; cin>>a;
   	B[i] = a;
   }
   for(int i = 0; i < n - 1; ++i){
   	int a, b; cin>>a>>b;
   	adj[a].push_back(b);
   	adj[b].push_back(a);
   }
   T[1] = 1;
   dfs(1);
   reverse(A.begin(),A.end());
   for(int i = 0; i < (int)A.size(); ++i){
   	C[A[i]] = i;
   	A[i] = B[A[i]];
   }
   build(0,n - 1,1);
   for(int i = 0; i < q; ++i){
   	int a; cin>>a;
   	if(a == 1){
   		int b,c; cin>>b>>c;
   		up(0,n - 1,1,C[b],c);
   	}else{
   		int a; cin>>a;
   		int b = sub[a];
   		cout<<a<<" "<<C[a]<<"\n"<<b<<" "<<C[b]<<"\n";
   		cout<<query(0,n - 1,1,C[a],C[b])<<"\n";
   	}
   }
}