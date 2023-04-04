#pragma once
#include"lib.h"

//chua toan bo cac thao tac mutex and thread
class Mutexthread
{
private:
	thread newuser;//them nguoi choi
	mutex lthread;//khoa mutex
public:
	Mutexthread();
	~Mutexthread();

	int Create();//khoi tao thread
	int Join();

	int createMutex();
	int Lockutex();
	int  UnlockMutex();
};