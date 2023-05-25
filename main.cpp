#include <iostream>
#include <string>

using namespace std;

void boardOut(string board[][3]){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << board[i][j];
             if (j < 2){
                cout << " | ";
            }
        }
        cout << endl;
        cout << endl;
    }
}
bool checkWin(string board[3][3]){
    for(int i=0; i<3; i++){
        if(board[i][0] != "#"){
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                return true;
            }
        }
    }
    for (int i=0; i<3; i++){
        if(board[0][i] != "#"){
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                return true;
            }
        }
    }
    if (board[0][0] != "#"){
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            return true;
        }
    }
    if (board[0][2] != "#"){    
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            return true;
        }
    }
    return false;
}


int main(){
    int xturn, oturn;

    string board[3][3] = {
        {"#", "#", "#"},
        {"#", "#", "#"},
        {"#", "#", "#"}
    };
    boardOut(board);
    bool gameOver = false;
    int row, col;

    while (!gameOver){
        cout << "X's turn:" << endl << endl;
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter col: ";
        cin >> col;
        board[row-1][col-1] = "X";
        system("cls");
        xturn++;
        boardOut(board);
        if (checkWin(board)){
            break;
        }
        cout << "O's turn:" << endl << endl;
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter col: ";
        cin >> col;
        board[row-1][col-1] = "O";
        system("cls");
        oturn++;
        boardOut(board);
        if (checkWin(board)){
            break;
        }
    }
    if (xturn > oturn){
        cout << "X wins!" << endl;
    }
    else{
        cout << "O wins!" << endl;
    }

    return 0;

}
