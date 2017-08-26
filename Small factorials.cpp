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
    ll t,n,carry,temp,j;
    cin>>t;
    while(t--)
    {
        ll k,cnt;
        ll vec[20000];
        vec[0]=1;
        cnt=1;
        cin>>n;
        fr(i,2,n+1)
        {
            k=0;
            carry=0;
            //cout<<i<<"  "<<cnt<<"\n";
            fr(j,0,cnt)
            {
                temp=vec[j]*i+carry;
                vec[k]=temp%10;
                carry=temp/10;
                k++;
            }
            while(carry)
            {
                vec[k]=carry%10;
                k++;
                carry/=10;
            }
            cnt=k;
        }
        //cout<<cnt<<"\n";
        frb(i,cnt-1,0)
            cout<<vec[i];
        cout<<"\n";
    }
    return 0;
}
