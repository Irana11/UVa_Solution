
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define sz 50
using namespace std;


char ch[sz],res[sz];
int i,j,l,cnt,take[sz],n;


/*void sort(char *ch)
{
    char tmp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ch[i]>ch[j])
            {
                tmp=ch[i];
                ch[i]=ch[j];
                ch[j]=tmp;
            }
        }
    }
}*/
void func(int start)
{
    int i;
    if(j==l)
    {
        cnt++;
        for(i=0;i<l;i++)
            printf("%c",res[i]);
        printf("\n");
    }
    else
    {
        for(i=start;i<n;i++)
        {
            if(take[i]==0)
            {
                take[i]=1;
                res[j++]=ch[i];
                func(i+1);
                take[i]=0;
                j--;
            }
            while(ch[i]==ch[i+1])
                i++;
        }
    }

}
int main()
{
    while(scanf("%s%d",&ch,&l)==2)
    {
        for(i=0;i<sz;i++)
            take[i]=0;
        n=strlen(ch);
        //sort(ch);
        sort(ch,ch+n);
        j=0;
        func(0);
    }
    return 0;
}
