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
#define pi 3.14159
int main()
{
    ll l,j;
    j=1;
    while(j!=0)
    {
        ssi(l);
        j=l;
        if(l!=0)
        {
            double ans=(l*l)/(2*pi);
            printf("%.2lf\n",ans);
        }
    }
    return  0;
}
