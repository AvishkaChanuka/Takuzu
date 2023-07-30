#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 4

void PrintGrid(char** Grid);

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