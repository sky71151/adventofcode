#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char line[20]; // Adjust the size as needed
    int elfs[1500];
    int lines = 2500;
    int index = 0;
    int score = 0;

    
    for (int i = 0; i < 1500 ; i++)
    {
        elfs[i] = 0;
    }
    
    
    file = fopen("C:\\Users\\vanba\\OneDrive\\Documenten\\campus 19\\adventofcode\\2022\\ex00\\day4input.txt", "r"); // Replace with your file path
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    for (int i = 0; i < 1000; i++)
    {
        
        fgets(line, sizeof(line), file);
        //printf("%c + %c + %c + %c", line[0], line[1],line[3], line[4]);

       // for (int i = 0; i < 12; i++)
       // {
       //     printf("%d ",line[i]);
       // }
        

        char first[3];
        char last[3];
        int c = 0;
        index = 0;
        while (line[index] >= '0' && line[index] <= '9')
        {   
            
          
     
            
            first[c] = line[index];
            c++;
            index++;
            
        }

        first[c] = '\0';
        c = 0;
        index++;

        while (line[index] >= '0' && line[index] <= '9')
        {   
         
            last[c] = line[index];
            c++;
            index++;
            
        }
        
        last[c] = '\0';
        
        int first_elf[2];
        
        first_elf[0] = atoi(first);
        first_elf[1] = atoi(last);
        index++;
        c = 0;

        while (line[index] >= '0' && line[index] <= '9')
        {   
            
          
            first[c] = line[index];
            c++;
            index++;
            
        }

        first[c] = '\0';
        c = 0;
        index++;

        while (line[index] >= '0' && line[index] <= '9')
        {   
         
            last[c] = line[index];
            c++;
            index++;
            
        }
        
        last[c] = '\0';

        int last_elf[2];
        
        last_elf[0] = atoi(first);
        last_elf[1] = atoi(last);
        
        printf("%d and %d / %d and %d\n",first_elf[0],first_elf[1],last_elf[0],last_elf[1]);
        score += checkRange(first_elf,last_elf);
        
        

        

    }

    printf("total overlaps = %d\n", score);
   
    
    fclose(file);
    return 0;
    
    
    
    }

    int checkRange(int *first_elf, int *last_elf)
    {
        if( last_elf[0] >= first_elf[0] && last_elf[1] <= first_elf[1])
        {   
            printf("overlap\n");
            return 1;
        }else if (first_elf[0] >= last_elf[0] && first_elf[1]<= last_elf[1])
        {
            printf("overlap\n");
            return 1;
        }
        else if (first_elf[0] == last_elf[0] || first_elf[0] == last_elf[1])
        {
            return 1;
        }else if (first_elf[1] == last_elf[0] || first_elf[1] == last_elf[1])
        {
            return 1;
        }else if (first_elf[0] >= last_elf[0] && first_elf[0] <= last_elf[1] ) //hier
        {
            return 1;
        }
        else if (first_elf[1] >= last_elf[0] && first_elf[1]<= last_elf[1])
        {
            return 1;
        }else if (last_elf[0] >= first_elf[0] && last_elf <= first_elf[1])
        {
            return 1;
        }
        else if (last_elf[1] >= first_elf[0] && last_elf[1] <= first_elf[1])
        {
            return 1;
        }
        
        
        
        
        return 0;
        
    }