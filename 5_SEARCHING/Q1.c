#include <stdio.h>
int main()
{
    char v1,v2,v3;
    char s1[20],s2[20],s3[20];
    double M,D,X;

    scanf(" %c %s",&v1,s1);
    scanf(" %c %s",&v2,s2);
    scanf(" %c %s",&v3,s3);

    M=0;
    D=0;
    X=0;

    if(v1=='M')
    {
        sscanf(s1,"%lf",&M);
    }
    else if(v1=='D')
    {
        sscanf(s1,"%lf",&D);
    }

    if(v2=='M')
    {
        sscanf(s2,"%lf",&M);
    }
    else if(v2=='D')
    {
        sscanf(s2,"%lf",&D);
    }

    if(v3=='M')
    {
        sscanf(s3,"%lf",&M);
    }
    else if(v3=='D')
    {
        sscanf(s3,"%lf",&D);
    }

    if(s3[0]=='?')
    {
        X=-M/D;
        printf("x %.2f",X);
    }

    return 0;
}