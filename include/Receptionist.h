#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <Employee.h>
#include "Room.h"

class Receptionist : public Employee
{
    public:
        /** Default constructor */
        Receptionist();
        const void show_info();
        void disk_in();
        void disk_out();
        std::string id_gnrt(std::string s_name);
        std::string pwd_gnrt();
        void del_own_rec();
        bool login_op();
        void main_func_recep();
        void ck_in_gst();
        void ck_out_gst();
        void ck_out_gst(std::string q_id,std::string q_pwd);
        void ck_info_gst();
        int h_m_d(int m);
        void prt_ord_lst();
        void show_empty_room();
        void infect_room();
        //const void operator ==(Employee* e);
        friend std::ostream& operator<<(std::ostream& os, Employee* dt);

        ~Receptionist()
        {
            delete r_obj;
        }


    protected:
        Room* r_obj;
    private:
};

#endif // RECEPTIONIST_H
