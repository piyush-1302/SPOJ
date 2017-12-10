#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frn(i,a,b) for(ll i=a;i<=b;i++)
#define frb(i,a,b) for(ll i=a;i>=b;i--)
#define ssi(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
const int N=100007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll a,b,c,d=1;
    ssi(a);
    ssi(b);
    ssi(c);
    while(d)
    {
        if(a==0 && b==0 && c==0)
            break;
        if((c+a)==2*b)
            cout<<"AP "<<a+3*(b-a)<<"\n";
        else
            cout<<"GP "<<a*(b/a)*(b/a)*(b/a)<<"\n";
        ssi(a);
        ssi(b);
        ssi(c);
    }
    return 0;
}
