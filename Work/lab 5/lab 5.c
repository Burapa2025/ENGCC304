#include <stdio.h>

int main() {
    char employeeID[11]; // รองรับสูงสุด 10 ตัวอักษร + null terminator
    int hours;
    float rate, salary;

    // รับข้อมูลจากผู้ใช้
    printf("Input the Employees ID(Max. 10 chars): ");
    scanf("%s", employeeID);

    printf("Input the working hrs: ");
    scanf("%d", &hours);

    printf("Salary amount/hr: ");
    scanf("%f", &rate);

    // คำนวณรายได้รวม
    salary = hours * rate;

    // แสดงผลลัพธ์
    printf("Employees ID = %s\n", employeeID);
    printf("Salary = US $%.2f\n", salary);

    return 0;
}
