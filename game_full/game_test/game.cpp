#include".\game.h"

Game::Game() {}

Game::~Game() {}

void Game::resetmatch()
{
	for (int i = 0; i < match.size(); i++)
	{
		for (int j = 0; j < match[i].size(); j++)
		{
			match[i][j].setcheck(0);
		}
	}
}

void Game::crematch(int size)
{
	Point p;
	for (int i = 0; i < size; i++)
	{
		match[i].push_back(p);
	}
}

int Game::getPoint(mCoord v)
{
	return match[v.P.X][v.P.Y].getcheck();
}

int Game::getPointint(int x, int y)
{
	return match[x][y].getcheck();
}

void Game::pushOtotable(mCoord v)
{
	match[v.P.X][v.P.Y].setcheck(1);
}

void Game::pushXtotable(mCoord v)
{
	match[v.P.X][v.P.Y].setcheck(-1);
}


