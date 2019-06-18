
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int>vec[300];
int n,e,i,j,k,u,v,l,s,d,x,y,flg;
int color[300];

void bfs()
{
    int i,j;
    queue<int>q;
    q.push(0);
    color[0]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        l=vec[u].size();
        for(i=0; i<l; i++)
        {
            v=vec[u][i];
            if(color[v]==0)
            {
                if(color[u]==1)
                    color[v]=2;
                else
                    color[v]=1;

                q.push(v);
            }
            else if(color[u]==color[v])
            flg=1;
        }
    }
}


int main()
{

    while(scanf("%d",&n)==1&&n!=0)
    {
        for(i=0; i<n; i++)
        {
            color[i]=0;
        }

        scanf("%d",&e);
        while(e--)
        {
            scanf("%d %d",&x,&y);
            vec[x].push_back(y);
            vec[y].push_back(x);
        }

        flg=0;
        bfs();


        if(flg==1)
            printf("NOT BICOLORABLE.\n");
        else
            printf("BICOLORABLE.\n");

        for(i=0; i<n; i++)
            vec[i].clear();
    }
    return 0;
}
