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
char arr[10000000+10];
ll f[28] ;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while( scanf("%s",&arr)==1 )
    {
        ll len = strlen(arr);
        ll ans = len*len ;

        memset(f,0,sizeof(f));
        for(int i=0;i<len;i++) f[arr[i]-'a']++;

        for(int i=1;i<len;i++)
        {
            ll s = f[arr[i]-'a'] ;
            if(arr[i]==arr[len-1]) s--;
            ans-=s;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
