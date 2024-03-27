#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *input, *output;
    char buffer[1024];
    int year = 1980;
    
    input=fopen("input.txt", "r");
    if (input==NULL)
    {
        fputs("Error", stderr);
        exit(1);
    }
    
    output=fopen("output.txt", "w");
    if (output==NULL)
    {
        fprintf(stderr, "Error\n");
        exit(1);
    }
    
    while (fgets(buffer, sizeof(buffer), input)!=NULL)
    {
        char*year_str=strtok(buffer, "\n");
        if (year_str!=NULL)
        {
            int parsed_year=atoi(year_str);
            if (parsed_year>year)
            {
                fputs(buffer, output);
            }
        }
    }




    #include <stdio.h>
#include <stdlib.h>
int main() {
FILE *fpIn, *fpOut;
char name[100], year[5];
int yearRead;
// Открываем входной и выходной файлы
if ((fpIn = fopen("input.txt", "r")) == NULL) {
    printf("Ошибка открытия входного файла!\n");
    exit(1);
}
if ((fpOut = fopen("output.txt", "w")) == NULL) {
    fclose(fpIn);
    printf("Ошибка создания выходного файла!\n");
    exit(2);
}

while (fscanf(fpIn, "%s %c", name, year) == 2) {
    // Считываем данные из входного файла
    yearRead = atoi(year);

    if (yearRead > 1980) {
        // Если год рождения больше 1980, записываем в выходной файл
sprintf(year, "%d", yearRead); // форматированный вывод года
fprintf(fpOut, "%s %s\n", name, year);
}
}
fclose(fpIn);  // Закрываем входные файлы

return 0;
}
    fclose(input);
    fclose (output);
    
    return 0;
}
