#ifndef FONT_H
#define FONT_H

#include <iostream>
 #include <Windows.h>
 #include<conio.h>
 #include<stdlib.h>
 #include <conio.h>

class Font
{
    public:
        Font();
        virtual ~Font();
        static void fontsize(int n,int m);
        static void Waitkey();
        static void welcome();
        static void PlaceCursor(int n,int m);

    protected:

    private:
};

#endif // FONT_H
