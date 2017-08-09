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
bool fermats(ll n)
{
    ll cnt=0;
    if(n==0)
        return false;
    frn(i,2,sqrt(n)+1)
    {
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                cnt++;
                n/=i;
            }
            if(i==3 || (i-3)%4==0)
            {
                if(cnt%2!=0)
                    return false;
            }
        }
    }
    if(n>1 && (n==3|| (n-3)%4==0))
        return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n;
    cin>>t;
    while(t--)
    {
        bool ans;
        cin>>n;
        ans=fermats(n);
        if(ans)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
