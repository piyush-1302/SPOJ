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
const int N=107;
bool vis[N][N];
ll dis[N][N];
ll x[8]={2,2,1,-1,-2,-2,1,-1};
ll y[8]={1,-1,2,2,1,-1,-2,-2};
void bfs(ll a,ll b,ll c,ll d)
{
    ll i,j;
    queue<pair<ll,ll> >q;
    q.push(mp(a,b));
    dis[a][b]=0;
    vis[a][b]=true;
    while(!q.empty())
    {
       ll p1,p2,p,f,g;
       p1=q.front().ff;
       p2=q.front().ss;
       q.pop();
       //f=p1;
       //g=//p2;
       //cout<<"F  :"<<p1<<"\tG   :"<<p2<<"\n";
       fr(i,0,8)
       {
               //p1+=x[i];
               //p2+=y[i];
               //cout<<"P1 : "<<p1<<"\tP2 : "<<p2<<"\n";
               if(p1+x[i]<=8 && p1+x[i]>0 && p2+y[i]<=8 && p2+y[i]>0)
               {
                   if(vis[p1+x[i]][p2+y[i]]==false)
                   {
                       vis[p1+x[i]][p2+y[i]]=true;
                       dis[p1+x[i]][p2+y[i]]=dis[p1][p2]+1;
                       q.push(mp(p1+x[i],p2+y[i]));
                   }
               }
       }
    }
}
int main()
{
    ll t,x1,x2,y1,y2,i,j;
    ssi(t);
    string s,d;
    while(t--)
    {
        cin>>s>>d;
        x1=s[0]-96;
        x2=d[0]-96;
        y1=s[1]-'0';
        y2=d[1]-'0';
        //cout<<x1<<"\t"<<x2<<"\t"<<y1<<"\t"<<y2<<"\n";
        frn(i,0,8)
        {
            frn(j,0,8)
            {
                vis[i][j]=false;
                dis[i][j]=-1;
            }
        }
        bfs(x1,y1,x2,y2);
        printf("%lld\n",dis[x2][y2]);
    }
    return 0;
}
