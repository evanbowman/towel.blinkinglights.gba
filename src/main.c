////////////////////////////////////////////////////////////////////////////////
//
// The ascii animation gba driver
//
////////////////////////////////////////////////////////////////////////////////


#include "toolbox.h"



void screen_vsync()
{
    VBlankIntrWait();
}



void screen_clear()
{
    for (int x = 0; x < 240; ++x) {
        for (int y = 0; y < 160; ++y) {
            m3_plot(x, y, RGB15(0, 0, 0));
        }
    }
}



void screen_plot_char(int x, int y, char c)
{
    int sx = x * 4 - 3 * 4;
    int sy = y * 6 + 38;

    const u16 white = RGB15(31, 31, 31);

    if (sx >= 240 || x < 0) {
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

    case 't':
        m3_plot(sx, sy + 0, white);
        m3_plot(sx + 1, sy + 0, white);
        m3_plot(sx + 2, sy + 0, white);

        m3_plot(sx + 1, sy + 1, white);
        m3_plot(sx + 1, sy + 2, white);
        m3_plot(sx + 1, sy + 3, white);
        m3_plot(sx + 1, sy + 4, white);
        break;

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

    }
}



void screen_plot_frame(const char* frame)
{
    int y = 0;
    int x = 0;

    while (y < 14) {
        if (*frame == '\0') {
            return;
        }
        if (*frame == '\n') {
            ++frame;
            ++y;
            x = 0;
            continue;
        }

        screen_plot_char(x++, y, *(frame++));
    }
}



int main()
{
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;


    while (1) {
        screen_clear();
        screen_plot_frame(test);
        screen_vsync();
    }

    return 0;
}
