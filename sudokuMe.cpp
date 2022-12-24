#include <bits/stdc++.h>
using namespace std;


bool rowCheck(int ** sudoku,int size,int col,int num){
    for(int i=0;i<size;i++)
    {
        if(sudoku[i][col]==num) return false;
    }
    return true;
}


bool colCheck(int ** sudoku,int size,int row,int num){
    for(int i=0;i<size;i++)
    {
        if(sudoku[row][i]==num) return false;
    }
    return true;
}

bool boxCheck(int ** sudoku,int size,int row,int col,int num){
    int sqrt = pow(size,0.5);    
    int rs = row - row%sqrt;
    int cs = col - col%sqrt;

    for(int i=rs;i<rs+sqrt;i++)
    {
        for(int j=cs;j<cs+sqrt;j++)
        {
            if(sudoku[i][j]==num) return false;
        }
    }
    return true;
}

bool canPlace(int** sudoku,int size,int row,int col,int num){
    if(!rowCheck(sudoku,size,col,num)) return false;
    if(!colCheck(sudoku,size,row,num)) return false;
    if(!boxCheck(sudoku,size,row,col,num)) return false;
    return true;
}


bool sudokuSolver(int ** sudoku,int size){
    int row = -1;
    int col = -1;
    int found = false;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(sudoku[i][j]==0) {
                found = true;
                row = i;
                col = j;
                break;
            }
        }
        if(found) break;
    }

    if(!found) return true;
    for(int i=1;i<=size;i++)
    {
        if(canPlace(sudoku,size,row,col,i)){
            sudoku[row][col]= i;
            if(sudokuSolver(sudoku,size)) return true;
            sudoku[row][col]=0;
        }
    }
    return false;
}

int main()
{
    int size;
    // cout<<"Enter the size of sudoku(if 9x9: enter 9):\n";
    cin>>size;
    int **sudoku = new int*[size];
    for(int i=0;i<size;i++)
    {
        sudoku[i]= new int[size];
        for(int j=0;j<size;j++)
        {
            cin>>sudoku[i][j];
        }
    }
    if(sudokuSolver(sudoku,size)) cout<<"Yay!"<<endl;
    else cout<<"Nay!"<<endl;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}