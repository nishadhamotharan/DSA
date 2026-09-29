#include <stdio.h>

long long count(long long n)
{
    long long k,m,s1,s2;

    if(n<=0)
        return 0;

    m=1;
    while((m+1)*(m+1)<=n)
        m++;

    s1=0;

    for(k=1;k<m;k++)
        s1+=k*(2*k+1);

    s1+=m*(n-m*m+1);

    if(n%2==0)
    {
        k=n/2;
        s2=k*(k+1);
    }
    else
    {
        k=n/2;
        s2=(k+1)*(k+1);
    }

    return s1+s2;
}

long long lower(long long x)
{
    long long l=1,r=100000000;

    while(l<r)
    {
        long long mid=(l+r)/2;

        if(count(mid)>=x)
            r=mid;
        else
            l=mid+1;
    }

    return l;
}

int main()
{
    int q;
    long long l,r,a,b;

    scanf("%d",&q);

    while(q--)
    {
        scanf("%lld%lld",&l,&r);

        a=lower(l);
        b=lower(r);

        if(count(b-1)>=r)
            b--;

        printf("%lld\n",b-a+1);
    }

    return 0;
}