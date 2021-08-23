//Programmers:			Jay Anino   
//Student ID:			Jay's ID: 270115050
//School:				Yoobee College
//Due Date:				None
//Project Name:    	    CS105 LAB 4
//Project Description:  This program is a game that lets the user create an Alien and perform breeding among aliens.
//                      The aim for this Lab is to learn how to use operator overloading.

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
using namespace std;
#include "Graphics.h";
#include "Alien.h";


int main()
{
    vector<Alien> alien;
    Alien a;
    Graphics g;
    int choice = 0, male = 1, female = 2;
    bool isTrue;
    char gender = 'z';

    system("Color 0A");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    alien = a.createDefaultAlien(alien);

    g.playIntro();
    do {
        isTrue = true;
        g.printAlienTitle();
        g.printMainMenu();
        cin >> choice;
        
        switch (choice) {
        case 1:
            alien.push_back(a.createAlien(a));
            break;
        case 2:
            alien = a.selectAlien(alien);
            break;
        case 3:
            a.selectAlien(alien, a);
            break;
        case 4:
            a.showListOfAliens(alien);
            break;
        case 5:
            isTrue = false;
            break;
        default:
            cout << "\n" << string(9, '\t') << "Invalid Input, Please Try Again....\n";
            break;
        }
        system("pause");
        system("cls");
    } while (isTrue);
}