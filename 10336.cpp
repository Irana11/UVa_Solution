#include<stdio.h>
#include<algorithm>
using namespace std;
#define sz 10000

int m,n,i,j,k;
char ch[sz][sz],vis[sz][sz];
char c;
int cnt[125],ar[sz];

struct ss
{
    int cnt,value;
}arr[125];

bool cmp(ss aa,ss bb)
{
    if(aa.cnt==bb.cnt)
    return aa.value<bb.value;

    return aa.cnt>bb.cnt;
}

void dfs(int i,int j)
{
    if(i<0||j<0||i>=m||j>=n)
    return;
    if(ch[i][j]!=c||vis[i][j]!=0)
    return;
    vis[i][j]=1;

    dfs(i,j-1);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i+1,j);
}


int main()
{
    int i,j,t,cs,max;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%d%d",&m,&n);
        for(i=97;i<=122;i++)
        {
            arr[i].cnt=0;
            arr[i].value=i;
        }
        for(i=0;i<m;i++)
        {
            scanf("%s",ch[i]);
            for(j=0;j<n;j++)
           {
                vis[i][j]=0;
            }
        }
        printf("World #%d\n",cs);
        k=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                c=ch[i][j];
                if(vis[i][j]==0&&ch[i][j]==c)
                {
                    dfs(i,j);
                   // arr[c].value=c;
                    arr[c].cnt++;
                }
            }
        }
        sort(arr+97,arr+123,cmp);
        for(i=97;i<=122;i++)
        {
            if(arr[i].cnt>0)
            {
                printf("%c: %d\n",arr[i].value,arr[i].cnt);
            }
        }
    }
    return 0;
}
