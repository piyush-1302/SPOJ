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
int main()
{
    ios_base::sync_with_stdio(false);
    unsigned long long t,n,k,cnt;
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>n>>k;
        if(k==1)
            cout<<"Male\n";
        else if(k==2)
            cout<<"Female\n";
        else
        {
            k--;
            while(k>1)
            {
                if(k%2!=0)
                    cnt++;
                k/=2;
            }
            if(cnt%2==0)
                cout<<"Female\n";
            else
                cout<<"Male\n";
        }
    }
    return 0;
}
