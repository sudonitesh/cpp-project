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
    
    void header() // student or Admin
    {
        cout<<"4. Search by student name\n 5. Search by ID\n6. Search by room\n7. Check room availability\n8. Display all entries\n";
        //4. name_search()
        //5. stud_search()
        //6. check_room()
        //7. stud_all_display()
    }
    // int idposition(int sid); // for update, delete , search
    void store_value(); //*
    
    void vector_2_file();
    void file_display();
    void name_search();
    
    
    //void get_stud_info();//(done)
    void stud_all_display();//*(done)
    void stud_search();//(done)
    
    
    //void get_roominfo();
    // void room_add();
    void room_search();//(done)
    // void room_remove();
    // int room_position(int n); //get floor
    void check_room();//(done)
    //void available_rooms();
    void vector_to_array();
    
    
    
    void stud_del(); //*(done)
    
    void program_close();//* file close
};

class Student: public Hostel
{
private:
    string password;
public:
    void header()// functions that student can access
    {
        cout<<"Enter password: ";
        cin>> password;
        if(password == "1234")
        {
        cout<<"Working as student"<<endl;
        cout<<"===================================="<<endl;
        cout<<"\n1. Request to leave hostel\n 2. Request to join hostel\n3. Request to keep guests\n";
        }
        
        //1. leave_app(id, name, room_no, start_date, end_date, reason)
        //2. join(id, name)
        //3. guest(id, name, start_date, end_date, g_name, g_relation)
        else
        {
            cout<<"Incorrect password."<<endl;
            exit(0);
        }
        
    }
    void leave_app() // 1. leave application
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

        string file_name = "leave.csv", line;
        ofstream file(file_name, ios::out);

        line = ID + "," + name + "," + room_no + "," + start_date + "," + end_date + "," + reason + "\n";
        file<<line;
        file.close();
    }
    
    void join() // 2. if student wants to join then get id, and details, send to db
    {
        string ID, name;
        cout<< "ID: ";cin>> ID;
        cout<<endl;
        cout<<"Name:"; cin>> name;
        cout<<endl;
        
        
        string file_name = "join.csv", line;
        ofstream file(file_name, ios::out);

        line = ID + "," + name + "\n";
        file<<line;
        file.close();
    }
    
    void guest() // 3. application request for guest... room reserved for guest
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
        
        string file_name = "guest.csv", line;
        ofstream file(file_name, ios::out);

        line = ID + "," + name + "," + start_date + "," + end_date + "," + g_name + "," + g_relation + "\n";
        file<<line;
        file.close();
    }
};

class Admin: public Hostel
{
private:
    string password;

public:
    void header() // functions admin can acess
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
    //1. add_student()
        //2. stud_del();
        //stud_clear();
            
    void add_student(); //*(done)
    void stud_clear(); //remove all students(done)
};

void Hostel:: store_value()
{
	string file_name = "db.csv", delimeter = ",";

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
    
    // for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    // {
    //     cout<< *it<< "\t";
    //     cout<< studentname[it-studentid.begin()]<< "\t";
    //     cout<< rnumber[it-studentid.begin()]<< endl;
    // }
    
}

void Hostel::stud_del() //error:
{
    cout<<endl<<"Enter ID of leaving student:";
    string id;
    cin>>id;
    int i = 0;
    
    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        cout<<*it<<" ";
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
    // studentname.erase (studentname.begin() + i);
    // rnumber.erase (rnumber.begin() + i);
    // vector_2_file();d
    
    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        cout<< *it<< "\t\t";
        cout<< studentname[it-studentid.begin()]<< "\t\t";
        cout<< rnumber[it-studentid.begin()]<< endl;
    }
    vector_2_file();
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
    vector_2_file();
}

void Hostel::vector_to_array()
{
    for (vector<string>::iterator it = rnumber.begin() ; it != rnumber.end(); ++it)
        cout<< *it<< "\t";
}
void Hostel::vector_2_file()    //stores values from all the three vectors into db1.csv
{
    string file_name = "db.csv", line;
    
    ofstream file(file_name, ios::out|ios::app);
    
    // for(int i = 0 ; i < studentname.size() ; i++)
    // {
    //     line = studentid[i] + "," + studentname[i] + "," + rnumber[i] + "\n";
    //     file<<line;
    // }
    
    for (vector<string>::iterator it = studentid.begin() ; it != studentid.end(); ++it)
    {
        line = string(*it) + "," + string(studentname[it-studentid.begin()]) + "," +  string(rnumber[it-studentid.begin()]) + '\n';
        file<<line;
    }
    
}

void Hostel::file_display()    //displays db1.csv
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
        // std::cout << "Element found in myvector: " << *it << '\n';
        cout<<"\nROOM NOT VACANT\n";

    }
    else {
        cout<<"\nROOM VACANT\n";

        // std::cout << "Element not found in myvector\n";
    }
    // for(vector<string>::iterator it = rnumber.begin(); it != rnumber.end(); ++it)
    // {
    //     if(*it == roomid)
    //     {
    //         cout<<"not vacant";
    //         break;
    //     }
    //     else {
    //         cout<<"ok vacant\n";
    //     }
    
    // }
 }

// void Hostel::get_stud_info()
// {
//     string name;
//     cout<<"Enter student's name:";
//     cin>>name;

// }
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
        

int main()
{
    Hostel H;
    Admin A;
    Student S;
    H.store_value();
    H.stud_all_display();
    
    // H.file_display();
    // H.stud_all_display();
    
    // S.leave_app("33", "nkt", "232", "22-11-22", "32-11-34", "reasonw wofwfc wcowcw");
    // S.leave_app("33324", "nkt", "232", "22-11-22", "32-11-34", "dsf"); // database overwriting not updating
    
    // S.join("342", "nsmer");
    // S.join("342", "nsfdgfdmer"); // database overwriting not updating
    
    // S.guest("ID", "name","start_date","end_date", "guest_name", "guest_relation");
    
    // A.stud_clear(); //error: not working
//    A.add_student();
//    A.add_student();
    // A.stud_all_display();
//    A.vector_2_file();
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
            case 2: H.stud_del();
                break;
            case 3: A.stud_clear();
                break;
            case 4: H.name_search();
                break;
            case 5: H.stud_search();
                break;
            case 6: H.check_room();
                break;
            case 7: H.room_search();
                 break; 
            case 8: H.stud_all_display();
            
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
            case 1: S.leave_app();
                break;
            case 2: S.join();
                break;
            case 3: S.guest();
                break;
            case 4: H.name_search();
                break;
            case 5: H.stud_search();
                break;
            case 6: H.check_room();
                break;
            case 7: H.stud_all_display();
                break;
        }
    }
    else if(choice == 0)
        return 0;
    return 0;
}

