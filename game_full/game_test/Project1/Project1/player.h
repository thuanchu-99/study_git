#pragma once
#include"lib.h"
// Player definition: dinh nghi du lieu nguoi choi
class Player
{
public:
private:
	int ID;
	string name;
	int win;
	int lose;
	int draw;

public:

	Player();
	~Player();

	Player(string);

	string GetName();
	void SetName(string);

	void setID(int);
	int getID();

	void SetWin(int);
	void SetLose(int);
	void SetDraw(int);

	int GetWin();
	int GetLose();
	int GetDraw();

	void IncreWin();
	void IncreLose();
	void IncreDraw();
};