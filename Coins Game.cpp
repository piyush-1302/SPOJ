/*#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<math>
#include<set>
#include<iterator>*/
#include<bits/stdc++.h>
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
const int N=1000007;
bool ans[N];
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,l,k,x,m;
    cin>>k>>l>>m;
    memset(ans,false,sizeof ans);
    ans[0]=false;
    ans[1]=true;
    frn(i,2,N)
    {
        if(i==k || i==l)
            ans[i]=true;
        else if(i<k)
        {
            if(ans[i-1]!=false)
                ans[i]=false;
            else
                ans[i]=true;
        }
        else if(i>k && i<l)
        {
            if(ans[i-1]!=false && ans[i-k]!=false)
                ans[i]=false;
            else
                ans[i]=true;
        }
        else
        {
            if(ans[i-1]!=false && ans[i-k]!=false && ans[i-l]!=false)
                ans[i]=false;
            else
                ans[i]=true;
        }
    }
    fr(i,0,m)
    {
        cin>>x;
        if(ans[x])
            cout<<"A";
        else
            cout<<"B";
    }
    cout<<"\n";
    return 0;
}
