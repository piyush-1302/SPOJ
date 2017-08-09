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
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,ans,x,y,prev;
    cin>>t;
    while(t--)
    {
        vector<pii>vec;
        cin>>n;
        fr(i,0,n)
        {
            cin>>x>>y;
            vec.pb(pii(y,x));
        }
        sort(vec.begin(),vec.end());
        ans=1;
        prev=vec[0].ff;
        fr(i,1,n)
        {
            if(vec[i].ss>=prev)
            {
                ans++;
                prev=vec[i].ff;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
