// required header files
#include <iostream>
#include <string>
#include <fstream>
#include <limits> // for GotoLine function
#include <conio.h>
#include <graphics.h>
#include <windows.h>

// defined constants
#define TOTAL_ELEMENTS 118

// required namespaces
using namespace std;

// function to goto specific line in the file
fstream &GotoLine(fstream &file, unsigned int num)
{
    file.seekg(ios::beg);
    for (int i = 0; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
    return file;
}

void drawMPTL(int MPTLC_SX, int MPTLC_SY, int MPTLC_EB)
{
    string title = "PERIODIC TABLE";
    int modernPeriodicTableLogoCOORD_U[] = {
        MPTLC_SX, MPTLC_SY,
        MPTLC_SX, MPTLC_SY + (MPTLC_EB * 7),
        MPTLC_SX + (MPTLC_EB * 2), MPTLC_SY + (MPTLC_EB * 7),
        MPTLC_SX + (MPTLC_EB * 2), MPTLC_SY + (MPTLC_EB * 5),
        MPTLC_SX + (MPTLC_EB * 3), MPTLC_SY + (MPTLC_EB * 5),
        MPTLC_SX + (MPTLC_EB * 3), MPTLC_SY + (MPTLC_EB * 7),
        MPTLC_SX + (MPTLC_EB * 18), MPTLC_SY + (MPTLC_EB * 7),
        MPTLC_SX + (MPTLC_EB * 18), MPTLC_SY,
        MPTLC_SX + (MPTLC_EB * 17), MPTLC_SY,
        MPTLC_SX + (MPTLC_EB * 17), MPTLC_SY + (MPTLC_EB * 1),
        MPTLC_SX + (MPTLC_EB * 12), MPTLC_SY + (MPTLC_EB * 1),
        MPTLC_SX + (MPTLC_EB * 12), MPTLC_SY + (MPTLC_EB * 3),
        MPTLC_SX + (MPTLC_EB * 2), MPTLC_SY + (MPTLC_EB * 3),
        MPTLC_SX + (MPTLC_EB * 2), MPTLC_SY + (MPTLC_EB * 1),
        MPTLC_SX + (MPTLC_EB * 1), MPTLC_SY + (MPTLC_EB * 1),
        MPTLC_SX + (MPTLC_EB * 1), MPTLC_SY,
        MPTLC_SX, MPTLC_SY};

    int modernPeriodicTableLogoCOORD_L[] = {
        MPTLC_SX + (MPTLC_EB * 3), MPTLC_SY + (MPTLC_EB * 8),
        MPTLC_SX + (MPTLC_EB * 18), MPTLC_SY + (MPTLC_EB * 8),
        MPTLC_SX + (MPTLC_EB * 18), MPTLC_SY + (MPTLC_EB * 10),
        MPTLC_SX + (MPTLC_EB * 3), MPTLC_SY + (MPTLC_EB * 10),
        MPTLC_SX + (MPTLC_EB * 3), MPTLC_SY + (MPTLC_EB * 8)};

    int sizeU = (sizeof(modernPeriodicTableLogoCOORD_U) / sizeof(int)) / 2;
    int sizeL = (sizeof(modernPeriodicTableLogoCOORD_L) / sizeof(int)) / 2;
    int colorCode = 2;

    while (true)
    {
        if (GetAsyncKeyState(13))
        {
            break;
        }
        else
        {
            // to reset color code
            if (colorCode >= 15)
            {
                colorCode = 2;
            }
            else
            {
                colorCode++;
            }

            // title border
            setcolor(colorCode);
            setlinestyle(SOLID_LINE, 0, 3);
            rectangle(50, 50, 960, 210);

            // title credits
            settextstyle(8, 0, 2);
            outtextxy(650, 165, "A PROJECT BY SAAD MANSOOR");

            // to print periodic table logo
            settextstyle(8, 0, 8);
            setlinestyle(SOLID_LINE, 0, 1);
            setfillstyle(SOLID_FILL, colorCode);
            fillpoly(sizeU, modernPeriodicTableLogoCOORD_U);
            fillpoly(sizeL, modernPeriodicTableLogoCOORD_L);

            // to print PERIODIC TABLE
            for (int text_X = 275, i = 0; i < 14; i++)
            {
                outtextxy(text_X, 70, &title[i]);
                text_X += 47;
            }

            // title and credit divider
            setlinestyle(SOLID_LINE, 0, 2);
            line(275, 152, 930, 152);
            setlinestyle(DOTTED_LINE, 0, 1);
            line(275, 155, 930, 155);

            // color animation delay
            delay(1000);
        }
    }
}

void bgLineDrawer(int bgColor = 0, int fgColor = 0, int lineNumber = 0)
{
    lineNumber = (lineNumber - 1) * 20;
    int points[] = {0, 48 + lineNumber, 750, 48 + lineNumber, 750, 70 + lineNumber, 0, 70 + lineNumber};
    setcolor(bgColor);
    setfillstyle(SOLID_FILL, bgColor);
    fillpoly((sizeof(points) / sizeof(int)) / 2, points);
    setbkcolor(bgColor);
    setcolor(fgColor);
}
