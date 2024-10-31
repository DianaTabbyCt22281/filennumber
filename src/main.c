#include <stdio.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    struct Student students[n];
    FILE *file = fopen("students.txt", "a");  // Open in append mode

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Input for n students
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
        
        // Write to file
        fprintf(file, "%s %d\n", students[i].name, students[i].marks);
    }

    fclose(file);
    printf("Data appended to students.txt\n");
    return 0;
}