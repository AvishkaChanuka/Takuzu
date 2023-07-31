#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int GRID_SIZE  = 4;

//Select Game difficulty
void GameDifficulty();

//Print Game Rules
void GameRules();

//Print the current Grid
void PrintGrid(char** Grid);

//Assign a value to a cell
void InputData(char** Grid);

//Assign '-' to each cell for clear grid
void EmptyGrid(char** Grid);

//Check every cells have been filled with either 1 or 0
bool IsGridFull(char** Grid);

//Check Game rule 1
bool IsEqualCountRow(char** Grid);

//Check Game rule 2
bool IsEqualCountCol(char** Grid);

//Check Game rule 3
bool IsTwoRowsIdentical(char** Grid);

//Check Game rule 4
bool IsTwoColsIdentical(char** Grid);

//Print message in Ascill comment style
void PrintMessage(char msg[]);

int main(){

    /*
     *******************************************
     * Initialization
     *******************************************
    */

    PrintMessage("Welcome to Takuzu *");

    //Game difficulty
    GameDifficulty();


    //Dynamically allocate memory for the Grid
    char** grid = (char**)malloc(GRID_SIZE * sizeof(char*));

    for(int i = 0; i < GRID_SIZE; i++){
        grid[i] = (char*)malloc(GRID_SIZE * sizeof(char));
    }
    EmptyGrid(grid);

    bool rule1 = false, rule2 = false, rule3 = false, rule4 = false, isGameOver = false;

    GameRules();

    PrintGrid(grid);

    /*
     *******************************************
     * Game Loop
     *******************************************
    */
    while(!isGameOver){

        //IsGridFull(grid)
        //Handle User Input
        InputData(grid);

        //Print the grid in each game loop
        printf("\n");
        PrintGrid(grid);

        //Check Game Rule: Equal Number of 0s and 1s each row
        rule1 = IsEqualCountRow(grid);
        if(rule1 == false){
            PrintMessage("Equal Number of 0s and 1s shuld be in each row");
        }

        //Check Game Rule: Equal Number of 0s and 1s each column
        rule2 = IsEqualCountCol(grid);
        if(rule2 == false){
            PrintMessage("Equal Number of 0s and 1s shuld be in each Column");
        }

        //Check Game Rule: No two rows can be identical
        rule3 = IsTwoRowsIdentical(grid);
        if(rule3 == false){
            PrintMessage("No two rows can be identical");
        }

        //Check Game Rule: No two columns can be identical
        rule4 = IsTwoColsIdentical(grid);
        if(rule4 == false){
            PrintMessage("No two Columns can be identical");
        }
        
        if(IsGridFull(grid)){
            
            if(rule1 && rule2 && rule3 && rule4){
                PrintMessage("Hurray! You win the Game!!!");
            }
            else{
                PrintMessage("Sorry! Game Over!!!");
            }
            isGameOver = true;
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

void GameDifficulty(){
    bool isValid = false;
    int index, difficulty[] = {4,6,8};

    printf("\n");
    printf("1 - 4x4 Grid (Beginner)\n");
    printf("2 - 8x8 Grid (Intermediate)\n");
    printf("3 - 6x6 Grid (Pro)\n\n");

    while (!isValid)
    {
        printf("Select Grid Size (1 or 2 or 3): ");
        scanf("%i",&index);

        if(index > 0 && index < 4){
            GRID_SIZE = difficulty[index-1];
            isValid = true;
        }
    }
    

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

void GameRules(){
    printf("\n");
    printf("Game Rules\n");
    printf("-----------\n\n");
    printf("Rule 0 - Each cell must be fill with either 0 or 1\n");

    printf("Rule 1 - Equal Number of 0s and 1s shuld be in each rows\n");
    printf("Rule 2 - Equal Number of 0s and 1s shuld be in each columns\n");

    printf("Rule 3 - No two rows can be identical\n");
    printf("Rule 4 - No two Columns can be identical\n");

    printf("\nLet's Begin...\n\n");
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

    int count = 0;

    for(int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if(Grid[i][j] != '-'){
                count++;
            }
        }
    }

    if(count == (GRID_SIZE * GRID_SIZE)){
        return true;
    }
    else{
        return false;
    }

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

    int decimalNum[GRID_SIZE];
    int decimalCount[GRID_SIZE];

    for(int i = 0; i< GRID_SIZE; i++){
        decimalNum[i] = 0;
        decimalCount[i] = 0;
    }

    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            if(Grid[i][j] == '1'){
                decimalNum[i] += pow(2,(GRID_SIZE - (j+1)));
            }

            if(Grid[i][j] != '-'){
                decimalCount[i]++;
            }
        }
    }

    for (int i = 0; i < GRID_SIZE-1; i++)
    {
        for(int j = i+1; j<GRID_SIZE; j++){
            if(decimalNum[i] == decimalNum[j] && decimalNum[i] != 0 && decimalNum[j] != 0 && decimalCount[i] == 4 && decimalCount[j] == 4){
                return false;
            }
        }
    }

    return true;
    
}

bool IsTwoColsIdentical(char** Grid){

    int decimalNum[GRID_SIZE];
    int decimalCount[GRID_SIZE];

    for(int i = 0; i< GRID_SIZE; i++){
        decimalNum[i] = 0;
        decimalCount[i] = 0;
    }

    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            if(Grid[j][i] == '1'){
                decimalNum[i] += pow(2,(GRID_SIZE - (j+1)));
            }

            if(Grid[j][i] != '-'){
                decimalCount[i]++;
            }
        }
    }

    for (int i = 0; i < GRID_SIZE-1; i++)
    {
        for(int j = i+1; j<GRID_SIZE; j++){
            if(decimalNum[i] == decimalNum[j] && decimalNum[i] != 0 && decimalNum[j] != 0 && decimalCount[i] == 4 && decimalCount[j] == 4){
                return false;
            }
        }
    }

    return true;
    
}

void PrintMessage(char msg[]){
    int length = strlen(msg) + 1;

    for(int i = 0; i<=length; i++){
        printf("*");
    }

    printf("\n* %s \n",msg);

    for(int i = 0; i<=length; i++){
        printf("*");
    }
    printf("\n");
}