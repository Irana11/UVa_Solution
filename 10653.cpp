#include<stdio.h>
#include<queue>
#define sz 1005
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int vis[sz][sz],cst[sz][sz];
int i,j,sx,sy,d1,d2,r,c,t,n;

int bfs(int x,int y)
{
   int i,j,ux,uy,vx,vy,flg=0;
   queue<int>q;
   q.push(sx);
   q.push(sy);
   cst[sx][sy]=0;
   while(q.empty()==0)
   {
       ux=q.front();
       q.pop();
       uy=q.front();
       q.pop();
       for(i=0;i<4;i++)
       {
           vx=ux+dx[i];
           vy=uy+dy[i];
           if(vx>=0&&vx<r&&vy>=0&&vy<c&&vis[vx][vy]!=1&&flg==0)
           {
               q.push(vx);
               q.push(vy);
               vis[vx][vy]=1;
               cst[vx][vy]=cst[ux][uy]+1;
               if(vx==d1&&vy==d2)
               flg=1;
           }
       }
   }
}
int main()
{
    while((scanf("%d%d",&r,&c))==2)
    {
        if(r==0&&c==0)
        break;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                vis[i][j]=0;
            }
        }
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&i,&n);
            while(n--)
            {
                scanf("%d",&j);
                vis[i][j]=1;
            }
        }
        scanf("%d%d%d%d",&sx,&sy,&d1,&d2);
        bfs(sx,sy);
        printf("%d\n",cst[d1][d2]);
    }
    return 0;
}

