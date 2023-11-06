#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int container[10][150] = {{8,'D','T','R','B','J','L','W','G'},{3,'S','W','C'},{4,'R','Z','T','M'},{7,'D','T','C','H','S','P','V'},{6,'G','P','T','L','D','Z'},{8,'F','B','R','Z','J','Q','C','D'},{8,'S','B','D','J','M','F','T','R'},{7,'L','H','R','B','V','V','M'},{5,'Q','P','D','S','V'}};

int main() {
    FILE *file;
    char line[4095]; // Adjust the size as needed
    int elfs[1500];
    int lines = 2500;
    int index = 0;
    int score = 0;
    int max_index = 4093;

    int number = 0;
    int from = 0;
    int to = 0;
    


    //printContainer();

    
    
    file = fopen("C:\\Users\\vanba\\OneDrive\\Documenten\\campus 19\\adventofcode\\2022\\ex00\\day6text.txt", "r"); // Replace with your file path
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    for (int i = 0; i < 1; i++)
    {
        
        fgets(line, sizeof(line), file);
        //printf("%c + %c + %c + %c", line[0], line[1],line[3], line[4]);

       // for (int i = 0; i < 12; i++)
       // {
       //     printf("%d ",line[i]);
       // }
        index = 13;
       while( index != 4095)
       {
        if (checkdubbel(line,&index) == 1 )
        {
            printf("start is on %d", (index+1));
            break;
        }
        
        index++;
       }

       


    }

    printf("total overlaps = %d\n", score);
   
    
    fclose(file);
    return 0;
}

int checkdubbel(char *str, int *index)
{
    int seen[128];

    for (int i = 0; i < 128; i++)
    {
        seen[i] = 0;
    }

    for (int i = 0; i < 14; i++)
    {
        if(seen[str[*index - i]] == 0)
        {
            seen[str[*index - i]] = 1;
        }else if(seen[str[*index - i]] == 1){
            return 0;
        }
    }
    return 1;
        
}
    
    
  