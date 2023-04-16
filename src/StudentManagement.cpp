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
    if(!ifs){
        cerr << "Error: file not opened." << endl;
        return datas;
    }
    Document d;
    const char* json = "{\"project\":\"stdio_demo\",\"id\":12}";
    //Đọc và in lần lượt các ký tự trong file
    // while(ifs  >> json){ 
        d.Parse(json);
    // }
    //Đóng file
    ifs.close();
    static int index = datas.size();
    return datas;
}


};

