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
#define mod 1000000009
#define pii pair<ll,ll>
const int N=50007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,i,ans,cnt,zcnt;
    cin>>t;
    while(t--)
    {
        ll a[N];
        ans=0;
        zcnt=0;
        cin>>n;
        fr(i,0,n)
        {
            cin>>a[i];
            if(a[i]==0)
                zcnt++;
            else if(a[i]>0)
                ans+=a[i];
        }
        sort(a,a+n);
        if(a[n-1]<0)
        {
            cnt=1;
            frb(i,n-2,0)
            {
                if(a[i]==a[i+1])
                    cnt++;
                else
                    break;
            }
            ans=a[n-1];
        }
        else if(a[n-1]==0)
        {
            cnt=1;
            fr(i,0,zcnt)
            {
                cnt=(cnt*2)%mod;
            }
            ans=a[n-1];
            cnt-=1;
        }
        else
        {
            cnt=1;
            fr(i,0,zcnt)
            {
                cnt=(cnt*2)%mod;
            }
        }
        cout<<ans<<" "<<(cnt+mod)%mod<<"\n";
        cout<<n<<"\n";
    }
    return 0;
}
