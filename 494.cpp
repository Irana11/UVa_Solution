#include<stdio.h>
#include<string.h>

int main()
{
    int i,l,cnt;
    char s[1000010];
    while(gets(s))
    {
        l=strlen(s);
        i=0;
        cnt=0;
        while(i<l)
        {
            if((65<=s[i]&&s[i]<=90)||(97<=s[i]&&122>=s[i]))
            {
                while((65<=s[i]&&s[i]<=90)||(97<=s[i]&&122>=s[i]))
                {
                    i++;
                }
                cnt++;
            }
            i++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
