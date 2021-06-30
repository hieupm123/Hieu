#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
const int M = 2e5 + 100;
vector<int> adj[M], T(M),vis(M),adj1[M];
vector<vector<int>> dp(M,vector<int>(25));
void dfs(int a){
   vis[a] = 1;
   for(int i = 0; i < (int)adj[a].size(); ++i){
      int b = adj[a][i];
      if(!vis[b]){
         T[b] = T[a] + 1;
         dp[b][0] = a;
         dfs(b);
      }
   }
}
int query(int a, int b){
   if(T[a] > T[b]){
      swap(a,b);
   }
   int ans = T[b] - T[a];
   for(int i = 0; i <= 20; ++i){
      if(ans & (1 << i)){
         b = dp[b][i];
      }
   }
   if(a == b){
      return ans;
   }
   for(int i = 20; i >= 0; --i){
      if(dp[b][i] != dp[a][i]){
         a = dp[a][i];
         b = dp[b][i];
         ans += 2 * (1 << i);
      }
   }
   return ans + 2;
}
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n,q; cin>>n>>q;
   for(int i = 0; i < n - 1; ++i){
      int a,b; cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
      adj1[b].push_back(a);
   }
   T[1] = 1;
   dfs(1);
   dp[1][0] = 1;
   for(int i = 1; i <= 20; ++i){
      for(int j = 0; j <= n; ++j){
         dp[j][i] = dp[dp[j][i - 1]][i - 1];
      }
   }
   for(int i = 0; i < q; ++i){
      int a,b; cin>>a>>b;
      cout<<query(a,b)<<"\n";
   }
}