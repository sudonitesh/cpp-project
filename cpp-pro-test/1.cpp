#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<boost/algorithm/string.hpp>

#include <typeinfo>


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

        void vector_2_file();
        void file_display();

        

        void get_stud_info();
        void stud_all_display();//*(done)
        void stud_search();
        

        //void get_roominfo();
        // void room_add();
        void room_search();
        // void room_remove();
        // int room_position(int n); //get floor
        int check_room(int roomid);
        void available_rooms();
        void vector_to_array();

        


        void program_close();//* file close
};

class Student: public Hostel
{
    public:
    void header(); // functions that student can access
    void leave_app(string ID, string name, string room_no, string start_date, string end_date, string reason) // 1. leave application
    {
	string file_name = "leave.csv", line;
	ofstream file(file_name, ios::out);

	line = ID + "," + name + "," + room_no + "," + start_date + "," + end_date + "," + reason + "\n";
	file<<line;
	file.close();
    }
    
    void join(string ID, string name) // 2. if student wants to join then get id, and details, send to db
    {
	string file_name = "join.csv", line;
	ofstream file(file_name, ios::out);

	line = ID + "," + name + "\n";
	file<<line;
	file.close();
    }

    void guest(string ID, string name, string start_date, string end_date, string guest_name, string guest_relation) // 3. application request for guest... room reserved for guest 
    {
	string file_name = "guest.csv", line;
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

void Hostel:: store_value()
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

    studentname.push_back(name);
    studentid.push_back(id);
    rnumber.push_back(room);

    // for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    // {
    //     cout<< *it<< "\t";
    //     cout<< studentname[it-studentid.begin()]<< "\t";
    //     cout<< rnumber[it-studentid.begin()]<< endl;
    // }

}

void Admin::stud_del()
{
    cout<<endl<<"Enter ID of leaving student:";
    string id;
    cin>>id;
    int i = 0;
    cout<<endl;

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
    
    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        cout<< *it<< "\t";
        cout<< studentname[it-studentid.begin()]<< "\t";
        cout<< rnumber[it-studentid.begin()]<< endl;
    }
}

void Hostel::stud_all_display()
{
    for(vector<string>::iterator it = studentid.begin(); it != studentid.end(); ++it)
    {
        cout<< *it<< "\t";
        cout<< studentname[it - studentid.begin()]<< "\t";
        cout<< rnumber[it - studentid.begin()]<< endl;
    }
}
    


void Admin::stud_clear()
{
    rnumber.clear();
    studentid.clear();
    studentname.clear();
}

void Hostel::vector_to_array()
{
    for (vector<string>::iterator it = rnumber.begin() ; it != rnumber.end(); ++it)
        cout<< *it<< "\t";
}
void Hostel::vector_2_file()	//stores values from all the three vectors into db1.csv
{
	string file_name = "db.csv", line;

	ofstream file(file_name, ios::out);

	// for(int i = 0 ; i < studentname.size() ; i++)
	// {
	// 	line = studentid[i] + "," + studentname[i] + "," + rnumber[i] + "\n";
	// 	file<<line;
	// }
    
    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        line = string(*it) + "," + string(studentname[it-studentid.begin()]) + "," +  string(rnumber[it-studentid.begin()]) + '\n';
        file<<line;
    }

}

void Hostel::file_display()	//displays db1.csv
{
		
	string file_name = "db.csv", delimeter = ",";

	ifstream file(file_name);
	vector<vector<string> > dataList;
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
// void Hostel::room_search()
// {
//     int roomno;
//     cout<<"\nEnter the room no. to be searched:";
//     cin>>roomno;
//     vector<int>::iterator it;
//     it=find(studentroom.begin(),studentroom.end(),roomno);
//     if(it!=studentroom.end())
//     {
//         if(studentid[it-studentroom.begin()]=='\0')
//           cout<<"\nRoom is vacant!!";
//         else
//           {
//              cout<<"\nStudent Details for Room no."<<*it<<":";
//              cout<<"\nName:"<<studentname[it-studentroom.begin()];
//              cout<<"\nID:"<<studentid[it-studentroom.begin()];
//           }
//     }
//     else
//         cout<<"Room not found!"<<"\n\n";
// }
// int Hostel::check_room(int roomid)
// {
//     vector<int>::iterator it;
//     it=find(studentroom.begin(),studentroom.end(),roomid);
//     if(it!=studentroom.end())
//     {
//         if(studentid[it-studentroom.begin()]=='\0')
//           return 0; //Room is vacant
//         else
//           return 1; //Room is occupied already
//     }
//     else
//         return -1;//Invalid room number entered
// }

// void Hostel::get_stud_info()
// {
//     string name;
//     cout<<"Enter student's name:";
//     cin>>name;

// }

int main()
{
    Hostel H;
    Admin A;
    Student S;
    H.store_value();

    // H.file_display();
    // H.stud_all_display();

    // S.leave_app("33", "nkt", "232", "22-11-22", "32-11-34", "reasonw wofwfc wcowcw");
    // S.leave_app("33324", "nkt", "232", "22-11-22", "32-11-34", "dsf"); // database overwriting not updating

    // S.join("342", "nsmer");
    // S.join("342", "nsfdgfdmer"); // database overwriting not updating

    // S.guest("ID", "name","start_date","end_date", "guest_name", "guest_relation");

    // A.stud_clear(); //error: not working
    A.add_student();
    A.add_student();
    // A.stud_all_display();
    A.vector_2_file();

    return 0;
}
