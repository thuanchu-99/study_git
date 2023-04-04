#pragma once
#include".\lib.h"
#include".\view.h"
#include".\model.h"

class Control
{
private:
	Model mModel;
	View mView;
public:
	mCoord VtoM(vCoord);//console -> table
	vCoord MtoV(mCoord);//table -> console

	/*int checkwin(mCoord);*/// kiem tra 0 hoa, -1 user 1 thang, 1 user2 thang
	int checkwin(int, int, int);
	void runProgram();

	// cac ham con xay dung cac trang khac nhau
	int cmd_menu(vCoord);//luu lua chon tai menu
	int cmd_table(vCoord, int);//luu danh co
	string inttostring(int);//doi int sang string them 0 neu nho hon 10
	int stringtointwld(string s);
	void updatefile(Player);
};