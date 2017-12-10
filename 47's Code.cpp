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
void func(int a[],int pos,int k,int n)
{
    if(k<=0||pos>=n)
    return ;
    int maxNum=a[pos],maxPos=pos,i;
    for( i=pos+1;i<=pos+k&&i<n;i++)
    {
        if(a[i]>maxNum)
        {
            maxNum=a[i];
            maxPos=i;
        }
    }
    for(i=maxPos-1;i>=pos;i--)
    a[i+1]=a[i];
    a[pos]=maxNum;
    func(a,pos+1,k-(maxPos-pos),n);
}

int main()
{


    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        func(a,0,k,n);
        for(int i=0;i<n;i++)
        cout<<a[i];
        cout<<endl;
    }
    return 0;
}
