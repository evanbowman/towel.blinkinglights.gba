////////////////////////////////////////////////////////////////////////////////
//
// The ascii animation gba driver
//
// Looks for data mounted at symbol __rom_end__.
//
////////////////////////////////////////////////////////////////////////////////


#include "/opt/devkitpro/libgba/include/gba_interrupt.h"

#define EWRAM_DATA	__attribute__((section(".ewram")))
#define M3_SIZE			0x12C00		//!< Mode 3 buffer size
EWRAM_DATA _Alignas(4) u16 mem_back[M3_SIZE / 2];
#include "toolbox.h"



extern char __rom_end__;



void screen_vsync()
{
    VBlankIntrWait();
}



void screen_clear()
{
    m3_fill_black();
}



void screen_plot_char(int x, int y, char c)
{
    int sx = x * 4 - 3 * 4;
    int sy = y * 6 + 38;

    const u16 white = RGB15(31, 31, 31);

    if (sx >= 240 || sx < 0) {
        return;
    }

    switch (c) {
    case ' ':
        break;

    case '.':
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '@':
        m3_plot(sx, sy, white);
        m3_plot(sx + 1, sy, white);
        m3_plot(sx + 2, sy, white);

        m3_plot(sx + 2, sy + 1, white);

        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);

        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx, sy + 3, white);

        m3_plot(sx, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '-':
        m3_plot(sx, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        break;

    case '*':
    case '+':
        m3_plot(sx, sy + 2, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx + 2, sy + 2, white);
        break;


    case '=':
        m3_plot(sx, sy + 1, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);

        m3_plot(sx, sy + 3, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        break;

    case '|':
        m3_plot(sx + 1, sy, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        break;

    case '#':
    case '8':
        m3_plot(sx, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '_':
        m3_plot(sx, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '<':
        m3_plot(sx + 2, sy, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '>':
        m3_plot(sx, sy, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx, sy + 4, white);
        break;

    case '/':
        m3_plot(sx + 2, sy, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx, sy + 4, white);
        break;

    case '\\':
        m3_plot(sx, sy, white);
        m3_plot(sx, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '(':
        m3_plot(sx + 1, sy, white);
        m3_plot(sx, sy + 1, white);
        m3_plot(sx, sy + 2, white);
        m3_plot(sx, sy + 3, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case ')':
        m3_plot(sx, sy, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx, sy + 4, white);
        break;

    case '[':
        m3_plot(sx + 1, sy, white);
        m3_plot(sx, sy, white);
        m3_plot(sx, sy + 1, white);
        m3_plot(sx, sy + 2, white);
        m3_plot(sx, sy + 3, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx, sy + 4, white);
        break;

    case ']':
        m3_plot(sx, sy, white);
        m3_plot(sx + 1, sy, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case 'o':
    case 'O':
    case '0':
        m3_plot(sx, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'a':
    case 'A':
        m3_plot(sx + 1, sy, white);
        m3_plot(sx, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'b':
    case 'B':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case 'c':
    case 'C':
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'd':
    case 'D':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case 'e':
    case 'E':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'f':
    case 'F':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        break;

    case 'g':
    case 'G':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 2, sy + 3, white);
        break;

    case 'H':
    case 'h':
        m3_plot(sx, sy + 0, white);
        m3_plot(sx, sy + 1, white);
        m3_plot(sx, sy + 2, white);
        m3_plot(sx, sy + 3, white);
        m3_plot(sx, sy + 4, white);

        m3_plot(sx + 1, sy + 2, white);

        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'i':
    case 'I':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'j':
    case 'J':
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case 'k':
    case 'K':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'l':
    case 'L':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'm':
    case 'M':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'n':
    case 'N':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'p':
    case 'P':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        break;

    case 'q':
    case 'Q':
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'r':
    case 'R':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 's':
    case 'S':
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case 'T':
    case 't':
        m3_plot(sx, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);

        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case 'u':
    case 'U':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'v':
    case 'V':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case 'w':
    case 'W':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'x':
    case 'X':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case 'y':
    case 'Y':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case 'z':
    case 'Z':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '~':
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        break;

    case '1':
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '2':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '3':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '4':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '!':
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case '5':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '6':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 0, sy + 3, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 0, sy + 4, white);
        m3_plot(sx + 1, sy + 4, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '7':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '9':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 0, sy + 2, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 2, sy + 3, white);
        m3_plot(sx + 2, sy + 4, white);
        break;

    case '\'':
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 1, sy + 1, white);
        break;

    case '?':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 2, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 2, sy + 2, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

    case '"':
        m3_plot(sx + 0, sy + 0, white);
        m3_plot(sx + 0, sy + 1, white);

        m3_plot(sx + 2, sy + 0, white);
        m3_plot(sx + 2, sy + 1, white);
        break;
    }
}



const char* screen_plot_frame(const char* frame)
{
    int y = 0;
    int x = 0;

    while (y < 13) {
        if (*frame == '\0') {
            return frame;
        }
        if (*frame == '\n') {
            ++frame;
            ++y;
            x = 0;
            continue;
        }

        screen_plot_char(x++, y, *(frame++));
    }

    return frame;
}



const char* anim_parse_framecount(const char* anim, int* result)
{
    *result = 0;
    while (*anim != '\n') {
        *result = 10 * (*result) + (*anim - '0');
        ++anim;
    }
    ++anim; // ignore newline after parsed framecount

    return anim;
}



int main()
{
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;

    irqInit();
    irqEnable(IRQ_VBLANK);

    const char* anim = &__rom_end__;


    while (1) {
        int fc;
        anim = anim_parse_framecount(anim, &fc);
        screen_clear();
        anim = screen_plot_frame(anim);


        // NOTE: multipling frame count by four for the original playback rate
        // of about 15 frames per second.

        int sleep_frames = fc * 4 - 1;
        screen_vsync();
        for (int i = 0; i < M3_SIZE / 4; ++i) {
            ((u32*)vid_mem)[i] = ((u32*)mem_back)[i];
        }

        for (int i = 0; i < sleep_frames; ++i) {
            screen_vsync();
        }
    }

    return 0;
}
