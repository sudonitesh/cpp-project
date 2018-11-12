#ifndef CLASSES_H
#define CLASSES_H
#include <vector>
#include<string>


// class Demo
// {
//     private:
//         int i;
//     public:
//         Demo(int n);
//         int showData();
// };
class Hostel
{
    public:
        std::vector<std::string>rnumber;
        std::vector<int>rfloor;
        std::vector<std::string> studentid;
        std::vector<std::string>studentname;
        std::vector<int>studentroom;

        void program_open();

        void header();
        
        // int idposition(int sid); // for update, delete , search

        void add_student();
        void store_value();

        void stud_del();

        void get_stud_info();
        void stud_all_display();
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

#endif