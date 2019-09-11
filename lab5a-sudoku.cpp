//this program solves sudoku puzzle

#include <iostream>
#define UNASSIGNED 0
#define N 9
#define SQN 3
using namespace std;

bool FindUnassignedLocation(int grid[N][N], int &row, int &col){
	for(row = 0; row<N; row++)
		for(col = 0; col<N; col++)
			if(grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

bool UsedInRow(int grid[N][N], int row, int num){
	for(int i=0; i<N; i++)
		if(grid[row][i] == num)
			return true;
	return false;
}

bool UsedInCol(int grid[N][N], int col, int num){
	for(int i =0; i<N; i++)
		if(grid[i][col] == num)
			return true;
	return false;
}

bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
	for(int i=0; i<SQN; i++)
		for(int j=0; j<SQN;j++)
			if(grid[i+boxStartRow][j+boxStartCol] == num)
				return true;
	return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){
	return !UsedInRow(grid, row, num) && !UsedInCol(grid,col,num) && !UsedInBox(grid,row-row%SQN, col-col%SQN,num);
}

bool solveSudoku(int grid[N][N]){
	int row, col;
	if(!FindUnassignedLocation(grid,row, col))
		return true;
	for(int num = 1; num<=N; num++){
		if(isSafe(grid,row,col,num)){
			grid[row][col]=num;
			if(solveSudoku(grid))
				return true;
			grid[row][col] = UNASSIGNED;
		}
	}
	return false;
}

int main(){
	int grid[N][N];
	cout<<"Enter the Sudoku puzzle(0 for unfilled) :\n";
	for(int i =0; i<N; i++)
		for(int j=0;j<N;j++)
			cin>>grid[i][j];
	if(solveSudoku(grid)){
		for(int i =0; i<N;i++){
			for(int j=0;j<N;j++)
				cout<<grid[i][j]<<"\t";
			cout<<"\n";
		}
	}
	return 0;
}


