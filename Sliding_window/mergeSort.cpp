#include<bits/stdc++.h>
#define nl "\n"
#define pb push_back
#define all(a) a.begin(),a.end()
using namespace std;

void mergeSort(int l,int r,vector<int> &v){
  
  int mid=(l+r)/2;
  if(l>=r) return;
  mergeSort(l,mid,v);
  mergeSort(mid+1,r,v);
  int h1=l,h2=mid+1;
  vector<int>nv=vector<int>(r-l+1); 
  for (int i = 0; i < nv.size(); ++i)
  {
  	if(h1>mid){
   nv[i]=v[h2];
   h2++;
   } 
  	else if(h2>r){
   nv[i]=v[h1];
   h1++;
   } 
  	else if(v[h1]>=v[h2]){
  		nv[i]=v[h2];
  		h2++;
  	}
  	else{
  		nv[i]=v[h1];
  		h1++;
  	}
  }

  for (int i = 0; i < nv.size(); ++i)
  {
  	v[l+i]=nv[i];
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
  int t;
  cin>>t;
  vector<int>v(t);
  //cout<<t<<nl;
  for (int i = 0; i < t; ++i)
  {
     cin>>v[i];
  }
   int l=0,r=v.size()-1;  
   mergeSort(l,r,v);
   for (int i = 0; i < v.size(); ++i)
   {
   	cout<<v[i]<<" ";
   }
  return 0;
}