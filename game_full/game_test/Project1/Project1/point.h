#pragma once
#include"lib.h"

// dinh nghia class point duoc luu trong vector ban co
// khong luu toa do
//chi luu gia tri check
//0: chua dien, -1: da dien X, 1: da dien O

class Point
{
private:
	int check;//-1, 0, 1

public:
	Point();
	~Point();

	void setcheck(int);//dien gia tri vao khi nhan chuot
	int getcheck();
};