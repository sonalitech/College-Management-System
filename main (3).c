/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>  //for using exit() function & for using Dynamic Memory Allocation function
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
void inputStudentDetails(FILE*,struct student*,int);  //struct student* is a pointer variable of struct 
                                                      //student data type for storing the pointer of 
                                                      //dynamically allocated memory.
void inputFacultyDetails(FILE*,struct faculty*,int);
void inputStaffDetails(FILE*,struct staff*,int);
int main()
{
    FILE *fp;
    fp=fopen("ClgSystem1.txt","w");
    //Students details
    struct student *ptrIT,*ptrCSE,*ptrCivil,*ptrECE;
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
    if(sizeIT>=0 && sizeCSE>=0 && sizeCivil>=0 && sizeECE>=0)  //it may happen that there is no student in any one of the stream
    {
        //Dynamic memory allocation for student
        ptrIT=(struct student*)calloc(sizeIT,sizeof(struct student));
        ptrCSE=(struct student*)calloc(sizeCSE,sizeof(struct student));
        ptrCivil=(struct student*)calloc(sizeCivil,sizeof(struct student));
        ptrECE=(struct student*)calloc(sizeECE,sizeof(struct student));
        if(ptrIT==NULL || ptrCSE==NULL || ptrCivil==NULL || ptrECE==NULL)
        {
            printf("Error!Memory not allocated\n");
            exit(0);
        }
        else
        {
            printf("\nEnter the details of students\n");
            fprintf(fp,"%s\n","STUDENT DETAILS");
            fprintf(fp,"%-50s%-15s%-10s%-50s\n\n","NAME","ROLL NO.","SEMESTER","STREAM");
            //calling functions for taking input from the user
            inputStudentDetails(fp,ptrIT,sizeIT);        //for IT students
            inputStudentDetails(fp,ptrCSE,sizeCSE);      //for CSE students
            inputStudentDetails(fp,ptrCivil,sizeCivil);  //for Civil students
            inputStudentDetails(fp,ptrECE,sizeECE);      //for ECE students
            fclose(fp);
            printf("Student data has been stored successfully...\n");
        }   
        free(ptrIT);
        free(ptrCSE);
        free(ptrCivil);
        free(ptrECE);
    }
    else
    {
        printf("\nAny of the size is Invalid. Please enter a non-negative value.\n");
    }
    
    //Faculty Details
    fp=fopen("ClgSystem1.txt","a");
    struct faculty *ptrFac;
    int sizeFac;
    printf("\nEnter the number of faculties :");
    scanf("%d",&sizeFac);
    getchar();
    if(sizeFac>0)
    {
        //Dynamic memory allocation for faculty
        ptrFac=(struct faculty*)calloc(sizeFac,sizeof(struct faculty));
        if(ptrFac==NULL)
        {
            printf("\nError!Memory not allocated\n");
            exit(0);
        }
        else
        {
            printf("\nEnter the details of faculty\n");
            fprintf(fp,"\n\n%s\n","FACULTY DETAILS");
            fprintf(fp,"%-40s%-40s%-40s\n\n", "NAME", "SUBJECT", "DEPARTMENT");
            //calling function for taking input from the user
            inputFacultyDetails(fp,ptrFac,sizeFac);  //for faculty
            fclose(fp);
            printf("Faculty data has been stored successfully...\n");
        }  
        free(ptrFac);
    }
    else
    {
        printf("\nSize is Invalid. Please enter a non-negative value.\n");
    }
    
    
    //Staff Details
    fp=fopen("ClgSystem1.txt","a");
    struct staff *ptrStaff;
    int sizeStaff;
    printf("\nEnter the size for staff :");
    scanf("%d",&sizeStaff);
    getchar();
    if(sizeStaff>0)
    {
        //Dynamic memory allocation for staff
        ptrStaff=(struct staff*)calloc(sizeStaff,sizeof(struct staff));
        if(ptrStaff==NULL)
        {
            printf("\nError!Memory not allocated\n");
            exit(0);
        }
        else
        {
            printf("\nEnter the details of staff\n");
            fprintf(fp,"\n\n%s\n","STAFF DETAILS");
            fprintf(fp,"%-40s%-40s\n\n", "NAME", "SECTION");
            //calling function for taking input from the user
            inputStaffDetails(fp,ptrStaff,sizeStaff);    //for staff
            fclose(fp);
            printf("Staff data has been stored successfully...\n");
        } 
        free(ptrStaff);
    }
    else
    {
        printf("\nSize is invalid. Please enter a non-negative value.\n");
    }

    //reading from File 
    if(sizeIT>0 || sizeCSE>0 || sizeCivil>0 || sizeECE>0 || sizeFac>0 || sizeStaff>0)
    {
        printf("\nREADING FROM FILE...\n\n");
        fp=fopen("ClgSystem1.txt","r");
        if(fp==NULL)
        {
            printf("Error!in file opening");
            exit(0);
        }
        else
        {
            char ch;
            while((ch=fgetc(fp))!=EOF)
            {
                printf("%c",ch);
            }
            fclose(fp);
            printf("\nFile has been read successfully...\n");
        }
    }
    else
    {
        printf("\nThere is no data stored in the file\n");
    }
    return 0;
}  

void inputStudentDetails(FILE *fp,struct student *stu,int size)
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
        fprintf(fp,"%-50s%-15lld%-10d%-50s\n",stu[i].name,stu[i].roll,stu[i].semester,stu[i].stream);
        printf("\n");
    }
}

void inputFacultyDetails(FILE *fp,struct faculty *fac,int size)
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
        fprintf(fp,"%-40s%-40s%-40s\n", fac[j].name, fac[j].subject, fac[j].department);
        printf("\n");
    }
}

void inputStaffDetails(FILE *fp,struct staff *staff,int size)
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
        fprintf(fp,"%-40s%-40s\n",staff[k].name,staff[k].section);
        printf("\n");
    }
}
    
    
   
    
    

