#include<iostream>
#include<time.h>

using namespace std;

int N;
char qblock[100][100];     //IDK how to use dynamic memeory allocation

clock_t start = clock();

void q_assign(){                         //To assign the values first to make it an empty board
    for(int row = 0;row<N;row++){
        for(int col = 0;col<N;col++){
            qblock[row][col] = ' ';
        }
    }
}

bool checkBlock(int row,int col){
    int i,j;
    for(i = 0;i<col;i++){
        if(qblock[row][i] == 'Q'){        //Checking for columns
            return false;
        }
    }

    for(i = row,j = col;i>=0 && j>=0;i--,j--){       //Checking 1'o clock diag (upper half)
        if(qblock[i][j] == 'Q'){
            return false;
        }
    }

    for(i = row,j = col;i<N && j>=0;i++,j--){       //Checking other diag (lower half)
        if(qblock[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

bool backtrack(int row,int col){
    if(row == N){
        return false;
    }
    if(col == N){
        return true;
    }

    if(checkBlock(row,col)){
        qblock[row][col] = 'Q';
        if(backtrack(0,col+1)){
            return true;
        }
        qblock[row][col] = ' ';
    }
        return backtrack(row+1,col);
}

int main(){
    cout << "Enter the size of the board: ";
    cin >> N;

    q_assign();                //write after taking input or else the program will fail 

    if(backtrack(0,0)){
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(qblock[i][j] == 'Q'){
                    cout << "Coordinate: (" << i+1 << "," << j+1 << ")" << endl; 
                }
            }
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", time_spent);

    system("pause");

    return 0;
}