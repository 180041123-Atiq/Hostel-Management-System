#ifndef PORTER_H
#define PORTER_H

#include <Employee.h>


class Porter : public Employee
{
    public:
        /** Default constructor */
        Porter();
        const void show_info();
        void disk_in();
        void disk_out();
        std::string id_gnrt(std::string s_name);
        std::string pwd_gnrt();
        void del_own_rec();
        bool login_op();
        void ck_prt_ord_lst();
        void del_prt_ord_lst(std::string q_room_no);
        void main_func_prt();

        ~Porter()
        {

        }

    protected:

    private:
};

#endif // PORTER_H
