#include<bits/stdc++.h>
using namespace std;
vector<int >adj[20001];
bool vis[20001];
void dfs(int pos)
{
    vis[pos]=true;
    for(int j=0;j<adj[pos].size();j++)
    {
        if(vis[adj[pos][j]]==false)
            dfs(adj[pos][j]);
    }
}
int main()
{
    int n,m,x,y,i,flag=0,cnt=0;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(i=0;i<=n+1;i++)
        vis[i]=false;
    for(i=1;i<=n;i++)
    {
        if(vis[i]==false && i>1) // for checking any disconnection in the graph
            cnt=1;
        cout<<vis[i]<<"\t"<<i<<"\n";
        if(vis[i]==false)
            dfs(i);
        if(adj[i].size()==0) // for checking the isolation of any node
            flag=1;
    }
    if(flag==0 && cnt==0 && n-1==m)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
