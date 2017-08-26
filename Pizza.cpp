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
    ll n,i,ans=1,half=0,quarter=0,tquarter=0;
    cin>>n;
    string s;
    fr(i,0,n)
    {
        cin>>s;
        if(s[0]=='1' && s[2]=='4')
            quarter++;
        else if(s[0]=='1' && s[2]=='2')
            half++;
        else
            tquarter++;
    }
    if(quarter>=tquarter)
    {
        quarter-=tquarter;
        ans+=tquarter;
    }
    else if(quarter<tquarter)
    {
        quarter=0;
        ans+=tquarter;
    }
    if(half%2!=0)
    {
        ans+=(1+half/2);
        quarter-=2;
    }
    else
        ans+=half/2;
    if(quarter%4!=0 && quarter>0)
        ans+=(1+quarter/4);
    else if(quarter%4==0 && quarter>0)
        ans+=quarter/4;
    cout<<ans<<"\n";
    return 0;
}
