#include <stdio.h>
#include <string.h>

// ประกาศโครงสร้าง Student
struct Student {
    char Name[20] ;      // เก็บชื่อนักเรียน (string ความยาวไม่เกิน 19 ตัวอักษร)
    char ID[5] ;         // เก็บรหัสนักเรียน (string ความยาวไม่เกิน 4 ตัวอักษร)
    float ScoreSub1 ;    // คะแนนวิชาที่ 1
    float ScoreSub2 ;    // คะแนนวิชาที่ 2
    float ScoreSub3 ;    // คะแนนวิชาที่ 3
    float ScoreSub4 ;    // คะแนนวิชาที่ 4
    float ScoreSub5 ;    // คะแนนวิชาที่ 5
} typedef S ;            // typedef เพื่อเรียกสั้น ๆ ว่า S

// ฟังก์ชันแปลง "คะแนน" เป็น "เกรด"
void gradeFromScore(float s, char out[]) {
    if (s >= 80) strcpy(out, "A");      // 80 ขึ้นไป ได้ A
    else if (s >= 75) strcpy(out, "B+");// 75–79 ได้ B+
    else if (s >= 70) strcpy(out, "B"); // 70–74 ได้ B
    else if (s >= 65) strcpy(out, "C+");// 65–69 ได้ C+
    else if (s >= 60) strcpy(out, "C"); // 60–64 ได้ C
    else if (s >= 55) strcpy(out, "D+");// 55–59 ได้ D+
    else if (s >= 50) strcpy(out, "D"); // 50–54 ได้ D
    else strcpy(out, "F");              // ต่ำกว่า 50 ได้ F
} // End gradeFromScore

// ฟังก์ชันรับข้อมูลนักเรียนจากผู้ใช้
void inputStudent(S students[], int n) {
    printf("Student %d:\n", n + 1);

    printf("Name:\n");                      // กรอกชื่อ
    scanf(" %[^\n]", students[n].Name);     // อ่านทั้งบรรทัดจนกว่าจะเจอ Enter

    printf("ID:\n");                        // กรอกรหัส
    scanf("%s", students[n].ID);            // อ่าน string ไม่เว้นวรรค

    // รับคะแนนทีละวิชา
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

    printf("\n"); // เว้นบรรทัดเพื่อความสวยงาม
} // End inputStudent

// ฟังก์ชันแสดงผลข้อมูลนักเรียน
void printStudent(S students[], int n) {
    
    char g1[3], g2[3], g3[3], g4[3], g5[3]; // ตัวเก็บเกรดของแต่ละวิชา

    // แปลงคะแนนเป็นเกรดทีละวิชา
    gradeFromScore(students[n].ScoreSub1, g1);
    gradeFromScore(students[n].ScoreSub2, g2);
    gradeFromScore(students[n].ScoreSub3, g3);
    gradeFromScore(students[n].ScoreSub4, g4);
    gradeFromScore(students[n].ScoreSub5, g5);

    // แสดงข้อมูลนักเรียน
    printf("Student %d:\n", n + 1);
    printf("Name: %s\n", students[n].Name);
    printf("ID: %s\n", students[n].ID);

    // แสดงคะแนน 5 วิชา
    printf("Scores: %.0f %.0f %.0f %.0f %.0f\n",
           students[n].ScoreSub1, students[n].ScoreSub2,
           students[n].ScoreSub3, students[n].ScoreSub4,
           students[n].ScoreSub5);

    // แสดงเกรด 5 วิชา
    printf("Grades: %s %s %s %s %s\n", g1, g2, g3, g4, g5);

    printf("\n");
} // End printStudent

// ฟังก์ชันหลัก
int main() {
    S students[3]; // เก็บข้อมูลนักเรียน 3 คน

    printf("Enter the details of 3 students :\n");

    // วนลูปรับข้อมูลนักเรียน 3 คน
    for (int i = 0; i < 3; i++) {
        inputStudent(students, i);
    }

    // วนลูปแสดงข้อมูลนักเรียน 3 คน
    for (int i = 0; i < 3; i++) {
        printStudent(students, i);
    }

    return 0;
} // End main
