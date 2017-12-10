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
const int N=1000007;
set<ll>st;
ll bs(ll ind)
{
    set<ll>::iterator pos;
    if(st.size()==0)
        return -1;
    pos=st.lower_bound(ind);
    if(*pos>=ind)
        return *pos;
    else
        return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,k,x,y,a;
    cin>>n>>k;
    fr(i,0,k)
    {
        cin>>x>>y;
        if(x==1)
            st.insert(y);
        else
        {
            cout<<bs(y)<<"\n";
        }
    }
    return 0;
}
