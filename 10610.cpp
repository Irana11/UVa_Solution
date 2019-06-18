#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#define sz 1100
using namespace std;
vector<int>vec[sz];
map<double,int>mp;
int vis[sz],flg;
int node,a,b,i,j,cnt,cst[sz],src,l,dest;
double x,y,m,n,hole[sz][3],k,v,t,u,path;
char s[sz],space[sz];

void bfs()
{
    queue<int>q;
    int i,l,a,b;
    cst[0]=0;
    q.push(0);
    while(q.empty()==0)
    {
        a=q.front();
        q.pop();
        l=vec[a].size();
        for(i=0;i<l;i++)
        {
            b=vec[a][i];
            if(vis[b]==0)
            {
                cst[b]=cst[a]+1;
                q.push(b);
                vis[b]=1;
            }
        }
    }

}
int main()
{
    while(scanf("%lf%lf",&v,&t)==2)
    {
        gets(space);
        if(v==0&&t==0)
        break;
        path=t*v*60.0;
        node=1;
        i=0;
        while(gets(s))
        {
            if(strcmp(s,"\0")==0)
            break;
            sscanf(s,"%lf%lf",&hole[i][0],&hole[i][1]);
            i++;
        }
        l=i;
        for(i=0;i<l;i++)
        vis[i]=0;
        for(i=0;i<l;i++)
        {
            for(j=i+1;j<l;j++)
            {
                u=hole[i][0]-hole[j][0];
                if(u<0)
                u=u*-1;
                v=hole[i][1]-hole[j][1];
                if(v<0)
                v=v*-1;
                k=sqrt(pow(u,2)+pow(v,2));
                if(k<=path)
                {
                    vec[i].push_back(j);
                    vec[j].push_back(i);
                }
            }
        }
        bfs();
       if(vis[1]!=0)
        {
            printf("Yes, visiting %d other holes.\n",cst[1]-1);
        }
        else
        {
            printf("No.\n");
        }
        for(i=0;i<l;i++)
        vec[i].clear();
        mp.clear();
    }
    return 0;
}
