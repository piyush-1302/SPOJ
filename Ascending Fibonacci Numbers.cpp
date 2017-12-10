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
const int N=1100007;
ll ar[N];
ll fib(ll x)
{
    if(x==1)
        return 0;
    else if(ar[x]!=0)
        return ar[x];
    else
    {
        ar[x]=(fib(x-1)+fib(x-2))%100000;
        return ar[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    memset(ar,0,sizeof(ar));
    ar[1]=0;
    ar[2]=1;
    fib(1100001);
    cin>>t;
    fr(k,1,t+1)
    {
        ll a,b;
        cin>>a>>b;
        cout<<"Case "<<k<<": ";
        priority_queue<ll>pq;
        frn(i,a,a+b)
        {
        	pq.push(-1*ar[i]);
        }
        ll cnt=0;
        ll sz=pq.size();
        ll req=min((ll)100,sz);
        while(cnt<req)
        {
        	cnt++;
        	ll p=pq.top();
        	pq.pop();
        	cout<<-1*p;
        	if(pq.size()>=1)
        	   cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
