#ifndef ROOM_H
#define ROOM_H
#define maximum_room 90
enum Variety{emptyy,infected,full};


class Room
{
    public:
        /** Default constructor */
        Room();
        bool occupied(int room_no);
        static Variety rooms[maximum_room+10];

        ~Room()
        {

        }

    protected:

    private:
};

#endif // ROOM_H
