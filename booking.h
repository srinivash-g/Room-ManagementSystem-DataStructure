#ifndef BOOKING_H_INCLUDED
#define BOOKING_H_INCLUDED

#pragma once
#include<iostream>
#include<string>
using namespace std;
class Booking
{
public:
	string memberID;
	string date;
	string timeStart;
	string timeEnd;
	string roomID;
	string organizer;
	int NoOFparticipants;

public:
	static int count;
	Booking();
	Booking(string m,string d,string ts,string te,string r,string o,int p);
	Booking(Booking &obj);
	void editDisplay();
	void searchdate();
    void showBookingInfo();
	void showInfoTomember();
	~Booking();
};



#endif // BOOKING_H_INCLUDED
