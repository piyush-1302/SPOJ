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
ll vis[N][N];
ll ans=0,cnt=0;
char s[N][N];
ll n,m;
void bfs(ll i, ll j)
{
    //vis[i][j]=true;
    queue<pair<ll,ll> >q;
    q.push(mp(i,j));
    while(!q.empty())
    {
        ll fr=q.front().ff;
        ll bc=q.front().ss;
        q.pop();
        if(fr>=0 && fr<n && bc>=0 && bc<m)
        {
            if(vis[fr][bc]==0)
            {
                vis[fr][bc]=cnt;
                if(s[fr][bc]=='N')
                    q.push(mp(fr-1,bc));
                else if(s[fr][bc]=='W')
                    q.push(mp(fr,bc-1));
                else if(s[fr][bc]=='S')
                    q.push(mp(fr+1,bc));
                else
                    q.push(mp(fr,bc+1));
            }
            else
            {
                if(vis[fr][bc]==cnt)
                    return ;
                else
                {
                    ans--;
                    return ;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,j;
    cin>>n>>m;
    fr(i,0,n)
    cin>>s[i];
    fr(i,0,N)
    {
        fr(j,0,N)
        vis[i][j]=0;
    }
    fr(i,0,n)
    {
        fr(j,0,m)
        {
            if(vis[i][j]==0)
            {
                ans++;
                cnt++;
                //cout<<i<<"\t"<<j<<"\n";
                //cout<<ans<<"\n";
                bfs(i,j);

            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
