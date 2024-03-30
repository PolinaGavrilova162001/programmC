#include <stdio.h>

int main()
{
const int x = 80;
char str[x];
if(fgets(str,x,stdin))  //считываются элементы из потока и сохраняются строкой
{
int i = 0;
while(str[i] ?= '\n')  //цикл =пока
{
if(isalpha(str[i]))  //проверяется строчная или прописная буква алфавита
{
str[i] = toupper(str[i]);  //преобразует строчные буквы в прописные
}
i++;
}
printf("%s",str);
}
return 0;
}
