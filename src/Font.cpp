#include "Font.h"
#include<windows.h>
#define _WIN32_WINNT 0x0601
//the function declaration begins
#ifdef __cplusplus
extern "C" {
#endif
BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX
lpConsoleCurrentFontEx);
#ifdef __cplusplus
}
#endif

Font::Font()
{
    //ctor
}

Font::~Font()
{
    //dtor
}



void Font:: fontsize(int n,int m)
{
    typedef struct _CONSOLE_FONT_INFOEX
{
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
}CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;



int
    newWidth=n,
    newHeight=m;
    CONSOLE_FONT_INFOEX fontStructure={0};
    fontStructure.cbSize=sizeof(fontStructure);
    fontStructure.dwFontSize.X=newWidth;
    fontStructure.dwFontSize.Y=newHeight;
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetCurrentConsoleFontEx(hConsole, true, &fontStructure);
    system("pause");
}
 void Font::Waitkey()
{

   Sleep(1000);

    system("CLS");

}

 void Font:: welcome()
{ HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    int len = 0,x, y=245; // 240 = white background, black foreground

std::    string text = "Welcome To Hostel Management System";
    len = text.length();
    std::cout  << std::endl <<std:: endl <<std:: endl<<std:: endl<<std:: endl<<std:: endl<<std:: endl << "\t";// start 3 down, 2 tabs, right
    for ( x=0;x<len;x++)
    {
        SetConsoleTextAttribute(console, y); // set color for the next print
std::        cout << text[x];
        y++; // add 1 to y, for a new color
        if(y==247 ||y==254 ||y==240)
{y=y+1;}
        if ( y >254) // There are 255 colors. 255 being white on white. Nothing to see. Bypass it
            y=245; // if y > 254, start colors back at white background, black chars
        Sleep(250); // Pause between letters
    }

    SetConsoleTextAttribute(console, 15); // set color to black background, white chars
    Waitkey(); // Program over, wait for a keypress to close program
}

void Font::PlaceCursor(const int x, const int y) {



    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



    COORD PlaceCursorHere;

    PlaceCursorHere.X = x;

    PlaceCursorHere.Y = y;



    SetConsoleCursorPosition(hConsole, PlaceCursorHere);

    return;

}

