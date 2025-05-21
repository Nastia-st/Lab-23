#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[100];
    char size[50];
    char genre[50];
    int year;
    char author[100];
} Painting;

int main() {
    system("chcp 65001");
    Painting paintings[MAX] = {
        {"Весна в Карпатах", "60x80", "пейзаж", 1995, "Іван Іваненко"},
        {"Портрет Марії", "50x70", "портрет", 2001, "Олена Петренко"},
        {"Захід сонця", "70x90", "пейзаж", 2010, "Петро Сидоренко"},
        {"Квіти", "40x60", "натюрморт", 1999, "Наталя Білик"}
    };

    int n = 4;
    FILE *file = fopen("peizazhi.txt", "w");
    if (file == NULL) {
        printf("Помилка відкриття файлу!\n");
        return 1;
    }
    printf("Картини жанру 'пейзаж':\n");
    fprintf(file, "Картини жанру 'пейзаж':\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(paintings[i].genre, "пейзаж") == 0) {
            printf("Назва: %s\n", paintings[i].name);
            printf("Розмір: %s\n", paintings[i].size);
            printf("Жанр: %s\n", paintings[i].genre);
            printf("Рік: %d\n", paintings[i].year);
            printf("Автор: %s\n\n", paintings[i].author);

            fprintf(file, "Назва: %s\n", paintings[i].name);
            fprintf(file, "Розмір: %s\n", paintings[i].size);
            fprintf(file, "Жанр: %s\n", paintings[i].genre);
            fprintf(file, "Рік: %d\n", paintings[i].year);
            fprintf(file, "Автор: %s\n\n", paintings[i].author);
        }
    }

    fclose(file);
    return 0;
}