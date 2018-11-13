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
    cout<<"\t\t\t  4. Search by student name\n\t\t\t  5. Search by ID\n\t\t\t  6. Check room availability\n\t\t\t  7. Search by room\n\t\t\t  8. Display all entries\n";
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
    cout<<"\t\t\tEnter password: ";
    cin>> password;
    if(password == "1234")
    {
        //system("CLS");
        cout<<"\n\t\t\t====================================";
        cout<<"\n\t\t\t         LOGGED in as : Student"<<endl;
        cout<<"\t\t\t===================================="<<endl;
        cout<<"\n\t\t\t  1. Request to leave hostel\n\t\t\t  2. Request to join hostel\n\t\t\t  3. Request to keep guests\n";
    }

    else
    {
        cout<<"\n\n\t\t   <<<<<<< ERROR:Incorrect password!! >>>>>>>>>"<<endl;
        cout<<"\n\t\t\t  TERMINATING...........\n\n";
        exit(0);
    }

}

void Admin::header()
{
    cout<<"\t\t\tEnter password: ";
    cin>> password;
    if(password == "abcd")
    {
        //system("CLS");
        cout<<"\n\t\t\t====================================";
        cout<<"\n\t\t\t         LOGGED in as : Admin "<<endl;
        cout<<"\t\t\t===================================="<<endl;
        cout<<"\n\t\t\t  1. Add a new student\n\t\t\t  2. Remove a student\n\t\t\t  3. Clear all entries\n";
    }
    else
    {
        cout<<"\n\n\t\t   <<<<<<<<< ERROR:Incorrect password!! >>>>>>>>>>"<<endl;
        cout<<"\n\t\t\t   TERMINATING...........\n\n";
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
    //system("CLS");
    cout<<"\n\t\t\t====================================";
    cout<<"\n\t\t\t       Enter the following Details:"<<endl;
    cout<<"\t\t\t===================================="<<endl;
    string id;
    cout<<"\t\t\tStudent ID: ";
    cin>> id;cout<<endl;
    string name;
    cout<<"\t\t\tStudent Name: ";
    cin>> name;cout<<endl;
    string room;
    cout<<"\t\t\tRoom Number: ";
    cin>>room;cout<<endl;

    studentname.push_back(name);
    studentid.push_back(id);
    rnumber.push_back(room);

    cout<<"\n\n\t\t\t<<<<<<<<__Student successfully added.__>>>>>>>>>"<<endl;

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
    //system("CLS");
    cout<<"\n\t\t\t====================================";
    cout<<"\n\t\t\t       Enter the following Details:"<<endl;
    cout<<"\t\t\t===================================="<<endl;
    cout << "\t\t\tID of leaving student:";
    cin>>id;
    cout<<"\t\t\tName of the student:";
    cin>>nm;
    cout<<"\t\t\tRoom no:";
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
    //system("CLS");
    cout<<"\n\t\t\t   ====================================";
    cout<<"\n\t\t\t            Complete details:"<<endl;
    cout<<"\t\t\t   ===================================="<<endl;
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
            cout<<"\t\t"<<data<<" ";
        }

        cout<<endl;
    }
}



void Admin::stud_clear()
{
    rnumber.clear();
    studentid.clear();
    studentname.clear();
    //system("CLS");
    cout<<"\n\n\n\n\n\t\t\t------------------STUDENT DETAILS DELETED SUCCESSFULY!!---------------------";
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
    //system("CLS");
    cout<<"\n\t\t\t   ====================================";
    cout<<"\n\t\t\t            Enter the details:"<<endl;
    cout<<"\t\t\t   ===================================="<<endl;
    string roomno;
    cout<<"\n\t\t\tRoom no. to be searched:";
    cin>>roomno;
    vector<string>::iterator it;
    it=find(rnumber.begin(),rnumber.end(),roomno);
    if(it!=rnumber.end())
    {
        if(studentid[it-rnumber.begin()] == "")
        cout<<"\n\n\t\t\tRoom is vacant!!";
        else
        {
            cout<<"\n\t\t\tStudent Details for Room no."<<*it<<":";
            cout<<"\n\t\t\tName:"<<studentname[it-rnumber.begin()];
            cout<<"\n\t\t\tID:"<<studentid[it-rnumber.begin()];
        }
    }
    else
    cout<<"Room not found!"<<"\n\n";
 }
 void Hostel::check_room()
 {
    //system("CLS");
    cout<<"\n\t\t\t   ====================================";
    cout<<"\n\t\t\t            Enter the details:"<<endl;
    cout<<"\t\t\t   ===================================="<<endl;
    cout<<"\n\t\t\tRoom number:"<<endl;
    string roomid;
    cin>>roomid;
    std::vector<string>::iterator it;
    it = find (rnumber.begin(), rnumber.end(), roomid);
    if (it != rnumber.end())
    {
        cout<<"\nROOM NOT VACANT\n";
    }
    else
    {
        cout<<"\nROOM VACANT\n";
    }

 }

// search by id
void Hostel::stud_search()
{
     string ID;
     //system("CLS");
     cout<<"\n\t\t\t   ====================================";
     cout<<"\n\t\t\t            Enter the details:"<<endl;
     cout<<"\t\t\t   ===================================="<<endl;
     cout<<"\n\t\t\tID to be searched:";
     cin>>ID;
     vector<string>::iterator it;
     it=find(studentid.begin(),studentid.end(),ID);
     if(it!=studentid.end())
     {

              cout<<"\n\t\t\tStudent Details for Room no."<<*it<<":";
              cout<<"\n\t\t\tName:"<<studentname[it-studentid.begin()];
              cout<<"\n\t\t\tID:"<<studentid[it-studentid.begin()]<<endl;

     }
     else
         cout<<"\n\t\t\tID not found!"<<"\n\n";

}
// search by name
void Hostel::name_search()
{
    string name;
    //system("CLS");
    cout<<"\n\t\t\t   ====================================";
    cout<<"\n\t\t\t            Enter the details:"<<endl;
    cout<<"\t\t\t   ===================================="<<endl;
    cout<<"\n\t\t\tName of the student:\n";
    cin>>name;
    vector<string>::iterator it;
    it=find(studentname.begin(),studentname.end(),name);
    if(it!=studentname.end())
    {
        cout<<"\n\t\t\tSTUDENT FOUND:\n";
        cout<<"\n\t\t\tID:"<<studentid[it-studentname.begin()];
        cout<<"\n\t\t\tROOM NO.:"<<rnumber[it-studentname.begin()]<<endl;
    }
    else
        cout<<"\t\t\tElement not found!"<<"\n\n\n";
}
