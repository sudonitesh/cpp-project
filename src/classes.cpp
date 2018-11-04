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
