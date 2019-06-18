#include<stdio.h>
#include<string.h>

char s[1000005];

int main()
{
    int i,j,k,l,x,y,m;
    char ch;
    while(gets(s))
    {
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U')
            {
                while((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))
                {
                    printf("%c",s[i]);
                    i++;
                }
                printf("ay");
            }
            else if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))
            {
                ch=s[i];
                i++;
                while((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))
                {
                    printf("%c",s[i]);
                    i++;
                }
                printf("%cay",ch);
            }
            printf("%c",s[i]);
        }
        printf("\n");
       // puts('"');
    }
    return 0;
}
