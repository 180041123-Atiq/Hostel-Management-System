#ifndef CLEANER_H
#define CLEANER_H

#include <Employee.h>


class Cleaner : public Employee
{
    public:
        /** Default constructor */
        Cleaner();
        const void show_info();
        void disk_in();
        void disk_out();
        std::string id_gnrt(std::string s_name);
        std::string pwd_gnrt();
        void del_own_rec();
        bool login_op();
        void main_func_cln();
        void del_gst_ord(std::string q_room_no);

        ~Cleaner()
        {

        }

    protected:

    private:
};

#endif // CLEANER_H
