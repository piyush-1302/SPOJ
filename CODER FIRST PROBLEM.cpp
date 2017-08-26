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
ll rec(ll n)
{
    if(n==0 || n%2!=0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else
        return (2+rec(n/2));
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    cout<<rec(n)<<"\n";
    return 0;
}
