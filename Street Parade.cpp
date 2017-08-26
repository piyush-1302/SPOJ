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
const int N=100007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,cnt,x,flag=1;
    while(flag)
    {
        queue<ll>q;
        stack<ll>s;
        cin>>n;
        if(n==0)
        {
            flag=0;
            break;
        }
        else
        {
            fr(i,0,n)
            {
                cin>>x;
                q.push(x);
            }
            cnt=1;
            while(!q.empty() || !s.empty())
            {
                if(!q.empty() && q.front()==cnt)
                {
                    cnt++;
                    q.pop();
                }
                else
                {
                    if(!s.empty() && s.top()==cnt)
                    {
                        cnt++;
                        s.pop();
                    }
                    else
                    {
                        if(!q.empty())
                        {
                            s.push(q.front());
                            q.pop();
                        }
                        else
                            break;
                    }
                }
            }
            if(cnt==n+1)
                cout<<"yes\n";
            else
                    cout<<"no\n";
        }
    }
    return 0;
}
