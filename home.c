#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main()
{
    int total;
    int avg;
    int counter;

    FILE* stream = fopen("649.csv", "r");

    char line[1024];
    int p = 0;
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        total += atoi(getfield(tmp, 5));
        //printf("%d\n", total);
        // NOTE strtok clobbers tmp
        if(p == 0 ) {
            printf("%d\n", total);
            p += 1;
        }
        free(tmp);
        counter++;
    }

    // Compute the Average
    avg = counter / total;

    printf("Average First Number: %d\n", avg);
}