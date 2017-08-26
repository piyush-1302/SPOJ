#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t,n,x,y,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&x,&y);
        for(i=x;i<n;i++)
        {
            if(i%x==0 && i%y!=0)
            {
                printf("%lld",i);
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
