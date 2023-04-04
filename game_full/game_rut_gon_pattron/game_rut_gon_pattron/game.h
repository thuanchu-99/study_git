#pragma once
#include".\lib.h"
#include"point.h"

class Game
{
private:
	vector<vector<Point>> match;//luu tran dau

public:
	Game();
	~Game();

	void crematch(int);
	void resetmatch();

	int getPoint(mCoord);//lay point tu vector match ra 
	int getPointint(int, int);

	int getsize();

	void pushXtotable(mCoord);
	void pushOtotable(mCoord);
};

