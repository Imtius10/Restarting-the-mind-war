#include<bits/stdc++.h>
#include<limits.h>
#define nl "\n"
#define pb push_back
#define ll long long
using namespace std;



void sortPairFirstElement(){
	
	int n; cin>>n;
	vector<pair<int,int>>pr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>pr[i].first>>pr[i].second;
	}
     sort(pr.begin(),pr.end());
	for(auto a:pr){
		cout<<a.first<<" "<<a.second<<nl;
	}
}


void sortPairSecondElement(){
	
	int n; cin>>n;
	vector<pair<int,int>>pr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>pr[i].first>>pr[i].second;
	}
     sort(pr.begin(),pr.end(),[](const pair<int,int>&a,const pair<int,int>&b){
     	return a.second<b.second;
     });
	for(auto a:pr){
		cout<<a.first<<" "<<a.second<<nl;
	}
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
  sortPairFirstElement();
  sortPairSecondElement();
  
  return 0;
}