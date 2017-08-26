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
const int N=10007;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,i,c,d;
    a[1]=1;
    fr(i,2,N)
    {
        c=i;
        d=a[i-1];
        while(c!=d)
        {
            if(c>d)
                c=c-d;
            else
                d=d-c;
        }
        a[i]=(i*a[i-1])/c;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<a[n]%1000000007<<"\n";
    }
    return 0;
}
