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
const int N=2007;
vector<pair<ll,ll> >vec;
int main()
{
    ios_base::sync_with_stdio(false);
    ll x,a[N][N]={0},y,i,j,n,s;
    ssi(s);
    ssi(n);
    fr(i,0,n)
    {
        ssi(x);
        ssi(y);
        vec.pb(mp(y,x));
    }
    sort(vec.begin(),vec.end());
    frn(i,1,n)
    {
        frn(j,1,s)
        {
            if(j<vec[i].ss)
                a[i][j]=a[i-1][j];
            else
                a[i][j]=max(vec[i].ff+a[i-1][j-vec[i].ss],a[i-1][j]);
        }
    }
    cout<<a[n][s]<<"\n";
    return 0;
}
