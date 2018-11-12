#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<boost/algorithm/string.hpp>
#include "../include/classes.h"
#include "../include/functions.h"

using namespace std;

int main()
{
    Hostel H;
    Admin A;
    Student S;
    H.store_value();
    cout<<"\nPress the appropriate key:"<<endl;
    cout<<"\n1. Admin\n2. Student\n0. Exit\n";
    int admin_choice=1, stud_choice, choice;
    cin>>choice;
    if(choice == 1)
    {
        A.header();
        H.header();

        cin>> admin_choice;
        switch(admin_choice)
        {
            case 1: 
                A.add_student();
                break;
            case 2: 
                H.stud_del();
                break;
            case 3: 
                A.stud_clear();
                break;
            case 4: 
                H.name_search();
                break;
            case 5: 
                H.stud_search();
                break;
            case 6: 
                H.check_room();
                break;
            case 7: 
                H.room_search();
                 break; 
            case 8: 
                H.stud_all_display();
                break;
        }
    }
    
    else if(choice == 2)
    {
        S.header();
        H.header();
        cin>> stud_choice;
        switch(stud_choice)
        {
            case 1: 
                S.leave_app();
                break;
            case 2: 
                S.join();
                break;
            case 3: 
                S.guest();
                break;
            case 4: 
                H.name_search();
                break;
            case 5: 
                H.stud_search();
                break;
            case 6: 
                H.check_room();
                break;
            case 7: 
                H.stud_all_display();
                break;
        }
    }
    else if(choice == 0)
        {
            exit(0);
        }
    
    return 0;
}

