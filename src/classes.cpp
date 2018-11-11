#include "../include/classes.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<boost/algorithm/string.hpp>


using namespace std;

/***rest of the functions */////

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

//Clear all the student details
void Hostel::stud_clear()
{
    rnumber.clear();
    studentid.clear();
    studentname.clear();
    studentroom.clear();
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
        cout<<"Room not found!"<<"\n\n\n";
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


//Check for the number of available/unoccupied rooms
void Hostel::available_rooms()
{
    //Addition of code after add_student() function
}

//display all student details
void Hostel::stud_all_display()
{
    cout<< "Student ID\tStudent Name\tRoom No."<< endl;
    for(unsigned int i = 0; i <= studentname.size(); i++)
    {
        cout<< studentid[i]<<"\t"<< studentname[i]<<"\t"<<rnumber[i]<< endl;;
    }
}

//Add a student
void Hostel::add_student()
{
    string id;
    cout<<"Enter student id: ";
    cin>> id;
    string name;
    cout<<"Enter student name: ";
    cin>> name;
    if(rnumber.size() > 60)
    {
        cout<< "No vacancy."<< endl;
    }
    else
    {
        int i = 0;
        while(rnumber[i] != NULL)
        {
            i++;
        }
        studentname[i] = name;
        studentid[i] = id;
        rnumber[i] = i;
        if(rnumber[i] <= 20) //20 rooms in one floor
            rfloor[i] = 1;
        else if(rnumber[i] > 20 && rnumber[i] <= 40)
            rfloor[i] = 2;
        else
            rfloor[i] = 3;
    }
    display_details(i);
}

//Display the details of a given index
void Hostel::display_details(int i)
{
    cout<< "ID: "<< studentid[i]<< endl;
    cout<< "Name: "<< studentname[i]<< endl;
    cout<<"Room No.: "<< rnumber[i]<< endl;
    cout<<"Floor No.: "<< rfloor[i]<< endl;
}

//Remove a student
void Hostel::stud_del()
{
    int room_no;
    cout<< "Enter room number: ";
    cin>> room_no;
    int i = 0;
    while(rnumber[i] != room_no)
    {
        i++;
    }
    rnumber[i] = NULL;
    studentname[i] = NULL;
    studentid[i] = NULL;
    rfloor[i] = NULL;
}
