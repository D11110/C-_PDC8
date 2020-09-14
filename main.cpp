#include <curses.h>

int main()
{

    int limiteEnX, limiteEnY;
    int cont = 0;
    initscr();
    getmaxyx(stdscr, limiteEnY, limiteEnX);

    if (!has_colors())
    {
        endwin();
        return 1;
    }

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    WINDOW *mainWindow = newwin(limiteEnY, limiteEnX, 0, 0);

    int calcDeX = (limiteEnX / 4) - 2;
    int calcDeY = limiteEnY - 2;
    
    int cuadrado2 = limiteEnX / 4 + 1;
    int cuadrado3 = (2 * (limiteEnX / 4) + 1);
    int cuadrado4 = (3 * (limiteEnX / 4) + 1);

    intrflush(mainWindow, FALSE);
    keypad(mainWindow, TRUE);

    refresh();
    cbreak();
    noecho();
    nonl();

    wbkgd(mainWindow, COLOR_PAIR(1));

    WINDOW *derWind1 = derwin(mainWindow, calcDeY, calcDeX, 1, 1);
    wbkgd(derWind1, COLOR_PAIR(1));

    WINDOW *derWind2 = derwin(mainWindow, calcDeY, calcDeX, 1, cuadrado2);
    wbkgd(derWind2, COLOR_PAIR(1));

    WINDOW *derWind3 = derwin(mainWindow, calcDeY, calcDeX, 1, cuadrado3);
    wbkgd(derWind3, COLOR_PAIR(1));

    WINDOW *derWind4 = derwin(mainWindow, calcDeY, calcDeX, 1, cuadrado4);
    wbkgd(derWind4, COLOR_PAIR(1));

    touchwin(mainWindow);
    wrefresh(mainWindow);

    bool vive = true;
    while (vive)
    {
        if (getch() != 27)
        {

            if (cont == 0)
            {
                wclear(derWind4);
                box(derWind1, ACS_VLINE, ACS_HLINE);


                touchwin(derWind1);
                wrefresh(derWind1);

                touchwin(derWind4);
                wrefresh(derWind4);
                cont++;
            }
            else if (cont == 1)
            {
                wclear(derWind1);
                box(derWind2, ACS_VLINE, ACS_HLINE);


                touchwin(derWind1);
                wrefresh(derWind1);

                touchwin(derWind2);
                wrefresh(derWind2);

                cont++;
            }
            else if (cont == 2)
            {
                wclear(derWind2);
                box(derWind3, ACS_VLINE, ACS_HLINE);


                touchwin(derWind2);
                wrefresh(derWind2);

                touchwin(derWind3);
                wrefresh(derWind3);

                wclear(derWind1);
                touchwin(derWind1);
                wrefresh(derWind1);
                cont++;
            }
            else if (cont == 3)
            {
                wclear(derWind3);
                box(derWind4, ACS_VLINE, ACS_HLINE);


                touchwin(derWind3);
                wrefresh(derWind3);

                touchwin(derWind4);
                wrefresh(derWind4);
                wclear(derWind1);
                touchwin(derWind1);
                wrefresh(derWind1);
                cont = 0;
            }
            else
            {
                break;
            }
        }
        else
        {
            vive = false;
        }
    }
    endwin();
    return 0;
}