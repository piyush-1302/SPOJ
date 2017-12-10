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
    ll n,x,curr,prev,next;
    stack<ll>st;
    cin>>n;
    ll flag,ans=0;
    fr(i,0,n)
    {
        cin>>x;
        flag=1;
        //cout<<x<<"   ";
        if(st.empty())
            st.push(x);
        else
        {
            while(flag)
            {
                //flag=0;
                if(x>st.top())
                {
                    //cout<<"Y1\n";
                    curr=st.top();
                    st.pop();
                    next=x;
                    if(st.empty())
                        prev=mod;
                    else
                        prev=st.top();
                    if(prev>next)
                    {
                        ans+=next;
                    }
                    else
                    {
                        ans+=prev;
                    }
                    if(st.empty())
                        break;
                }
                else
                    break;
            }
            st.push(x);
        }
        //cout<<ans<<"\n";
    }
    st.pop();
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    cout<<ans<<"\n";
    return 0;
}
