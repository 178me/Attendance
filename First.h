//
// Created by yzl178me on 19-7-15.
//

#ifndef ATTENDANCE_FIRST_H
#define ATTENDANCE_FIRST_H

#include <iostream>
#include <string>
using namespace std;
#define N 6
class First {
private:
    string _name;
    string Task[N]{
        "C++","Linux","健身","English","Qt5","网络安全原理"
    };
    int TaskCount[N]{
        0,0,0,0,0,0
    };
    int _day;
public:
    First(string name);
    ~First();
    void MainMenu();
    void MenuFunction();
    void Check_inPage();
    void Cls();
    void CheckFunction();
    void ShowTaskCount();
};

#endif //ATTENDANCE_FIRST_H
