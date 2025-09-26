#include <stdio.h>
#include <string.h>

// โครงสร้าง Student ใช้เก็บข้อมูลนักเรียน
struct Student {
    char Name[20] ;      // เก็บชื่อนักเรียน
    char ID[5] ;         // เก็บรหัสนักเรียน
    float ScoreSub1 ;    // คะแนนวิชาที่ 1
    float ScoreSub2 ;    // คะแนนวิชาที่ 2
    float ScoreSub3 ;    // คะแนนวิชาที่ 3
    float ScoreSub4 ;    // คะแนนวิชาที่ 4
    float ScoreSub5 ;    // คะแนนวิชาที่ 5
} typedef S ;            // typedef ให้ struct Student ใช้ชื่อสั้น ๆ ว่า S

// ฟังก์ชันแปลงคะแนนเป็นเกรด
void gradeFromScore(float s, char out[]) {
    if (s >= 80) strcpy(out, "A");       // 80 ขึ้นไป = A
    else if (s >= 75) strcpy(out, "B+"); // 75–79 = B+
    else if (s >= 70) strcpy(out, "B");  // 70–74 = B
    else if (s >= 65) strcpy(out, "C+"); // 65–69 = C+
    else if (s >= 60) strcpy(out, "C");  // 60–64 = C
    else if (s >= 55) strcpy(out, "D+"); // 55–59 = D+
    else if (s >= 50) strcpy(out, "D");  // 50–54 = D
    else strcpy(out, "F");               // ต่ำกว่า 50 = F
} // End gradeFromScore

// ฟังก์ชันรับข้อมูลนักเรียน
void inputStudent(S students[], int n) {
    printf("Student %d:\n", n + 1);                // แสดงว่าเป็นนักเรียนคนที่เท่าไร

    printf("Name:\n");                             // ขอชื่อ
    scanf(" %[^\n]", students[n].Name);            // อ่าน string แบบเว้นวรรคได้

    printf("ID:\n");                               // ขอรหัสนักเรียน
    scanf("%s", students[n].ID);                   // อ่าน string ไม่มีช่องว่าง

    // รับคะแนนแต่ละวิชา
    printf("Scores in Subject 1:\n");
    scanf("%f", &students[n].ScoreSub1);

    printf("Scores in Subject 2:\n");
    scanf("%f", &students[n].ScoreSub2);

    printf("Scores in Subject 3:\n");
    scanf("%f", &students[n].ScoreSub3);

    printf("Scores in Subject 4:\n");
    scanf("%f", &students[n].ScoreSub4);

    printf("Scores in Subject 5:\n");
    scanf("%f", &students[n].ScoreSub5);

    printf("\n");                                  // เว้นบรรทัดเพื่อความสวยงาม
} // End inputStudent

// ฟังก์ชันแสดงข้อมูลนักเรียน
void printStudent(S students[], int n) {
    char g1[3], g2[3], g3[3], g4[3], g5[3];        // เก็บเกรดแต่ละวิชา

    // แปลงคะแนนเป็นเกรด
    gradeFromScore(students[n].ScoreSub1, g1);
    gradeFromScore(students[n].ScoreSub2, g2);
    gradeFromScore(students[n].ScoreSub3, g3);
    gradeFromScore(students[n].ScoreSub4, g4);
    gradeFromScore(students[n].ScoreSub5, g5);

    // คำนวณค่าเฉลี่ย = (ผลรวมคะแนนทั้ง 5 วิชา) / 5
    float average = (students[n].ScoreSub1 +
                     students[n].ScoreSub2 +
                     students[n].ScoreSub3 +
                     students[n].ScoreSub4 +
                     students[n].ScoreSub5) / 5.0;

    // แสดงข้อมูลนักเรียน
    printf("Student %d:\n", n + 1);
    printf("Name: %s\n", students[n].Name);        // ชื่อ
    printf("ID: %s\n", students[n].ID);            // รหัส
    printf("Scores: %.0f %.0f %.0f %.0f %.0f\n",   // คะแนนวิชาต่าง ๆ
           students[n].ScoreSub1, students[n].ScoreSub2,
           students[n].ScoreSub3, students[n].ScoreSub4,
           students[n].ScoreSub5);
    printf("Grades: %s %s %s %s %s\n",             // เกรดวิชาต่าง ๆ
           g1, g2, g3, g4, g5);
    printf("Average Score: %.2f\n", average);      // คะแนนเฉลี่ย (ทศนิยม 2 ตำแหน่ง)

    printf("\n");
} // End printStudent

// ฟังก์ชันหลัก
int main() {
    S students[3];                                 // เก็บข้อมูลนักเรียน 3 คน

    printf("Enter the details of 3 students :\n");

    // วนลูปเพื่อรับข้อมูลทีละคน
    for (int i = 0; i < 3; i++) {
        inputStudent(students, i);
    }

    // วนลูปเพื่อแสดงข้อมูลทีละคน
    for (int i = 0; i < 3; i++) {
        printStudent(students, i);
    }

    return 0;
} // End main
