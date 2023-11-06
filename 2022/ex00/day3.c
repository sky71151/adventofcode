#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkDubbel(char * front, char *back);

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
    for (int i = 0; i < 300; i++)
    {
        fgets(line, sizeof(line), file);
        //printf("%s", line);

        //printf("line %d = %d characters\n", i, getlen(line));
        lenght = getlen(line);
        char *front = malloc(sizeof(char) * ((lenght / 2) + 1));
        char *back = malloc(sizeof(char) * ((lenght / 2) + 1));
        if(!front)
        {
            printf("malloc error on front\n");
        }
        if (!back)
        {
            printf("malloc error on back");   /* code */
        }
        spilt(front,back,line,lenght);

        printf("backpack nr %d\n", i);
        printf("front = %s\n", front);
        printf("back  = %s\n", back);

        sum += checkDubbel(front,back);
        
        free(front);
        free(back);
    }
    printf("total sum = %d\n",sum);

    
}

int checkDubbel(char * front, char *back)
{
    int seen[128];
    int index = 0;
    char c;
    int k = 0;

    for (int i = 0; i < 128 ; i++)
    {
        seen[i] = 0;
    }

    while (front[index])
    {
        seen[front[index]] = 1;
        index++;
    }
    index = 0;
    while (back[index])
    {
        if (seen[back[index]] == 1)
        {
            
            c = back[index];
            if (c >= 'a' && c <= 'z')
            {
                k += c - 96;
            }else if (c >= 'A' && c <= 'Z')
            {
                k += c - 38;
            }
            printf("dubbel = %c\n",back[index]);
            seen[back[index]] = 2;
            
        }
        index++;
        
    }
    return k;
}

void spilt(char *front, char *back, char *source, int size)
{
    int index = 0;
    while (index < (size / 2))
    {
        front[index] = source[index];
        index++;
    }
    front[index] = '\0';
    int x = 0;
    while (index < size)
    {
        back[x] = source[index];
        index++;
        x++;
    }
    back[x] = '\0';  
}

int getlen(char *str)
{
    int len = 0;
    while(str[len] != 10 && str[len] != 13 && str[len] != 0)
    {
        //printf("%d ",str[len]);
        len++;
    }
   // printf("\n");
    return len;
}