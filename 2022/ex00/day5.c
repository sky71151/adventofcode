#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int container[10][150] = {{8,'D','T','R','B','J','L','W','G'},{3,'S','W','C'},{4,'R','Z','T','M'},{7,'D','T','C','H','S','P','V'},{6,'G','P','T','L','D','Z'},{8,'F','B','R','Z','J','Q','C','D'},{8,'S','B','D','J','M','F','T','R'},{7,'L','H','R','B','V','V','M'},{5,'Q','P','D','S','V'}};

int main() {
    FILE *file;
    char line[40]; // Adjust the size as needed
    int elfs[1500];
    int lines = 2500;
    int index = 0;
    int score = 0;

    int number = 0;
    int from = 0;
    int to = 0;
    


    //printContainer();

    
    
    file = fopen("C:\\Users\\vanba\\OneDrive\\Documenten\\campus 19\\adventofcode\\2022\\ex00\\day5text.txt", "r"); // Replace with your file path
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    for (int i = 0; i < 503; i++)
    {
        
        fgets(line, sizeof(line), file);
        //printf("%c + %c + %c + %c", line[0], line[1],line[3], line[4]);

       // for (int i = 0; i < 12; i++)
       // {
       //     printf("%d ",line[i]);
       // }

        number = 0;
        from = 0;
        to = 0;
        index = 0;
       while (line[index] < '0' || line[index] > '9')
       {
            index++;
       }
       while (line[index] >= '0' && line[index] <= '9')
       {
            number *= 10;
            number += (line[index] - 48);
            index++;
       }

        while (line[index] < '0' || line[index] > '9')
       {
            index++;
       }
       while (line[index] >= '0' && line[index] <= '9')
       {
            from *= 10;
            from += (line[index] - 48);
            index++;
       }

        while (line[index] < '0' || line[index] > '9')
       {
            index++;
       }
       while (line[index] >= '0' && line[index] <= '9')
       {
            to *= 10;
            to += (line[index] - 48);
            index++;
       }

       
       printf("%d and %d and %d and line = %d\n", number,from,to, i);
      
        int y = number;
       while (number)
       {
        int x = container[from -1][container[from - 1][0]-(number - 1)];
        container[from - 1][container[from - 1][0] - (number - 1)] = 0;
        //container[from - 1][0] -= 1;
        container[to - 1][(container[to -1][0] + 1)] = x;
        container[to - 1][0] +=1;
        number--;
       }
       container[from - 1][0] -= y;
       printContainer();
       

       
       
       
       
       
        

        
        

        

    }

    printf("total overlaps = %d\n", score);
   
    
    fclose(file);
    return 0;
}

void printContainer(void)
{
        for (int i = 50; i >= 1; i--)
    {
        for (int j = 0; j < 9 ; j++)
        {
            if (container[j][i] != 0)
            {
                printf("[%c]", container[j][i]);
            }else{
                printf("   ");
            }

            
        }
        printf("\n");
        
        
    }
}
    
    
  