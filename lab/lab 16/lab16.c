#include <stdio.h>

int main() {
    int data[] = {15, 7, 25, 3, 73, 32, 45};
    int n = sizeof(data) / sizeof(data[0]);
    int i, j, temp, pos = -1;

    // แสดงข้อมูลก่อนเรียง
    printf("Old Series : ");
    for (i = 0; i < n; i++) {
        printf("%d", data[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");

    // เรียงข้อมูลแบบ Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    // แสดงข้อมูลหลังเรียง
    printf("New Series : ");
    for (i = 0; i < n; i++) {
        printf("%d", data[i]);
        if (i < n - 1) printf(" ,");
    }
    printf("\n");

    // หาตำแหน่งของหมายเลข 32
    for (i = 0; i < n; i++) {
        if (data[i] == 32) {
            pos = i;
            break;
        }
    }

    printf("Pos of 32 : %d\n", pos);

    return 0;
}