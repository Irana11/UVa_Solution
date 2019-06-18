
#include<stdio.h>
#include<string.h>
#define sz 105
int a,b,i,j,t,cs,cnt,m,n,l;
char ch[sz][sz],c1;
char c[sz][sz];

void dfs(int i,int j)
{
    if(i<0||j<0||i>=m||j>=n)
    return;
    if(c[i][j]=='L')
    return;

    cnt++;
    c[i][j]='L';

    dfs(i,j-1);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i-1,j-1);
    dfs(i-1,j+1);
    dfs(i+1,j);
    dfs(i+1,j-1);
    dfs(i+1,j+1);
}

int main()
{
    int f1,f2;


    scanf("%d",&t);

    getchar();
    getchar();
    for(cs=1; cs<=t; cs++)
    {
        i=0;
        f1=0;

        while(gets(ch[i]))
        {
            if(strcmp(ch[i],"")==0)
            break;
            if(ch[i][0]>=48&&ch[i][0]<=57)
            {
                if(f1==0)
                {
                    m=i;
                    n=strlen(ch[i-1]);
                    f1=1;
                }
                for(j=0;j<m;j++)
                {
                    strcpy(c[j],ch[j]);
                }
                cnt=0;
                sscanf(ch[i],"%d%d",&a,&b);
                dfs(a-1,b-1);
                printf("%d\n",cnt);
                continue;
            }

            i++;
        }
        if(cs!=t)
        {
            printf("\n");
        }
    }
    return 0;
}
