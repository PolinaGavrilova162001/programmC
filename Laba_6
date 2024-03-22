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
    fclose(input);
    fclose (output);
    
    return 0;
}
