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
ll a[257][257];
bool vis[257][257];
vector<ll>vec;
ll x[]={-1,1,0,0};
ll y[]={0,0,1,-1};
void bfs(ll x1,ll y1, ll n, ll m)
{
    ll x2,y2,i,cnt=0;
    queue<pii>q;
    q.push(pii(x1,y1));
    cnt++;
    while(!q.empty())
    {
        ll t,b;
        t=q.front().ff;
        b=q.front().ss;
        q.pop();
        vis[t][b]=true;
        fr(i,0,4)
        {
            x2=t+x[i];
            y2=b+y[i];
            if(x2<m && x2>=0 && y2<n && y2>=0 && vis[x2][y2]==false && a[x2][y2]==1)
            {
                vis[x2][y2]=true;
                q.push(pii(x2,y2));
                cnt++;
            }
        }
    }
    vec.pb(cnt);
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll m,n,i,j,cnt1,flag=1;
    while(flag)
    {
        cin>>n>>m;
        if(n==0 && m==0)
        {
            flag=0;
            return 0;
        }
        else
        {
            fr(i,0,n)
            {
                fr(j,0,m)
                {
                     cin>>a[i][j];
                }
            }
            memset(vis,false,sizeof(vis));
            fr(i,0,n)
            {
                fr(j,0,m)
                {
                    if(vis[i][j]==false && a[i][j]==1)
                        bfs(i,j,n,m);
                }
            }
            cout<<vec.size()<<"\n";
            sort(vec.begin(),vec.end());
            fr(i,0,vec.size())
            {
                cnt1=0;
                fr(j,i,vec.size())
                {
                    if(vec[i]==vec[j])
                    {
                        cnt1++;
                        i=j;
                    }
                    else
                    {
                        i=j-1;
                        break;
                    }
                }
                cout<<vec[i]<<" "<<cnt1<<"\n";
            }
            vec.clear();
        }
    }
    return 0;
}

