#ifndef __GENERAL_H
#define __GENERAL_H

#include <windows.h> // for gotoxy and colors
#include <process.h> // for system
#include <cstdlib> // for rand
#include <ctime> // for rand seed
#include <iostream>

void gotoxy(int, int); // Function to set the cursor position in the console

void clrscr();// Function to clear the console screen

void maximizeConsole();// Function to maximize the console window to the screen size


#endif 