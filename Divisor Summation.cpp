#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t,i,n,cnt;
    scanf("%lld",&t);
    while(t--)
    {
        cnt=0;
        scanf("%lld",&n);
        if(n==1)
            printf("0\n");
        else
        {
            for(i=1;i<=sqrt(n);i++)
            {
                //cout<<"I===    "<<i<<"\n";
                if(n%i==0)
                {
                    if((n/i)==i)
                        cnt=cnt+i;
                    else
                        cnt=cnt+i+(n/i);
                    //cout<<cnt<<"\n";
                }
            }
            printf("%lld\n",cnt-n);
        }
    }
    return 0;
}
