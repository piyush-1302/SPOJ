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
ll rec(string s, ll position, ll prevsum)
{
    ll i,sum=0,ans=0;
    if(position==s.length())
        return 1;
    fr(i,position,s.length())
    {
        sum+=(s[i]-'0');
        //cout<<sum<<" ";
        if(sum>=prevsum)
            ans+=rec(s,i+1,sum);
        //cout<<ans<<"\n";
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll flag=1,cas=1;
    while(flag)
    {
        string s;
        cin>>s;
        if(s=="bye")
            break;
        else
        {
            cout<<cas<<". "<<rec(s,0,0)<<"\n";
            cas++;
        }
    }
    return 0;
}
