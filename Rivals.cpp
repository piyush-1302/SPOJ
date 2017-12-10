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
ll arr[2000009];
void pre()
{
    arr[0] = 1;
    arr[1] = 1;
    for(ll i = 2 ; i<=2000000 ; i++)
        arr[i] = (arr[i-1] * i)%mod;
}
ll inv_mod(ll x)
{
    ll a = 1 , p = x , n = 1000000005;
    while(n)
    {
        if(n&1)
            a = (a*p)%mod;
        p = (p * p )%mod;
        n>>=1;
    }
    return a;
}
int main()
{
    ll t;
    pre();
    cin>>t;
    while(t--)
    {
        ll x , y;
        cin>>x>>y;
        ll temp = (inv_mod(arr[x]) * inv_mod(arr[y]))%mod;
        ll res = (arr[x+y] * temp)%mod;
        cout<<res<<"\n";
    }
    return 0;
}
