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
const int N=100007;
vector<pii>vec[N];
bool vis[N];
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,ans=0,flag=1,cnt=1;
    string s;
    while(flag)
    {
        ans=0;
        cin>>s;
        if(s[0]=='-')
            break;
        //cnt=0;
        stack<char> st;
        fr(i,0,s.length())
        {
            if(s[i]=='{')
                st.push(s[i]);
            else if(s[i]=='}' && !st.empty())
                st.pop();
            else if(s[i]=='}' && st.empty())
            {
                s[i]='{';
                st.push(s[i]);
                ans++;
            }
        }
        ans+=st.size()/2;
        cout<<cnt<<". "<<ans<<"\n";
        cnt++;
    }
    return 0;
}
