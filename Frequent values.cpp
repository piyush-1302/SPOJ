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
ll segtree[4*N],prefix[N],start[3*N],cnt[3*N]={0};
void buildtree(ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=cnt[prefix[low]];
        return;
    }
    ll mid=(low+high)>>1;
    buildtree(low,mid,2*pos);
    buildtree(mid+1,high,2*pos+1);
    segtree[pos]=max(segtree[2*pos],segtree[2*pos+1]);
}
ll querry(ll ldx, ll hdx, ll low, ll high, ll pos)
{
    if(low>high || ldx>high || hdx<low)
        return -1;
    if(ldx<=low && hdx>=high)
        return segtree[pos];
    ll mid=(low+high)>>1;
    return max(querry(ldx,hdx,low,mid,2*pos),querry(ldx,hdx,mid+1,high,2*pos+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,q,a,b;
    while(true){
        cin>>n;
        if(n==0)
            break;
    cin>>q;
    memset(cnt,0,sizeof(cnt));
    memset(start,0,sizeof(start));
    ll x;
    start[0]=0;
    fr(i,1,n+1)
    {
        cin>>prefix[i];
        prefix[i]+=100000;
        cnt[prefix[i]]++;
        if(cnt[prefix[i]]==1)
            start[prefix[i]]=i;
    }
    buildtree(1,n,1);
    ll ans=0,k,temp1,temp2,temp3;
    ll na,nb;
    while(q--)
    {
        cin>>a>>b;
        if(start[prefix[a]]==start[prefix[b]])
            ans=b-a+1;
        else
        {
            na=cnt[prefix[a]]+start[prefix[a]]-a;
            nb=b-start[prefix[b]]+1;
            ans=max(na,nb);
            a+=na;
            b-=nb;
            if(a<=b)
                ans=max(ans,querry(a,b,1,n,1));
        }
        cout<<ans<<"\n";
    }
    }
    return 0;
}
