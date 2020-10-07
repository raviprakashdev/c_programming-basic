#include<stdio.h>

int main()
{
    int s,t,a,b,m,n;
    int apple=0, orange=0;

    scanf("%d %d", &s, &t);

    scanf("%d %d", &a, &b);

    scanf("%d %d", &m, &n);
    int ap[m],o[n];

    for(int i=0;i<m;i++)
    {
        scanf("%d", &ap[i]);
        if(ap[i]+a>=s && ap[i]+a<=t)
            apple++;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d", &o[i]);
        if(o[i]+b>=s && o[i]+b<=t)
            orange++;
    }

    printf("%d\n%d", apple, orange);
    return 0;
}
