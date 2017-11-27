#ifndef CONIO_H
#define CONIO_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

int getAsyncKeyState();
void setTerminalCONIOMode();

#endif