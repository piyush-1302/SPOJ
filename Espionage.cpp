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
    ll t,n,r,x,y,c;
    cin>>t;
    c=1;
    while(t--)
    {
        cin>>n>>r;
        ll a[N]={0},b[N]={0};
        while(r--)
        {
            cin>>x>>y;
            a[x]++;
            b[y]++;
        }
        ll flag=1;
        fr(i,1,n+1)
        {
            if(a[i]>0 && b[i]>0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"Scenario #"<<c<<": spying\n";
        else
            cout<<"Scenario #"<<c<<": spied\n";
        c++;
    }
    return 0;
}
