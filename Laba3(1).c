#include <stdio.h>

int main()
{
const int x = 80;
char str[x];
if(fgets(str,x,stdin))
{
int i = 0;
while(str[i] ?= '\n')
{
if(isalpha(str[i])) /*проверяем строчный или заглавный символ*/
{
str[i] = toupper(str[i]);
}
i++;
}
printf("%s",str);
}
return 0;
}
