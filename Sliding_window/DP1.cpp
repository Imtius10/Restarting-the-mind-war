#include<bits/stdc++.h>
#define nl "\n"
#define pb push_back
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;

vector<long long>price,wt;
int dp[105][100005];
int n;
int knapsack(int pos,int c){

	if (pos==n)
	{
		return 0;
	}
	if(dp[pos][c]!=-1) return dp[pos][c];
     int max1=0,max2=0;
    if(c>=wt[pos]){
        max1=price[pos]+knapsack(pos+1,c-wt[pos]);
    }

    max2=knapsack(pos+1,c);
    dp[pos][c]=max(max1,max2);
    return dp[pos][c];

}
signed main()
{
   ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
  int c;
  cin>>n>>c;

  for (int i = 0,w,p; i < n; ++i){

  	cin>>w>>p;
  	wt.pb(w);
  	price.pb(p);
  }
 
  	


  memset(dp,-1,sizeof(dp));

  cout<<knapsack(0,c)<<endl;
  return 0;
}