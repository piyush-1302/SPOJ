#include<bits/stdc++.h>
/*#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<math>
#include<set>
#include<iterator>
#include<tuple>*/
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frn(i,a,b) for(ll i=a;i<=b;i++)
#define frb(i,a,b) for(ll i=a;i>=b;i--)
#define ssi(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
#define mod 1000000007
#define pii pair<ll,ll>
const int N=200007;
ll a[N],segtree[4*N][2];
struct node
{
   int first;
   int second;
};
node tree[3*100005];
int arr[100005];
/*This function is used to build the
Segment Tree.*/
void build(int index,int start,int high)
{
   if(start==high)
   {
      tree[index].first = arr[start];
      tree[index].second = INT_MIN;
   }
   else
   {
      int mid = (start+high)/2;
      build(2*index+1,start,mid);
      build(2*index+2,mid+1,high);
      tree[index].first = max(tree[2*index+1].first,tree[2*index+2].first);
      tree[index].second = min(max(tree[2*index+1].first,tree[2*index+2].second),max(tree[2*index+1].second,tree[2*index+2].first));
   }
}
/*This function is used to answer the queries
that  are there*/
node query(int index,int start,int high,int l,int r)
{
   node result;
   result.first = result.second = -1;
   if(start>r || high<l )
      return result;
   if(start>=l && high<=r)
      return tree[index];
   int mid = (start+high)/2;
   if(l>mid)
      return query(2*index+2,mid+1,high,l,r);
   if(r<=mid)
      return query(2*index+1,start,mid,l,r);
   node left = query(2*index+1,start,mid,l,r);
   node right = query(2*index+2,mid+1,high,l,r);
   result.first =  max(left.first,right.first);
   result.second = min(max(left.first,right.second),max(left.second,right.first));
   return result;
}
/*This function is used to update the value in
the Segment Tree*/
void update(int index,int start,int high,int idx,int value)
{
   if(start == high)
   {
      tree[index].first = value;
      tree[index].second = INT_MIN;
   }
   else
   {
      int mid = (start+high)/2;
      if(idx <= mid)
         update(2*index+1,start,mid,idx,value);
      else
         update(2*index+2,mid+1,high,idx,value);
      tree[index].first=max(tree[2*index+1].first,tree[2*index+2].first);
      tree[index].second=min(max(tree[2*index+1].first,tree[2*index+2].second),max(tree[2*index+1].second,tree[2*index+2].first));
   }
}
int main()
{
   ios::sync_with_stdio(false);
   int n,q,a,b;
   char ch;

   cin>>n;
   for(int i=0;i<n;++i)
      cin>>arr[i];
   build(0,0,n-1);
   cin>>q;

   for(int i=0;i<q;++i)
   {
      cin>>ch>>a>>b;
      if(ch=='Q')
      {
         node result = query(0,0,n-1,a-1,b-1);
         cout<<result.first+result.second<<"\n";
      }
      else
         update(0,0,n-1,a-1,b);
   }
   return 0;
}
