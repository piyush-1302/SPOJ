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
ll a[200009];
ll ans=0;
void Merge(ll left_begin,ll left_end,ll right_begin,ll right_end)
{
    ll pos=0,pp=left_begin;
    ll temp[right_end-left_begin+3];
    while(left_begin<=left_end&&right_begin<=right_end)
    {
        if(a[left_begin]<=a[right_begin])
            temp[pos++]=a[left_begin++];
        else
        {
            ans=ans+(left_end-left_begin+1);
            temp[pos++]=a[right_begin++];
        }
    }
    while(left_begin<=left_end) temp[pos++]=a[left_begin++];
    while(right_begin<=right_end) temp[pos++]=a[right_begin++];
    for(ll i=0;i<pos;i++)
        a[pp+i]=temp[i];
    return;
}

void MergeSort(ll left,ll right)
{
    ll mid=(left+right)>>1;
    if(left<right)
    {
        MergeSort(left,mid);
        MergeSort(mid+1,right);
        Merge(left,mid,mid+1,right);
    }
}

int main()
{
    ll i,j,k,n,m,d,test,t=0;
    scanf("%lld",&test);
    while(test--)
    {
        ans=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        MergeSort(0,n-1);
        printf("%lld\n",ans);
        for(i=0;i<n;i++)
            printf("%lld   ",a[i]);
    }
    return 0;
}
