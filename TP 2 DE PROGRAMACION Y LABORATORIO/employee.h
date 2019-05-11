#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

#endif // EMPLOYEE_H_INCLUDED

int menu();
int initEmployees(Employee list[], int len);
int searchFree(Employee list[], int len);
int higherIdEmployee(Employee list[], int len);
int addEmployee(Employee list[], int len);
int findEmployeeById(Employee list[], int len,int id);
int removeEmployee(Employee list[], int len);
int sortEmployees(Employee list[], int len);
void printEmployee(Employee anEmployee);
int printEmployees(Employee list[], int length);
void modificationEmployee(Employee list[], int len);







