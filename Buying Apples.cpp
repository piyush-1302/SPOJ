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
#include<tuple>
#include<set>
#include<limit>*/
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
const int N=507;
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,j,ans[N],k,n,t,a[N];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        frn(i,0,n)
            ans[i]=-1;
        frn(i,1,k)
        {
            cin>>a[i];
            ans[i]=a[i];
        }
        frn(i,2,k)
        {
            frn(j,1,i)
            {
                if(a[i-j]==-1 || ans[j]==-1)
                    continue;
                if(ans[i]==-1)
                    ans[i]=a[i-j]+ans[j];
                else
                    ans[i]=min(ans[i],ans[j]+a[i-j]);
            }
        }
        cout<<ans[k]<<"\n";
    }
    return 0;
}
