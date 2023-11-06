#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char line[10]; // Adjust the size as needed
    int elfs[1500];
    int lines = 2249;
    int index = 0;
    int counter = 0;

    for (int i = 0; i < 1500 ; i++)
    {
        elfs[i] = 0;
    }
    
    
    file = fopen("C:\\Users\\vanba\\OneDrive\\Documenten\\campus 19\\adventofcode\\2022\\ex00\\text.txt", "r"); // Replace with your file path
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    for (int i = 0; i < lines; i++)
    {
        fgets(line, sizeof(line), file);


        if(line[0] == 10)
        {
            printf("10 gevonden op index 0\n");
            printf( "valua of elf%d = %d\n",index, elfs[index]);
            index++;
        }else{
            elfs[index] += atoi(line);
            
        }
    }

    int max = elfs[0];
    int max_index = 0;
    for (int i = 0; i < 253; i++)
    {
        if (max < elfs[i])
        {
            max = elfs[i];  /* code */
            max_index = i;
        }
        
    }

    elfs[253] = 49545;

    printf( "maxium elf%d = %d\n",max_index, max);

    sort(&elfs,253);
    
/*
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
*/
    fclose(file);
    return 0;
}

void sort(int elfs[], int n)
{
    int i = 0;
    int j = 0;
    int index = 0;
    while(index < n )
    {
        if (elfs[index] > elfs[index + 1])
        {
            int tmp = elfs[index];
            elfs[index] = elfs[index +1];
            elfs[index + 1] = tmp;
            index = 0;
        }
        index ++;
    }

    printf("elf 1 = %d\n", elfs[253]);
    printf("elf 2 = %d\n", elfs[252]);
    printf("elf 3 = %d\n", elfs[251]);
    int som = elfs[253] + elfs[252] + elfs[251];
    printf("total of top 3 elfs = %d", som);
    

}