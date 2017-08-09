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
#include<limit>*/
using namespace std;
#define ll int
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
const int N=1007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,m,x,i,time;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        queue<pii>q;
        priority_queue<ll>pq;
        fr(i,0,n)
        {
            cin>>x;
            q.push(pii(x,i));
            pq.push(x);
        }
        time=0;
        while(!q.empty())
        {
            ll num1=q.front().ff;
            ll num2=q.front().ss;
            q.pop();
            if(num1!=pq.top())
            {
                q.push(pii(num1,num2));
            }
            else
            {
                time++;
                pq.pop();
                if(num2==m)
                    break;
            }
        }
        cout<<time<<"\n";
    }
    return 0;
}
