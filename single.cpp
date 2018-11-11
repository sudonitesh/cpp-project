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
        std::vector<int>rfloor;
        std::vector<std::string> studentid;
        std::vector<std::string>studentname;
        std::vector<int>studentroom;

        // void program_open();

        // void header();
        
        // int idposition(int sid); // for update, delete , search

        void add_student(); //*
        void store_value(); //*

        void stud_del(); //*

        void get_stud_info();
        void stud_all_display();//*
        void stud_search();
        void stud_clear(); //remove all students

        void get_roominfo();
        // void room_add();
        void room_search();
        // void room_remove();
        // int room_position(int n); //get floor
        int check_room(int roomid);
        void available_rooms();

        


        void program_close();
};

class Student: public Hostel
{

};
class Staff: public Hostel
{

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

void Hostel::add_student()
{
    string id;
    //* cout<<"Enter student id: ";
    // cin>> id;
    id = "33";
    string name;
    //* cout<<"Enter student name: ";
    // cin>> name;
    name="sacfd";
    string room;
    //* cout<<"room num";
    // cin>>room;
    room = "343";
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
         for (vector<string>::iterator it = studentname.begin() ; it != studentname.end(); ++it)
            cout << ' ' << *it;
        cout<<endl;
         for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
            cout << ' ' << *it;
        //  for (vector<string>::iterator it = rnumber.begin() ; it != rnumber.end(); ++it)
        //     cout << ' ' << *it;
    // }
    // display_details(i);
}

void Hostel::stud_del()
{
    cout<<"id";
    string id;
    cin>>id;
    int i=0;
    cout<<endl;
    for (vector<string>::iterator it = studentname.begin() ; it != studentname.end(); ++it)
    cout << ' ' << *it;
    cout<<endl;

    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        if(*it == id)
        {
            cout<<"remove"<<*it<<endl;
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
    //     cout << ' ' << *it;
    // cout<<endl;
    //  for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    //     cout << ' ' << *it;
    // cout<<endl;
}

void Hostel::stud_all_display()
{
    cout<<endl;
    for (vector<string>::iterator it = studentname.begin() ; it != studentname.end(); ++it)
        cout << ' ' << *it;
    cout<<endl;
    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
        cout << ' ' << *it;
    //*: either show row-column wise or simply show the database
    cout<<endl;

}



int main()
{
    Hostel H;
    H.store_value();
    H.add_student();
    H.stud_del();
    H.stud_all_display();

    return 0;
}