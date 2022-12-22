#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#pragma once
#include<iostream>
#include<string>
using namespace std;
class Room
{
public:
	string roomType;
	string roomID;
	int capacity;
public:
	static int roomcount;
	Room();
	void editDisplay();
	Room(string rt,string id,int c);
    void displayInfo();
	~Room();
};


#endif // ROOM_H_INCLUDED
