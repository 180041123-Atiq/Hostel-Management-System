#ifndef WAITER_H
#define WAITER_H

#include <Employee.h>


class Waiter : public Employee
{
    public:
        /** Default constructor */
        Waiter();
        const void show_info();
        void disk_in();
        void disk_out();
        std::string id_gnrt(std::string s_name);
        std::string pwd_gnrt();
        void del_own_rec();
        bool login_op();
        void main_func_wtr();
        void ck_gst_ord();
        void del_gst_ord(std::string q_room_no);
        bool addequate(std::string q_set);

        ~Waiter()
        {

        }

    protected:

    private:
};

#endif // WAITER_H
