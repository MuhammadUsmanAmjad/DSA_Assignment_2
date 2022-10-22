#include <iostream>
#include <fstream>
#include<time.h>
using namespace std;
void read_board(int **&board, string s, int &rows, int &cols)
{
    ifstream fin;
    fin.open("board.txt");
    if (!fin)
    {
        cout << "file Not found\n";
        return;
    }
    fin >> rows;
    fin >> cols;
    board = new int *[rows];
    for (int i = 0; i < rows; i++)
        board[i] = new int[cols];
    char ch;
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        k = 0;
        for (int j = 0; j < cols; j++)
        {
            fin >> ch;
            if (ch != '.')
                board[i][j] = int(ch - 48);
            else
                board[i][j] = -1;
            fin >> ch;
        }
    }
}
void print_board(int **board, int rows, int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {    if(board[i][j]!=-1)
            cout<<board[i][j]<<" ";
            else
                cout<<"? ";
            if((j+1)%3==0)
                cout<<" ||  ";
        }
        if((i+1)%3==0)
            cout<<"\n";
        cout<<endl;
    }
}
bool check_row_col(int **board, int i, int j, int key)
{
    for (int k = 0; k < 9; k++)
        if (board[i][k] == key || board[k][j]==key)
            return false;
    return true;
}
bool check_3_3_array(int **board, int i, int j, int key)
{
    int Row = i/3*3;
    int Col = j/3*3;
    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            if (board[a + Row][b + Col] == key)
                return false;
    return true;
}
bool get_row_col(int**arr,int&row,int&col)
{
    for(row=0;row<9;row++)
        for(col=0;col<9;col++)
            if(arr[row][col]==-1)
                return false;
    return true;
}
bool fill_board(int **board)
{
    int row,col;
    if(get_row_col(board,row,col))
        return true;
    for(int i=1;i<=9;i++){
        if(check_row_col(board,row,col,i)&& check_3_3_array(board,row,col,i)) {
            board[row][col] = i;
            if (fill_board(board))
                return true;
            board[row][col] = -1;
        }
    }
    return false;
}
int main()
{
    int **board;
    int rows = 0;
    int cols = 0;
    read_board(board, "board.txt", rows, cols);
    print_board(board, rows, cols);
    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n";
    if(fill_board(board))
    print_board(board, rows, cols);
    return 0;
}