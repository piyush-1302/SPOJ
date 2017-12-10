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
const int N=300007;
struct node
{
    ll L,R,i;
}querry[N];
ll block=555,answer=0;
bool comp(node x, node y)
{
    if(x.L/block!=y.L/block)
        return x.L/block<y.L/block;
    else
        return x.R<y.R;
}
ll n,a[N],q,ans[N],cnt[1000007]={0};
void add(ll pos)
{
    cnt[a[pos]]++;
    if(cnt[a[pos]]==1)// && pos>0)
        answer++;
}
void rmv(ll pos)
{
    cnt[a[pos]]--;
    if(cnt[a[pos]]==0)// && pos>0)
        answer--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    //a[0]=0;
    fr(i,0,n)
        cin>>a[i];
    cin>>q;
    fr(i,0,q)
    {
        cin>>querry[i].L>>querry[i].R;
        querry[i].L--;
        querry[i].R--;
        querry[i].i=i;
    }
    sort(querry,querry+q,comp);
    ll currentL=0;
    ll currentR=0;
    fr(i,0,q)
    {
        ll L=querry[i].L;
        ll R=querry[i].R;
        while(currentL<L)
        {
            rmv(currentL);
            currentL++;
        }
        while(currentL>L)
        {
            add(currentL-1);
            currentL--;
        }
        while(currentR<=R)
        {
            add(currentR);
            currentR++;
        }
        while(currentR>R+1)
        {
            rmv(currentR-1);
            currentR--;
        }
        ans[querry[i].i]=answer;
    }
    fr(i,0,q)
        cout<<ans[i]<<"\n";
    return 0;
}
