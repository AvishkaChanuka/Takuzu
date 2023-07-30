#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRID_SIZE 4

void PrintGrid(char** Grid);
void InputData(char** Grid);
void EmptyGrid(char** Grid);

int main(){

    /*
     *******************************************
     * Initialization
     *******************************************
    */

    //Dynamically allocate memory for the Grid
    char** grid = (char**)malloc(GRID_SIZE * sizeof(char*));

    for(int i = 0; i < GRID_SIZE; i++){
        grid[i] = (char*)malloc(GRID_SIZE * sizeof(char));
    }
    EmptyGrid(grid);

    InputData(grid);

    PrintGrid(grid);

    /*
     *******************************************
     * DeInitialization
     *******************************************
    */

    //Free Dynamically allocated memory
    for(int i = 0; i< GRID_SIZE; i++){
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}

void PrintGrid(char** Grid){

    for(int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++)
        {
            printf("%c\t", Grid[i][j]);
        }
        
        printf("\n\n");
    }
}

void InputData(char** Grid){

    int x,y;
    bool isValid[3] = {false,false,false};

    while(!isValid[0] || !isValid[1] || !isValid[2]){
        
        if(!isValid[0]){
            printf("Enter Row no (1 - %i): ", GRID_SIZE);
            scanf("%i",&x);

            if(x > 0 && x <= GRID_SIZE){
                isValid[0] = true;
            }
            else{
                printf("Invalid Row number! \n");
                continue;
            }
        }

        if(!isValid[1]){
            printf("Enter Col no (1 - %i): ", GRID_SIZE);
            scanf("%i",&y);

            if(y > 0 && y <= GRID_SIZE){
                isValid[1] = true;
            }
            else{
                printf("Invalid Column number! \n");
                continue;
            }
        }

        if(!isValid[2]){
            printf("Enter Value (0 or 1): ");
            scanf(" %c",&Grid[x-1][y-1]);

            if(Grid[x-1][y-1] == '0' || Grid[x-1][y-1] == '1'){
                isValid[2] = true;
            }
            else{
                printf("Invalid value! \n");
                continue;
            }
        }
    }
    
}

void EmptyGrid(char** Grid){
    for(int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++)
        {
            Grid[i][j] = '-';
        }
        
    }
}