//
// Created by yzl178me on 19-7-15.
//

#include "First.h"

void First::MainMenu() {
    cout << "Welcome to Yang Zelin's home!" << endl;    //欢迎来到我的小窝
    cout << "Enter 1 Into the Check-in page!" << endl;  //输入1签到
    MenuFunction();
}

void First::MenuFunction() {
    char Choice(0);
    do{
        cin.sync();
        cin.get(Choice);
    }
    while(Choice == '\n');    //用户选择
    /* 菜单功能的入口
     * 输入正确则进入，否则重新输入
     * */
    if(Choice == '1'){
        Check_inPage();
    }else{
        cout << "Please re-enter" << endl;  //请重新输入
        Cls();
    }
}

void First::Check_inPage() {
    cout << this->_name + ",欢迎进入签到页面" << endl;
    for(int i = 0;i < N;++i){
        cout << i+1 << "." + Task[i] << endl;
    }
    cout << "0.返回主菜单" << endl;  //
    cout << "S.查看记录" << endl;
    CheckFunction();
}

void First::Cls() {
    char temp(0);
    cout << "Please press Enter to continue." << endl;  //请按回车键继续
    cin.sync();    //清除缓存区
    do {
        cin.get(temp);  //暂停
    }while(temp == '\n');
    system("clear");    //调用Linux的清屏功能
}

First::~First() {
    cout << "end" << endl;
}

void First::CheckFunction() {
    char Choice(1);
    for(int i = 0;Choice != '0';++i){
       cout << "Please select daily attendance items." << endl;
       cin.sync();
       cin >> Choice;
       if(Choice == '1'){
           cout << "Successful typing" << endl;
           TaskCount[0]++;
       }
       else if(Choice == '2'){
           cout << "Successful typing" << endl;
           TaskCount[1]++;
       }
       else if(Choice == '3'){
           cout << "Successful typing" << endl;
           TaskCount[2]++;
       }
       else if(Choice == '4'){
           cout << "Successful typing" << endl;
           TaskCount[3]++;
       }
       else if(Choice == '5'){
           cout << "Successful typing" << endl;
           TaskCount[4]++;
       }
       else if(Choice == '6'){
           cout << "Successful typing" << endl;
           TaskCount[5]++;
       }
       else if(Choice == '0'){
           system("clear");
           break;
       }
       else if(Choice == 's' || Choice == 'S'){

           ShowTaskCount();
       }
       else{
           cout << "Card failure！" << endl; //打卡失败
       }
    }
}

First::First(string name):_name(name){
    
}

void First::ShowTaskCount() {
    cout << "Daily attendance record:" << endl;
    for(int i = 0;i < N;++i){
        cout << Task[i] + ":" << TaskCount[i] << endl;
    }
}
