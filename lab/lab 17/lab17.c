#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// โครงสร้างข้อมูลหนังสือ
typedef struct {
    int id;
    char title[100];
    char author[100];
    int year;
} Book;

// เพิ่มหนังสือใหม่
void addBook(Book books[], int *count) {
    printf("Enter Book ID: ");
    scanf("%d", &books[*count].id);
    getchar(); // เคลียร์ newline

    printf("Enter Title: ");
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = '\0'; // ลบ newline

    printf("Enter Author: ");
    fgets(books[*count].author, sizeof(books[*count].author), stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = '\0';

    printf("Enter Year: ");
    scanf("%d", &books[*count].year);

    (*count)++;
    printf("Book added successfully!\n");
}

// ค้นหาหนังสือตามชื่อ
void searchBook(Book books[], int count, char title[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

// แสดงรายการหนังสือทั้งหมด
void displayBooks(Book books[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Book ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Year: %d\n\n", books[i].year);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;
    char searchTitle[100];

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Book\n");
        printf("2. Search Book by Title\n");
        printf("3. Display All Books\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // เคลียร์ newline

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                printf("Enter Title to Search: ");
                fgets(searchTitle, sizeof(searchTitle), stdin);
                searchTitle[strcspn(searchTitle, "\n")] = '\0';
                searchBook(books, count, searchTitle);
                break;
            case 3:
                displayBooks(books, count);
                break;
            case 0:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}