//
// Created by yzl178me on 19-7-15.
//

#include "First.h"

void First::MainMenu() {
    cout << "Welcome to Yang Zelin's home!" << endl;    //欢迎来到我的小窝
    cout << "Enter 1 Into the Check-in page!" << endl;  //输入1签到
    cout << "Enter q exit!" << endl;
    cout << "Enter t Set Time!" << endl;
    /* 输出菜单信息
     * 签到功能
     * 退出
     * 设置时间
     * */
    MenuFunction();
    //进入实现方法
}

void First::MenuFunction() {
    char Choice(0);
    isEndl(Choice);
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
    else if(Choice == 't'){
        Setdate();
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
    isEndl(temp);
    system("clear");    //调用Linux的清屏功能
}

First::~First() {
}

void First::CheckFunction() {
    char Choice(1);
    for(int i = 0;Choice != '0';++i){
       cout << "Please select daily attendance items." << endl;
       isEndl(Choice);
       char temp('1');
       for(int j = 0;j < N+1;j++){
           if(Choice == temp){
               if(!isTime()){
                   cout << "一天只能打一次卡哦" << endl;
                   break;
               }else {
                   cout << "Successful typing" << endl;
                   Savetime(Task[j]);
                   TaskCount[j]++;
                   break;
               }
           }
           temp++;
       }
        temp = '1';
       /* 用循环的方式来判断1-6个选项
        * 每次打卡成功记录打卡信息
        * 循环结束后temp复位
        * */
/*       if(Choice == '1'){
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
       */
       if(Choice == '0'){
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
//    读取打卡记录信息
    Getdate();
//    更新时间
}
void First::ShowTaskCount() {
     cout << left << "Task:" << setw(6) << ' ';
        for (int i = 0; i < N; ++i) {
            cout << left << Task[i] << setw(2) << ' ';
        }
        cout << endl;
        cout << left << "TaskCount:" << setw(1) << ' ';
        for (int i = 0; i < N; ++i) {
            cout << left << TaskCount[i] << setw(6) << ' ';
        }
        cout << endl;
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
        if(!TaskRead){
            cout << "open file error!" << endl;
            SaveInfo('1');
            TaskRead.open("Info", ios::in);
        }
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
//            cout << TaskRead.tellg() << endl;
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
void First::isEndl(char&temp) {
    do {
        cin.sync();
        cin.get(temp);
        cin.sync();
    }while(temp == '\n');
    /* 先清理缓存
     * 然后请求输入
     * 以防意外，在清理一遍
     * 判断字符是否为换行符
     * */
}

bool First::isTime() {
    time_t temp = time(NULL);
    struct tm * date = localtime(&temp);
    bool is = date->tm_year == _date[0]-1900 && date->tm_mon == _date[1]-1 && date->tm_mday == _date[2];
    Getdate();
    return is;
    /* 1.获取时间戳
     * 2.转化为时间结构
     * 3.将本地时间的日期与变量date比较后赋值给is
     * 4.更新时间后返回
     * */
}
void First::Getdate(){
    time_t temp = time(NULL);
    struct tm * date;
    date = localtime(&temp);
    _date[0] = 1900 + date->tm_year;
    _date[1] = 1 + date->tm_mon;
    _date[2] = date->tm_mday;
    /* 1.获取本地时间
     * 2.将本地时间赋值给date
     * */
}

void First::Setdate() {
    int choice(0);
    cout << "1.手动设置" << endl;
    cout << "2.自动设置" << endl;
    do{
        cin.sync();
        cin >> choice;
        cin.sync();
    }while(isdigit(choice));
    //isdigit()判断是否为数字，不是则返回0
    if(choice == 1) {
        int t1(0),t2(0),t3(0);
        do {
            cout << "请输入你要设置的时间" << endl;
            cout << "提示：格式为：年 空格 月 空格 日 回车" << endl;
            cin.sync();
            cin >> t1 >> t2 >> t3;
            cin.sync();
        } while (isdigit(t1) != 0 && isdigit(t2) != 0 && isdigit(t3) != 0);
        _date[0] = t1;
        _date[1] = t2;
        _date[2] = t3;
    }
    /* 手动设置
     * 1.设置三个临时变量接受输入
     * 2.判断用户输入是否为数字
     * 3.通过循环将临时变量的值赋值给date
     * */
    else if(choice == 2){
        Getdate();
    }
    /* 自动设置
     * 更新时间
     * */
    cout << "时间设置成功" << endl;
}

void First::Savetime(string str1) {
    ofstream file;
    file.open("log",ios::app);
    if(!file){
        cout << "open file error!" << endl;
        exit(0);
    }
    time_t t = time(NULL);
    struct tm * tt = localtime(&t);
    char tep[40];
    strftime(tep,40,"%Y-%m-%d %X",tt);
    file << tep << '\t' << str1 + "打卡成功！" << endl;
    file.close();
    /* 用追加的方式打开文件
     * 获取时间
     * strftime（）是自定义格式输出时间
     * 用tep来接收时间
     * 将信息输入到文件中
     * 关闭文件
     * */
}


