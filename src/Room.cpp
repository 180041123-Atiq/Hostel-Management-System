#include "Room.h"

Room::Room()
{
    //ctor
}

bool Room::occupied(int room_no)
{
   int floor=room_no/100;
    room_no=room_no%100;
    room_no=(room_no-1)+(30*(floor-1));

    bool flag=true;

    if(rooms[room_no]==emptyy)flag=false;

    switch(floor)
    {
    case 1 :
        for(int i=room_no;i<room_no+3;i++)
        {
           if(i>=0&&i<30)
           {
               if(rooms[i]==infected)
               {
                   flag=true;
                   break;
               }
           }
        }
        for(int i=room_no;i>room_no-3;i--)
        {
            if(i>=0&&i<30)
            {
                if(rooms[i]==infected)
                {
                    flag=true;
                    break;
                }
            }
        }
        break;
    case 2 :
        for(int i=room_no;i<room_no+3;i++)
        {
           if(i>=30&&i<60)
           {
               if(rooms[i]==infected)
               {
                   flag=true;
                   break;
               }
           }
        }
        for(int i=room_no;i>room_no-3;i--)
        {
            if(i>=30&&i<60)
            {
                if(rooms[i]==infected)
                {
                    flag=true;
                    break;
                }
            }
        }
        break;
    case 3 :
        for(int i=room_no;i<room_no+3;i++)
        {
           if(i>=60&&i<90)
           {
               if(rooms[i]==infected)
               {
                   flag=true;
                   break;
               }
           }
        }
        for(int i=room_no;i>room_no-3;i--)
        {
            if(i>=60&&i<90)
            {
                if(rooms[i]==infected)
                {
                    flag=true;
                    break;
                }
            }
        }
        break;
    }
    return flag;
}

