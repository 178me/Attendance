//
// Created by yzl178me on 19-7-15.
//

#ifndef ATTENDANCE_FIRST_H
#define ATTENDANCE_FIRST_H

#include <iostream>
#include <fstream>  //使用文件操作
#include <iomanip>  //设置字符宽度/格式
#include <string>   //字符串
#include <ctime>    //时间日期
#include <cctype>   //类型函数
using namespace std;
#define N 6     //任务数
class First {
private:
    string _name;       //用户姓名
    //任务名称
    string Task[N]{
        "C++","Linux","motion","English","Qt5","网络安全原理"
    };
    //记录每个任务的打卡次数
    int TaskCount[N]{
        0,0,0,0,0,0
    };
    //存储时间，分别是年月日
    int _date[3]{0};
public:
    First(string name);
    //读取数据
    ~First();
    void MainMenu();
    /* 主菜单
     * 显示菜单功能
     * 实现功能的方法
     * */
    void MenuFunction();
    /* 实现菜单功能
     * 接受用户的字符判断
     * 1为进入签到，q为退出程序
     * 其他则清屏
     * */
    void Check_inPage();
    /* 签到功能
     * 显示可签到的任务名称及编号
     * 还有返回主菜单和查看记录
     * 实现功能的人口
     * */
    void Cls();
    /* 清屏
     * 提示并暂停
     * 接受用户任意输入之后调用系统命令clear
     * */
    void CheckFunction();
    /* 处理签到功能的方法
     * 接受用户输入的字符
     * 判断进入各个选择
     * 最后写入信息
     * */
    void ShowTaskCount();
    /* 查看记录功能
     * 按照格式输出TaskCount数组
     * */
    void SaveInfo(char);
    /* 写入文件和读取文件信息
     * 按照参数来区分读写，1写2读
     * 按照格式写入任务名称数组和打卡记录数组
     * 按照格式读取打卡记录
     * */
    void isEndl(char&);
    /* 解决输入读取换行符的bug*/
    bool isTime();
    /* 判断时间
     * 使用当前日期与变量date比较
     * 相同提示，否则更新时间
     * */
    void Getdate();
    /* 更新时间
     * 将本地时间的年月日赋值给date数组
     * */
    void Setdate();
    /* 设置时间
     * 手动设置：用户输入年月日，然后赋值给date数组
     * 自动设置：更新时间
     * */
    void Savetime(string);
    /* 保存时间记录
     * 记录打卡的时间
     * */
};

#endif //ATTENDANCE_FIRST_H
