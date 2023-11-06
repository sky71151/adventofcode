#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkDubbel(char * firts, char *second, char *last);

int main() {
    FILE *file;
    char line[50]; // Adjust the size as needed
    int elfs[1500];
    int lines = 300;
    int index = 0;
    int score = 0;
    int lenght = 0;
    char backpack[301];
    int sum = 0;
    
    for (int i = 0; i < 301 ; i++)
    {
        backpack[i] = 0;
    }
    
    
    file = fopen("C:\\Users\\vanba\\OneDrive\\Documenten\\campus 19\\adventofcode\\2022\\ex00\\day3input.txt", "r"); // Replace with your file path
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    for (int i = 0; i < 100; i++)
    {
        fgets(line, sizeof(line), file);
        lenght = getlen(line);
        printf("%s\n",line);
        char *first = malloc(sizeof(char) * (lenght + 1));
        strcpy(first,line);

        fgets(line, sizeof(line), file);
        lenght = getlen(line);
        char *second = malloc(sizeof(char) * (lenght + 1));
        strcpy(second,line);

        fgets(line, sizeof(line), file);
        lenght = getlen(line);
        char *last = malloc(sizeof(char) * (lenght + 1));
        strcpy(last,line);

        if(!first)
        {
            printf("malloc error on first\n");
        }
        if (!second)
        {
            printf("malloc error on second");   /* code */
        }
        if (!last)
        {
            printf("malloc error on last");   /* code */
        }

        sum += checkDubbel(first,second,last);

        printf("index on %d\n",i);
        printf(" e1 = %s\n",first);
        printf(" E2 = %s\n",second);
        printf(" E3 = %s\n",last);


        free(first);
        free(second);
        free(last);
        
    }


    printf("final score = %d", sum);
    
    fclose(file);
    return 0;
    
    
    
}

int checkDubbel(char * firts, char *second, char *last)
{
    int seen[128];
    int index = 0;
    char c;
    int k = 0;

    for (int i = 0; i < 128 ; i++)
    {
        seen[i] = 0;
    }

    while (firts[index])
    {
        seen[firts[index]] = 1;
        index++;
    }
    index = 0;
    while (second[index])
    {
        if (seen[second[index]] == 1)
        {
            seen[second[index]] = 2;
            
        }
        index++;
        
    }
    index = 0;
    while (last[index])
    {
        if (seen[last[index]] == 2)
        {
            c = last[index];
            if (c >= 'a' && c <= 'z')
            {
                k += c - 96;
            }else if (c >= 'A' && c <= 'Z')
            {
                k += c - 38;
            }
            printf("sharing = %c\n",last[index]);

            seen[last[index]] = 3;
            
        }
        index++;
        
    }
    return k;
}

int getlen(char *str)
{
    int len = 0;
     while(str[len] != 10 && str[len] != 13 && str[len] != 0)
    {
        //printf("%d ",str[len]);
        len++;
    }
    str[len] = '\0';
    //printf("\n");
    return len;
}
