#include <stdio.h>

int main() {
    int days;
    long seconds;

    // รับค่าจำนวนวันจากผู้ใช้
    printf("Input Days: ");
    scanf("%d", &days);

    // คำนวณวินาที
    seconds = days * 24 * 60 * 60;

    // แสดงผลลัพธ์
    printf("%d days = %ld seconds\n", days, seconds);

    return 0;
}
