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
const int N=1007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,t,p,a[N],i,j,k,flag,temp,sum;
    cin>>t;
    while(t--)
    {
        flag=0;
        cin>>n;
        fr(i,0,n)
        cin>>a[i];
        sort(a,a+n);
        cin>>p;
        for(i=0;i<n && flag==0;i++)
        for(j=0,k=n-1;j<k;)
        {
            sum=p-a[i];
            temp=a[j]+a[k];
            if(sum==temp && i!=j && i!=k)
            {
                flag=1;
                break;
            }
            else if(i==j)
            j++;
            else if(i==k)
            k--;
            else if(sum<temp)
            k--;
            else if(sum>temp)
            j++;
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
