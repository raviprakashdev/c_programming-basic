/* Objective: program to find whether the entered three points lie on the same line (i.e collinear)
 * logic: area of triangle formed by these three points should be zero for them to
 * lie on the same line

    using determinant to calculate area of triangle
    /*      | x1 y1 1 |
            | x2 y2 1 |
            | x3 y3 1 |

            expanding:
            x1(y2-y3) -x2(y1-y3) + x3(y1-y2)

 */
 
#include<stdio.h>
short IsCollinear(int,int,int,int,int,int);
int main()
{
    int x1,y1,x2,y2,x3,y3;

    printf("\nEnter the coordinates: ");
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    
    short result = IsCollinear(x1,y1,x2,y2,x3,y3);
    
    if(result == 1)
        printf("\nThe entered points lie on the same line.\n");
    else printf("\nThe entered points does not lie on the same line.\n");
    return 0;
}
short IsCollinear(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int area = x1*(y2-y3) -x2*(y1-y3) + x3*(y1-y2);
    if(area==0) return 1;
    else return 0;
}
