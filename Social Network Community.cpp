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
ll sz[N],parent[N];
ll root(ll x)
{
    while(x!=parent[x])
    {
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}
void uni(ll a, ll b)
{
    if(sz[a]>sz[b])
    {
        sz[a]+=sz[b];
        parent[b]=parent[a];
    }
    else
    {
        sz[b]+=sz[a];
        parent[a]=parent[b];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll x,y,n,q;
    cin>>n>>q;
    multiset<ll>st;
    multiset<ll>::iterator it;
    fr(i,1,n+1)
    {
        parent[i]=i;
        sz[i]=1;
        st.insert(1);
    }
    while(q--)
    {
        cin>>x>>y;
        ll r1=root(x);
        ll r2=root(y);
        //cout<<r1<<"   "<<r2<<"\n";
        if(r1!=r2)
        {
            st.erase(st.find(sz[r1]));
            st.erase(st.find(sz[r2]));
            uni(r1,r2);
            if(sz[r1]>sz[r2])
            {
                st.insert(sz[r1]);
                sz[r2]=0;
            }
            else
            {
                st.insert(sz[r2]);
                sz[r1]=0;
            }
        }
        it=st.end();
        it--;
        //cout<<*it<<"   "<<*st.begin()<<"\n";
        cout<<*it-*st.begin()<<"\n";
    }
    return 0;
}
