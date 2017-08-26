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
const int N=1007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,a[N],l,r,flag,cnt[N],c[N],j;
    cin>>t;
    while(t--)
    {
        flag=1;
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        memset(c,-1,sizeof(c));
        fr(i,0,n)
        {
            cin>>a[i];
            cnt[a[i]]++;
        }
        sort(a,a+n);
        j=1;
        fr(i,0,n)
        {
            if(cnt[a[i]]==2)
            {
                c[a[i]]=a[i];
                c[n-1-a[i]]=a[i];
                i++;
            }
            else if(cnt[a[i]]==1)
            {
                c[a[i]]=a[i];
            }
        }
        fr(i,0,n)
        {
            if(c[i]==-1)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
