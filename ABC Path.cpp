#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frn(i,a,b) for(ll i=a;i<=b;i++)
#define frb(i,a,b) for(ll i=a;i>=b;i--)
#define ssi(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
const int N=57;
ll dis[N][N];
bool vis[N][N];
char a[N][N];
ll x[8]={-1,-1,-1,0,1,1,1,0};
ll y[8]={-1,0,1,1,1,0,-1,-1};
ll h,w,ans1;

void bfs(ll m, ll n)
{
    vis[m][n]=true;
    dis[m][n]=1;
    queue<pair<ll,ll> >q;
    q.push(mp(m,n));
    ll c,b,i,j;
    while(!q.empty())
    {
        b=q.front().ff;
        c=q.front().ss;
        q.pop();
        fr(i,0,8)
        {
           if(a[b+x[i]][c+y[i]]==a[b][c]+1 && vis[b+x[i]][c+y[i]]==false && (b+x[i])>=0 && (b+x[i])<h && (c+y[i])>=0 && (c+y[i])<w)
            {
                vis[b+x[i]][c+y[i]]=true;
                dis[b+x[i]][c+y[i]]=dis[b][c]+1;
                ans1=max(ans1,dis[b+x[i]][c+y[i]]);
                q.push(mp(b+x[i],c+y[i]));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll i,j,n,m,ans,t=1;
    ssi(h);
    ssi(w);
    while(h!=0 || w!=0)
    {
        if(h==0 && w==0)
            break;
        else
        {
           fr(i,0,h)
           {
                scanf("%s",&a[i]);
           }
           ans=0;
           memset(vis,false,sizeof vis);
           memset(dis,0,sizeof dis);
           fr(i,0,h)
           {
               fr(j,0,w)
               {
               		ans1=0;
                   if(a[i][j]=='A' && dis[i][j]==0)
                   {
                       m=i;
                       n=j;
                       memset(vis,false,sizeof vis);
                       memset(dis,0,sizeof dis);
                       ans1=0;
                       bfs(m,n);
                       //cout<<ans1<<"\n";
                       ans=max(ans,ans1);
                   }
               }
           }
           cout<<"Case "<<t<<": "<<ans<<"\n";
           t++;
           ssi(h);
           ssi(w);
        }
    }
    return 0;
}
