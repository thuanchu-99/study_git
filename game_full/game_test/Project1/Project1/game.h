#pragma once
#include"point.h"

class Game
{
private:
	vector<vector<Point>> match;//luu tran dau

public:
	Game();
	~Game();

	void resetmatch();
	void crematch(int);

	int getPoint(mCoord);//lay point tu vector match ra 
	int getPointint(int, int);

	void pushXtotable(mCoord);
	void pushOtotable(mCoord);
};

