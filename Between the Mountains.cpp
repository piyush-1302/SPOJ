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
#define ll int
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
const int N=1007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n1,n2,i,ans,x,pos;
    cin>>t;
    while(t--)
    {
        vector<ll> vec;
        ans=1000000007;
        ll ar[N];
        cin>>n1;
        fr(i,0,n1)
        {
            cin>>x;
            vec.pb(x);
        }
        sort(vec.begin(),vec.end());
        cin>>n2;
        fr(i,0,n2)
            cin>>ar[i];
        fr(i,0,n2)
        {
            pos=lower_bound(vec.begin(),vec.end(),ar[i])-vec.begin();
           // cout<<pos<<"\t";
            if(pos==0)
                ans=min(ans,abs(vec[0]-ar[i]));
            else if(pos==n1-1)
                ans=min(ans,min(abs(vec[pos-1]-ar[i]),abs(vec[pos]-ar[i])));
            else if(pos==n1)
                ans=min(ans,abs(vec[pos-1]-ar[i]));
            else
                ans=min(ans,min(abs(vec[pos]-ar[i]),min(abs(vec[pos-1]-ar[i]),abs(vec[pos+1]-ar[i]))));
            //cout<<ans<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
