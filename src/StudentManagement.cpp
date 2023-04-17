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
        int currIndex = 0, i = 0;  
        int startIndex = 0, endIndex = 0;  
        char seperator = ';';
        while (i <= rawData.size())  
        {  
            if(rawData[i] == seperator || i == rawData.size()){
            endIndex = i;  
            string subStr = "";  
            subStr.append(rawData, startIndex, endIndex - startIndex);  
            currIndex += 1;  
            startIndex = endIndex + 1; 
            data.push_back(subStr);
            }
            i++;
        }
        for (string s : data){
            cout << "Check data member: " << s << "\n";
            cout << "typeid(s).name(): " << typeid(s).name() << endl;
            datas.push_back(setData(s));
        }
    }
    ifs.close();
    static int index = datas.size();
    return datas;
}

public: Student setData(string data){
    // string s11 = "{\"project\":\"stdio_demo\",\"id\":12}";
    const char* json = data.c_str();
    cout << "check object json: " << json << "\n";
    cout << "typeid(json).name(): " << typeid(json).name() << endl;
    Document document;
    document.Parse(json);
    int s, s2, s3;
    string s1;
    s  = document["id"].GetInt();
    s1 = document['name'].GetString();
    s2 = document['old'].GetInt();
    s3 = document['mssv'].GetInt();
    Student student;
    student.id = s;
    student.name = s1;
    student.old = s2;
    student.mssv = s3;
    return student;
}


};

