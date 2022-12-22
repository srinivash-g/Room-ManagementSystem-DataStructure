#ifndef ROOMLIST_H_INCLUDED
#define ROOMLIST_H_INCLUDED

#pragma once
#include"room.h"
#include <iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;

struct Noder
{
	Room data;
	Noder* next;
	Noder* prev;
};

class RoomList
{
	Noder*head;
	Noder*tail;
public:
	RoomList();
	void insert(string rt,string id,int c);
	void ridcheck(string& id);
	void roomidcheck(string rid,string& ab);
	void displayedit();
	void capacitycheck(string rid,int capacity,string& ac);
	void readfromfile();
	void writetofile();
	void displayFromHead();
	void displayFromTail();
	void deleteInBetween(string val);
	void edit(string rt, string id, int c);
	~RoomList();

};




#endif // ROOMLIST_H_INCLUDED
