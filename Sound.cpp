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
const int N=1000007;
int main()
{
    ios_base::sync_with_stdio(false);
    deque<ll>dmax;
    deque<ll>dmin;
    ll n,m,c,a[N],l,flag=0;
    cin>>n>>m>>c;
    fr(i,0,n)
        cin>>a[i];
    fr(i,0,m)
    {
        while(!dmax.empty() && dmax.back()<a[i])
            dmax.pop_back();
        dmax.push_back(a[i]);
        while(!dmin.empty() && dmin.back()>a[i])
            dmin.pop_back();
        dmin.push_back(a[i]);
    }
    l=0;
    fr(i,m,n)
    {
        if(dmax.front()-dmin.front()<=c)
        {
            flag=1;
            cout<<l+1<<"\n";
        }
        if(a[l]==dmax.front())
            dmax.pop_front();
        if(a[l]==dmin.front())
            dmin.pop_front();
        l++;
        while(!dmax.empty() && dmax.back()<a[i])
            dmax.pop_back();
        dmax.push_back(a[i]);
        while(!dmin.empty() && dmin.back()>a[i])
            dmin.pop_back();
        dmin.push_back(a[i]);
    }
    //cout<<pqmax.top()<<" "<<pqmin.top()<<"\n";
    if(dmax.front()-dmin.front()<=c)
    {
        flag=1;
        cout<<l+1<<"\n";
    }
    if(!flag)
        cout<<"NONE\n";
    return 0;
}
