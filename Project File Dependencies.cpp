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
#define ll int
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
vector<int> v[101];
ll first_zero(ll a[],ll n)
{
    ll i;
    fr(i,0,n)
    {
        if(a[i]==0)
            return i;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,i,k,j,a,temp;
    ll outdegree[101]={0};
    cin>>n>>m;
    fr(i,0,m)
    {
        cin>>a>>k;
        fr(j,0,k)
        {
            cin>>temp;
            v[temp-1].pb(a-1);
            outdegree[a-1]++;
        }
    }
    vector<int> ans;
    fr(i,0,n)
    {
        j = first_zero(outdegree,n);
        ans.pb(j+1);
        outdegree[j]=-1;
        fr(k,0,v[j].size())
            outdegree[v[j][k]]--;
    }
    fr(i,0,n-1)
       cout<<ans[i]<<" ";
    cout<<ans[n-1];
    cout<<"\n";
    return 0;
}

