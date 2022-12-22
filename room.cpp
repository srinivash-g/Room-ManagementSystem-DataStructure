#include "room.h"

Room::Room()
{
	roomType=" ";
	roomID=" ";
	capacity=0;

}
Room::Room(string rt,string id,int c)
{
	roomType = rt;

	roomID = id;

	capacity=c;
	roomcount++;
}
void Room::editDisplay()
{
    cout << "\n\t\tRoom ID: " <<roomID<<endl;
    cout << "\n\t\tRoom Type: " <<roomType<<endl;
}
void Room::displayInfo()
{
	cout << "\n\tRoom ID: "<< roomID<<endl;
	cout << "\n\tRoom Type: "<< roomType << endl;
	cout << "\n\tCapacity: "<< capacity << endl;
	cout<<"*******************************************************\n";
}

Room::~Room()
{

}
