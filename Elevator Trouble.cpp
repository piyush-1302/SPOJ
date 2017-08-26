#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frn(i,a,b) for(ll i=a;i<=b;i++)
#define ssi(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
const int N=1000007;
bool vis[N];
ll f,s,g,u,d,dis[N];

void bfs(ll a)
{
    ll tempu=0,tempd=0,i,j;
    queue<ll>q;
    vis[a]=true;
    q.push(a);
    dis[a]=0;
    while(!q.empty())
    {
        ll num=q.front();
        q.pop();
        if(num<=f && num>=0)
        {
            tempu=num+u;
            tempd=num-d;
        }
        if(vis[tempu]==false && tempu<=f)
        {
            dis[tempu]=dis[num]+1;
            vis[tempu]=true;
            q.push(tempu);
        }
        if(vis[tempd]==false && tempd>=0)
        {
            vis[tempd]=true;
            dis[tempd]=dis[num]+1;
            q.push(tempd);
        }
    }
}
int main()
{
    ssi(f);
    ssi(s);
    ssi(g);
    ssi(u);
    ssi(d);
    ll i,j;
    memset(vis,false,sizeof vis);
    memset(dis,-1,sizeof dis);
    bfs(s);
    if(dis[g]==-1)
        printf("use the stairs\n");
    else
        printf("%lld\n",dis[g]);
    return 0;
}
