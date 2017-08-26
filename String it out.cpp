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
ll check(string a, string b, ll mid)
{
    ll i=0,j=0,k=0;
    ll len1=a.length();
    ll len2=b.length();
    while(i<len2 && j<len1)
    {
        if(k==mid)
        {
            k=0;
            j++;
        }
        if(a[j]==b[i])
        {
            i++;
            k++;
        }
        else
            i++;
    }
    if(j==len1)
        return 1;
    else
        return 0;
}
ll subseq(string a, string b)
{
    ll i,j;
    ll low,high,mid;
    ll len1=a.length();
    ll len2=b.length();
    high=len2/len1;
    low=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(check(a,b,mid))
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,i;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        cout<<subseq(s1,s2)<<"\n";
    }
    return 0;
}
