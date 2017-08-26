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
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,i,j,height[N],width[N],length[N],flag=1,ans,dp[N],a,b,c;
    while(flag)
    {
        cin>>n;
        if(n==0)
            return 0;
        else
        {
            for(i=0;i<n;i++)
            {
                cin>>a>>b>>c;

                length[3*i]=a;
                width[3*i]=b;
                height[3*i]=c;

                length[3*i+1]=b;
                width[3*i+1]=c;
                height[3*i+1]=a;

                length[3*i+2]=c;
                width[3*i+2]=a;
                height[3*i+2]=b;
            }
            for(i=0;i<3*n;i++)
            {
                for(j=i+1;j<3*n;j++)
                {
                    if((length[j]<length[i] && width[j]<width[i]) || (width[j]<length[i] && length[j]<width[i]))
                    {
                        swap(length[i],length[j]);
                        swap(width[i],width[j]);
                        swap(height[i],height[j]);
                    }
                }
            }
            ans=-1;
            for(i=0;i<3*n;i++)
                dp[i]=height[i];
            i=1;
            j=0;
            while(i<3*n)
            {
                j=0;
                while(j<i)
                {
                    if((length[j]<length[i] && width[j]<width[i]) || (width[j]<length[i] && length[j]<width[i]))
                        dp[i]=max(dp[i],dp[j]+height[i]);
                    ans=max(ans,dp[i]);
                    j++;
                }
                i++;
            }
        }
        cout<<ans<<"\n";
    }
}
