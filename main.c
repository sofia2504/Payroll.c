#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PAY_RECS_NO 10000

struct payroll {
    unsigned long long int internal_id;
    char first_name[50];
    char last_name[50];
    char department[100];
    unsigned char dob_day;
    unsigned char dob_month;
    unsigned short dob_year;
    double monthly_salary;
};

struct payroll pay_recs[MAX_PAY_RECS_NO];
size_t pay_recs_no;


//prints out payroll layout of the input dept including first and last name, DOB, monthly salary, total number of employees and total salary. prints error message if dept not found.
void PrintDeptPayrollRecords(char* dept_name){
  //number of empoyees anf total salary
  int nEmp = 0;
  double tSal= 0;

  //checks to see number of employees under dept
  for(int q = 0; q< pay_recs_no; q++){
    if(strcmp(pay_recs[q].department, dept_name)==0)
      nEmp++;
  }

  //if number of employees is 0, print no payroll record
  if(nEmp==0){
    printf("Department %s has no payroll records.", dept_name);
  }
  else{
    printf("Employees of the %s Department:\n", dept_name);
    printf("Last Name\t First Name\t Date of Birth\t Monthly Salary\n");

    //prints little lines
    for(int i=0; i<55; i++)
      printf("-");
    printf("\n");

    //goes through record and prints info
    for(int j=0; j<pay_recs_no; j++){
      if(strcmp(pay_recs[j].department, dept_name)==0){
        printf("%-7s\t\t %-7s\t\t%d-%d-%d\t\t%.2f\n",pay_recs[j].last_name, pay_recs[j].first_name, pay_recs[j].dob_year, pay_recs[j].dob_month, pay_recs[j].dob_day, pay_recs[j].monthly_salary);
        tSal+= pay_recs[j].monthly_salary; 
      }
    }
    //prints number of employees and total salary
    printf("Total Number of Employees in the Department: %d\n", nEmp);
    printf("Aggregated Salary of the Department: %.2f\n", tSal);
  }
}


//creates a file with the name input by user that saves out payroll layout of the input dept including first and last name, DOB, monthly salary, total number of employees and total salary. saves error message if dept not found.
void SaveDeptPayrollRecordsToFile(char* dept_name, char* file_name){
  //creates file
  FILE * file = fopen(file_name, "w");
  
  //checks to see if there's any employees under dept
  int nEmp = 0;
  double tSal= 0;
  for(int q = 0; q< pay_recs_no; q++){
    if(strcmp(pay_recs[q].department, dept_name)==0)
      nEmp++;
  }
  //if dept not found, error message
  if(nEmp==0){
    fprintf(file, "Department %s has no payroll records.", dept_name);
  }
  else{
    //saves the layouy(table) to files
    fprintf(file, "Employees of the %s Department:\n", dept_name);
    fprintf(file, "Last Name\t First Name\t Date of Birth\t Monthly Salary\n");

    //saves littles lines to file
    for(int i=0; i<55; i++)
      fprintf(file, "-");
    fprintf(file, "\n");

    //goes through record and saves info to file 
    for(int j=0; j<pay_recs_no; j++){
      if(strcmp(pay_recs[j].department, dept_name)==0){
        fprintf(file, "%-7s\t\t %-7s\t\t %d-%d-%-8d\t\t%.2f\n",pay_recs[j].last_name, pay_recs[j].first_name, pay_recs[j].dob_year, pay_recs[j].dob_month, pay_recs[j].dob_day, pay_recs[j].monthly_salary);
        tSal+= pay_recs[j].monthly_salary; 
      }
    }  
    //saves to file number of employees and total salary
    fprintf(file,"Total Number of Employees in the Department: %d\n", nEmp);
    fprintf(file, "Aggregated Salary of the Department: %.2f\n", tSal);
  }
  //closes file 
  fclose(file);
}

int main(void) {
  
  //payroll 1
  pay_recs[0].internal_id= 1;
  strcpy(pay_recs[0].last_name, "Bey");
  strcpy(pay_recs[0].first_name, "Sof");
  strcpy(pay_recs[0].department, "Computer Science");
  pay_recs[0].dob_day= 25;
  pay_recs[0].dob_month= 04;
  pay_recs[0].dob_year= 2002;
  pay_recs[0].monthly_salary= 6000;
  //payroll 2
  pay_recs[1].internal_id= 2;
  strcpy(pay_recs[1].last_name, "Arruda");
  strcpy(pay_recs[1].first_name, "Gabe");
  strcpy(pay_recs[1].department, "Computer Science");
  pay_recs[1].dob_day= 16;
  pay_recs[1].dob_month= 11;
  pay_recs[1].dob_year= 2001;
  pay_recs[1].monthly_salary= 6000;
  //payroll 3
  pay_recs[2].internal_id= 3;
  strcpy(pay_recs[2].last_name, "Habbal");
  strcpy(pay_recs[2].first_name, "Reem");
  strcpy(pay_recs[2].department, "Accounting");
  pay_recs[2].dob_day= 07;
  pay_recs[2].dob_month= 13;
  pay_recs[2].dob_year= 2002;
  pay_recs[2].monthly_salary= 2500;
  //payroll 4
  pay_recs[3].internal_id= 4;
  strcpy(pay_recs[3].last_name, "Caggia");
  strcpy(pay_recs[3].first_name, "Valentina");
  strcpy(pay_recs[3].department, "Business");
  pay_recs[3].dob_day= 04;
  pay_recs[3].dob_month= 25;
  pay_recs[3].dob_year= 2002;
  pay_recs[3].monthly_salary= 2000;
  //payroll 5 
  pay_recs[4].internal_id= 5;
  strcpy(pay_recs[4].last_name, "Ramirez");
  strcpy(pay_recs[4].first_name, "Agustin");
  strcpy(pay_recs[4].department, "Lawyer");
  pay_recs[4].dob_day= 07;
  pay_recs[4].dob_month= 12;
  pay_recs[4].dob_year= 2002;
  pay_recs[4].monthly_salary= 2700;
  //payroll 6
  pay_recs[5].internal_id= 6;
  strcpy(pay_recs[5].last_name, "Wu");
  strcpy(pay_recs[5].first_name, "Anthony");
  strcpy(pay_recs[5].department, "Computer Science");
  pay_recs[5].dob_day= 9;
  pay_recs[5].dob_month= 06;
  pay_recs[5].dob_year= 2002;
  pay_recs[5].monthly_salary= 5500;
  //payroll 7
  pay_recs[6].internal_id= 7;
  strcpy(pay_recs[6].last_name, "Villegas");
  strcpy(pay_recs[6].first_name, "Andres");
  strcpy(pay_recs[6].department, "Marketing");
  pay_recs[6].dob_day= 29;
  pay_recs[6].dob_month= 9;
  pay_recs[6].dob_year= 2000;
  pay_recs[6].monthly_salary= 4000;
  //payroll 8
  pay_recs[7].internal_id= 8;
  strcpy(pay_recs[7].last_name, "Delgado");
  strcpy(pay_recs[7].first_name, "Andres");
  strcpy(pay_recs[7].department, "Computer Science");
  pay_recs[7].dob_day= 03;
  pay_recs[7].dob_month= 03;
  pay_recs[7].dob_year= 2000;
  pay_recs[7].monthly_salary= 6500;
  //payroll 9
  pay_recs[8].internal_id= 9;
  strcpy(pay_recs[8].last_name, "Haselbacher");
  strcpy(pay_recs[8].first_name, "Maria");
  strcpy(pay_recs[8].department, "Marketing");
  pay_recs[8].dob_day= 05;
  pay_recs[8].dob_month= 07;
  pay_recs[8].dob_year= 2002;
  pay_recs[8].monthly_salary= 4000;
  //payroll 10
  pay_recs[9].internal_id= 10;
  strcpy(pay_recs[9].last_name, "Gardner");
  strcpy(pay_recs[9].first_name, "Reece");
  strcpy(pay_recs[9].department, "Gardner");
  pay_recs[9].dob_day= 17;
  pay_recs[9].dob_month= 03;
  pay_recs[9].dob_year= 2005;
  pay_recs[9].monthly_salary= 4700;

  //size of payroll record array
  pay_recs_no = 10;
  
  //creates real and fake departments 
  char* dept= "Computer Science";
  char* fake_dept= "Human Resources";

  //prints real records
  PrintDeptPayrollRecords(dept);
  printf("\n");

  //prints error fake dept and error message
  PrintDeptPayrollRecords(fake_dept);
  printf("\n");
  printf("\n");

  //asks user for file name and stores 
  char file_name;
  printf("Input dept name to save in file \n");
  scanf("%s", &file_name); 
 
  //creates payroll file with user file name
  SaveDeptPayrollRecordsToFile(dept, &file_name);

  return 0;
}
