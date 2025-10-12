#include <stdio.h>

int main() {
    int num1, num2, num3, sum;

    // รับค่าจากผู้ใช้
    printf("กรอกเลขทั้งหมดจำนวน 3 ค่าที่ต้องการ:");
    scanf("%d %d %d", &num1, &num2, &num3);

    // คำนวณผลรวม
    sum = num1 + num2 + num3;

    // แสดงผลลัพธ์
    printf("Answer = %d\n", sum);

    return 0;
}
