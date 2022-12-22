#include"doublylinkedlist.h"
#include"roomlist.h"
#include"room.h"
#include"booking.h"
#include<string>
#include<windows.h>
#include<cstdlib>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<ctime>
#include<fstream>
using namespace std;
void displayinfo();
int Booking::count=0;
int Room::roomcount=0;
int main()
{
	RoomList room;
	DoublyLinkedList booking;
	time_t now =time(0);
    char* dt=ctime(&now);
	int choice, num;
	string rt, id, Date, st, et, rid, organizer, em, name, pass1, del,searche,ch,ab,ac;
	int capacity;
	Room r;
	Booking b;
	room.readfromfile();
	booking.readfromfileb();
	system("cls");
	while(1)
    {
    string user,pass;
    cout<<dt<<endl;
    cout<<"\n\t\t==========================================================================";
    cout<<"\n\t\t\t        ***************ROOM BOOKING SYSTEM*************";
    cout<<"\n\t\t==========================================================================";
    cout<<"\n\n\n\n\t\t\t\t\t*Security is required*";
	cout<<"\n\n\n\t\t\tUsername: ";
	cin>>user;
	cout<<"\n\n\n\t\t\tPassword: ";
	for(int i=1;i<=8;i++)
		{
			ch=getch();
			pass+= ch;
			cout<<"*";
		}
	if(user== "admin" && pass=="admin123")
	{
      cout<<"\n\n\n\n\t\t\t\t\tLoading.....";
      for(int i=1;i<=5;i++)
			{
				Sleep(500);
				cout<<".";
			}
	  system("cls");
	  cout<<"\t\t\n\n\n\n\t\t\t\t\t\tLog IN Successfull."<<endl;
	  Sleep(1500);
	  system("cls");
	  while(1)
	  {
      cout<<"\n\t\t==========================================================================";
      cout<<"\n\t\t\t        ***************ROOM BOOKING SYSTEM*************";
      cout<<"\n\t\t==========================================================================";
      cout<<"\n\t\tPress '1' to View all Rooms."<<endl;
	  cout<<"\n\t\tPress '2' to Add a room."<<endl;
	  cout<<"\n\t\tPress '3' to Edit a room info."<<endl;
	  cout<<"\n\t\tPress '4' to View all booking records."<<endl;
	  cout<<"\n\t\tPress '5' to Add Booking."<<endl;
	  cout<<"\n\t\tPress '6' to Edit Booking"<<endl;
	  cout<<"\n\t\tPress '7' to Delete Booking"<<endl;
	  cout<<"\n\t\tPress '8' to Search the booking records."<<endl;
	  cout<<"\n\t\tPress '9' to contact us."<<endl;
	  cout<<"\n\t\tPress '10' to Exit.";
	  cout<<"\n\n\t\tEnter your choice:";
	  cin>>choice;
	  switch(choice)
	  {
      case 1:
	     system("cls");
	     room.displayFromHead();
    	 system("pause");
	     system("cls");
		  break;
      case 2:
		  system("cls");
		  cout << "\n\n\t\tTotal rooms added: " << Room::roomcount << endl;
		  cout << "\n\n\t\tNo of rooms Left: " << 50 - Room::roomcount << endl;
		  cout<<"\n\n\t\tEnter RoomID:";
		  cin>>id;
		  room.ridcheck(id);
		  while(id=="exist")
          {
          cout<<"\n\n\tThe Entered Room Id Already Exists!Try again"<<endl;
          cout<<"\n\n\t\tRenter RoomID:";
          cin>>id;
          room.ridcheck(id);
          }
		  cout<<"\n\n\t\tEnter Room Type:";
          cin>>rt;
		  cout<<"\n\n\t\tEnter Room capacity:";
		  cin>>capacity;
		  room.insert(rt,id,capacity);
          cout<<"\n\n\t\tRoom Added.."<<endl;
		  system("pause");
		  system("cls");

		  break;
	  case 3:
		  system("cls");
		  room.displayedit();
		  cout << "\n\n\t\tEnter RoomID:";
		  cin >> id;
		  cout << "\n\n\t\tEnter Room Type:";
		  cin >> rt;
		  cout << "\n\n\t\tEnter Room capacity:";
		  cin >> capacity;
		  room.edit(rt, id, capacity);
		  cout << "\n\n\t\tReturned Successfully.." << endl;
		  system("pause");
		  system("cls");
		  break;
	  case 4:
		  system("cls");
		  booking.displayFromHead();
		  system("pause");
		  system("cls");
		  break;
	  case 5:
	      ab="clear";
	      ac="clear";
		  system("cls");
		  cout<<dt<<endl;
		  room.displayFromHead();
		  cout<<"\n\t\tEnter User ID:";
		  cin>>id;
		  booking.uidcheck(id);
		  while(id=="exist")
          {
          cout<<"\n\t\tThe Entered User Id Already Exists!Try again"<<endl;
          cout<<"\n\t\tRenter UserID:";
          cin>>id;
          booking.uidcheck(id);
          }
		  cout<<"\n\t\tDate(DD/MM/YYYY):";
		  cin>>Date;
		  cout<<"\n\t\tCheck-In Time:";
		  cin>>st;
		  cout<<"\n\t\tPhone number:";
		  cin>>et;
		  cout<<"\n\t\tEnter RoomID:";
		  cin>>rid;
		  room.roomidcheck(rid,ab);
		  while(ab!="ridexist")
          {
          cout<<"\n\t\tThe Entered Room Id doesn't Exist!Try again"<<endl;
          cout<<"\n\t\tRenter Roomid:";
          cin>>rid;
          room.roomidcheck(rid,ab);
          }
		  cout<<"\n\t\tEnter Name:";
		  cin>>organizer;
		  cout<<"\n\t\tEnter No Of Members:";
		  cin>>capacity;
		  room.capacitycheck(rid,capacity,ac);
		  while(ac!="notexist")
          {
          cout<<"\n\t\tThe Entered Room Id capacity doesn't matches!Try again"<<endl;
          cout<<"\n\t\tRenter No Of Members:";
          cin>>capacity;
          room.capacitycheck(rid,capacity,ac);
          }
		  booking.insert(id,Date,st,et,rid,organizer,capacity);
		  cout<<"\n\t\tAdded Successfully.."<<endl;
		  system("pause");
		  system("cls");
		  break;
	  case 6:
		  system("cls");
		  booking.displayedit();
		  cout << "\n\t\tEnter User ID:";
		  cin >> id;
		  cout << "\n\t\tEnter Date(DD/MM/YYYY):";
		  cin >> Date;
		  cout << "\n\t\tCheck-In Time:";
		  cin >> st;
		  cout << "\n\t\tPhone number:";
		  cin >> et;
		  cout << "\n\t\tEnter RoomID:";
		  cin >> rid;
		  room.roomidcheck(rid,ab);
		  while(ab!="ridexist")
          {
          cout<<"\n\t\tThe Entered Room Id doesn't Exist!Try again"<<endl;
          cout<<"\n\t\tRenter Roomid:";
          cin>>rid;
          room.roomidcheck(rid,ab);
          }
		  cout << "\n\t\tEnter Name:";
		  cin >> organizer;
		  cout << "\n\t\tEnter No Of Members:";
		  cin >> capacity;
		  room.capacitycheck(rid,capacity,ac);
		  while(ac!="notexist")
          {
          cout<<"\n\t\tThe Entered Room Id capacity doesn't matches!Try again"<<endl;
          cout<<"\n\t\tRenter No Of Members:";
          cin>>capacity;
          room.capacitycheck(rid,capacity,ac);
          }
		  booking.edit(id, Date, st, et, rid, organizer, capacity);
		  cout << "\n\t\tReturned Successfully.." << endl;
		  system("pause");
		  system("cls");
		     break;
	  case 7:
		  system("cls");
		  booking.displayedit();
		  cout << "\n\n\t\tEnter the User ID:";
		  cin >> del;
		  booking.deleteInBetween(del);
		  cout << "\n\n\t\tDeleted Successfully.." << endl;
		  system("pause");
		  system("cls");
		  break;
	  case 8:
		  system("cls");
		  cout << "\n\n\t\tEnter 1 to search by Date(DD/MM/YYYY)." << endl;
		  cout << "\n\n\t\tEnter 2 to search by User ID." << endl;
		  cin >> num;

		  if (num == 1)
		  {
		      booking.displaydate();
			  cout << "\n\n\t\tEnter Date(DD/MM/YYYY): ";
		  }
		  else if (num == 2)
		  {
		      booking.displayedit();
			  cout << "\n\n\t\tEnter User ID: ";
		  }
		  cin >> searche;
		  booking.search(searche,num);
		  system("pause");
		  system("cls");
		  break;


      case 9:
        system("cls");
        cout << "\n\t\tAdmin ID: A000383" <<endl;
        cout << "\n\t\tName: Jungle Resort " << endl;
        cout << "\n\t\tPhone No:+91 2231448 "<< endl;
        cout << "\n\t\tEmail:Jungleresort@gmail.com "<< endl;
        system("pause");
        system("cls");
        break;
	  case 10:
	      {
           room.writetofile();
           booking.writetofileb();
	      }
		  return 0;
	  }

	  }
	  return 0;
	}

	Sleep(2000);
	cout<<"Invalid Username or Password!!"<<endl;
	Sleep(1000);
	cout<<"Please Try Again.."<<endl;
	Sleep(1500);
	system("cls");
	}

	system("pause");
	return 0;
}
