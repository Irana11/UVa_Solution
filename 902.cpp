#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
#define sz 1000005
using namespace std;
map<string,int>mp;

int main()
{
    char s[sz],s_cpy[11],s_r[11];
    int mx,i,j,cnt,l,n,k;
    while(scanf("%d",&n)==1)
    {
        getchar();
        gets(s);
        l=strlen(s);
        mx=0;
        for(i=0;i<l-(n-1);i++)
        {
            k=i;
            for(j=0;j<n;j++)
            {
                s_cpy[j]=s[k];
                k++;
            }
            mp[s_cpy]++;
            cnt=mp[s_cpy];
            if(cnt>mx)
            {
                mx=cnt;
                strcpy(s_r,s_cpy);
            }
        }
        s_r[n]='\0';
        printf("%s\n",s_r);
        mp.clear();

    }
    return 0;
}
