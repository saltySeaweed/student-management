#include <C:\Users\Dell\Documents\Github\student-management\src\Student.cpp>
#include <list>
#include <fstream>
#include <C:\Users\Dell\Documents\Github\student-management\ThirdParty\rapidjson\include\rapidjson\document.h>

using namespace std;
using namespace rapidjson;

#include <iostream>

class StudentManagement
{
public: void addStudent(list<Student> &listStudent){
    Student sv;
    int index1 = 1;
    sv.id = index1;
    cout << "\n Nhap ten: "; cin >> sv.name;
    cout << " Nhap tuoi: "; cin >> sv.old;
    cout << " Nhap msv: "; cin >> sv.mssv;
    listStudent.push_back(sv);
    cout << "\n Them moi sinh vien thanh cong!";
}
public: void searchStudent(string name){
    
}
public: void deleteStudent(string id){
    
}
public: list<Student> readData(string path){
    ifstream ifs("C:\\Users\\Dell\\Documents\\Github\\student-management\\data\\du_lieu.txt");
    list<Student> datas;
    Document d;
    string s;
    const char* json;
    if(!ifs){
        cerr << "Error: file not opened." << endl;
        return datas;
    }
    while(ifs  >> s){
         
        json = s.c_str();
    }
    ifs.close();
    static int index = datas.size();
    return datas;
}


};

