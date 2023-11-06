#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char line[10]; // Adjust the size as needed
    int elfs[1500];
    int lines = 2500;
    int index = 0;
    int score = 0;

    
    for (int i = 0; i < 1500 ; i++)
    {
        elfs[i] = 0;
    }
    
    
    file = fopen("C:\\Users\\vanba\\OneDrive\\Documenten\\campus 19\\adventofcode\\2022\\ex00\\day2input.txt", "r"); // Replace with your file path
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    for (int i = 0; i < lines; i++)
    {
      
        fgets(line, sizeof(line), file);
        //printf("%s", line);

        char op = line[0];
        char me = line[2];
            
        if (op == 'A')          //steen
        {
            if (me == 'X')  //moet verliezen
            {   
                score += 3;
            }else  if (me == 'Y')   //moet gelijkspel
            {
                score += 3 + 1;
            }else  if (me == 'Z')   //moet winnen
            {
                score += 2 + 6;
            }      
        }
        
        if (op == 'B')          //papier
        {
            if (me == 'X')          //moet verliezen
            {   
                score += 1;
            }else  if (me == 'Y')       //moet gelijkspel
            {
                score += 2 + 3;
            }else  if (me == 'Z')       //moet winnen
            {
                score += 3 + 6;
            }      
        }

        if (op == 'C')          //schaar
        {
            if (me == 'X')          //moet verliezen
            { 
                score += 2;
            }else  if (me == 'Y')   //moet gelijkspel
            {
                score += 3 + 3;
            }else  if (me == 'Z')   //moet winnen
            {
                score += 1 + 6;
            }      
        }
        
    }
    printf("final score = %d", score);
    
    fclose(file);
    return 0;
    
    
    
    }