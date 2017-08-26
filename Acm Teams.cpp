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
    ll t,e,n;
    ssi(t);
    while(t--)
    {
        ssi(e);
        ssi(n);
        if(n==0 || e==0)
            cout<<"0\n";
        else if(2*e<=n)
            cout<<e<<"\n";
        else if(e>=2*n)
            cout<<n<<"\n";
        else
            cout<<(e+n)/3<<"\n";
    }
    return 0;
}
