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
ll findLargestOddDivisor(ll n){
    while(n % 2 == 0){
        n >>= 1;
    }
    return n;
}

int main() {
    ll t, n, cas=0;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        printf("Case %lld: %lld\n", ++cas, findLargestOddDivisor(n));
    }
    return 0;
}
