#include<bits/stdc++.h>
#define nl "\n"
#define pb push_back
#define all(a) a.begin(),a.end()
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
  int t;
  cin>>t;
     while(t--){
       int n; cin>>n;
       vector<int> v(n);
       for (int i = 0; i < n; ++i)
       {
       	cin>>v[i];
       }
       vector<int>x;
       x=v;
       sort(x.begin(),x.end());
       vector<int>nv(n+1);
       nv[0]=0;
       for (int i = 1; i <= n; ++i)
       {
       	nv[i]=nv[i-1]+x[i-1];
       }
       int flag=true;
      if (n==1)
      {
      	flag=false;
      }
      else{
      	 for (int i = 1; i < v.size(); ++i)
       {
       
       
       	//cout<<v[i]<<"-->"<<nv[i+1]<<" ";

       	if (v[i]==nv[i+1])
       	{
       		flag=false;
       		break;
       	}
       }
      }
       if (!flag)
       {
       	cout<<-1<<nl;
       }
      else {
       	for (int i = n-1; i >=0; --i)
       	{
       		if(i){
               cout<<
            }
       	}
       	cout<<nl;
       }
      //cout<<nl;
     }

  return 0;
}