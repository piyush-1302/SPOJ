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
int main()
{
    ll t,n,i,sum1,sum2,sum,a,b,j;
    ssi(t);
    while(t--)
    {
        ssi(n);
        a=n/7;
        b=n/13;
        sum1=0;
        sum2=0;
        sum=0;
        fr(i,1,b);
            sum1+=i;
        fr(j,b,a)
            sum2+=j;
        sum=13*sum1+7*(sum1+sum2);
        printf("%lld\n",sum);
    }
    return 0;
}
