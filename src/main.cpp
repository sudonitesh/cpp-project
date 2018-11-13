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
    int choice=1;
    do{
        cout<<"\n\t\t\t~~-----------------------------~~";
        cout<<"\n\t\t\t  **PRESS the appropriate key**"<<endl;
        cout<<"\t\t\t~~-----------------------------~~"<<endl;
        cout<<"\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
        cout<<"\n\t\t\t1. Admin\n\t\t\t2. Student\n\t\t\t0. Exit\n\n\t\t\tEnter your choice:";
        int admin_choice=1, stud_choice;
        cin>>choice;
        cout<<endl;

            if(choice == 1)
            {
                A.header();
                H.header();

                cout<<"\n\t\t\tEnter your choice:";
                cin>> admin_choice;
                cout<<endl;

                switch(admin_choice)
                {
                    case 1:
                        A.add_student();
                        break;
                    case 2:
                        H.stud_del();
                        break;
                    case 3:
                        A.stud_clear(); //!error
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

                cout<<"\n\t\t\tEnter your choice:";
                cin>> stud_choice;
                cout<<endl;

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
                        H.check_room(); //!error
                        break;
                    case 7:
                        H.room_search();
                    case 8:
                        H.stud_all_display(); //!error
                        break;
                }
            }
    } while(choice!=0);

    return 0;
}

