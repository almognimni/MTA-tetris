/**
 * @file General.h
 * @brief General utility functions and system dependencies
 * 
 * This file contains general utility functions for console manipulation,
 * screen clearing, and system-specific operations. These functions provide
 * a platform-specific interface for console-based graphics and input.
 */

#ifndef __GENERAL_H
#define __GENERAL_H

#include <windows.h> // for gotoxy and colors
#include <process.h> // for system
#include <cstdlib> // for rand
#include <ctime> // for rand seed
#include <iostream>


/**
 * @brief Positions the console cursor at specified coordinates
 * @param x X coordinate (column)
 * @param y Y coordinate (row)
 */
void gotoxy(int x, int y);

/**
 * @brief Clears the console screen
 */
void clrscr();

/**
 * @brief Attempts to maximize the console window (currently not working)
 */
void maximizeConsole();

#endif // __GENERAL_H