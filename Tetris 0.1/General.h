#ifndef __GENERAL_H
#define __GENERAL_H

#include <windows.h> // for gotoxy
#include <process.h> // for system
#include <cstdlib> // for rand
#include <ctime> // for rand seed
#include <iostream>


void gotoxy(int, int);
void clrscr();
void maximizeConsole();

#endif // __GENERAL_H