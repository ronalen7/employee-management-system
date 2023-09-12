#include <stdio.h>

// Definition of the Employee structure
struct Employee {
    int Empno;
    char Ename[100]; 
    struct Date {
        int day, month, year;
    } hiredate;
    float basicSal, netSal;
};

// Function to accept employee data
void acceptEmpData(struct Employee *emp) {
    printf("Enter the employee ID: ");
    scanf("%d", &emp->Empno);

    printf("Enter the employee name: ");
    scanf("%s", &emp->Ename); // no spaces in the name
    // fgets(emp->Ename, 100, stdin);
    // gets(emp->Ename);

    printf("Enter the hire date in the format (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &emp->hiredate.day, &emp->hiredate.month, &emp->hiredate.year);

    printf("Enter Basic Salary: ");
    scanf("%f", &emp->basicSal);
}

// Function to calculate net pay
void calNetPay(struct Employee *emp) {
    // Calculation of DA, TA, and PF
    float DA = 0.40 * emp->basicSal;
    float TA = 0.10 * emp->basicSal;
    float PF = 0.05 * emp->basicSal;

    // Calculation of Net Salary
    emp->netSal = emp->basicSal + DA + TA - PF;
}


// Function to display employee data
void showEmpData(struct Employee *emp) {
    printf("| Employee ID: %d |\n", emp->Empno);
    printf("----------------------------\n");
    printf("| Employee Name: %s |\n", emp->Ename);
    printf("----------------------------\n");
    printf("| Hire Date: %d/%d/%d |\n", emp->hiredate.day, emp->hiredate.month, emp->hiredate.year);
    printf("----------------------------\n");
    printf("| Basic Salary: %.2f |\n", emp->basicSal);
    printf("----------------------------\n");
    printf("| Net Salary: %.2f |\n", emp->netSal);
    printf("============================\n");
    printf("============================\n");
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    struct Employee emp[n];

    for(int i=0;i<n;i++) {
        // Accept employee data
        acceptEmpData(&emp[i]);
    
        // Calculate net pay
        calNetPay(&emp[i]);
    }

    // Displaying employee data
    printf("============================\n");
    printf("Employees Details :-\n");
    printf("============================\n");
    for(int i=0;i<n;i++) {
        showEmpData(&emp[i]);
    }

    return 0;
}