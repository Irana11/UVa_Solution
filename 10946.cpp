#include<stdio.h>
#include<algorithm>

using namespace std;
int m,n,i,j,k;
int vis[500][500];
char x;
char ch[500][500];

struct ss
{
    char c;
    int cnt;
}ar[2500];

bool cmp(ss aa,ss bb)
{
    if(aa.cnt==bb.cnt)
    return aa.c<bb.c;

    return aa.cnt>bb.cnt;
}
void dfs(int i,int j)
{
    if(i<0||j<0||i>=m||j>=n)
    return;
    if(vis[i][j]==1||ch[i][j]!=x)
    return;

    vis[i][j]=1;
    ar[k].cnt++;

    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i-1,j);
}

int main()
{
    int t;
    t=1;
    while((scanf("%d%d",&m,&n))==2)
    {
        if(m==0&&n==0)
        {
            break;
        }
        for(i=0;i<m;i++)
        {
            scanf("%s",ch[i]);
            for(j=0;j<n;j++)
            {
                vis[i][j]=0;
            }
        }
        printf("Problem %d:\n",t);
        t++;

        k=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                ar[k].cnt=0;
                if(ch[i][j]!='.'&&vis[i][j]==0)
                {
                    x=ch[i][j];
                    ar[k].c=x;
                    dfs(i,j);
                    k++;
                }
            }
        }
        sort(ar+0,ar+k,cmp);
        for(i=0;i<k;i++)
        {
            if(ar[i].cnt>0)
            {
                printf("%c %d\n",ar[i].c,ar[i].cnt);
            }
        }
    }
    return 0;
}
