#include <C:\Users\Vu Le\Documents\Github\student-management\src\Student.cpp>
#include <list>
#include <fstream>
#include <C:\Users\Vu Le\Documents\Github\student-management\ThirdParty\rapidjson\include\rapidjson\document.h>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;
using namespace rapidjson;

#include <iostream>

class StudentManagement
{
public: void addStudent(list<Student> &listStudent){
    Student sv;
    cout << "\n Nhap ten: "; cin >> sv.name;
    cout << " Nhap tuoi: "; cin >> sv.old;
    cout << " Nhap msv: "; cin >> sv.mssv;
    listStudent.push_back(sv);
    cout << "\n Them moi sinh vien thanh cong!";
}
public: void searchStudent(list<Student> datas ,string name){
    list<Student> listFound;
    char tenSV[30];
    for(auto data : datas) {
        if(data.name == name){
            listFound.push_back(data);
        }
    }
    showStudent(listFound);
    
}

void showStudent(list<Student> listFound) {
    printLine(100);
    cout <<"\n\nSTT\tHo va ten\tTuoi\t\tMssv";
    int i = 0;
    for(Student student : listFound) {
        // in sinh vien thu i ra man hinh
        printf("\n %d", i ++);
        cout << "\t" << student.name;
        printf("\t\t%d", student.old);
        printf("\t\t%d", student.mssv);
    }
    printLine(100);
}
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}
public: int deleteStudent(list<Student> &listStudent, int mssv){
    auto itr = listStudent.begin(); 
    int found = 0;
    int index = 0, local = 0;
    for(Student data : listStudent) {
        if(data.mssv == mssv){
            found = 1;
            local = index;
        }
        index ++;

    }
    if(found == 1){
    if(local ==0) {
        printLine(40);
        listStudent.erase(itr);
        cout << "\n Da xoa SV co mssv = " << mssv;
        printLine(40);
    } else {
        for(int i =1; i <= local; i++){
                    itr ++;
        }
        printLine(40);
        listStudent.erase(itr);
        cout << "\n Da xoa SV co mssv = " << mssv;
        printLine(40);
    }
    }
    if(found == 0) {
        printf("\n Sinh vien co mssv = %d khong ton tai.", mssv);
        return 0;
    }
    return found;
}
public: list<Student> readData(string path){
    ifstream ifs(path);
    list<Student> datas;
    string rawData;
    const char* json;
    if(!ifs){
        cerr << "Error: file not opened." << endl;
        return datas;
    }
    while(ifs  >> rawData){
        list<string> data;
        char seperator = ';';
        data = split(rawData, seperator);
        for (string s : data){
            datas.push_back(setData(s));
        }
    }
    ifs.close();
    static int index = datas.size();
    return datas;
}
public: list<string> split(string rawData, char seperator){
    list<string> datas;
    int currIndex = 0, i = 0;  
    int startIndex = 0, endIndex = 0;  
    while (i <= rawData.size())  
            {  
                if(rawData[i] == seperator || i == rawData.size()){
                    endIndex = i;  
                    string subStr = "";  
                    subStr.append(rawData, startIndex, endIndex - startIndex);  
                    currIndex += 1;  
                    startIndex = endIndex + 1; 
                    datas.push_back(subStr);
                }
                i++;
            }
    return datas;        
}
// Set data with datatypes string;
public: Student setData(string data){
    char seperator1 = ',';
    list<string> datas = split(data, seperator1);
    Student student;
    int i = 0;
    for( auto data : datas){
        switch (i)
        {
        case 0:
            student.name = data;
            break;
        case 1:
            student.old = stoi(data);
            break;
        case 2:
            student.mssv = stoi(data);
            break;        
        
        default:
            break;
        }
        i++;
    }
    // cout << " kiem tra ten: " << student.name << "\n";
    // cout << "  kiem tra old: " << student.old << "\n";
    // cout << "kiem tra mssv: " << student.mssv << "\n";

    return student;
}
// Set data with datatypes Json;
public: Student setDataJson(string data){
    // string s11 = "{\"project\":\"stdio_demo\",\"id\":12}";
    const char* json = data.c_str();
    cout << "check object json: " << json << "\n";
    cout << "typeid(json).name(): " << typeid(json).name() << endl;
    Document document;
    document.Parse(json);
    int  s2, s3;
    string  s1;
    // s  = document["id"].GetInt();
    s1 = document["name"].GetString();
    s2 = document["old"].GetInt();
    s3 = document["mssv"].GetInt();
    Student student;
    // student.id = s;
    student.name = s1;
    student.old = s2;
    student.mssv = s3;
    return student;
}


};

