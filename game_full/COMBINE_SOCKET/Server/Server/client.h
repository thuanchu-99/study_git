#pragma once
#include"lib.h"

//la doi tuong duoc tao sau khi nhan duoc connect
//luu ten nguoi choi
//id game

class Client
{
private:
	string username;
	string game_id;
	SOCKET Connect;

public:
	Client();
	~Client();
	void Setname(string);
	void SetIDgame(string);
};