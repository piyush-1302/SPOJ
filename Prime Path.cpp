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
const int N=10007;
bool vis[N],prime[N];
ll a,b,dis[N],ar[4];

void sieve()
{
    ll i,j;
    memset(prime, false, sizeof(prime));
    frn(i,2,101)
    {
        if(prime[i]==false)
        {
            for(j=i*i;j<=10002;j+=i)
                prime[j]=true;
        }
    }
}
void numarr(ll ar[],ll num)
{
    ll i=3;
    while(num)
    {
        ar[i]=num%10;
        i--;
        num/=10;
    }
}
int numform(ll i,ll j)
{
    ll temp;
    if(j==0)
        temp=i*1000+ar[1]*100+ar[2]*10+ar[3];
    else if(j==1)
        temp=ar[0]*1000+i*100+ar[2]*10+ar[3];
    else if(j==2)
        temp=ar[0]*1000+ar[1]*100+i*10+ar[3];
    else
        temp=ar[0]*1000+ar[1]*100+ar[2]*10+i;
    return temp;
}
void bfs(ll x,ll y)
{
    ll num,i,j,temp;
    queue<ll>q;
    q.push(a);
    dis[a]=0;
    vis[a]=true;
    while(!q.empty())
    {
       num=q.front();
       q.pop();
      frn(j,0,3)
       {
           numarr(ar,num);
           frn(i,0,9)
           {
               temp=numform(i,j);
               //cout<<"TEMP   "<<temp<<"\n";
               if(prime[temp]==false && temp>=1000 && dis[temp]==-1 && vis[temp]==false && temp!=num)
               {
                   //if(temp==8179)
                    //cout<<"NNUM   "<<num;
                   vis[temp]=true;
                   dis[temp]=dis[num]+1;
                   q.push(temp);
               }
           }
       }
    }
}
int main()
{
    ll t;
    sieve();
    ssi(t);
    while(t--)
    {
        ssi(a);
        ssi(b);
        memset(vis,false,sizeof vis);
        memset(dis,-1,sizeof dis);
        if(a==b)
            printf("0\n");
        else
        {
            bfs(a,b);
            if(dis[b]==-1)
                printf("Impossible\n");
            else
                printf("%lld\n",dis[b]);
        }
    }
    return 0;
}
