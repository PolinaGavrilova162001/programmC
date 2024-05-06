#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double unary_op(char op, double operand)
{
    if (op == '-')
    {
        return -operand;
    }
    else
    {
        return operand;
    }
}

double calculate(char *expression)
{
    double result = 0.0;
    char *token;
    char *delimiter = " ";
    
    token = strtok(expression, delimiter);
    
    if (token != NULL)
    {
        result = atof(token);
    }
    
    while ((token = strtok(NULL, delimiter)) != NULL)
    {
        char op = token[0];
        token = strtok(NULL, delimiter);
        double operand = atof(token);
        
        if (op == '+' || op == '-')
        {
            result += unary_op(op, operand);
        }
        else
        {
            printf("Error");
            return 0.0;
        }
    }
    return result;
}

int main()
{
    char expression[100];
    
    printf("Vvedite arifmeticheskoe vurajenie: ");
    fgets(expression, sizeof(expression), stdin);
    
    if (expression[strlen(expression) - 1] == '\n')
    {
        expression[strlen(expression) - 1] = '\0';
    }
    
    double result = calculate(expression);
    
    printf("Rezultat: %.2f/n", result);
    
    return 0;
}
