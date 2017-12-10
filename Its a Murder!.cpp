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
ll a[N],ans=0;
void merged(ll lowstart, ll lowend, ll highstart, ll highend)
{
   // cout<<lowstart<<"\t"<<highstart<<"\t"<<highend<<"\t";
    ll pos=0,temp[N],p=lowstart;
    while(lowstart<=lowend && highstart<=highend)
    {
        if(a[lowstart]>=a[highstart])
        {
            temp[pos]=a[highstart];
            pos++;
            highstart++;
        }
        else
        {
            ans+=(highend-highstart+1)*a[lowstart];
            temp[pos]=a[lowstart];
            pos++;
            lowstart++;
        }
    }
    while(lowstart<=lowend)
    {
        temp[pos]=a[lowstart];
        lowstart++;
        pos++;
    }
    while(highstart<=highend)
    {
        temp[pos]=a[highstart];
        pos++;
        highstart++;
    }
    fr(i,0,pos)
    {
        a[p+i]=temp[i];
    }
    //cout<<ans<<"\n\n";
    return;
}
void mergesort(ll low, ll high)
{
    if(low<high)
    {
        ll mid=(low+high)>>1;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merged(low,mid,mid+1,high);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        fr(i,0,n)
        cin>>a[i];
        ans=0;
        mergesort(0,n-1);
        cout<<ans<<"\n";
    }
    return 0;
}
