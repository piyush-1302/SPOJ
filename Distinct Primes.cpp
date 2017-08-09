#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frn(i,a,b) for(ll i=a;i<=b;i++)
#define ssi(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
const int N=4000;
ll vis[N],prime[N];
//ll f,s,g,u,d,dis[N];
void sieve()
{
    memset(vis,0,sizeof vis);
    ll i,j,k=1;
    vis[0]=1;
    vis[1]=1;
    frn(i,2,3000)
    {
        if(vis[i]==0)
        {
            for(j=2*i;j<=4000;j+=i)
            {
                vis[j]+=1;
            }
        }
    }
}
int main()
{
    ll t,n,i,j;
    sieve();
    j=0;
    memset(prime,0,sizeof prime);
    frn(i,30,3000)
    {
        if(vis[i]>=3)
        {
            prime[j]=i;
            j++;
        }
    }
    ssi(t);
    while(t--)
    {
        ssi(n);
        printf("%lld\n",prime[n-1]);
    }
    return 0;
}
