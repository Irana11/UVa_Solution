#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

double x[110],y[110],cst;
long par[110],i,j,u,v,k,t,n;
struct ss
{
    long beg,end;
    double cost;

}Case[11010];

bool cmp(ss aa,ss bb)
{
    return aa.cost<bb.cost;
}

long find(long r)
{
    if (par[r]==r)
    return r;
    return par[r]=find(par[r]);
}

int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lf %lf",&x[i],&y[i]);
            par[i]=i;
        }
        k=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                Case[k].beg=i;
                Case[k].end=j;
                Case[k++].cost=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            }
        }
        sort(Case,Case+k,cmp);
        cst=0;
        for(i=0;i<k;i++)
        {
            u=find(Case[i].beg);
            v=find(Case[i].end);
            if(u!=v)
            {
                cst+=sqrt(Case[i].cost);
                par[v]=u;
            }
        }
        printf("%.2lf\n",cst);
        if(t)
            printf("\n");
    }
    return 0;
}

