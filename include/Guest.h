#ifndef GUEST_H
#define GUEST_H
#include<string>

class Guest
{
    public:
        /** Default constructor */
        Guest();
        std::string id_gnrt(std::string g_name);
        std::string pwd_gnrt();
        bool login_op();
        void main_func_gst();
        void prt_ord_lst();
        void wtr_ord_lst();
        void cln_ord_lst();

        /** Access name
         * \return The current value of name
         */

         std::string Getdate() {return date;}

         void Setdate(std::string val) {date=val;}

        std::string Getname() { return name; }
        /** Set name
         * \param val New value to set
         */
        void Setname(std::string val) { name = val; }
        /** Access id
         * \return The current value of id
         */
        std::string Getid() { return id; }
        /** Set id
         * \param val New value to set
         */
        void Setid(std::string val) { id = val; }
        /** Access pwd
         * \return The current value of pwd
         */
        std::string Getpwd() { return pwd; }
        /** Set pwd
         * \param val New value to set
         */
        void Setpwd(std::string val) { pwd = val; }
        /** Access room_no
         * \return The current value of room_no
         */
        std::string Getroom_no() { return room_no; }
        /** Set room_no
         * \param val New value to set
         */
        void Setroom_no(std::string val) { room_no = val; }

        ~Guest()
        {

        }

    protected:

    private:
        std::string name; //!< Member variable "name"
        std::string id; //!< Member variable "id"
        std::string pwd; //!< Member variable "pwd"
        std::string room_no; //!< Member variable "room_no"
        std::string date;
};

#endif // GUEST_H
