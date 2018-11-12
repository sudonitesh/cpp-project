// #include "../include/classes.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<boost/algorithm/string.hpp>


using namespace std;

class Hostel
{
    public:
        std::vector<std::string>rnumber;
        // std::vector<int>rfloor;
        std::vector<std::string> studentid;
        std::vector<std::string>studentname;
        std::vector<int>studentroom;

        // void program_open();

        void header(); // student or Admin

        // int idposition(int sid); // for update, delete , search

        void store_value(); //*



        void get_stud_info();
        void stud_all_display();//*(done)
        void stud_search();


        void get_roominfo();
        // void room_add();
        void room_search();
        // void room_remove();
        // int room_position(int n); //get floor
        int check_room(int roomid);
        void available_rooms();




        void program_close();//* file close
};

class Student: public Hostel
{
    public:
    void header(); // functions that student can access
//////////////////////////////////////////FOR ALL THE BELOW THREE FUNCTIONS, TELL ME IF YOU WANT TO ADD THREE DISPLAY FUNCTIONS FOR EACH////////////////////
    void leave_app(string ID, string name, string room_no, string start_date, string end_date, string reason) // 1. leave application
    {
	string file_name = "../database/leave.csv", line;
	ofstream file(file_name, ios::out);

	line = ID + "," + name + "," + room_no + "," + start_date + "," + end_date + "," + reason + "\n";
	file<<line;
	file.close();
    }

    void join(string ID, string name) // 2. if student wants to join then get id, and details, send to db
    {
	string file_name = "../database/join.csv", line;
	ofstream file(file_name, ios::out);

	line = ID + "," + name + "\n";
	file<<line;
	file.close();
    }

    void guest(string ID, string name, string start_date, string end_date, string guest_name, string guest_relation) // 3. application request for guest... room reserved for guest
    {
	string file_name = "../database/guest.csv", line;
	ofstream file(file_name, ios::out);

	line = ID + "," + name + "," + start_date + "," + end_date + "," + guest_name + "," + guest_relation + "\n";
	file<<line;
	file.close();
    }
};

class Admin: public Hostel
{
    public:
        void header(); // functions admin can acess
        void add_student(); //*(done)
        void stud_del(); //*(done)
        void stud_clear(); //remove all students(done)



};


void Hostel:: store_value()	//stores all IDs, names and room nos in separate vectors
{
	string file_name = "db.csv", delimeter = ",";

	ifstream file(file_name);

	vector<string> nm_v, rm_v, id_v;

	string line = "";

	getline(file, line);

	while(getline(file, line))
	{
			vector<string> vect;
			boost::algorithm::split(vect, line, boost::is_any_of(delimeter));

			studentid.push_back(vect[0]);
			studentname.push_back(vect[1]);
			rnumber.push_back(vect[2]);
	}

	// file.close();

	// for (int i = 0 ; i < 60 ; i++)	//display all the vectors (delete if you don't want)
  	// {
	//    cout <<  studentid[i] << " " << studentname[i] << " " << rnumber[i] << endl;
  	// }
}

void Admin::add_student()
{
    string id;
    cout<<"Enter student id: ";
    cin>> id;
    string name;
    cout<<"Enter student name: ";
    cin>> name;
    string room;
    cout<<"Enter room number: ";
    cin>>room;
    // if(rnumber.size() > 60)
    // {
    //     cout<< "No vacancy."<< endl;
    // }
    // else
    // {
    // int i = 0;
    // while(studentname[i] != NULL)
    // {
    //     i++;
    // }
    studentname.push_back(name);
    studentid.push_back(id);
    rnumber.push_back(room);

    // if(rnumber[i] <= 20) //20 rooms in one floor
    //     rfloor[i] = 1;
    // else if(rnumber[i] > 20 && rnumber[i] <= 40)
    //     rfloor[i] = 2;
    // else
    //     rfloor[i] = 3;
    // cout<< "ID: "<< studentid.end()<< endl;
    // cout<< "Name: "<< studentname.end()<< endl;
    // cout<<"Room No.: "<< rnumber.end()<< endl;
    // cout<<"Floor No.: "<< rfloor[i]<< endl;
    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        cout<< *it<< "\t";
        cout<< studentname[it-studentid.begin()]<< "\t";
        cout<< rnumber[it-studentid.begin()]<< endl;
    }
    // cout<<endl;
    // for (vector<string>::iterator it = rnumber.begin() ; it != rnumber.end(); ++it)
    //     cout<< *it<< "\t";
    // }
    // display_details(i);
}

void Admin::stud_del()
{
    cout<<endl<<"Enter ID of leaving student:";
    string id;
    cin>>id;
    int i = 0;
    cout<<endl;
    // for (vector<string>::iterator it = studentname.begin() ; it != studentname.end(); ++it)
    // cout << ' ' << *it;
    // cout<<endl;

    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        if(*it == id)
        {
            cout<<"Removing "<<*it<<endl;
            // break;
            studentid.erase (studentid.begin() + i);
            break;
        }
        i++;
    }
    cout<<endl;
    studentname.erase (studentname.begin() + i);
    rnumber.erase (rnumber.begin() + i);

    // cout<<endl;

    // for (vector<string>::iterator it = studentname.begin() ; it != studentname.end(); ++it)
    //     cout<< *it<<"\t";
    // cout<<endl;
    // for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    //     cout<< *it<<"\t";
    // cout<<endl;
    // for (vector<string>::iterator it = rnumber.begin() ; it != rnumber.end(); ++it)
    //     cout<< *it<<"\t";
    // cout<<endl;
    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        cout<< *it<< "\t";
        cout<< studentname[it-studentid.begin()]<< "\t";
        cout<< rnumber[it-studentid.begin()]<< endl;
    }
}

void Hostel::stud_all_display()
{
    // cout<<endl;
    // for (vector<string>::iterator it = studentname.begin() ; it != studentname.end(); ++it)
    //     cout << *it<< "\t";
    // cout<<endl;
    // for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    //     cout<< *it<< "\t";
    // cout<<endl;
    // for (vector<string>::iterator it = rnumber.begin() ; it != rnumber.end(); ++it)
    //     cout<< *it<< "\t";
    // //*: either show row-column wise or simply show the database
    // cout<<endl;
    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        cout<< *it<< "\t";
        cout<< studentname[it-studentid.begin()]<< "\t";
        cout<< rnumber[it-studentid.begin()]<< endl;
    }

}

void Admin::stud_clear()
{
    rnumber.clear();
    studentid.clear();
    studentname.clear();
}


void vector_2_file()	//stores values from all the three vectors into db1.csv
{
	string file_name = "../database/db1.csv", line;

	ofstream file(file_name, ios::out);

	for(int i = 0 ; i < studentname.size() ; i++)
	{
		line = studentid[i] + "," + studentname[i] + "," + rnumber[i] + "\n";
		file<<line;
	}

}

void file_display()	//displays db1.csv
{

	string file_name = "../database/db1.csv", delimeter = ",";

	ifstream file(file_name);
	vector<vector<string>> dataList;
	string line = "";

	while(getline(file, line))
	{
		vector<string> vect;
		boost::algorithm::split(vect, line, boost::is_any_of(delimeter));
		dataList.push_back(vect);
	}

	for(vector<string> vect : dataList)
	{
		for(string data : vect)
		{
			cout<<data<<" , ";
		}

		cout<<endl;
	}

	file.close();

}

//Some Hostel functions added

//Search a student name and room number by his id
void Hostel::stud_search()
{
    int ser;
    cout<<"\nEnter the Student Id:\n";
    cin>>ser;
    vector<int>::iterator it;
    it=find(studentid.begin(),studentid.end(),ser);
    if(it!=studentid.end())
    {
        cout<<"\nSTUDENT FOUND:\n";
        cout<<"\nNAME:"<<studentname[it-studentid.begin()];
        cout<<"\nROOM NO.:"<<studentroom[it-studentroom.begin()];
    }
    else
        cout<<"Element not found!"<<"\n\n\n";
}


//Search for the student name and id by the room number
void Hostel::room_search()
{
    int roomno;
    cout<<"\nEnter the room no. to be searched:";
    cin>>roomno;
    vector<int>::iterator it;
    it=find(studentroom.begin(),studentroom.end(),roomno);
    if(it!=studentroom.end())
    {
        if(studentid[it-studentroom.begin()]=='\0')
          cout<<"\nRoom is vacant!!";
        else
          {
             cout<<"\nStudent Details for Room no."<<*it<<":";
             cout<<"\nName:"<<studentname[it-studentroom.begin()];
             cout<<"\nID:"<<studentid[it-studentroom.begin()];
          }
    }
    else
        cout<<"Room not found!"<<"\n\n";
}

//Check whether the searched room is vacant
int Hostel::check_room(int roomid)
{
    vector<int>::iterator it;
    it=find(studentroom.begin(),studentroom.end(),roomid);
    if(it!=studentroom.end())
    {
        if(studentid[it-studentroom.begin()]=='\0')
          return 0; //Room is vacant
        else
          return 1; //Room is occupied already
    }
    else
        return -1;//Invalid room number entered
}


//Check for the number of available/unoccupied rooms not required anymore
/*void Hostel::available_rooms()
{
    //Addition of code after add_student() function
}*/


int main()
{
    Hostel H;
    Admin A;
    Student S;
    H.store_value();
    H.header();
    int i, stud_option, admin_option;
    cin>>i;
    if(i==1)
    {
        // while input not equal 0 run
        cout<<"student\n";
        S.header();
        /*
            1. stud_all_display
        */
       cin>>stud_option;
       switch(stud_option)
        {
            case 1:
                S.stud_all_display();

        }

    }
    if(i==2)
    {
        cout<<"admin\n";
        A.header();

    }
    // H.store_value();
    // H.add_student();
    // H.stud_del();
    // H.stud_all_display();

    return 0;
}
