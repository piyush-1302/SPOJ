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
ll josephus(ll n, ll d)
{
    if(n==1)
        return 1;
    else
        return (josephus(n-1,d)+d-1)%n+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,d,w,flag=1;
    while(flag)
    {
        cin>>n>>d;
        if(n==0 && d==0)
        {
            flag=0;
            break;
        }
        else
        {
            w=josephus(n,d);
            cout<<n<<" "<<d<<" "<<w<<"\n";
        }
    }
    return 0;
}
