#include"player.h"

Player::Player()
{
	name = "";
	win = lose = draw = 0;
	ID = 0;
}

Player::Player(string iname)
{
	name = iname;
	win = lose = draw = 0;
	ID = 0;
}

Player::~Player() {}

string Player::GetName()
{
	return name;
}

void Player::SetName(string value)
{
	name = value;
}

void Player::SetWin(int value) { win = value; }
void Player::SetLose(int value) { lose = value; }
void Player::SetDraw(int value) { draw = value; }

int Player::GetWin() { return win; }
int Player::GetLose() { return lose; }
int Player::GetDraw() { return draw; }

void Player::IncreWin() { win++; }
void Player::IncreLose() { lose++; }
void Player::IncreDraw() { draw++; }

void Player::setID(int id)
{
	ID = id;
}

int Player::getID()
{
	return ID;
}