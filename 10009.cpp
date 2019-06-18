#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<queue>
#define sz 10002
using namespace std;
map<string,int>mp;
vector<int>vec[sz];
int vis[sz],p[sz],i,j,k,l,indx,m,n,u,v,t,source,dest,node;
char ch[sz],re[sz],c1[sz],c2[sz];

void bfs()
{
    queue<int>q;
    int u,v,i,l;
    vis[source]=1;
    q.push(source);
    while(q.empty()==0)
    {
        u=q.front();
        q.pop();
        l=vec[u].size();
        for(i=0;i<l;i++)
        {
            v=vec[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                q.push(v);
                p[v]=u;
            }
        }
    }
}
void save(int x)
{
    if(x==source)
    {
        re[indx]=ch[x];
        indx++;
        return;
    }
    save(p[x]);
    re[indx]=ch[x];
    indx++;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        getchar();
        node=1;
        while(m--)
        {
            scanf("%s%s",&c1,&c2);
            if(mp[c1]==0)
            {
                mp[c1]=node++;
                ch[node-1]=c1[0];
            }
            if(mp[c2]==0)
            {
                mp[c2]=node++;
                ch[node-1]=c2[0];
            }
            u=mp[c1];
            v=mp[c2];
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        while(n--)
        {
            for(i=0;i<node;i++)
            {
                vis[i]=0;
            }
            scanf("%s%s",c1,c2);
            source=mp[c1];
            dest=mp[c2];
            bfs();
            indx=0;
            save(dest);
            for(i=0;i<indx;i++)
            {
                printf("%c",re[i]);
            }
            printf("\n");
        }
        for(i=0;i<node;i++)
        {
            vec[i].clear();
        }
        mp.clear();
        if(t)
        {
            printf("\n");
        }
    }
    return 0;
}

