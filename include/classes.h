#ifndef CLASSES_H
#define CLASSES_H
#include <vector>
#include<string>

class Hostel
{
    public:
        std::vector<std::string>rnumber;
        std::vector<std::string> studentid;
        std::vector<std::string>studentname;
        std::vector<int>studentroom;
        
        
        void header();
        void store_value(); //*
        
        void vector_2_file();
        void file_display();
        void name_search();
        
    
        void stud_all_display();
        void stud_search();
    
        void room_search();

        void check_room();
        void vector_to_array();
        
        
        
        void stud_del(); //*(done)
        
        void program_close();//* file close
};

class Student: public Hostel
{
    private:
        string password;
    public:
        void header();
        void leave_app();
        
        void join() ;
        
        void guest();
};

class Admin: public Hostel
{
private:
    string password;

public:
    void header();
            
    void add_student();
    void stud_clear(); 
};
#endif