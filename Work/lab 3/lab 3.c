#include <stdio.h>

int main() {
    float base, height, area;

    // รับค่าฐานและความสูงจากผู้ใช้
    printf("High : ");
    scanf("%f", &base);

    printf("Width : ");
    scanf("%f", &height);

    // คำนวณพื้นที่
    area = (base * height) / 2;

    // แสดงผลลัพธ์
    printf("Area : %.2f\n", area);

    return 0;
}