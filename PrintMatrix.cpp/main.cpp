#include <iostream>

using namespace std;



int main() {
    
    int num;
    int mat[2][2];
    cout<<"Enter the dimention of the matrix"<<" :"<<" ";
    cin>>num;
    cout<<"Enter the elements of the matrix"<<" :"<<" ";
    for(int i=0;i<num;i++)
        for(int j=0;j<num;j++)
            cin>>mat[i][j];
    
    for(int l=0;l<num;l++)
        for(int m=0;m<num;m++)
            cout<<mat[l][m]<<endl;
    return 0;
}
//indrijeet
