#include".\model.h"

Model::Model() {}

Model::~Model(){}

//interaction Game current
bool Model::checkpointgame(mCoord v)
{
	if (current.getPoint(v) == 0)
		return true;
	else
		return false;
}

int Model::getpointgame(mCoord v)
{
	return current.getPoint(v);
}

int Model::getpointgameint(int x, int y)
{
	return current.getPointint(x, y);
}

void Model::addXtogame(mCoord v)
{
	current.pushXtotable(v);
}

void Model::addOtogame(mCoord v)
{
	current.pushOtotable(v);
}

//model interaction ListMatch
void Model::addgame(int sec)
{
	ListMatch.insert(pair<int, Game>(sec, current));
}

Game Model::search(int s)
{
	map<int, Game>::iterator itr;
	for (itr = ListMatch.begin(); itr != ListMatch.end(); ++itr) 
	{
		if (itr->first == s)
			return itr->second;
	}
}

//vector csdl interaction
void Model::addPlayer(Player one)
{
	csdl.push_back(one);
}

//tim ng choi theo sec
pair<Player, Player> Model::getPlayer(int sec)
{
	pair<Player, Player> p;
	int i, j;
	for (i = 0; i < csdl.size(); i++)
	{
		if (csdl[i].getID() == sec)
		{
			p.first = csdl[i];
			break;
		}
	}

	for (j = i + 1; j < csdl.size(); j++)
	{
		if (csdl[j].getID() == sec)
		{
			p.second = csdl[j];
			break;
		}
	}

	return p;
}

void Model::newGame()
{
	current.resetmatch();
}