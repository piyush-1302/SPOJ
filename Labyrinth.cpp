#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define si(a) scanf("%d",&a)
#define ssi(a) scanf("%lld",&a)
char s[1007][1007];
bool vis[1007][1007];
ll dis[1007][1007]={0};
ll row,col,e,f;
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
void bfs(ll i,ll j)
{
    ll a,b,k;
    vis[i][j]=true;
    dis[i][j]=0;
    queue<pair<ll,ll> >q;
    q.push(mp(i,j));
    while(!q.empty())
    {
        a=q.front().ff;
        b=q.front().ss;
        q.pop();
        fr(k,0,4)
        {
            if(vis[x[k]+a][y[k]+b]==false && s[x[k]+a][y[k]+b]=='.')
            {
                vis[x[k]+a][y[k]+b]=true;
                dis[x[k]+a][y[k]+b]=dis[a][b]+1;
                q.push(mp((x[k]+a),(y[k]+b)));
            }
        }
    }
}

int main()
{
    int t;
    ll ans=0;
    si(t);
    while(t--)
    {
        ans=0;
        ssi(col);
        ssi(row);
        fr(i,0,row)
        {
            scanf("%s",&s[i]);
        }
        fr(i,0,row)
        {
            fr(j,0,col)
            {
                if(s[i][j]=='.')
                {
                    e=i;
                    f=j;
                    break;
                }
            }
        }
        memset(vis,false,sizeof vis);
        memset(dis,0,sizeof dis);
        bfs(e,f);
        fr(i,0,row)
        {
            fr(j,0,col)
            {
                if(dis[i][j]>ans)
                {
                    ans=dis[i][j];
                    e=i;
                    f=j;
                }
            }
        }
        memset(vis,false,sizeof vis);
        memset(dis,0,sizeof dis);
        bfs(e,f);
        ans=0;
        fr(i,0,row)
        {
            fr(j,0,col)
            {
                ans=max(ans,dis[i][j]);
            }
        }
        printf("Maximum rope length is %lld.\n",ans);
    }
    return 0;
}
