В следующей программе переменные объявлены внутри программы. Исправьте её таким образом, чтобы значения переменных a, b, и с считывались функцией scanf.

  #include <stdio.h> 
int main(void) {
  int a, b, res;
  
  scanf("%d", &a);  
  scanf("%d", &b);
  res = a + b;
  
  int c;
  scanf("%d", &c);
  res = res - c;

  printf("%d\n", res);
  return 0;
}
