#include<stdio.h>

int vis[60][60];
int cnt,i,h,w,j,k;
char ch[60][60];

void dfs(int i,int j)
{
   if(i<0||j<0||i>=h||j>=w)
   return;
   if(vis[i][j]==1||ch[i][j]=='#')
   return;
   if(ch[i+1][j]=='T'||ch[i-1][j]=='T'||ch[i][j+1]=='T'||ch[i][j-1]=='T')
   {
       if(ch[i][j]=='G')
       {
           vis[i][j]=1;
           cnt++;
       }
       return;
   }

   vis[i][j]=1;
   if(ch[i][j]=='G')
   {
       cnt++;
   }

   dfs(i,j+1);
   dfs(i,j-1);
   dfs(i+1,j);
   dfs(i-1,j);
}

int main()
{
    while((scanf("%d%d",&w,&h))==2)
    {
        getchar();
        for(i=0;i<h;i++)
        {
            gets(ch[i]);
            for(j=0;j<w;j++)
            {
                vis[i][j]=0;
            }
        }
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(ch[i][j]=='P')
                {
                    cnt=0;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
