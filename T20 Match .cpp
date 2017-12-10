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
    ll t,n,ans;
    cin>>t;
    while(t--)
    {
        ans=0;
        ll ar[N],k=1;
        ar[0]=0;
        string s1,s2;
        cin>>s1>>s2;
        n=s1.length();
        fr(i,0,n)
        {
            ll a=s1[i]-'A';
            ll b=s2[i]-'A';
            if(a!=b)
            {
                ar[k]=i;
                k++;
            }
            if(abs(a-b)<=13)
            {
                ans+=(abs(a-b));

            }
            else
            {
                ans+=(26-abs(a-b));
            }
        }
        fr(i,0,k)
        ar[i+k]=ar[i];
        ll j=k;
        ll l=k;
        ll t1=0,t2=0;
        ll mv1,mv2,m=1;
        ll temp=1000000007;
        while(m<k)
        {
            mv1=0;
            mv2=0;
            t1=n-ar[l-m];
            mv1+=2*t1;
            mv1+=ar[l-m+k-1];
            t2=ar[j+m];
            mv2+=2*t2;
            mv2+=(n-ar[j+m-k+1]);
            temp=min(temp,min(mv1,mv2));
            m++;
        }
        temp=min(temp,min(ar[k-1],n-ar[1]));
        cout<<ans+temp<<"\n";
    }
    return 0;
}
