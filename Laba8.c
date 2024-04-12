Создать текстовый файл с записями, включающие имя/фамилию человека, год рождения, пол и рост (в метрах).
Упорядочить элементы по году рождения, имени/фамилии, полу или росту.
Вывести результат. Указать элемент, по которому следует упорядочить, через консоль.
А также реализовать возможность задавать несколько полей для упорядочивания.
___________________________________________________________________________________________________

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Person {
    char name[50];
    char surname[50];
    int birth_year;
    char gender;
    float height;
};

int comparator(const void *a, const void *b) {
    struct Person *personA = (struct Person *)a;
    struct Person *personB = (struct Person *)b;
    return personA->birth_year == personB->birth_year ? 
           personA->gender == personB->gender ? 
           strcmp(personA->name, personB->name) : personA->gender - personB->gender : 
           personA->birth_year - personB->birth_year;
}

int main() {
    int n, i, j;
    printf("n= ");
    scanf("%d", &n);
    
    struct Person* people = (struct Person*)malloc(n * sizeof(struct Person));
    
    for(i=0; i<n; i++) {
        printf("Name, surname, god rojdenia, pol (m/j), и rost (m) cheloveka %d:\n", i+1);
        scanf("%s %s %d %c %f", people[i].name, people[i].surname, &people[i].birth_year, &people[i].gender, &people[i].height);
    }

    int num_sort_fields;
    printf("Kolichestvo polei dlya sortirovki (max 4): ");
    scanf("%d", &num_sort_fields);
    
    int sort_field_indices[4];
    for(i=0; i<num_sort_fields; i++) {
        printf("Pole po kotoromy bydet otsortirovka %d (0: name, 1: surname, 2: god rojdenia, 3: pol, 4: rost): ", i+1);
        scanf("%d", &sort_field_indices[i]);
    }
    
    qsort(people, n, sizeof(struct Person), comparator);
    
    printf("\nGotovii spisok:\n");
    for(i=0; i<n; i++) {
        printf("%s %s, %d, %c, %.2f\n", people[i].name, people[i].surname, people[i].birth_year, people[i].gender, people[i].height);
    }
    
    free(people);
    
    return 0;
}

