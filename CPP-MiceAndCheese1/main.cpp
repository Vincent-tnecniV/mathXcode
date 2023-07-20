#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#define size 7

struct BoardState 
{
	int x = 0;
	int y = 0;
	int licks = 0;
	bool a[size][size] = { 0 };
	bool b[size][size] = { 0 };
};

stack<BoardState> boards;

int dirx[4] = { 1, 0, -1, 0 };
int diry[4] = { 0, 1, 0, -1 };


int main()
{
	BoardState board;
	BoardState inital_board;
	inital_board.b[0][0] = 1;
	boards.push(inital_board);
	int record = 1;

	while (!boards.empty())
	{
		board = boards.top();
		boards.pop();
		if (!(board.x < size && board.x >= 0))
			continue;
		if (!(board.y < size && board.y >= 0))
			continue;
		if (board.licks >= record)
		{
			if (board.licks == record)
			{
				cout << "TIED" << endl;
			}
			else
			{
				cout << "IMPOROVED" << record << endl;
				record = board.licks;
			}
			cout << "licks=" << board.licks << "\t pos= " << board.x << ", " << board.y << endl;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
					cout << board.a[i][j] << " ";
				cout << endl;
			}
			cout << endl;
		}
		if (board.b[board.x][board.y])
		{
			if (board.a[board.x][board.y])
			{
				board.licks++;
			}
			board.x += dirx[board.licks % 4];
			board.y += diry[board.licks % 4];
		}
		else
		{
			board.b[board.x][board.y] = 1;
			// without cheese
			board.x += dirx[board.licks % 4];
			board.y += diry[board.licks % 4];
			boards.push(board);
			// with cheese
			board.x -= dirx[board.licks % 4];
			board.y -= diry[board.licks % 4];
			board.a[board.x][board.y] = 1;
			board.licks++;
			board.x += dirx[board.licks % 4];
			board.y += diry[board.licks % 4];
		}
		boards.push(board);
	}
}