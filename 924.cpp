#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int>vec[2501];
int vis[2501],cst[2501],cnt[2501],i,j,k,mx,t,n,e,s,d;
 void bfs()
 {
     int i,j,l,u,v;
     queue<int>q;
     q.push(s);
     cst[s]=0;
     vis[s]=1;
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
                 cst[v]=cst[u]+1;
                 q.push(v);
                 vis[v]=1;
                 cnt[cst[v]]++;
             }
         }
     }
 }
 int main()
 {
     while(scanf("%d",&e)==1)
     {
         for(i=0;i<e;i++)
         {
             scanf("%d",&n);
             while(n--)
             {
                 scanf("%d",&j);
                 vec[i].push_back(j);
             }
         }
         scanf("%d",&t);
         while(t--)
         {
             scanf("%d",&s);
             mx=0;
             for(i=0;i<e;i++)
             {
                  cnt[i]=0;
                  vis[i]=0;
             }
             bfs();
             i=1;
             while(cnt[i]!=0&&i<e)
             {
                 if(cnt[i]>mx)
                 {
                     mx=cnt[i];
                     d=i;
                 }
                 i++;
             }
             if(mx!=0)
             {
                printf("%d %d\n",mx,d);
             }
             else
             {
                printf("%d\n",mx);
             }
          }
     }
     return 0;
 }
