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
    ll n,ar[N],left,k;
    cin>>n;
    fr(i,1,n+1)
        cin>>ar[i];
    cin>>k;
    deque<ll>q;
    fr(i,1,k+1)
    {
        while(!q.empty() && q.back()<ar[i])
            q.pop_back();
        q.push_back(ar[i]);
    }
    left=2;
    //right=4;
    fr(i,k+1,n+1)
    {
        cout<<q.front()<<" ";
        if(ar[left-1]==q.front())
            q.pop_front();
        while(!q.empty() && q.back()<ar[i])
                q.pop_back();
        q.push_back(ar[i]);
        left++;
    }
    cout<<q.front()<<"\n";
    return 0;
}
