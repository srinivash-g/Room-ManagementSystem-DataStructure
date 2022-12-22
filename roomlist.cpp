#include "roomList.h"


RoomList::RoomList()
{
	head = nullptr;
	tail = nullptr;
}

void RoomList::insert(string rt,string id,int c)
{
	Room rooms(rt,id,c);
	Noder *newNoder;
	newNoder = new Noder;
	newNoder->next = nullptr;
	newNoder->prev = nullptr;
	newNoder->data = rooms;
	if (head == nullptr)
	{
		head = newNoder;
		tail = newNoder;
	}
	else
	{
		tail->next = newNoder;
		newNoder->prev = tail;
		tail = newNoder;
	}
}
void RoomList::ridcheck(string& id)
{
	Noder* temp = head;
	while (temp!=nullptr)
	{
		if(temp->data.roomID==id)
		{
           id="exist";
		   break;
		}

		else
		{
			temp = temp->next;
		}
	}

}
void RoomList::roomidcheck(string rid,string& ab)
{
    Noder* temp = head;
	while (temp!=nullptr)
	{
		if(temp->data.roomID==rid)
		{
           ab="ridexist";
		   break;
		}

		else
		{
			temp = temp->next;
		}
	}


}
void RoomList::capacitycheck(string rid,int capacity,string& ac)
{
    Noder* temp = tail;
	while (temp!=nullptr)
	{
		if(temp->data.roomID==rid)
		{
		    if(temp->data.capacity>=capacity)
            {
             ac="notexist";
		     break;
            }
            break;
		}

		else
		{
			temp = temp->prev;
		}
	}

}
void RoomList::displayFromHead()
{
	Noder *temp = head;
	if (head == nullptr)
	{
		cout << "NO rooms To show.." << endl;
	}
	else{

		while (true)
		{
			temp->data.displayInfo();
			temp = temp->next;

			if (temp == nullptr)
				break;

		}
	}
}
void RoomList::displayedit()
{
	Noder *temp = head;
	if (head == nullptr)
	{
		cout << "NO Bookings To show.." << endl;
	}
	else
	{
		while (true)
		{
		    temp->data.editDisplay();
			cout << endl;
			temp = temp->next;

			if (temp == nullptr)
				break;

		}
	}
}
void RoomList::edit(string rt, string id, int c)
{
	Noder* temp = tail;
	while (temp != nullptr)
	{
		if (temp->data.roomID == id)
		{
			temp->data.roomType= rt;
			temp->data.capacity = c;
			cout << "\n\n\t\tEdited Successfully.." << endl;
			break;
		}

		else
		{
			temp = temp->prev;
		}
	}
	if (temp == nullptr)
    {
        cout<<"Room Id entered Not found";
    }

}
void RoomList::writetofile()
{
    ofstream f;
    f.open("room.dat",ios::out);
    Noder *temp =head;
	if (head == nullptr)
	{
		cout << "NO rooms To show.." << endl;
	}
	else{

		while (true)
		{
			temp->data.displayInfo();
			size_t len=temp->data.roomID.length()+1;
			f.write((char*)&len,sizeof(size_t));
			f.write(temp->data.roomID.c_str(),len);
            len=temp->data.roomType.length()+1;
			f.write((char*)&len,sizeof(size_t));
			f.write(temp->data.roomType.c_str(),len);
			f.write((char*)&temp->data.capacity,sizeof(int));
			temp = temp->next;
			if (temp == nullptr)
				break;

		}
	}
	f.close();

}
void RoomList::readfromfile()
{
    ifstream file("room.dat",ios::in);
    Room r;
    size_t len;
    char* s;
	if(file)
	while(true)
    {

        file.read((char*)&len,sizeof(size_t));
        if(!file)
            break;
        s=new char[len];
        file.read(s,len);
        r.roomID=s;
        delete s;
        file.read((char*)&len,sizeof(size_t));
        s=new char[len];
        file.read(s,len);
        r.roomType=s;
        delete s;
        int c;
        file.read((char*)&c,sizeof(int));
        r.capacity=c;
        insert(r.roomType,r.roomID,r.capacity);
    }
    file.close();
}
RoomList::~RoomList()
{


}
