	Написать программу-календарь. Пользователь может указать даты в формате:
	- гггг.мм.дд – программа вычисляет день недели соответствующий данной дате;
	- гггг.мм – программа выводит календарь за данный месяц;
	- гггг – календарь за год;
	- now – текущую дату.
_________________

#include <stdio.h>	//подключаем библиотеку основную
#include <time.h>	//подключаем библиотеку

void print_day_of_week(int year, int month, int day)	//функция принимает год, месяц и день
{
    struct tm time_struct = {0};	//используем структуру tm чтобы определить день недели для указанной даты и вывести его на экран
    time_struct.tm_year = year - 1900;
    time_struct.tm_mon = month - 1;
    time_struct.tm_mday = day;
    mktime(&time_struct);
    
    switch(time_struct.tm_wday)
    {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
    }
}

void print_month_calendar(int year, int month)	//принимает год и месяц. Выводит календарь месяца для указанного года и месяца, каждое число представляет день месяца
{
    struct tm time_struct = {0};
    time_struct.tm_year = year - 1900;
    time_struct.tm_mon = month - 1;
    time_struct.tm_mday = 1;
    mktime(&time_struct);
    
    printf(" S  M  T  W  T  F  S\n");
    
    for (int i = 0; i < time_struct.tm_wday; i++)
    {
        printf("    ");
    }
    
    int days_in_month;
    if (month == 2)
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {
            days_in_month = 29;
        }
        else
        {
            days_in_month = 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month ==11)
    {
        days_in_month = 30;
    }
    else
    {
        days_in_month = 31;
    }
    
    for (int day = 1; day <= days_in_month; day++)
    {
        printf("%3d", day);
        if ((day + time_struct.tm_wday) % 7 == 0)
        {
            printf("\n");
        }
    }
}

void print_year_calendar(int year)	//принимает год и выводит на экран календарь для каждого месяца данного года
{
    for (int month = 1; month <= 12; month++)
    {
        printf("\n\n%3d\n", month);
        print_month_calendar(year, month);
    }
}

void print_current_date()	//получает информацию о текущей дате и времени и выводит ее в формате yyyy-mm-dd
{
    time_t current_time;
    struct tm* time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    printf("Current date: %d-%02d-%02d\n", time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday);
}

int main()	//происходит ввод строки от пользователя, которая обрабатывается с помощью sscanf для определения формата введенных данных и вызова соотвутствующих функций. Если ввод не соответствует ни одному из ожидаемых форматов, выводится ссобщение об ошибке.
{
    int year, month, day;
    char input[50];
    
    printf("Enter 'yyyy.mm.dd' or 'yyyy.mm' or 'yyyy' or 'now' format: ");
    scanf("%s", input);
    
    if (sscanf(input, "%d.%d.%d", &year, &month, &day) == 3)
    {
        print_day_of_week(year, month, day);
    }
    else if (sscanf(input, "%d.%d", &year, &month) == 2)
    {
        print_month_calendar(year, month);
    }
    else if (sscanf(input, "%d", &year) == 1)
    {
        print_year_calendar(year);
    }
    else if (strcmp(input, "now") == 0)
    {
        print_current_date();
    }
    else
    {
        printf("Invalid Input. Expected formats: 'yyyy.mm.dd', 'yyyy.mm', 'yyyy', 'now'\n");
    }
    
    return 0;	//конец
}
