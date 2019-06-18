#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<string.h>
#define sz 210
using namespace std;

vector<int>vec[sz];
map<string,int>mp;
int vis[sz],cst[sz],i,j,k,l1,l2,u,v,t,l,node,cnt,s,d;
char ch[sz][15],st[100],*ptr,source[15],dest[15];

void bfs()
{
    int i,j,u,v,l;
    queue<int>q;
    q.push(s);
    cst[s]=0;
    while(q.empty()==0)
    {
        u=q.front();
        q.pop();
        l=vec[u].size();
        for(j=0; j<l; j++)
        {
            v=vec[u][j];
            if(vis[v]==0)
            {
                q.push(v);
                vis[v]=1;
                cst[v]=cst[u]+1;
            }
        }
    }
}
int main()
{
    int cs;
    scanf("%d",&t);
    gets(st);
    gets(st);
    for(cs=1; cs<=t; cs++)
    {
        node=1;
        i=0;
        while(gets(ch[i]))
        {
            if(ch[i][0]=='*')
                break;
            if(mp[ch[i]]==0)
            {
                mp[ch[i]]=node++;
            }
            i++;
        }
        for(i=0; i<node; i++)
        {
            l1=strlen(ch[i]);
            for(j=i+1; j<node; j++)
            {
                l2=strlen(ch[j]);
                if(l1==l2)
                {
                    cnt=0;
                    for(k=0; k<l1; k++)
                    {
                        if(ch[i][k]!=ch[j][k])
                            cnt++;
                    }
                    if(cnt==1)
                    {
                        u=mp[ch[i]];
                        v=mp[ch[j]];
                        vec[u].push_back(v);
                        vec[v].push_back(u);
                    }
                }
            }
        }
        while(gets(st))
        {
            if(strcmp(st,"")==0)
                break;
            ptr=strtok(st," ");
            strcpy(source,ptr);
            s=mp[source];
            ptr=strtok(NULL," ");
            strcpy(dest,ptr);
            d=mp[ptr];
            for(i=0; i<node; i++)
            {
                vis[i]=0;
            }
            bfs();
            printf("%s %s %d\n",source,dest,cst[d]);
        }
        for(i=0;i<node;i++)
        {
            vec[i].clear();
        }
        mp.clear();
        if(cs!=t)
        {
            printf("\n");
        }
    }

    return 0;
}

