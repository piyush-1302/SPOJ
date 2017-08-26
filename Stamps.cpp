#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
int main()
{
    ll n,i,a,b,j;
    cin>>n;
    for(j=1;j<=n;j++)
    {
        cin>>a>>b;
        ll c[1007]={0},sum=0,cnt;
        for(i=0;i<b;i++)
        {
            cin>>c[i];
            sum+=c[i];
        }
        sort(c,c+b);
        if(sum<a)
            cout<<"Scenario #"<<j<<":\n"<<"impossible"<<"\n\n";
        else if(sum==a)
            cout<<"Scenario #"<<j<<":\n"<<b<<"\n\n";
        else
        {
            sum=0;
            i=b-1;
            cnt=0;
            while(sum<a)
            {
                sum+=c[i];
                i--;
                cnt++;
            }
            cout<<"Scenario #"<<j<<":\n"<<cnt<<"\n\n";
        }
    }
    return 0;
}
