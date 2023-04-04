#pragma once
#include"view.h"
#include"model.h"

class Control
{
private:
	Model mModel;
	View mView;
public:
	mCoord VtoM(vCoord);//console -> table
	vCoord MtoV(mCoord);//table -> console

	/*int checkwin(mCoord);*/// kiem tra 0 hoa, -1 user 1 thang, 1 user2 thang
	int checkwin(int, int);
	//int checkwin(mCoord);

	//void newGame();

	//void showhistory();

	void runProgram();

	// cac ham con xay dung cac trang khac nhau
	int cmd_menu(vCoord);//luu lua chon tai menu
	//int cmd_inPlayer();//luu hoat dong nhap
	int cmd_table(vCoord);//luu danh co
	//int cmd_sec(vCoord);//luu lua chon tai danh co
	//int cmd_finish(vCoord);//luu lua chon sau khi finish sec

};