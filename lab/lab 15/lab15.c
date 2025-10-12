#include <stdio.h>
#include <ctype.h>

int main() {
    char filename[100];
    FILE *file;
    char ch;
    int inWord = 0, wordCount = 0;

    // รับชื่อไฟล์จากผู้ใช้
    printf("Enter file name: ");
    scanf("%s", filename);

    // เปิดไฟล์
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    // อ่านไฟล์ทีละตัวอักษร
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            inWord = 0;
        } else {
            if (inWord == 0) {
                wordCount++;
                inWord = 1;
            }
        }
    }

    fclose(file);

    // แสดงผลลัพธ์
    printf("Total number of words in '%s' : %d words\n", filename, wordCount);

    return 0;
}
