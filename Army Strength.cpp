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
    ll t,n1,n2,m1,m2,x;
    cin>>t;
    while(t--)
    {
        cin>>n1>>n2;
        m1=0;
        m2=0;
        fr(i,0,n1)
        {
            cin>>x;
            m1=max(x,m1);
        }
        fr(i,0,n2)
        {
            cin>>x;
            m2=max(x,m2);
        }
        if(m1>=m2)
            printf("Godzilla\n");
        else
            printf("MechaGodzilla\n");
    }
    return 0;
}
