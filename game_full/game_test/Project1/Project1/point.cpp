#include"point.h"

//Point class definition
//khoi tao ban dau check = 0
//method: getcheck se tra ve gia tri luc dien vao hoc kiem tra

Point::Point()
{
	check = 0;
}

Point::~Point(){}

void Point::setcheck(int icheck)
{
	check = icheck;
}

int Point::getcheck()
{
	return check;
}

