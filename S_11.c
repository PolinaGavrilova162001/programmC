Гилл Байтс хотел написать программу, которая по текущему времени выводит количество секунд, прошедших с начала суток.
Для этого требовалось, чтобы на вход программе подавались три числа (текущее время): первое — количество часов, второе — количество минут и третье — количество секунд.
  Но т.к. Гилл плохо изучил первые три урока, то допустил в своей программе много ошибок. Помогите Гиллу их исправить.

#include <stdio.h>  //подключаем библиотеку
int main(void)  //вводим функцию
{

  int h; //вводим переменную для значения часы
  int m; //вводим переменную для значения минуты
  int s; //вводим переменную для значения секунды

  scanf("%d",&h);  //заносим значение в переменную часы
  scanf("%d",&m);  //заносим значение в переменную минуты
  scanf("%d",&s);  //заносим значение в переменную секунды

  int seconds = h*60*60 + m*60 + s;  //считаем в переменную секунды значение

  printf("%d\n", seconds);  //выводим значение переменной секунды

  return 0;  //конец функции
}
