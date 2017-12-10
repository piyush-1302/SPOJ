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
unordered_map<string,ll> mymap;
ll sz[N],parent[N];
void init()
{
   fr(i,1,N)
   {
       parent[i]=i;
       sz[i]=1;
   }
}
ll root(ll x)
{
    while(x!=parent[x])
    {
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}
void uni(ll x, ll y)
{
    ll a=root(x);
    ll b=root(y);
    if(a==b)
        cout<<sz[a]<<"\n";
    else
    {
    	if(sz[a]<sz[b])
        {
            sz[b]+=sz[a];
            parent[a]=b;
            cout<<sz[b]<<"\n";
        }
        else
        {
            sz[a]+=sz[b];
            parent[b]=a;
            cout<<sz[a]<<"\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        mymap.clear();
        ll n;
        cin>>n;
        ll x,y,k=1;
        string s1,s2;
        init();
        fr(i,0,n)
        {
            cin>>s1>>s2;
            if(mymap.find(s1)==mymap.end())
            {
                mymap[s1]=k;
                x=k;
                k++;
            }
            else
            {
                x=mymap[s1];
            }
            if(mymap.find(s2)==mymap.end())
            {
                mymap[s2]=k;
                y=k;
                k++;
            }
            else
            {
                y=mymap[s2];
            }
            //cout<<x<<"    "<<y<<endl;
            uni(x,y);
            //cout<<sz[root(x)]+sz[root(y)]<<"\n";
        }
    }
    return 0;
}
