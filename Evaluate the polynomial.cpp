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
    ll j=1;
    while(true)
    {
        ll n,a[N],k,x;
        cin>>n;
        if(n==-1)
            break;
        else
        {
            fr(i,0,n+1)
                cin>>a[i];
            cin>>k;
            cout<<"Case "<<j<<":\n";
            while(k--)
            {
                cin>>x;
                ll ans=0;
                ans=a[0]*x+a[1];
                fr(i,2,n+1)
                {
                    ans=ans*x+a[i];
                }
                cout<<ans<<"\n";
            }
            j++;
        }
    }
    return 0;
}
