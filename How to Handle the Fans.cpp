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
const int N=1000007;
void buildtree(ll a[], ll segment[], ll low, ll high, ll pos)
{
    if(high==low)
    {
        segment[pos]=a[low];
        return;
    }
    ll mid=(low+high)/2;
    buildtree(a,segment,low,mid,2*pos);
    buildtree(a,segment,mid+1,high,2*pos+1);
    segment[pos]=segment[2*pos]+segment[2*pos+1];
}
void update(ll segment[], ll idx, ll val, ll low, ll high, ll pos)
{
    if(low==high)
    {
        segment[pos]+=val;
        return;
    }
    else{
    ll mid=(low+high)/2;
    if(idx>=low && idx<=mid)
        update(segment,idx,val,low,mid,2*pos);
    else
        update(segment,idx,val,mid+1,high,2*pos+1);
    segment[pos]=segment[2*pos]+segment[pos*2+1];
    }
}
ll querry(ll segment[], ll ldx, ll hdx, ll low, ll high, ll pos)
{
    if(ldx<=low && hdx>=high)
        return segment[pos];
    if(ldx>high || hdx<low)
        return 0;
    ll mid=(high+low)/2;
    return (querry(segment,ldx,hdx,low,mid,2*pos)+querry(segment,ldx,hdx,mid+1,high,2*pos+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,q,x,y,i,j;
    ll segment[4*N],a[N]={0};
    cin>>n>>q;
    string s;
    fr(i,0,n)
        a[i]=0;
    buildtree(a,segment,1,n,1);
    while(q--)
    {
        cin>>s>>x>>y;
        if(s[0]=='a')
            update(segment,x,y,1,n,1);
        else
            cout<<querry(segment,x,y,1,n,1)<<endl;
    }
    return 0;
}
