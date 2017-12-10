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
ll gcd(ll a, ll b)
{
    if(a==0)
        return b;
    else
        gcd(b%a,a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<abs(a-b)/(gcd(abs(a),abs(b)))<<"\n";
    }
    return 0;
}
