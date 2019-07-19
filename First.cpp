//
// Created by yzl178me on 19-7-15.
//

#include "First.h"

void First::MainMenu() {
    cout << "Welcome to Yang Zelin's home!" << endl;    //欢迎来到我的小窝
    cout << "Enter 1 Into the Check-in page!" << endl;  //输入1签到
    cout << "Enter q exit!" << endl;
    /* 输出菜单信息
     * 签到功能和退出*/
    MenuFunction();
    //进入实现方法
}

void First::MenuFunction() {
    char Choice(0);
    do{
        cin.sync();
        cin.get(Choice);
        cin.sync();
    }
    while(Choice == '\n');    //用户选择
    /* 接受用户输入
     * 这里我觉得有必要提一下，掉了这个坑
     * cin.sync()是一个清除缓存区的方法
     * 如果不清除缓存区，将会造成重复读取的后果*/
    if(Choice == '1'){
        Check_inPage();
    }
    else if(Choice == 'q'){
        exit(0);    
    }
    else{
        cout << "Please re-enter" << endl;  //请重新输入
        Cls();
    }
    /* 菜单功能的入口
     * 输入正确则进入功能，否则重新输入
     * */
}

void First::Check_inPage() {
    cout << this->_name + ",欢迎进入签到页面" << endl;
    for(int i = 0;i < N;++i){
        cout << i+1 << "." + Task[i] << endl;
    }
    cout << "0.返回主菜单" << endl;  //
    cout << "S.查看记录" << endl;
    //显示签到信息
    CheckFunction();
    //进入实现方法
}

void First::Cls() {
    char temp(0);
    cout << "Please press Enter to continue." << endl;  //请按回车键继续 cin.sync();    //清除缓存区
    cin.sync();
    cin >> temp;  //暂停
    cin.sync();
    system("clear");    //调用Linux的清屏功能
}

First::~First() {
}

void First::CheckFunction() {
    char Choice(1);
    for(int i = 0;Choice != '0';++i){
       cout << "Please select daily attendance items." << endl;
       cin.sync();
       cin.get(Choice);
       cin.sync();
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
       /* 判断用户输入的字符
        * 1-6对应着任务的打卡记录
        * 0返回主菜单
        * s查看打卡记录*/
       SaveInfo('1');
       //判断之后保存数据
    }
}

First::First(string name):_name(name){
    SaveInfo('2');
    //读取打卡记录信息
}

void First::ShowTaskCount() {
    cout << "Daily attendance record:" << endl;
    for(int i = 0;i < N;++i){
        cout << Task[i] + ":" << TaskCount[i] << endl;
    }
    //显示打卡记录
}

void First::SaveInfo(char Choice = '1') {
    if(Choice == '1') {
        ofstream TaskInfo;
        TaskInfo.open("Info", ios::out);
        if (!TaskInfo) {
            cout << "open file lose!" << endl;
            exit(0);
        }
        TaskInfo << left << "Task:" << setw(6) << ' ';
        for (int i = 0; i < N; ++i) {
            TaskInfo << left << Task[i] << setw(6) << ' ';
        }
        TaskInfo << endl;
        TaskInfo << left << "TaskCount:" << setw(1) << ' ';
        for (int i = 0; i < N; ++i) {
            TaskInfo << left << TaskCount[i] << setw(6) << ' ';
        }
        TaskInfo << endl;
        TaskInfo.close();
    }
    /* 写入文件
     * 判断文件打开是否成功，还可以用其他方法
     * left是字符对齐左边，setw()是设置间隔，为了调整格式
     * 最后关闭文件
     * */
    if(Choice == '2') {
        ifstream TaskRead;
        TaskRead.open("Info", ios::in);
        if(!TaskRead) exit(0);
/*        TaskRead.seekg(101,ios::beg);
        char sr(0);
        while(sr != '\n'){
            TaskRead.read((char*)&sr,sizeof(char));
            cout << sr << '\t';
            cout << TaskRead.tellg() << '\t';
        }*/
//查看某段位置的字符  测试的时候用，确定数据位置
        TaskRead.seekg(101,ios::beg);
        for (int i = 0; i < N; ++i) {
            cout << TaskRead.tellg() << endl;
            TaskRead >> TaskCount[i];
            TaskRead.seekg(6,ios::cur);
        }
        TaskRead.close();
    }
    /* 读取文件
     * 判断文件是否打开
     * 设置文件指针位置到打卡记录数据的开始
     * 读取一个数据之后再从当前位置往前6个字节
     * 最后关闭文件
     * */
}

