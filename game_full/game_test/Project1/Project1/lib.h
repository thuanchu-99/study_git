#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
#include<map>
#include <iterator>
#include <utility>

using namespace std;

// parameter table chesh

#define SIZE 13
#define TOP 1
#define LEFT 1
#define WEIGHT 4
#define HEIGHT 2

struct vCoord
{
	COORD c;
	bool p;
};

struct mCoord
{
	COORD P;
};



