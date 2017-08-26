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
const int N=100007;
struct cistern
{
    ll height;
    ll length;
    ll width;
    ll base;
};
vector<cistern>vec;
vector<cistern>::iterator it;
bool check(ll n, long double vol, long double current)
{
    long double volume=0.0;
    for(it=vec.begin();it!=vec.end(); ++it)
    {
        if((*it).height+(*it).base<=current)
            volume+=(((*it).height)*((*it).width)*((*it).length));
        else if((*it).height+(*it).base>current && (*it).base<=current)
            volume+=((current-(*it).base)*((*it).width)*((*it).length));
        if(volume>=vol)
            return true;
    }
    return false;
}
long double bs(ll n, long double vol)
{
    long double lowlevel,highlevel,presentlevel;
    lowlevel=0.0;
    highlevel=1e7;
    while(highlevel-lowlevel>0.000001)
    {
        presentlevel=(lowlevel+highlevel)/2;
        if(check(n,vol,presentlevel))
            highlevel=presentlevel;
        else
            lowlevel=presentlevel;
    }
    return presentlevel;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n;
    long double volume,vol,ans;
    cin>>t;
    cistern cis;
    while(t--)
    {
        cin>>n;
        volume=0.0;
        fr(i,0,n)
        {
            cin>>cis.base>>cis.height>>cis.width>>cis.length;
            volume+=(cis.height*cis.width*cis.length);
            vec.pb(cis);
        }
        cin>>vol;
        if(vol>volume)
            cout<<"OVERFLOW\n";
        else
        {
           // sort(vec.begin(),vec.end());
            ans=bs(n,vol);
            cout<<fixed<<setprecision(2);
            cout<<ans<<"\n";
        }
        vec.erase(vec.begin(),vec.end());
    }
    return 0;
}
