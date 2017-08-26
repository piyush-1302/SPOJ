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
bool check(ll a[], ll mid, ll f1, ll f2)
{
    if(f1+f2>=a[mid] && a[mid]+f1>=f2 && f2+a[mid]>=f1)
        return false;
    else
        return true;
}
ll bs(ll a[], ll k, ll n, ll f1, ll f2)
{
    ll mid,low,high;
    low=k;
    high=n-1;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(check(a,mid,f1,f2))
            high=mid-1;
        else
            low=mid+1;
    }
    return (n-low);
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,a[N],ans,i;
    while(true)
    {
        ans=0;
        cin>>n;
        if(n==0)
            break;
        fr(i,0,n)
            cin>>a[i];
        sort(a,a+n);
        fr(i,0,n-2)
        {
            fr(j,i+1,n-1)
            {
                ans+=bs(a,j+1,n,a[i],a[j]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
