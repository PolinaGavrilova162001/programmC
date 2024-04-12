Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения.
Объявить два массива из четырёх элементов типа humen.
Ввести с консоли или из файла элементы одного массива
и построить на их основе другой, упорядочив элементы по годам рождения.
Вывести результат.
___________________________________________________________________________________________

#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char name[50];  //строка имена
    char surname[50];  //строка фамилии
    int birth_year;  //переменная года рождения
} human;

int main() {
    setlocale(LC_ALL, "Rus");  //руссификатор
    human arr1[4];
    human arr2[4];

    // Ввод данных для первого массива
    printf("Введите данные для 4 человек:\n");
    for(int i=0; i<4; i++) {
        printf("Человек %d:\n", i+1);
        printf("Имя: ");
        scanf("%s", arr1[i].name);
        printf("Фамилия: ");
        scanf("%s", arr1[i].surname);
        printf("Год рождения: ");
        scanf("%d", &arr1[i].birth_year);
    }

    // Копирование первого массива во второй
    memcpy(arr2, arr1, sizeof(arr1));

    // Сортировка массива по годам рождения
    for(int i=0; i<4; i++) {
        for(int j=i+1; j<4; j++) {
            if(arr2[i].birth_year > arr2[j].birth_year) {
                human temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }

    // Вывод отсортированного массива
    printf("Упорядоченный по годам рождения массив людей:\n");
    for(int i=0; i<4; i++) {
        printf("Человек %d: %s %s, %d год\n", i+1, arr2[i].name, arr2[i].surname, arr2[i].birth_year);
    }

    return 0;
}
