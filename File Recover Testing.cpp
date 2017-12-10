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
const int N=100007;
ll kmp(const string &needle)
{
  // Precompute border function
  ll m = needle.size();
  vector<ll> border(m + 1);
  border[0] = -1;
  fr(i,0,m)
  {
    border[i+1] = border[i];
    while (border[i+1] > -1 && needle[border[i+1]] != needle[i])
    {
      border[i+1] = border[border[i+1]];
    }
    border[i+1]++;
  }
  return border.back();
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll k;
  while(cin>>k)
  {
    if (k==-1)
        break;
    string line;
    cin>>line;
    ll m =  kmp(line);
    k-=m;
    if(k<=0)
      cout<<0<< endl;
    else
    {
      m=line.size()-m;
      cout<<k/m<<endl;
    }
  }
  return 0;
}
