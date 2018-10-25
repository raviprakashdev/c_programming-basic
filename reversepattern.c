#include <stdio.h>
int main()
{
    int i, j, rows,p;

    printf("Enter number of rows: ");
    scanf("%d",&rows);

    for(i=1; i<=rows; ++i)
    {
    	for(p=rows;p>=i;--p)
    	{
    		printf("  ");
		}
        for(j=1; j<=i; ++j)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}
