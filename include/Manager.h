#ifndef MANAGER_H
#define MANAGER_H

#include <Employee.h>


class Manager : public Employee
{
    public:
        /** Default constructor */
        Manager();
        void main_func_mng();
        void add_mng();
        void del_rec();
        void show_info_otr();
        const void show_info();
        void disk_in();
        void disk_out();
        std::string id_gnrt(std::string s_name);
        std::string pwd_gnrt();
        void del_own_rec();
        bool login_op();
        void show_this_month_profit(int e);

        ~Manager()
        {

        }

    protected:

    private:
};

#endif // MANAGER_H
