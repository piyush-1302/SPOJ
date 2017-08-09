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
#define ll int
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
const int N=1007;
int main()
{
    ios_base::sync_with_stdio(false);
    double prob;
    ll x,y,n,m,i,j,k;
    cin>>n;
    while(n)
    {
        cin>>m;
        double ans[N][N];
        memset(ans,0,sizeof ans);
        fr(i,0,m)
        {
            cin>>x>>y>>prob;
            ans[x][y]=prob/100.0;
            ans[y][x]=prob/100.0;
        }
        frn(i,1,n)
        {
            frn(j,1,n)
            {
                frn(k,1,n)
                    ans[j][k]=max(ans[j][k],ans[j][i]*ans[i][k]);
            }
        }
        cout<<setprecision(10);
        cout<<ans[1][n]*100.0+1e-10<<" percent\n";
        cin>>n;
    }
    return 0;
}

