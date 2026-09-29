#include<iostream>
#include<cstdlib>
#include<windows.h>

using namespace std;

int block[9][9];                      //universal block for the sudoku
bool isFixed[9][9];                   //an indicator to check that the cell is filled (a very very useful tool for future uses)

void displayBoard(){                  //logic for displaying the board
         cout << " ___________________________________\n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(j<1){
                cout << "\u2016";          //the \u2016 is a special character identifier
            }
            cout << "  ";
            if((j+1)%3 == 0){
                cout << " \u2016";
            }
            else{
                cout << " |";
            }
        }
        cout << "\n";
        if((i+1)%3 == 0 && i != 8){
            cout << "\u2016===|===|===\u2016===|===|===\u2016===|===|===\u2016\n";
        }
        else{
            cout << "\u2016___|___|___\u2016___|___|___\u2016___|___|___\u2016\n";
        }
    }
}

void workBoard(){
         cout << " ___________________________________\n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(j<1){
                cout << "\u2016";
            }
            cout << " " << block[i][j];
            if((j+1)%3 == 0){
                cout << " \u2016";
            }
            else{
                cout << " |";
            }
        }
        cout << "\n";
        if((i+1)%3 == 0 && i != 8){
            cout << "\u2016===|===|===\u2016===|===|===\u2016===|===|===\u2016\n";
        }
        else{
            cout << "\u2016___|___|___\u2016___|___|___\u2016___|___|___\u2016\n";
        }
    }
}

bool checkBlock(int num, int row_val, int col_val){                    //rules for placing a number in the sudoku

    //checking row
    for(int col_diff=0;col_diff<9;col_diff++){
        if(col_val == col_diff){
            continue;
        }
        if(block[row_val][col_diff] == num){
            return true;
        }
    }

    //checking column
    for(int row_diff=0;row_diff<9;row_diff++){
        if(row_val == row_diff){
            continue;
        }
        if(block[row_diff][col_val] == num){
            return true;
        }
    }

    //checking box
    int rowBox = (row_val/3)*3;
    int colBox = (col_val/3)*3;
    for(int row = rowBox;row < rowBox+3;row++){
        for(int col = colBox;col < colBox+3;col++){
            if(row_val == row && col_val == col){
                continue;
            }
            if(block[row][col] == num){
                return true;
            }
        }
    }

    return false;
}

bool backtrack(int row,int col){
    if(row == 9){
        return true;                 //if last row is reached then it means the loop is over
    }
    if(col == 9){
        return backtrack(row+1,0);   //if last column is reached, then go to next row
    }

    for(int num = 1;num < 10;num++){           //the most mind-boggling backtrack algorithm I have ever wrote (and learn a lot of things from)
        if(isFixed[row][col]){
            return backtrack(row,col+1);       //if the cell is already filled then skip it entirely
        }
        
            if(!checkBlock(num,row,col)){
            block[row][col] = num;
            if(backtrack(row,col+1)){
                return true;                     //if the entire grid is filled then it means the sudoku is solved
            }
                block[row][col] = 0;             //else that block for the time being becomes 0
        }
        else{
            continue;
        }
    }
    return false;                                 //meaning the particular block has no valid value for the time being
}


int main(){
    
    SetConsoleOutputCP(CP_UTF8);                 //for recognizing the special character
    displayBoard();

    cout << "\n";
    cout << "Welcome to the sudoku solver!\n";
    cout << "Enter your values in left to right order and fill up 0 for empty cells\n";

    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            cin >> block[row][col];                      //value input
            if(block[row][col] != 0){
                isFixed[row][col] = true;               //checking if block is already filled   
            }
        }
    }

    if(backtrack(0,0)){            //backtracking
        workBoard();
        cout << "\nHence the sudoku is solved!" << endl;
    }
    else{
        cout << "\nNo solution exist";
    }

    system("pause");

    return 0;
}