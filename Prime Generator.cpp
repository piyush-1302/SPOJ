#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//ll pr[100000007];
bool pr[1000000007];
void sieve()
{
    memset(pr,false,sizeof pr);
    ll i,j;
    pr[0]=true;
    pr[1]=true;
    for(i=2;i*i<1000000001;i++)
    {
        if(pr[i]==false)
        {
            for(j=2*i;j<1000000001;j+=i)
            {
                pr[j]=true;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    sieve();
    while(t--)
    {
        ll m,n,i;
        cin>>m>>n;
        for(i=m;i<=n;i++)
        {
            if(pr[i]==false)
                cout<<i<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
