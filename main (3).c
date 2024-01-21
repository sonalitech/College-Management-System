/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Structure Project(Final)
#include<stdio.h>
#include<string.h>
struct student
{
    char name[100];
    long long int roll;
    int semester;
    char stream[50];
};
struct faculty
{
    char name[100];
    char subject[100];
    char department[100];
};
struct staff
{
    char name[100];
    char section[100];  //in which section they work
};
//functions for taking inputs
void inputStudentDetails(struct student[],int);
void inputFacultyDetails(struct faculty[],int);
void inputStaffDetails(struct staff[],int);
//functions for printing output
void printStudentDetails(struct student[],int);
void printFacultyDetails(struct faculty[],int);
void printStaffDetails(struct staff[],int);
int main()
{
    //Students details
    int sizeIT,sizeCSE,sizeCivil,sizeECE;
    printf("Enter the size for the IT students :");
    scanf("%d",&sizeIT);
    getchar();  // Consume the newline character
    printf("Enter the size for the CSE students :");
    scanf("%d",&sizeCSE);
    getchar();
    printf("Enter the size for the Civil students :");
    scanf("%d",&sizeCivil);
    getchar();
    printf("Enter the size for the ECE students :");
    scanf("%d",&sizeECE);
    getchar();
    if(sizeIT>0 && sizeCSE>0 && sizeCivil>0 && sizeECE>0)
    {
        struct student stuIT[sizeIT];
        struct student stuCSE[sizeCSE];
        struct student stuCivil[sizeCivil];
        struct student stuECE[sizeECE];
    
        printf("\nEnter the details of students\n");
        //calling functions for taking input from the user
        inputStudentDetails(stuIT,sizeIT);        //for IT students
        inputStudentDetails(stuCSE,sizeCSE);      //for CSE students
        inputStudentDetails(stuCivil,sizeCivil);  //for Civil students
        inputStudentDetails(stuECE,sizeECE);      //for ECE students
    
        printf("Details of Studnets are :\n");
        printf("%-50s%-15s%-10s%-50s\n","Name","Roll No.","Semester","Stream");
        //calling functions for printing output
        printStudentDetails(stuIT,sizeIT);         //for IT students
        printStudentDetails(stuCSE,sizeCSE);       //for CSE students
        printStudentDetails(stuCivil,sizeCivil);   //for Civil students
        printStudentDetails(stuECE,sizeECE);       //for ECE students
    
    
        //Faculty Details
        int sizeFac;
        printf("\nEnter the number of faculties :");
        scanf("%d",&sizeFac);
        getchar();
        struct faculty fac[sizeFac];
        printf("\nEnter the details of faculty\n");
        //calling function for taking input from the user
        inputFacultyDetails(fac,sizeFac);  //for faculty
    
        printf("Details of Faculties are :\n");
        printf("%-40s%-40s%-40s\n", "Name", "Subject", "Department");
        //calling function for printing output
        printFacultyDetails(fac,sizeFac);   //for faculty
    
    
        //Staff Details
        int sizeStaff;
        printf("\nEnter the size for staff :");
        scanf("%d",&sizeStaff);
        getchar();
        struct staff staff[sizeStaff];
        printf("\nEnter the details of staff\n");
        //calling function for taking input from the user
        inputStaffDetails(staff,sizeStaff);    //for staff
    
        printf("Details of Staffs are :\n");
        printf("%-40s%-40s\n", "Name", "Section");
        //calling function for printing output
        printStaffDetails(staff,sizeStaff);    //for staff
    }
    else
    {
        printf("\nAny of the size is Invalid. Please enter a non-negative value.\n");
    }
    return 0;
}  

    
void inputStudentDetails(struct student stu[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("Name :");
        fgets(stu[i].name,sizeof(stu[i].name),stdin);
        stu[i].name[strcspn(stu[i].name,"\n")]='\0';   // Remove newline character
        printf("Roll No. :");
        scanf("%lld",&stu[i].roll);
        printf("Semester :");
        scanf("%d",&stu[i].semester);
        getchar();    // Consume the newline character
        printf("Stream :");
        fgets(stu[i].stream,sizeof(stu[i].stream),stdin);
        stu[i].stream[strcspn(stu[i].stream,"\n")]='\0';
        printf("\n");
    }
}
void printStudentDetails(struct student stu[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%-50s%-15lld%-10d%-50s\n",stu[i].name,stu[i].roll,stu[i].semester,stu[i].stream);
    }
}

void inputFacultyDetails(struct faculty fac[],int size)
{
    int j;
    for(j=0;j<size;j++)
    {
        printf("Name :");
        fgets(fac[j].name,sizeof(fac[j].name),stdin);
        fac[j].name[strcspn(fac[j].name,"\n")]='\0';
        printf("Subject :");
        fgets(fac[j].subject,sizeof(fac[j].subject),stdin);
        fac[j].subject[strcspn(fac[j].subject,"\n")]='\0';
        printf("Department :");
        fgets(fac[j].department,sizeof(fac[j].department),stdin);
        fac[j].department[strcspn(fac[j].department,"\n")]='\0';
        printf("\n");
    }
}
void printFacultyDetails(struct faculty fac[],int size)
{
    int j;
    for (j = 0;j<size;j++) 
    {
        printf("%-40s%-40s%-40s\n", fac[j].name, fac[j].subject, fac[j].department);
    }
}

void inputStaffDetails(struct staff staff[],int size)
{
    int k;
    for(k=0;k<size;k++)
    {
        printf("Name :");
        fgets(staff[k].name,sizeof(staff[k].name),stdin);
        staff[k].name[strcspn(staff[k].name,"\n")]='\0';
        printf("Section :");
        fgets(staff[k].section,sizeof(staff[k].section),stdin);
        staff[k].section[strcspn(staff[k].section,"\n")]='\0';
        printf("\n");
    }
}
void printStaffDetails(struct staff staff[],int size)
{
    int k;
    for (k=0;k<size;k++) 
    {
        printf("%-40s%-40s\n",staff[k].name,staff[k].section);
    }
}
    
    
    
   
    
    

