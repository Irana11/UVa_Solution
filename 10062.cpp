#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int c[130],i,j,k,l;
char  s[1010];

struct ss
{
    int cnt,nmbr;

}ar[130];

bool cmp(ss aa,ss bb)
{
    if(aa.cnt==bb.cnt)
    return aa.nmbr>bb.nmbr;
    return aa.cnt<bb.cnt;
}
int main()
{
    int m=0;
    while(gets(s))
    {
        for(i=0;i<130;i++)
        {
            c[i]=0;
        }
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            c[s[i]]++;
        }
        for(i=0,j=0;i<130;i++)
        {
            if(c[i]!=0)
            {
                ar[j].cnt=c[i];
                ar[j].nmbr=i;
                j++;
            }
        }
        sort(ar,ar+j,cmp);
        if(m>0)
        {
            printf("\n");

        }
        for(i=0;i<j;i++)
        {
             printf("%d %d\n",ar[i].nmbr,ar[i].cnt);
        }
        m++;

    }
    return 0;
}

