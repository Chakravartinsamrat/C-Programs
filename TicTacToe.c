//C Program to Play the Tic Tac Toe Game

#include<stdio.h>
//Gobally Declared 2D-aaray
char board[3][3];
//Function to initialize the game board
void initializeBoard()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j]=' ';
		}
	}
	int count =1;
	printf("\n\n\t  ");
	for(int i=0;i<3;i++)
	{
		for (int j=0;i<3;j++)
		{
			printf("%d",count++);
			if(j<2)
			{
				printf("  |  ");
			}
		}
		if(i<2)
		printf("\n\t-----------------\n\t");
	}
	printf("\n\n\n");
}

//function to show the game board
void showBoard(int x, int y)
{
	printf("\n\n\t  ");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%c",board[i][j]);
			if(j<2)
			{
				printf("  |  ");
			}
		}
		if(i<2)
		printf("\n\t------------------\n\t");
	}
	printf("\n\n\n");
}

//Function to update the game board
int updateBoard(int cell,char playerSign)
{
	int row =(cell-1)/3;
	int col=(cell-1)%3;
	int isValid=1;
	
	//accesing already played cell number
	if(board[row][col] !=' ')
	{
		printf("\nInvalid:Cell is already filled!!!\n");
		isValid=0;
	}
	//Valid cell Position
	else
	{
		board[row][col]=playerSign;
	}
	showBoard(row,col);
	
	return isValid;
}

//function to check tthe winner of the board game
int checkWinner(char sg)
{
	//check all rows
	if(board[0][0]==sg && board[0][1] == sg && board[0][2]==sg || board[1][0]==sg && board[1][1] == sg && board[1][2]==sg || board[2][0]==sg && board[2][1] == sg && board[2][2]==sg)
	{
		return 1;
	}
	//else check all columns
	else if( board[0][0] == sg && board[1][0] == sg && board [2][0] == sg || board[0][1] == sg && board[1][1] == sg && board[2][1]== sg || board[0][2] == sg && board[1][2] == sg && board[2][2] == sg)
	{
		return 1;
	}
	//check diagonals
	else if (board[0][0]==sg && board[1][1] == sg && board[2][2]==sg || board[0][2]==sg && board[1][1] == sg && board[2][0]==sg )
	{
		return 1;
	}
	//If there's no winner
	return 0;
}

//start your game from here
void playTicTacToe()
{
	int gameResult = 0;
	int cell = 0;
	int playCount =0;
	int updationResult =1;
	
	char playerSign = ' ';
	//start playing the game
	while (!gameResult && playCount <9)
	{
		if(playCount % 2==0)
		{
			//player1
			printf("\nPlayer 1 [X] :");
			playerSign ='X';
		}
		else 
		{
			//player 2
			printf("\nPlayer 2 [0]: ");
			playerSign = '0';
		}
		scanf("%d",&cell);
		if(cell > 0 && cell <10)
		{
			updationResult = updateBoard(cell, playerSign);
			//if Updation is possible
			if(updationResult)
			{
				gameResult = checkWinner (playerSign);
				//Print the winner of the game
				if(gameResult)
				{
					printf("\t *** Player %d has Won !!! ***\n", playerSign == 'X' ? 1:2);
				}
				playCount++;
			}
		}
		else if(cell == -1)
		{
			printf("\n\tGame Terminated\n");
			return;
		}
		else
		{
			printf("\n Please Enter a valid Cell value\n");
		}
	}
	//no one has won the game
	if(!gameResult && playCount ==9)
	{
		printf("\n\t ***Its a DRAW !! ***\n");
	}
	printf("\n\t--- Game Over --- \n");
}
int main()
{
	printf("--------- Tic Tac Toe ----------\n\n");
	
	printf("\n *INSTRUCTIONS* \n\n");
	printf("\t Player 1 sign =X\n");
	printf("\t Player 2 sign = O");
	printf("\n\t To Exit game, Enter -1\n");
	
	printf("\n\n *Cell Number on Board\n");
	initializeBoard();
	
	char start= ' ';
	printf(" \n Press  Enter  To  Start ...");
	scanf("%c", &start);
	if (start)
	{
		int userChoice = 1;
		//restart the game
		while (userChoice)
		{
			playTicTacToe();
			printf("\n *Menu \n");
			printf(" \n Press 1 to Restart");
			printf("\n Press 0 for Exit");
			printf("\n\n Choice:");
			scanf("%d", &userChoice);
			{
				initializeBoard();
			}
			printf("\n");
		}
	}
	printf("\n :: Thanks for Playing TIC TAC TOE game ! :: \n");
	return 0;
}