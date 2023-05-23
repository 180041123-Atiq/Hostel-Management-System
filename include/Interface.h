#ifndef INTERFACE_H
#define INTERFACE_H
#include "Room.h"

class Interface
{
    public:
        /** Default constructor */
        Interface();

        void main_func();
        void load_stat_room();
        void save_stat_room();

        ~Interface()
        {
            save_stat_room();
            delete r_obj;
        }

    protected:
        Room* r_obj;
    private:
};

#endif // INTERFACE_H
