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
ll v[N],n,ans[N][N];
ll dyn(ll j, ll k, ll day)
{
    if(j>k)
        return 0;
    else if(ans[j][k]!=-1)
        return ans[j][k];
    else
    {
        return (ans[j][k]=max(dyn(j+1,k,day+1)+day*v[j],dyn(j,k-1,day+1)+day*v[k]));
        //return ans[j][k];
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,ans1;
    cin>>n;
    fr(i,0,n)
    cin>>v[i];
    memset(ans,-1,sizeof ans);
    ans1=dyn(0,n-1,1);
    cout<<ans1<<"\n";
    return 0;
}
