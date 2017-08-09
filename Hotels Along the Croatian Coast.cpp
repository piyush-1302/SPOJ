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
const int N=300007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,ans=0,temp=0,a[N],j;
    cin>>n>>m;
    fr(i,0,n)
        cin>>a[i];
    j=0;
    fr(i,0,n)
    {
        ans+=a[i];
        while(ans>m && j<=i)
        {
            ans-=a[j];
            j++;
        }
        temp=max(temp,ans);
    }
    cout<<temp<<"\n";
    return 0;
}
