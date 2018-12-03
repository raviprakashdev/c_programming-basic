#include<stdio.h>
struct student 
{
	int r_no;
	char name[20];
};
struct student stud[5];

void main()
{
	int i;
	printf("\n Enter the details of students \n");
	for(i=0;i<3;i++)
	{
		printf("Enter the roll no.");
		scanf("%d",&stud[i].r_no);
		printf("Enter the name");
		scanf("%s",&stud[i].name);
	}
	printf("Details of the student in class\n");
	for(i=0;i<3;i++)
	{
		printf("Roll no = %d\n",stud[i].r_no);
		printf("Name= %s\n",stud[i].name);	
	}	
}
