#include "conio.h"
#include "stdio.h"

struct termios orig_termios;
void resetTerminalMode()
{
    tcsetattr(0, TCSANOW, &orig_termios);
}

void setTerminalCONIOMode()
{
    struct termios new_termios;

    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    atexit(resetTerminalMode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int getch()
{
    int r;
    unsigned char c;
    unsigned char c2;
    unsigned char c3;
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r;
    } else {
        if (c == 27) {
            if (!kbhit()) {
                return c;
            } else {
                if ((r = read(0, &c2, sizeof(c2))) < 0) {
                    return r;
                } else {
                    if (c2 == 91) {
                        if ((r = read(0, &c3, sizeof(c3))) < 0) {
                            return r;
                        } else {
                            return c3;
                        }
                    }
                }
            }
        }

        return c;
    }
}

bool getAsyncKeyState(int some_char)
{
    while (!kbhit()) {
        return false;
    }

    return getch() == some_char;
}