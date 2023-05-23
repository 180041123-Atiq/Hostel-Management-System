#ifndef COOK_H
#define COOK_H

#include <Employee.h>


class Cook : public Employee
{
    public:
        /** Default constructor */
        Cook();
        const void show_info();
        void disk_in();
        void disk_out();
        std::string id_gnrt(std::string s_name);
        std::string pwd_gnrt();
        void del_own_rec();
        bool login_op();
        void main_func_cok();

        ~Cook()
        {

        }

    protected:

    private:
};

#endif // COOK_H
