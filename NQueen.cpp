#include<iostream>

using namespace std;

bool isSafe(int** arr, int X, int Y, int n)
{
    for(int row = 0; row < X; row++)
    {
        if(arr[row][Y] == 1)
            return false;
    }

    int row = X;
    int col = Y;
    while(row >= 0 && col >= 0)
    {
        if(arr[row][col] == 1)
            return false;
        row--;
        col--;
    }
    row = X;
    col = Y;
    while(row >= 0 && col < n)
        {
            if(arr[row][col] == 1)
                return false;
            row--;
            col++;
        }
    return true;
}

bool nQueen(int** arr, int X, int n)
{
    if(X >=n)
    {
        return true;
    }
    for(int col = 0; col < n; col++)
    {
        if(isSafe(arr, X, col, n))
        {
            arr[X][col] = 1;
            if(nQueen(arr, X+1, n))
            {
                return true;
            }
            arr[X][col] = 0;
        }
    }
    return false;

}

int main()
{
    int n;
    cout<<"Enter the size of the chess matrix:";
    cin>>n;
    int** arr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    if(nQueen(arr, 0, n))
    {
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    return 0;
}