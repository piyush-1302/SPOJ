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
const int N=107;
vector<ll>vec1;
vector<ll>vec2;
ll ar[N];
ll n,a,b;
void sub1(ll start, ll no_of_ele)
{
    //cout<<"!  "<<(1<<no_of_ele)<<"\n\n";
    ll i,j,sum;
    for(i=0;i<(1<<no_of_ele);i++)
    {
        sum=0;
        for(j=0;j<no_of_ele;j++)
        {
            if(i & (1<<j))
                sum+=ar[j+start];
        }
        vec1.pb(sum);
    }
}
void sub2(ll start, ll no_of_ele)
{
    ll i,j,sum;
    //cout<<(1<<no_of_ele)<<"\n";
    for(i=0;i<(1<<no_of_ele);i++)
    {
        sum=0;
        for(j=0;j<no_of_ele;j++)
        {
            if(i&(1<<j))
                sum+=ar[j+start];
        }
        vec2.pb(sum);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>a>>b;
    fr(i,0,n)
    {
        cin>>ar[i];
    }
    sub1(0,n/2);
    sub2(n/2,n-n/2);
    sort(vec2.begin(),vec2.end());
    ll ans=0;
   /* fr(i,0,vec1.size())
        cout<<vec1[i]<<"   ";
    cout<<endl;
    fr(i,0,vec2.size())
        cout<<vec2[i]<<"   ";
    cout<<endl;*/
    fr(i,0,vec1.size())
    {
        ll pos1=lower_bound(vec2.begin(),vec2.end(),a-vec1[i])-vec2.begin();
        ll pos2=upper_bound(vec2.begin(),vec2.end(),b-vec1[i])-vec2.begin();
        ans+=(pos2-pos1);
    }
    cout<<ans<<"\n";
    return 0;
}
