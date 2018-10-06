

//We will solve the N-queens problem(Backtracking Algorithm)
#include <iostream>


const int N = 10;

bool solveNqueens(int board[N][N], int col);
bool isSafe( int board[N][N], int row, int col);

void printMatrix(int board[N][N]);


int main(int argc, char* argv[])
{



	std::cout << "\nWe will solve the N-queens problem.\n\n";
	std::cout << "what is the size of our board: " << N << std::endl ;



	//Create our 2D array.
	int board[N][N];

	// We have to populuate it, with all zeros
	for(int m = 0; m <N; m++){
		for(int n = 0; n < N; n++){
			board[m][n] = 0;
		}


	}


	//Solve the problem using this function, 
	//If no solution then state that there is no solution
	
	if(solveNqueens(board,0) == false){
	
		std::cout << "\n\nNo Solution was found\n\n";
		return 0;
	}
	

	//We found an answer
	//Print the Answer
	printMatrix(board);

}









bool solveNqueens(int board[N][N], int col){
	
	if(col >= N ){
	
		return true;
	}
	
	//Iterate thorugh every row in the given column(col)
	for(int i = 0; i < N; i++){
		
		//Determine if it is we are in a safe position.
		if(isSafe(board, i, col)){
		
		
			//We can safely place the queen in this position
			board[i][col] = 1;
			
			//Check the arrangement
			if(solveNqueens(board,col+1)){
				return 1;
			}		
			//If we have no possible arrangement, then we backTrack and remove the queen
			board[i][col] = 0;
		
		
		}

	}
	
	
	
	return false;
}


void printMatrix(int board[N][N]){

	std::cout << "Printing Matrix(" << N << "x" << N <<"):\n";
	
	for(int i = 0; i < N ; i++){
		for(int j = 0; j < N; j++){

			std::cout << board[i][j] << "  ";
		}
	
		std::cout << "\n";
	}

}


bool isSafe( int board[N][N], int row, int col){

	
	int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*

       //Checking this given row, on the left side
       for(int i = 0; i < col; i++){
       		if(board[row][i]){
			return false;
		}
       }

       //Checking the upper diagonal, on the left side
       //Start in the given position
       int m;
       int n;
       for(m = row, n =col; m >= 0 && n >=0; m--, n--)
       {
       		if(board[m][n]){
			return false;
		}
       	
       }



       //Checking the lower diagonal, on the left side
	for(m = row, n = col; m >= 0  && n < N ; m++,n--){
		if(board[m][n]) {
			return false;
		}
	}



	std::cout << "WE HAVE A SAFE POSITION.\n";
	return 1;
*/
}
