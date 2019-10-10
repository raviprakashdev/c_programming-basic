#include <stdio.h>

int main()
{
    int a[]={4,6,2,7,3,9},len,temp,i,k;
    len=sizeof(a)/sizeof(a[0]);
    for(k=1;k<len;k++)
    {
        for(i=0;i<len-1;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    for(i=0;i<len;i++)
    printf("%d",a[i]);
return 0;
}
