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
//const int N=100007;
int N, M;
int dp[201][201][2];
char grid[201][201];

int maximize(int x, int y, int dir){
    //printf("%d %d %d\n",x,y,dir);
    if (x>=M||y>=N||x<0||y<0)
        return 0;
    if (grid[x][y]=='#')
        return 0;
    if (dp[x][y][dir]!=-1)
        return dp[x][y][dir];
    //dp[x][y][dir] = 0;
    return dp[x][y][dir] = (grid[x][y]=='T'?1:0)+max(maximize(x+1,y,(dir+1)%2), maximize(x,y+(dir==0?1:-1),dir));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &M, &N);
        for (int i=0;i<M;i++)
            scanf("%s", grid[i]);
        memset(dp, -1, sizeof dp);
        printf("%d\n", maximize(0,0,0));
    }
}
