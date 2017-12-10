#include<stdio.h>

void main()
{
   int a = 640;
   char *x = (char *)&a;
   printf("%d", *x);
}

/*
Intern Ni lgaa
*/
#include <bits/stdc++.h>
#define ll long long int
#define si1(a) scanf("%d",&a)
#define si2(a,b) scanf("%d%d",&a,&b)
#define si3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sil1(a) scanf("%lld",&a)
#define sil2(a,b) scanf("%lld%lld",&a,&b)
#define sil3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pi1(a) printf("%d\n",a)
#define pi2(a,b) printf("%d%d",a,b)
#define pi3(a,b,c) printf("%d%d%d",a,b,c)
#define pil1(a) printf("%lld\n",a)
#define pil2(a,b) printf("%lld%lld",a,b)
#define pil3(a,b,c) printf("%lld%lld%lld",a,b,c)
#define dd double
using namespace std;
ll n,m;
ll a[505][505];
bool prime[1000005];
ll pehla[1000005];
ll dp[505][78499];
vector<ll>prime_factors[1000005];
int main()
{
    prime[0]=true;
    prime[1]=true;
    ll i,j,k;
    vector<ll>::iterator it;
    ll idx=0;
        for(i=0;i<1000001;i++)
        {
            if(!prime[i])
            {
                pehla[i] = idx++;
                for(j=i;j<1000001;j+=i){
                    prime_factors[j].pb(i);
                    prime[j]=true;}
            }
        }
   int t;
   si1(t);
   while(t--){
    sil2(n,m);
    ll i,j,k,ctr=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            sil1(a[i][j]);
        }
    }
          for(i=0;i<m;i++)
            {
                for(it=prime_factors[a[0][i]].begin();it!=prime_factors[a[0][i]].end();it++)
                {
                    if(dp[0][pehla[*(it)]]<a[0][i])
                        dp[0][pehla[*(it)]] = a[0][i];
                }
            }
           for(i=1;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                   ll ma = 0;
                    for(it=prime_factors[a[i][j]].begin();it!=prime_factors[a[i][j]].end();it++)
                    {
                        if(dp[i-1][pehla[*(it)]]!=0)
                            ma =max(ma,dp[i-1][pehla[*(it)]]+a[i][j]);
                    }
                    for(it=prime_factors[a[i][j]].begin();it!=prime_factors[a[i][j]].end();it++)
                    {
                        dp[i][pehla[*(it)]] = max(ma,dp[i][pehla[*(it)]]);
                    }
                }

                 for(j=0;j<m;j++)
                {
                  for(it=prime_factors[a[i-1][j]].begin();it!=prime_factors[a[i-1][j]].end();it++)
                {
                        dp[i-1][pehla[*(it)]] = 0;
                }
                }

            }
            for(i=0;i<=78498;i++){
                ctr=max(ctr,dp[n-1][i]);
                dp[n-1][i]=0;
            }
            pil1(ctr);
        }
    return 0;
