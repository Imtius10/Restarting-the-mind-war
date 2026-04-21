#include<bits/stdc++.h>
#define nl "\n"
#define pb push_back
#define all(a) a.begin(),a.end()
using namespace std;

int bin(vector<int>v,int n){
	int low=0,high=v.size();
    
	while(low<=high){
        int mid=low+(high-low)/2;
		if(v[mid]<=n) low=mid+1;
		else high=low-1;
	}
	return high;
}

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
    int ans=bin(v,n);
    cout<<ans<<nl;

  return 0;
}