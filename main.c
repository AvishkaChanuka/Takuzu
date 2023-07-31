#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 4

void PrintGrid(char** Grid);
void InputData(char** Grid);
void EmptyGrid(char** Grid);
bool IsGridFull(char** Grid);
bool IsEqualCountRow(char** Grid);
bool IsEqualCountCol(char** Grid);
bool IsTwoRowsIdentical(char** Grid);
bool IsTwoColsIdentical(char** Grid);

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

    /*
     *******************************************
     * Game Loop
     *******************************************
    */
    while(!IsGridFull(grid)){

        //Handle User Input
        InputData(grid);

        //Print the grid in each game loop
        PrintGrid(grid);

        //Check Game Rule: Equal Number of 0s and 1s each row
        if(IsEqualCountRow(grid) == false){
            printf("Equal Number of 0s and 1s shuld be in each row\n");
        }

        //Check Game Rule: Equal Number of 0s and 1s each column
        if(IsEqualCountCol(grid) == false){
            printf("Equal Number of 0s and 1s shuld be in each Column\n");
        }

        //Check Game Rule: No two rows can be identical
        
        if(IsTwoRowsIdentical(grid) == false){
            printf("No two rows can be identical\n");
        }

        //Check Game Rule: No two columns can be identical

        if(IsTwoColsIdentical(grid) == false){
            printf("No two Columns can be identical\n");
        }
        
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

bool IsGridFull(char** Grid){

    bool isFull = false;

    for(int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if(Grid[i][j] == '-'){
                isFull = false;
            }
            else{
                isFull = true;
            }
        }
    }

    return isFull;
}

bool IsEqualCountRow(char** Grid){

    int count_0 = 0, count_1 = 0;
    int checkCount = GRID_SIZE/2; 

    for(int i = 0; i < GRID_SIZE; i++){

        count_0 = 0; count_1 = 0;

        for(int j = 0; j < GRID_SIZE; j++){

            if(Grid[i][j] == '0'){

                count_0++;

            }
            else if(Grid[i][j] == '1'){

                count_1++;

            }

        }

        if(count_0 > checkCount || count_1 > checkCount){
        
            return false;
        }
    }
    return true;
}

bool IsEqualCountCol(char** Grid){

    int count_0 = 0, count_1 = 0;
    int checkCount = GRID_SIZE/2; 

    for(int i = 0; i < GRID_SIZE; i++){

        count_0 = 0; count_1 = 0;

        for(int j = 0; j < GRID_SIZE; j++){

            if(Grid[j][i] == '0'){

                count_0++;

            }
            else if(Grid[j][i] == '1'){

                count_1++;

            }

        }

        if(count_0 > checkCount || count_1 > checkCount){
        
            return false;
        }
    }
    return true;
}

bool IsTwoRowsIdentical(char** Grid){

    int decimalNum[GRID_SIZE] = {0,0,0,0};

    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            if(Grid[i][j] == '1'){
                decimalNum[i] += pow(2,(GRID_SIZE - (j+1)));
            }
        }
    }

    for (int i = 0; i < GRID_SIZE-1; i++)
    {
        for(int j = i+1; j<GRID_SIZE; j++){
            if(decimalNum[i] == decimalNum[j] && decimalNum[i] != 0 && decimalNum[j] != 0){
                return false;
            }
        }
    }

    return true;
    
}

bool IsTwoColsIdentical(char** Grid){

    int decimalNum[GRID_SIZE] = {0,0,0,0};

    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            if(Grid[j][i] == '1'){
                decimalNum[i] += pow(2,(GRID_SIZE - (j+1)));
            }
        }
    }

    for (int i = 0; i < GRID_SIZE-1; i++)
    {
        for(int j = i+1; j<GRID_SIZE; j++){
            if(decimalNum[i] == decimalNum[j] && decimalNum[i] != 0 && decimalNum[j] != 0){
                return false;
            }
        }
    }

    return true;
    
}