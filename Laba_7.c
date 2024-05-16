#include <stdio.h>
#include <string.h>    //подключаем библиотеки
    
struct humen    //вводим структуру humen
{
    char name[50];  //строка имена
    char surname[50];  //строка фамилии
    int year, i, j;  //переменная года рождения
};

int main()    //вводим функцию main
{
    int N = 4;    //вводим переменную N
    struct humen arr1[N];    //вводим размер структуры humen arr1 и arr2
    struct humen arr2[N];

    // Ввод данных для первого массива
    printf("Введите данные для 4 человек:\n");
    for(int i=0; i<N; i++)
    {
        printf("Человек %d:\n", i+1);
        printf("Имя: ");
        scanf("%s", arr1[i].name);
        printf("Фамилия: ");
        scanf("%s", arr1[i].surname);
        printf("Год рождения: ");
        scanf("%d", &arr1[i].year);
    }

    // Копирование первого массива во второй
    memcpy(arr2, arr1, sizeof(arr1));

    // Сортировка массива по годам рождения
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            if(arr2[i].year > arr2[j].year)
            {
                struct humen temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }

    // Вывод отсортированного массива
    printf("Упорядоченный по годам рождения массив людей:\n");
    for(int i=0; i<N; i++)
    {
        printf("Человек %d: %s %s, %d год\n", i+1, arr2[i].name, arr2[i].surname, arr2[i].year);
    }

    return 0;
}
