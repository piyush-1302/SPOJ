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
#define pii pair<ll,ll>
#define psi pair<string,ll>
const int N=10007;
map<string,ll>ma;
vector<pii> vec2[N];
map<string,ll> :: iterator it;

int main()
{
    ios_base::sync_with_stdio(false);
    ll n,s,x,y,i,j,p,nr,cost,r,cnt,start,des,ans;
    ll a,b,dis[N],f[N],c,d;
    string name,name1,name2;
    ssi(s);
    ll temp;
    while(s--)
    {
        ssi(n);
        cnt=1;
        temp=n;
        while(n--)
        {
            cin>>name;
            ma.insert(psi(name,cnt));
            ssi(p);
            while(p--)
            {
                ssi(nr);
                ssi(cost);
                vec2[cnt].pb(pii(nr,cost));
            }
            cnt++;
        }
        ssi(r);
        while(r--)
        {
            cin>>name1;
            cin>>name2;
            it=ma.find(name1);
            start=(*it).ss;
            it=ma.find(name2);
            des=(*it).ss;
            priority_queue< pii, vector< pii >, greater< pii > > q;
            q.push(pii(0,start));
            n=temp;
            //cout<<n<<"\n";
            frn(j,1,n)
            {
                dis[j]=10000000;
                f[j]=0;
               // cout<<dis[j]<<"\t";
            }
            dis[start]=0;
            while(!q.empty())
            {
                b=q.top().ff;
                a=q.top().ss;
                q.pop();
                if(f[a])
                    continue;
                fr(i,0,vec2[a].size())
                {
                    //cout<<"YES\n";
                    c=vec2[a][i].ff;
                    d=vec2[a][i].ss;
                    //cout<<"C  "<<c<<"\n";
                    //cout<<dis[a]+d<<"\t"<<dis[c]<<"\n";
                    if(dis[c]>dis[a]+d && !f[c])
                    {
                        //cout<<"NO\n";
                        dis[c]=dis[a]+d;
                        q.push(pii(dis[c],c));
                    }
                }
                f[a]=1;
                if(a==des)
                {
                    cout<<dis[des]<<"\n";
                    break;
                }
            }
        }
        frn(i,1,n)
        {
            vec2[i].clear();
        }
        ma.clear();
    }
    return 0;
}
