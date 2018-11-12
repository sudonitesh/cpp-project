#include "../include/classes.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<boost/algorithm/string.hpp>


using namespace std;

void Hostel:: header() 
{
    cout<<"4. Search by student name\n 5. Search by ID\n6. Check room availability\n7. Search by room\n8. Display all entries\n";
}

void Student:: guest()
{
    string ID, name, start_date, end_date, g_name, g_relation;
    cout<< "ID: ";cin>> ID;
    cout<<endl;
    cout<<"Name:"; cin>> name;
    cout<<endl;


    cout<< "Start date"; cin>> start_date;
    cout<<endl;

    cout<< "End date: "; cin>> end_date;
    cout<<endl;

    cout<< "Name of the guest:"; cin>> g_name;
    cout<<endl;
    cout<< "Relation:"; cin>> g_relation;
    cout<<endl;

    string file_name = "../database/guest.csv", line;
    ofstream file(file_name, ios::out);

    line = ID + "," + name + "," + start_date + "," + end_date + "," + g_name + "," + g_relation + "\n";
    file<<line;
    file.close();
}

void Student::join() 
{
    string ID, name;
    cout<< "ID: ";cin>> ID;
    cout<<endl;
    cout<<"Name:"; cin>> name;
    cout<<endl;
    
    
    string file_name = "../database/join.csv", line;
    ofstream file(file_name, ios::out);

    line = ID + "," + name + "\n";
    file<<line;
    file.close();
}

void Student::leave_app()
{
    string ID, name, room_no, start_date, end_date, reason;
    cout<< "ID: ";cin>> ID;
    cout<<endl;
    cout<<"Name:"; cin>> name;
    cout<<endl;
    cout<< "Room no.:"; cin>> room_no;
    cout<<endl;

    cout<< "Start date"; cin>> start_date;
    cout<<endl;

    cout<< "End date: "; cin>> end_date;
    cout<<endl;

    cout<< "Reason for leave:"; cin>> reason;
    cout<<endl;

    string file_name = "../database/leave.csv", line;
    ofstream file(file_name, ios::out);

    line = ID + "," + name + "," + room_no + "," + start_date + "," + end_date + "," + reason + "\n";
    file<<line;
    file.close();
}

void Student::header()
{
    cout<<"Enter password: ";
    cin>> password;
    if(password == "1234")
    {
    cout<<"Working as student"<<endl;
    cout<<"===================================="<<endl;
    cout<<"\n1. Request to leave hostel\n 2. Request to join hostel\n3. Request to keep guests\n";
    }
    
    else
    {
        cout<<"Incorrect password."<<endl;
        exit(0);
    }
    
}

void Admin::header() 
{
    cout<<"Enter password: ";
    cin>> password;
    if(password == "abcd")
    {
    cout<<"Working as Admin"<<endl;
    cout<<"===================================="<<endl;
    cout<<"\n1. Add a new student\n2. Remove a student\n3. Clear all entries\n";
    }
    else
    {
        cout<<"Incorrect password."<<endl;
        exit(0);
    }
}

void Hostel:: store_value()
{
	string file_name = "../database/db.csv", delimeter = ",";

	ifstream file(file_name);
	
	vector<string> nm_v, rm_v, id_v;

	string line = "";

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

    vector_2_file();
    
}

void Hostel::stud_del()
{
    /*cout<<endl<<"Enter ID of leaving student:";
    string id;
    cin>>id;
    int i = 0;
    
    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        //cout<<*it<<" ";
        if(*it == id)
        {
            cout<<"Removing "<<*it<<endl;
            // break;
            studentid.erase (studentid.begin() + i);
            break;
        }
        i++;
    }
    cout<<endl;*/
    // studentname.erase (studentname.begin() + i);
    // rnumber.erase (rnumber.begin() + i);
    //vector_2_file();

    ifstream file1;
    file1.open("../database/db.csv");
    
    ofstream file2;
    file2.open("../database/temp.csv");
    
    string id, nm, rm_no, deleteline, line;
    cout << "Enter ID of leaving student:";
    cin>>id;
    cout<<"Enter name of the student:";
    cin>>nm;
    cout<<"Enter room no:";
    cin>>rm_no;

    deleteline = id + "," + nm + "," + rm_no;

    while (!file1.eof())
    {
        getline(file1, line);

        if(line.compare(deleteline) != 0)
        {
            file2 << line << endl;
        }
    }
    //file2.close();
    //file1.close();
    
    remove("../database/db.csv");
    rename("../database/temp.csv","../database/db.csv");
    cout<<endl;

    /*for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        cout<< *it<< "\t\t";
        cout<< studentname[it-studentid.begin()]<< "\t\t";
        cout<< rnumber[it-studentid.begin()]<< endl;
    }
    vector_2_file();*/

    stud_all_display();

}

void Hostel::stud_all_display()
{
    string file_name = "../database/db.csv", delimeter = ",";

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
            cout<<data<<" ";
        }

        cout<<endl;
    }
}



void Admin::stud_clear()
{
    rnumber.clear();
    studentid.clear();
    studentname.clear();
    vector_2_file();
}

void Hostel::vector_to_array()
{
    for (vector<string>::iterator it = rnumber.begin() ; it != rnumber.end(); ++it)
        cout<< *it<< "\t";
}
void Hostel::vector_2_file() 
{
    string file_name = "../database/db.csv", line;
    
    ofstream file(file_name, ios::out|ios::app);

    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        line = string(*it) + "," + string(studentname[it-studentid.begin()]) + "," +  string(rnumber[it-studentid.begin()]) + '\n';
        file<<line;
    }
    
}

void Hostel::file_display()
{
    
    string file_name = "../database/db.csv", delimeter = ",";
    
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
 void Hostel::room_search()
 {
    string roomno;
    cout<<"\nEnter the room no. to be searched:";
    cin>>roomno;
    vector<string>::iterator it;
    it=find(rnumber.begin(),rnumber.end(),roomno);
    if(it!=rnumber.end())
    {
        if(studentid[it-rnumber.begin()] == "")
        cout<<"\nRoom is vacant!!";
        else
        {
            cout<<"\nStudent Details for Room no."<<*it<<":";
            cout<<"\nName:"<<studentname[it-rnumber.begin()];
            cout<<"\nID:"<<studentid[it-rnumber.begin()];
        }
    }
    else
    cout<<"Room not found!"<<"\n\n";    
 }
 void Hostel::check_room()
 {
    string roomid;
    cin>>roomid;
    std::vector<string>::iterator it;
    it = find (rnumber.begin(), rnumber.end(), roomid);
    if (it != rnumber.end())
    {
        cout<<"\nROOM NOT VACANT\n";
    }
    else {
        cout<<"\nROOM VACANT\n";
    }

 }

// search by id
void Hostel::stud_search()
{
    string ID;
     cout<<"\nEnter the ID to be searched:";
     cin>>ID;
     vector<string>::iterator it;
     it=find(studentid.begin(),studentid.end(),ID);
     if(it!=studentid.end())
     {
         
              cout<<"\nStudent Details for Room no."<<*it<<":";
              cout<<"\nName:"<<studentname[it-studentid.begin()];
              cout<<"\nID:"<<studentid[it-studentid.begin()]<<endl;
           
     }
     else
         cout<<"ID not found!"<<"\n\n";
   
}
// search by name
void Hostel::name_search()
{
    string name;
    cout<<"\nEnter the name of the student:\n";
    cin>>name;
    vector<string>::iterator it;
    it=find(studentname.begin(),studentname.end(),name);
    if(it!=studentname.end())
    {
        cout<<"\nSTUDENT FOUND:\n";
        cout<<"\nID:"<<studentid[it-studentname.begin()];
        cout<<"\nROOM NO.:"<<rnumber[it-studentname.begin()]<<endl;
    }
    else
        cout<<"Element not found!"<<"\n\n\n";
}
