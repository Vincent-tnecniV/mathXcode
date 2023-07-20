#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

extern int record;

#define size 4


struct BoardState
{
	int x = 0;
	int y = 0;
	int licks = 0;
	bool a[size][size] = { 0 };
	bool b[size][size] = { 0 };
};

extern stack<BoardState> boards;

extern int dirx[4];
extern int diry[4];

void dfs();