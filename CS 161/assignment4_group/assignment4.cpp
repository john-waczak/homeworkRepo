#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void displayBoard(char[][3], int);
void validateMoveFrom(char[][3], int&, int&, int);
void validateMoveTo(char[][3], int&, int&, int&, int&);
bool checkWinner(char[][3]);

int main()
{
char board[3][3]=  {{'*','*','*'},
		    {'*','*','*'},
		    {'*','*','*'}};

displayBoard(board, 3);

int player1pieces = 3;
int player2pieces = 3;
int currentPlayer = 1;
int turnCounter = 0;
int cord1, cord2, x, y;

do{
if(currentPlayer==1&&player1pieces>0&&checkWinner(board))
{
	cout <<"Player 1's turn"<<endl;
	cout <<"Enter the coordinates you would like to move to: "<<endl;
	cin >>cord1>>cord2;
	
	while(cord1==1&&cord2==1&&turnCounter==0)
	{
		cout <<"Illegal move"<<endl;
		cout <<"Enter the coordinates you would like to move to: "<<endl;
		cin>>cord1>>cord2;
	}
	
	while(board[cord1][cord2]=='x'||board[cord1][cord2]=='o')
	{
		cout<<"Illegal move"<<endl;
		cout<<"Enter the coordinates you would like to move to: "<<endl;
		cin>>cord1>>cord2;
	}

	turnCounter++;
	board[cord1][cord2] = 'x';
	displayBoard(board, 3);
	checkWinner(board);
	player1pieces--;
	currentPlayer = 2;
}
if(currentPlayer==1&&player1pieces==0&&checkWinner(board))
{
	cout <<"Player 1's turn"<<endl;
	cout <<"Enter the coordinates you would like to move a piece from: "<<endl;
	cin>>x>>y;

	validateMoveFrom(board,x,y,currentPlayer);

	board[x][y] = '*';
	cout <<"Enter the coordinates you would like to move to: "<<endl;
	cin>>cord1>>cord2;
	
	validateMoveTo(board,cord1,cord2,x,y);	
	
	board[cord1][cord2]='x';
	displayBoard(board, 3);
	checkWinner(board);
	currentPlayer=2;
}

if(currentPlayer==2&&player2pieces>0&&checkWinner(board))
{
	cout<<"Player 2's turn"<<endl;
	cout<<"Enter the coordinates you would like to move to: "<<endl;
	cin>>cord1>>cord2;

	while(board[cord1][cord2]=='x'||board[cord1][cord2]=='o')
	{
		cout<<"Illegal move"<<endl;
		cout<<"Enter the coordinates you would like to move to: "<<endl;
		cin>>cord1>>cord2;
	}
	
	board[cord1][cord2] = 'o';
	displayBoard(board,3);
	checkWinner(board);
	player2pieces--;
	currentPlayer = 1;
}
if(currentPlayer==2&&player2pieces==0&&checkWinner(board))
{
	cout<<"Player 2's turn"<<endl;
	cout<<"Enter the coordinates you would like to move a piece from: "<<endl;
	cin>>x>>y;

	validateMoveFrom(board,x,y,currentPlayer);	

	board[x][y] = '*';
	cout<<"Enter the coordinates you would like to move to: "<<endl;
	cin>>cord1>>cord2;

	validateMoveTo(board,cord1,cord2,x,y);	

	board[cord1][cord2] = 'o';
	displayBoard(board,3);
	checkWinner(board);
	currentPlayer=1;	
}
}while(checkWinner(board));

	return 0;
}

void displayBoard(char board[][3], int numColumns)
{
	cout <<"  "<<0<<" "<<1<<" "<<2<<endl;
	cout << 0<<" "<<board[0][0]<<" "<<board[0][1]<<" "<<board[0][2]<<" "<< endl;
	cout << 1<<" "<<board[1][0]<<" "<<board[1][1]<<" "<<board[1][2]<<" "<< endl;
	cout << 2<<" "<<board[2][0]<<" "<<board[2][1]<<" "<<board[2][2]<<" "<< endl;

}

void validateMoveFrom(char board[][3], int& x, int& y, int currentPlayer)
{
	while(board[x][y+1]!='*'&&board[x][y-1]!='*'&&board[x+1][y+1]!='*'&&board[x+1][y-1]!='*'&&board[x-1][y+1]!='*'&&board[x-1][y-1]!='*'&&board[x+1][y]!='*'&&board[x-1][y]!='*')
	{
		cout<<"Illegal move (that piece is trapped)"<<endl;
		cout<<"Enter the coordinates you would like to move a piece from: "<<endl;
		cin>>x>>y;
	}
	while((board[x][y]=='*'||board[x][y]=='o')&&currentPlayer==1)
	{
		cout<<"Illegal move"<<endl;
		cout<<"Enter the coordinates you would like to move a piece from: "<<endl;
		cin>>x>>y;
	}
	while((board[x][y]=='*'||board[x][y]=='x')&&currentPlayer==2)
	{
		cout<<"illegal move"<<endl;
		cout<<"Enter the coordinates you would like to move a piece from: "<<endl;
		cin>>x>>y;
	}
}

void validateMoveTo(char board[][3], int& cord1, int& cord2, int& x, int& y)
{
	while(board[cord1][cord2]=='o'||board[cord1][cord2]=='x')
	{
		cout<<"Illegal move"<<endl;
		cout<<"Enter the coordinates you would like to move to: "<<endl;
		cin>>cord1>>cord2;
	}
	while((cord1-x<-1||cord1-x>1)||(cord2-y<-1||cord2-y>1))
	{
		cout<<"Illegal move"<<endl;
		cout<<"Enter the coordinates you would like to move to: "<<endl;
		cin>>cord1>>cord2;
	}
}

bool checkWinner(char board[][3])
{
	int xCount=0;
	int yCount=0;

	for(int i=0; i<3; i++)
	{	
		for(int j=0; j<3; j++)
		{	
			if(board[i][j]=='x')
				xCount++;
		}
	if(xCount==3)
	{	
		cout<<"Player 1 wins!"<<endl;
		return 0;
	}
	else
		xCount=0;	
	}
	
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			if(board[i][j]=='x')
				xCount++;
		}
	if(xCount==3)
	{
		cout<<"Player 1 wins!"<<endl;
		return 0;
	}
	else
		xCount=0;		
	}

	if(board[0][0]=='x'&&board[1][1]=='x'&&board[2][2]=='x')
	{
		cout<<"Player 1 wins!"<<endl;
		return 0;
	}
	if(board[2][0]=='x'&&board[1][1]=='x'&&board[0][2]=='x')
	{
		cout<<"Player 1 wins!"<<endl;
		return 0;
	}
	
	for(int i=0; i<3; i++)
	{	
		for(int j=0; j<3; j++)
		{	
			if(board[i][j]=='o')
				yCount++;
		}
	if(yCount==3)
	{
		cout<<"Player 2 wins!"<<endl;
		return 0;
	}
	else
		yCount=0;	
	}
	
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			if(board[i][j]=='o')
				yCount++;
		}
	if(yCount==3)
	{
		cout<<"Player 2 wins!"<<endl;
		return 0;
	}
	else
		yCount=0;		
	}


	if(board[0][0]=='o'&&board[1][1]=='o'&&board[2][2]=='o')
	{
		cout<<"Player 2 wins!"<<endl;
		return 0;
	}
	if(board[2][0]=='o'&&board[1][1]=='o'&&board[0][2]=='o')
	{
		cout<<"Player 2 wins!"<<endl;
		return 0;
	}
}
