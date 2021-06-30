#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
struct node{
    int first = 0,second = 0;
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> A(n + 100);
    for(int i = 1; i <= n; ++i){
        cin>>A[i];
    }
    vector<node> dp(n + 100);
    multiset<int> S;
    for(int i = 1; i <= n; ++i){
        if(dp[i - 1].first + A[i] >= 0){
            dp[i].first = dp[i - 1].first + A[i];
            dp[i].second = dp[i - 1].second + 1;
            S.insert(A[i]);
        }else{
            if(!S.empty()){
                if(dp[i - 1].first - *S.begin() + A[i] > dp[i - 1].first){
                    dp[i].first = dp[i - 1].first - *S.begin() + A[i];
                    S.erase(begin(S));
                    S.insert(A[i]);
                }else{
                    dp[i].first = dp[i - 1].first;
                }
            }else{
                dp[i].first = dp[i - 1].first;
            }
            dp[i].second = dp[i - 1].second;
        }
    }
    cout<<dp[n].second<<"\n";
}