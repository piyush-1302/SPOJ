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
const int N=1000007;
vector<ll> vec;
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,n,x,ans,cnt,k,pos;
    ssi(n);
    ssi(k);
    fr(i,0,n)
    {
        ssi(x);
        vec.pb(x);
    }
    sort(vec.begin(),vec.end());
    cnt=0;
    fr(i,0,n)
    {
        pos=lower_bound(vec.begin(),vec.end(),vec[i]+k)-vec.begin();
        if(vec[pos]==vec[i]+k)
            cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}

