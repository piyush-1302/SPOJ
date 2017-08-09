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
vector<ll> vec1;
vector<ll> vec2;
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,j,k,a[N],b[N],ans,l,r,mid,n,s,c[N],m;
    ssi(n);
    fr(i,0,n)
    ssi(c[i]);
    fr(i,0,n)
    {
        fr(j,0,n)
        {
            fr(k,0,n)
            {
                vec1.pb(c[i]*c[j]+c[k]);
                if(c[k]!=0)
                {
                    vec2.pb((c[i]+c[j])*c[k]);
                }
            }
        }
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    fr(i,0,max(vec1.size(),vec2.size()))
    {
        r=upper_bound(vec2.begin(),vec2.end(),vec1[i])-vec2.begin();
        l=lower_bound(vec2.begin(),vec2.end(),vec1[i])-vec2.begin();
        ans+=(r-l);
    }
    cout<<ans<<"\n";
    return 0;
}
