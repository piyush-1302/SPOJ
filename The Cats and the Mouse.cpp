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
#include<tuple>
#include<set>
#include<limit>*/
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
const int N=507;
ll disc[N][N],dism[N][N];
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
ll n,m;
bool vis[N][N];
void bfsc(ll x1, ll y1)
{
    queue<pair<ll,ll> >q;
    q.push(mp(x1-1,y1-1));
    disc[x1-1][y1-1]=0;
    memset(vis,false,sizeof vis);
    while(!q.empty())
    {
        ll num1=q.front().ff;
        ll num2=q.front().ss;
        q.pop();
        if(vis[num1][num2]==false)
        {
            vis[num1][num2]=true;
            fr(i,0,4)
            {
                if(num1+x[i]>=0 && num1+x[i]<n && num2+y[i]>=0 && num2+y[i]<m && disc[num1+x[i]][num2+y[i]]>disc[num1][num2]+1)
                {
                    disc[num1+x[i]][num2+y[i]]=disc[num1][num2]+1;
                    q.push(mp(num1+x[i],num2+y[i]));
                }
            }
        }
    }
}
void bfsm(ll x1, ll y1)
{
    queue<pair<ll,ll> >q;
    q.push(mp(x1-1,y1-1));
    dism[x1-1][y1-1]=0;
    memset(vis,false,sizeof vis);
    while(!q.empty())
    {
        ll num1=q.front().ff;
        ll num2=q.front().ss;
        q.pop();
        if(vis[num1][num2]==false)
        {
            vis[num1][num2]=true;
            fr(i,0,4)
            {
                if(num1+x[i]>=0 && num1+x[i]<n && num2+y[i]>=0 && num2+y[i]<m && dism[num1+x[i]][num2+y[i]]>dism[num1][num2]+1)
                {
                    dism[num1+x[i]][num2+y[i]]=dism[num1][num2]+1;
                    q.push(mp(num1+x[i],num2+y[i]));
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,j,t,mx,my,cx1,cx2,cy1,cy2;
    cin>>n>>m;
    cin>>t;
    while(t--)
    {
        ll flag=0;
        cin>>mx>>my;
        cin>>cx1>>cy1>>cx2>>cy2;
        fr(i,0,N)
        {
            fr(j,0,N)
            {
                disc[i][j]=mod;
                dism[i][j]=mod;
            }
        }
        bfsc(cx1,cy1);
        bfsc(cx2,cy2);
        bfsm(mx,my);
        /*fr(i,0,n)
        {
            fr(j,0,m)
            {
                cout<<disc[i][j]<<"\t";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
        fr(i,0,n)
        {
            fr(j,0,m)
            {
                cout<<dism[i][j]<<"\t";
            }
            cout<<"\n";
        }*/
        fr(j,0,m)
        {
            if(dism[0][j]<disc[0][j] || dism[n-1][j]<disc[n-1][j])
            {
                flag=1;
                cout<<"YES\n";
                break;
            }
        }
        if(!flag)
        {
            fr(i,0,n)
            {
                //cout<<dism[i][0]<<"\t"<<disc[i][0]<<"\n"<<dism[i][m-1]<<"\t"<<disc[i][m-1]<<"\n\n";
                if(dism[i][0]<disc[i][0] || dism[i][m-1]<disc[i][m-1])
                {
                    flag=1;
                    cout<<"YES\n";
                    break;
                }
            }
        }
        if(!flag)
            cout<<"NO\n";
    }
    return 0;
}
