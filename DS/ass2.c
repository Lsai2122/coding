#include<stdio.h>
#include<string.h>
struct students
{
    char name[10];
    int id;
    char branch[10];
    float cgpa;
} student[7] = {
    {"Sai",1,"CSA",8.2},
    {"kamal",2,"ECE",9.1},
    {"Arpit",3,"CSA",7.1},
    {"Amulya",4,"CSE",6},
    {"Shilok",5,"Mech",9.1},
    {"Abhi",6,"ECI",5},
    {"Karthik",7,"CSE",7.8}
};
void display()
{
    printf("\t\tID\t\tName\t\tBranch\t\tCGPA\n");
    for(int i=0;i<7;i++)
    {
        printf("\t\t%d\t\t",student[i].id);
        fputs(student[i].name,stdout);
        printf("\t\t");
        fputs(student[i].branch,stdout);
        printf("\t\t%f\n",student[i].cgpa);
    }
}
int least_char(char * a[],int i,int j)
{
    for(int k=0;k<10;k++)
    {
        return strcmp(a[i],a[j])>0;
    }
}
void asc_ord()
{
    char* name[7];
    for(int i=0;i<7;i++)
    {
        name[i]=student[i].name;
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(least_char(name,j,j+1))
            {
                char* temp =name[j];
                name[j]=name[j+1];
                name[j+1]=temp;
            }
        }
    }
    printf("\n\n\nNames in Ascending order is : \n");
    for(int i=0;i<7;i++)
    {
        printf("\t\t%s\n",name[i]);
    }
    printf("\n\n\n");
}
void search(char a[])
{
    int count = 0;
    printf("\t\tID\t\tName\t\tBranch\t\tCGPA\n");
    for(int i =0;i<7;i++)
    {
        if(strcmp(a,student[i].branch)==0)
        {
            count++;
            printf("\t\t%d\t\t",student[i].id);
            fputs(student[i].name,stdout);
            printf("\t\t");
            fputs(student[i].branch,stdout);
            printf("\t\t%f\n",student[i].cgpa);
        }
    }
    if(count==0)
    {
        printf("NO data of branch %s fount",a);
    }
}
void sort_des()
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(student[j].cgpa<student[j+1].cgpa)
            {
                struct students temp = student[j];
                student[j]=student[j+1];
                student[j+1]=temp;
            }
        }
    }
}
int main()
{   
    int a=1;
    while(a)
    {
        printf("1. Display the students data.\n");
        printf("2. Display the names in Ascending order.\n");
        printf("3. Search using branch.\n");
        printf("4. Sort the records in descending order.\n");
        printf("5. Exit");
        int n;
        printf("Enter the Option u want to choose : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: display();break;
            case 2: asc_ord();break;
            case 3: 
            {
                char branch[10];
                printf("Enter branch (CSE,MECH,CSA,ECE,ECI) : ");
                scanf("%99s",branch);
                search(branch);
            };break;
            case 4: sort_des();break;
            case 5: a=0;
        }
    }
}