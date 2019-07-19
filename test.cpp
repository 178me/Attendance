#include <iostream>
#include <fstream>

using namespace std;
int main(){
    int num(11);
    ofstream out("out.txt",ios::out | ios::binary);
    out.open("out.txt",ios::out);
    if(!out){
        cout << "文件打开失败！" << endl;
        exit(0);
    }
  /*  for(int i = 0;i < 6;++i){
        num[i] = i;
        out << num[i];
    }*/
    out << "e";
    out << num;
    out.close();
    num = 122;
    ifstream in;
    in.open("out.txt",ios::in);
  /*  for(int i = 0;i < 6;++i){
        in >> num[i];
    }*/
    
    in >> num;
    in.close();
    cout << "need See num :";
/*    int index(0);
    cin >> index;*/
    cout << "num is :" << num << endl;
    return 0;
}
