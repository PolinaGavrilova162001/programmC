	Написать программу-календарь. Пользователь может указать даты в формате:
	- гггг.мм.дд – программа вычисляет день недели соответствующий данной дате;
	- гггг.мм – программа выводит календарь за данный месяц;
	- гггг – календарь за год;
	- now – текущую дату.
_________________
//подключаем библиотеки, стандартную и для работы со временем
#include <stdio.h>	
#include <time.h>	

//принимаем год, месяц и день
void print_day_of_week(int year, int month, int day)	
{
    struct tm time_struct = {0};	//структура 
    time_struct.tm_mon = month - 1;	//присваиваем значение, где вычисляем номер предыдущего месяца, переменной tm_mon структуры time_struct
    time_struct.tm_mday = day;	//присваиваем значение day полю tm_mday структуры time_struct
    mktime(&time_struct);	//преобразуем представление времени из структуры в число
    
    switch(time_struct.tm_wday)	//принимаем день недели
    {
        case 0:
            printf("Sunday\n");	//выводим воскресенье
            break;
        case 1:
            printf("Monday\n");	//выводим понедельник
            break;
        case 2:
            printf("Tuesday\n");	//вторник
            break;
        case 3:
            printf("Wednesday\n");	//среда
            break;
        case 4:
            printf("Thursday\n");	//четверг
            break;
        case 5:
            printf("Friday\n");	//пятница
            break;
        case 6:
            printf("Saturday\n");	//суббота
            break;
    }
}

//принимает год и месяц
void print_month_calendar(int year, int month)
{
    struct tm time_struct = {0};	//структура
    time_struct.tm_year = year - 1900;	//присваиваем значение, где вычисляется год начиная с 1900, полю tm_year структуры time_struct
    time_struct.tm_mon = month - 1;	//присваиваем значение, где вычисляем номер предыдущего месяца, переменной tm_mon структуры time_struct
    time_struct.tm_mday = 1;	//присваиваем значение day полю tm_mday структуры time_struct
    mktime(&time_struct);	//преобразуем в число

//выводит календарь месяца для указанного года и месяца
    printf(" S  M  T  W  T  F  S\n");	//выводим шапку для каждого месяца
    
    for (int i = 0; i < time_struct.tm_wday; i++)	//цикл, который выводит числа
    {
        printf("    ");
    }
    
    int days_in_month;	//вводим переменную дней в месяце
    if (month == 2)	//если месяц второй
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))	//если год делится на 4 И если год не делится на 100 ИЛИ если год делится на 400
        {
            days_in_month = 29;	//то переменная получает значение 29
        }
        else
        {
            days_in_month = 28;	//в противном случает получает значение 28
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month ==11)	//либо, если месяц 4, 6, 9, 11
    {
        days_in_month = 30;	//переменная получает значение 30
    }
    else
    {
        days_in_month = 31;	//в противном случае 31
    }
    
    for (int day = 1; day <= days_in_month; day++)	//цикл
    {
        printf("%3d", day);	//выводим дни
        if ((day + time_struct.tm_wday) % 7 == 0)	//если 7 чисел выведено
        {
            printf("\n");	//то переходим на новую строку
        }
    }
}

//принимает год и выводит на экран календарь для каждого месяца данного года
void print_year_calendar(int year)	
{
    for (int month = 1; month <= 12; month++)	//цикл
    {
        printf("\n\n%3d\n", month);	//выводим номер месяца
        print_month_calendar(year, month);	//и используем функцию для вывода календаря месяцев в году
    }
}

//получает информацию о текущей дате и времени и выводит ее в формате гггг-мм-дд
void print_current_date()	
{
    time_t current_time;	//текущее время
    struct tm* time_info;	//объявляем переменную
    time(&current_time);	//получаем текущее время
    time_info = localtime(&current_time);	//преобразуем значение в структуру 
    printf("Current date: %d-%02d-%02d\n", time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday);	//выводим текущую дату
}

int main() {	
    int year, month, day;	//вводим переменные год, месяц, день
    char input[50];	//вводим строку input, куда мы будем записывать данные

//запрашиваем у пользователя ввод строки в определенном формате и передаем это в строку
    printf("Enter 'yyyy.mm.dd' or 'yyyy.mm' or 'yyyy' or 'now' format: ");
    scanf("%s", input);

//анализ введенной строки и соответствующего вызова нужной функции в зависимости от формата
    if (sscanf(input, "%d.%d.%d", &year, &month, &day) == 3)	//если введены три переменные в строку
    {
        print_day_of_week(year, month, day);	//то выводим день недели
    }
    else if (sscanf(input, "%d.%d", &year, &month) == 2)	//либо, если введены год и месяц
    {
        print_month_calendar(year, month);	//то выводим календарь введенного месяца и года
    }
    else if (sscanf(input, "%d", &year) == 1)	//либо, если введен только год
    {
        print_year_calendar(year);	//то выводим календарь каждого месяца введенного года
    }
    else if (strcmp(input, "now") == 0)	//либо, если введено значение "now"
    {
        print_current_date();	//то выводим информацию о текущей дате и времени и выводит ее в формате гггг-мм-дд
    }
    else	//либо же
    {
        printf("Invalid Input. Expected formats: 'yyyy.mm.dd', 'yyyy.mm', 'yyyy', 'now'\n");	//выводим сообщение об ошибке
    }
    
    return 0;	//конец
}
