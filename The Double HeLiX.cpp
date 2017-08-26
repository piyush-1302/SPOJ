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
const int N=10007;
ll a[N],b[N];
ll bs(ll x, ll n2)
{
    ll low=1,high=n2,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(b[mid]==a[x])
            return mid;
        else
        {
            if(b[mid]>a[x])
                high=mid-1;
            else
                low=mid+1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n1,n2,flag=1,ans,suma[N],sumb[N],preva,pos,prevb,cnt,tempa,tempb,lpos;
    while(flag)
    {
        cin>>n1;
        if(!n1)
        {
            flag=0;
            break;
        }
        else
        {
            ans=0;
            suma[0]=0;
            sumb[0]=0;
            fr(i,1,n1+1)
            {
                cin>>a[i];
                suma[i]=a[i]+suma[i-1];
            }
            //cout<<suma[n1]<<"\n";
            cin>>n2;
            fr(i,1,n2+1)
            {
                cin>>b[i];
                sumb[i]=b[i]+sumb[i-1];
            }
            //cout<<sumb[n2]<<"\n";
            preva=0;
            pos=0;
            prevb=0;
            cnt=0;
            lpos=0;
            fr(i,1,n1+1)
            {
                pos=bs(i,n2);
              //  cout<<pos<<"\n\n";
                if(pos)
                {
                //    cout<<"RANGE  A :  "<<i<<"\t"<<preva<<"\n";
                  //  cout<<"RANGE  B :  "<<pos<<"\t"<<prevb<<"\n";
                    tempa=suma[i]-suma[preva];
                    preva=i;
                    tempb=sumb[pos]-sumb[prevb];
                    prevb=pos;
                    //cout<<tempa<<"\t"<<tempb<<"\n";
                    ans+=max(tempb,tempa);
                    //cout<<" ANS   :   "<<ans<<"\n";
                    lpos=pos;
                }
                else
                    cnt++;
            }
           // cout<<"RANGE  A :  "<<n1<<"\t"<<preva<<"\n";
           // cout<<"RANGE  B :  "<<lpos<<"\t"<<prevb<<"\n";
            tempa=suma[n1]-suma[preva];
            tempb=sumb[n2]-sumb[lpos];
            ans+=max(tempa,tempb);
            if(cnt==n1)
                cout<<max(suma[n1],sumb[n2])<<"\n";
            else
                cout<<ans<<"\n";
        }
    }
    return 0;
}
