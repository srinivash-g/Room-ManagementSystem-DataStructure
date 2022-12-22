#include "doublylinkedlist.h"
DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}
void DoublyLinkedList::insert(string m,string d,string ts,string te,string r,string o,int p)
{
	Booking book(m,d,ts,te,r,o,p);
	Node *newNode;
	newNode = new Node;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	newNode->data = book;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}
void DoublyLinkedList::uidcheck(string& id)
{
	Node* temp = head;
	while (temp!=nullptr)
	{
		if (temp->data.memberID == id)
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

void DoublyLinkedList::displayedit()
{
	Node *temp = head;
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

void DoublyLinkedList::displaydate()
{
	Node *temp = head;
	if (head == nullptr)
	{
		cout << "NO Bookings To show.." << endl;
	}
	else
	{
		while (true)
		{
		    temp->data.searchdate();
			cout << endl;
			temp = temp->next;

			if (temp == nullptr)
				break;

		}
	}
}
void DoublyLinkedList::displayFromHead()
{
	Node *temp = head;
	if (head == nullptr)
	{
		cout << "NO Bookings To show.." << endl;
	}
	else
	{
		while (true)
		{
			temp->data.showBookingInfo();
			cout << endl;
			temp = temp->next;

			if (temp == nullptr)
				break;

		}
	}
}
void DoublyLinkedList::search(string d,int n) //searching used here
{
	Node* temp = tail;
	if (head == nullptr)
	{
		cout << "NO Bookings To search.." << endl;
	}
	else{
		while (true)
		{
		    if (n==1)
            {
			if (temp->data.date == d)
			{
				temp->data.showBookingInfo();
				cout<<"*****************************\n";
				temp = temp->prev;
                if (temp == nullptr)
                {
                    break;
                }
                break;
            }

			else
			{
				temp = temp->prev;
			}
		}
		if(n==2)
        {
            if(temp->data.memberID == d)
            {
				temp->data.showBookingInfo();
				cout<<"*****************************\n";
				temp = temp->prev;
                if (temp == nullptr)
                {
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
}
}
void DoublyLinkedList::edit(string m, string d, string ts, string te, string r, string o, int p)
{
	Node* temp = tail;

		while (temp != nullptr)
		{

            if (temp->data.memberID == m)
			{

				temp->data.date = d;
				temp->data.timeStart = ts;
				temp->data.timeEnd = te;
				temp->data.roomID = r;
				temp->data.organizer = o;
				temp->data.NoOFparticipants = p;
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
        cout<<"Usser Id entered Not found";
    }

}
void DoublyLinkedList::deleteInBetween(string val)
//           bool flag=false;
           {
            Node *temp = head;
            bool flag=false;
            if(temp->data.memberID==val)
                   {
                    head =temp->next;
                    head->prev=NULL;
                    flag=true;
                    delete temp;
                    if (flag==true)
                    {
                        cout<<"\n\tRecord has deleted Successfully:"<<endl;

                    }
                  }
                  else
                  {
                   while(temp!=NULL)
                   {
                       if(temp->data.memberID==val)
                       {
                           Node *p,*q;
                           if(temp->next==NULL)
                           {
                               p=temp->prev;
                               p->next=NULL;
                               flag=true;
                               delete temp;

                           }
                           else
                           {
                               p=temp->prev;
                               q=temp->next;
                               p->next=q;
                               q->prev=p;
                               flag=true;
                               delete temp;
                           }
                       }
                       temp=temp->next;

                   }
                   if(flag==false)
                   {
                       cout<<"\n\tValue is Not Found !"<<endl;

                   }
                  }
}
void DoublyLinkedList::writetofileb()
{
    ofstream f1;
    f1.open("book.dat",ios::out);
    Node *temp =head;
	if (head == nullptr)
	{
		cout << "NO rooms To show.." << endl;
	}
	else{

		while (true)
		{
			temp->data.showBookingInfo();
			size_t len=temp->data.memberID.length()+1;
			f1.write((char*)&len,sizeof(size_t));
			f1.write(temp->data.memberID.c_str(),len);
            len=temp->data.date.length()+1;
			f1.write((char*)&len,sizeof(size_t));
			f1.write(temp->data.date.c_str(),len);
			len=temp->data.timeStart.length()+1;
			f1.write((char*)&len,sizeof(size_t));
			f1.write(temp->data.timeStart.c_str(),len);
			len=temp->data.timeEnd.length()+1;
			f1.write((char*)&len,sizeof(size_t));
			f1.write(temp->data.timeEnd.c_str(),len);
			len=temp->data.roomID.length()+1;
			f1.write((char*)&len,sizeof(size_t));
			f1.write(temp->data.roomID.c_str(),len);
			len=temp->data.organizer.length()+1;
			f1.write((char*)&len,sizeof(size_t));
			f1.write(temp->data.organizer.c_str(),len);
			f1.write((char*)&temp->data.NoOFparticipants,sizeof(int));
			temp = temp->next;
			if (temp == nullptr)
				break;

		}
	}
	f1.close();
}
void DoublyLinkedList::readfromfileb()
{
    ifstream file1("book.dat",ios::in);
    Booking b;
    size_t len;
    char* s;
	if(file1)
	while(true)
    {

        file1.read((char*)&len,sizeof(size_t));
        if(!file1)
            break;
        s=new char[len];
        file1.read(s,len);
        b.memberID=s;
        delete s;
        file1.read((char*)&len,sizeof(size_t));
        s=new char[len];
        file1.read(s,len);
        b.date=s;
        delete s;
        file1.read((char*)&len,sizeof(size_t));
        s=new char[len];
        file1.read(s,len);
        b.timeStart=s;
        delete s;
        file1.read((char*)&len,sizeof(size_t));
        s=new char[len];
        file1.read(s,len);
        b.timeEnd=s;
        delete s;
        file1.read((char*)&len,sizeof(size_t));
        s=new char[len];
        file1.read(s,len);
        b.roomID=s;
        delete s;
        file1.read((char*)&len,sizeof(size_t));
        s=new char[len];
        file1.read(s,len);
        b.organizer=s;
        delete s;
        int c;
        file1.read((char*)&c,sizeof(int));
        b.NoOFparticipants=c;
        insert(b.memberID,b.date,b.timeStart,b.timeEnd,b.roomID,b.organizer,b.NoOFparticipants);
    }
    file1.close();
}
DoublyLinkedList::~DoublyLinkedList()
{


}
