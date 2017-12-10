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
ll phi[N];
ll res[N],cum[N];
void solve()
{
    fr(i,1,N)
        phi[i]=i;
    fr(i,2,N)
    {
        if(phi[i]==i)
        {
            for(ll j=i;j<N;j+=i)
            {
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
    fr(i,1,N)
    {
        for(ll j=i;j<N;j+=i)
        {
            res[j]=res[j]+1ll*i*phi[j/i];
        }
    }
    fr(i,1,N)
        res[i]-=i;
    cum[0]=0;
    fr(i,1,N)
    {
        cum[i]=cum[i-1]+res[i];
    }
}
int main()
{
    solve();
    int n;
    while(true)
    {
        cin>>n;
        if(n==0)
            return 0;
        printf("%lld\n",cum[n]);
    }
    return 0;
}
