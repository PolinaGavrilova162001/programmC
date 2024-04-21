#include <stdio.h>
#include <string.h>
    
struct humen
{
    char name[20];
    char surname[20];
    int year, i, j;
};

int main()
{
    int N=4;
    struct humen h1[N];
    struct humen h2[N];

    printf("Введите данные для 4 человек:\n");
    for(int i=0; i<N; i++)
    {
        printf("Человек %d:\n", i+1);
        printf("Имя: ");
        scanf("%s", h1[i].name);
        printf("Фамилия: ");
        scanf("%s", h1[i].surname);
        printf("Год рождения: ");
        scanf("%d", &h1[i].year);
    }

    memcpy(h2, h1, sizeof(h1));

    for(int i=0; i<N-1; i++)
    {
        for(int j=i+1; j<N-i-1; j++)
        {
            if(h2[j].year > h2[j+1].year)
            {
                struct humen temp = h2[j+1];
                h2[j+1] = h2[j];
                h2[j] = temp;
            }
        }
    }

    printf("Упорядоченный по годам рождения массив людей:\n");
    for(int i=0; i<N; i++)
    {
        printf("Человек %d: %s %s, %d год\n", i+1, h2[i].name, h2[i].surname, h2[i].year);
    }

    return 0;
}
