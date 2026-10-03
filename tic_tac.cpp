#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

char board[3][3];

void boardVal(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }
}

void displayBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << " ";
            if(j<2){
                cout << board[i][j] << " |";
            }
            else{
                cout << board[i][j];
            }
        }
        cout << "\n";
        if(i<2){
            cout << "---|---|---\n";
        }
    }
}

bool WinGame(){
    for(int i=0;i<3;i++){
            //row
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
                return 1;
            }

            //column
            else if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
                return 1;
            }

            //diagonal
            else if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
                return 1;
            }

            else if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' '){
                return 1;
            }
        }
    return 0;
}

bool isDraw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    boardVal();
    char player = 'X';

    displayBoard();
    cout << "\n";
    cout << "Welcome to tic-tac-toe! (hit 69 to stop the game)" << endl;
    cout << "-------------------------------------------------\n";

    while(WinGame() == 0 && isDraw() == 0){
      cout << "Player is " << player << endl;
        cout << "Enter your postions(x,y): " << endl;

        int row,col;
        cin >> row >> col;
         cout << "\n";

        if(row == 6 && col == 9){
            break;
        }
        else if(row>3 || row<1 || col>3 || col<1){
            cout << "Input correct values you moron!\n";
        }
        else if(board[row-1][col-1] != ' '){
            cout << "Cell is already filled!\n";
            if(player == 'X'){
                player = 'X';
            }
            else{
                player = 'O';
            }
        }
        else{
            board[row-1][col-1] = player;

            cout << "\n";
             displayBoard();
       
        if(player == 'X'){
            player = 'O';
        }
        else{
            player = 'X';
        } 
    }  
    cout << "\n"; 
  }

  if(WinGame() == 1){
    if(player == 'X'){
        cout << "Player O wins!" << endl;
    }
    else{
        cout << "Player X wins!" << endl;
    }
  }

  else if(isDraw() == 1){
    cout << "The game ends in a draw!";
  }
  
//   string cont;
//   cin >> cont;
  
    return 0;
}
