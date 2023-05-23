#ifndef GUARD_H
#define GUARD_H

#include <Employee.h>


class Guard : public Employee
{
    public:
        /** Default constructor */
        Guard();
        const void show_info();
        void disk_in();
        void disk_out();
        std::string id_gnrt(std::string s_name);
        std::string pwd_gnrt();
        void del_own_rec();
        bool login_op();

        ~Guard()
        {

        }

    protected:

    private:
};

#endif // GUARD_H
