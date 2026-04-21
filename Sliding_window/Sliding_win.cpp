#include<bits/stdc++.h>
#include<limits.h>
#define nl "\n"
#define pb push_back
#define ll long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
  int t,n;
  cin>>t>>n;
  vector<int>v(t);
  for (int i = 0; i < t; ++i)
  {
  	cin>>v[i];
  }
  int sum=0;
  for (int i = 0; i < n; ++i)
  {
  	sum+=v[i];
  }
  int b=v[0];
  int a=v[n-1];
  for (int i = 0; i <(t-n+1); ++i)
  {
  	cout<<sum<<nl;
  	
  	a=v[i+n];
  	b=v[i];
    sum+=a-b;

  }
  
  return 0;
}