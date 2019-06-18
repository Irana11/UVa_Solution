
#include<stdio.h>
#include<math.h>
int a[55];

int gcd(int a,int b)
{
    int tmp;
    while(b!=0)
    {
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}
int main()
{
    int i,j,n,m,s,c,g;
    double p,z;
    while((scanf("%d",&n))==1&&n!=0)
    {

        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        s=0;
        c=0;
        for(i=n-1;i>0;i--)
        {
            s=s+i;
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                g=gcd(a[i],a[j]);
                if(g==1)
                {
                    c++;
                }
            }
        }
        if(c==0)
        {
            printf("No estimate for this data set.\n");
        }
        else
        {
            z=sqrt(6*s)/sqrt(c);
           // p=;
           // a=z/p;
            printf("%.6lf\n",z);
        }

    }
    return 0;
}
