#pragma once
#include".\lib.h"
#include"game.h"
#include"player.h"

//luu du lieu cac sec trong moot tran dau

class Model
{
private:
	Game current;
	vector<Player> TXT;
	vector<Player> csdl;
	map<int, Game> ListMatch;//so tran dau
public:
	Model();
	~Model();

	void newGame();//xoa
	void modelcrematch(int);

	//interaction Game current
	bool checkpointgame(mCoord);//enable point: da duoc dien hay chua
	int getpointgame(mCoord);//lay gia tri
	int getpointgameint(int, int);
	
	void addXtogame(mCoord);//
	void addOtogame(mCoord);//

	//model interaction ListMatch
	void addgame(int);//sau khi control kiem tra sec+=1
	Game search(int);//search theo sec

	//vector csdl interaction
	void addPlayer(Player);
	pair<Player, Player> getPlayer(int);

};