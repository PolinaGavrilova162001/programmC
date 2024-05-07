#include <stdio.h>

#define MAX(x, y)((x) > (y) ? (x):(y))

int main()
{
    int n;
    printf("Vvedite kolichestvo elementov: ");
    scanf("%d", &n);
    
    int arri;
    
    printf("Vvedite %d elementov cherez probel: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arri);
    }
    
    int max = arri;
    for (int i = 1; i < n; i++)
    {
        max = MAX(max, arri);
    }
    
    printf("Maximalnoe chislo ravno: %d\n", max);
    
    return 0;
}
