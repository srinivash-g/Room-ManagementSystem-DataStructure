#ifndef DOBLYLINKEDLIST_H_INCLUDED
#define DOBLYLINKEDLIST_H_INCLUDED

#pragma once
#include"booking.h"
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

struct Node
{
	Booking data;
	Node* next;
	Node* prev;
};

class DoublyLinkedList
{
	Node*head;
	Node*tail;
public:
	DoublyLinkedList();
	void insert(string m,string d,string ts,string te,string r,string o,int p);
	void uidcheck(string& id);
	void readfromfileb();
	void writetofileb();
	void displayedit();
	void displaydate();
	void displayFromHead();
	void displayFromTail();
	void deleteInBetween(string val);
	void search(string d,int n);
	void edit(string m, string d, string ts, string te, string r, string o, int p);
	~DoublyLinkedList();

};




#endif // DOBLYLINKEDLIST_H_INCLUDED
