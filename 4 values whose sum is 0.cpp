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
const int N=2507;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,a[N],b[N],c[N],d[N],add1[4000*4000],add2[4000*4000],cnt=0,k,low,high,mid,l,flag=1,j;
    cin>>n;
    fr(i,0,n)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    k=0;
    fr(i,0,n)
    {
        fr(j,0,n)
        {
            add1[k]=a[j]+b[i];
            add2[k]=c[j]+d[i];
            k++;
        }
    }
    sort(add1,add1+k);
    fr(i,0,k)
    {
        low=0;
        high=k-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(add1[mid]+add2[i]==0)
            {
                cnt++;
                j=mid-1;
                l=mid+1;
                flag=1;
                while(j>=0 && add1[j]==-add2[i])
                {
                    cnt++;
                    j--;
                }
                while(l<=k-1 && add1[l]==-add2[i])
                {
                    cnt++;
                    l++;
                }
                break;
            }
            else if(add1[mid]+add2[i]>0)
                high=mid-1;
            else
                low=mid+1;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
