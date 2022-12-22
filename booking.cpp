#include"booking.h"
Booking::Booking()
{
	memberID=" ";
	date=" ";
	timeStart=" ";
	timeEnd=" ";
	roomID=" ";
	organizer=" ";
	NoOFparticipants=0;

}
Booking::Booking(string m,string d,string ts,string te,string r,string o,int p)
{
	memberID = m;

	date = d;

	timeStart = ts;

	timeEnd = te;

	roomID = r;

	organizer = o;

	NoOFparticipants=p;
	count++;
}
Booking::Booking(Booking &obj)
{

	memberID = obj.memberID;

	date = obj.date;

	timeStart = obj.timeStart;

	timeEnd = obj.timeEnd;

	roomID = obj.roomID;

	organizer = obj.organizer;

	NoOFparticipants=obj.NoOFparticipants;
}

void Booking::showBookingInfo()
{
	cout << "\nUser ID: " << memberID<<endl;
	cout << "\nDate(DD/MM/YYYY): " << date <<endl;
	cout << "\nCheck-In Time:" << timeStart <<endl;
	cout << "\nCheck-Out Time:" << timeEnd <<endl;
	cout << "\nRoom ID: " << roomID <<endl;
	cout << "\nName: " << organizer <<endl;
	cout << "\nNo of Members: " << NoOFparticipants <<endl;
	cout<<"*************************************************\n";
}
void Booking::editDisplay()
{
    cout << "\n\t\tUser ID: " << memberID<<endl;
    cout << "\n\t\tName: " << organizer <<endl;
}
void Booking::searchdate()
{
    cout << "\n\t\tDate: " << date <<endl;
    cout << "\n\t\tName: " << organizer <<endl;
}
void Booking::showInfoTomember()
{
	cout << "\nBooked on: " << date << endl;
	cout << "\nUser ID: " << memberID << endl;
	cout << "\nCheck-In Time:" << timeStart << endl;
	cout << "\nCheck-Out time" << timeEnd << endl;
	cout << "\nRoom ID: " << roomID << endl;
	cout << "\nName: " << organizer << endl;
	cout << "\nNo of Members: " << NoOFparticipants << endl;

}
Booking::~Booking()
{

}
