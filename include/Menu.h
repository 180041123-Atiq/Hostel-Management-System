#ifndef MENU_H
#define MENU_H
#include<string>

class Menu
{
    public:
        /** Default constructor */
        Menu();

        /** Access set
         * \return The current value of set
         */
        std::string Getset() { return set; }
        /** Set set
         * \param val New value to set
         */
        void Setset(std::string val) { set = val; }
        /** Access room_no
         * \return The current value of room_no
         */
        std::string Getroom_no() { return room_no; }
        /** Set room_no
         * \param val New value to set
         */
        void Setroom_no(std::string val) { room_no = val; }

    protected:

    private:
        std::string set; //!< Member variable "set"
        std::string room_no; //!< Member variable "room_no"
};

#endif // MENU_H
