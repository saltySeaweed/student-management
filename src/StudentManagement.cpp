#include <C:\Users\Dell\Documents\Github\student-management\src\Student.cpp>
#include <list>
#include <fstream>
#include <C:\Users\Dell\Documents\Github\student-management\ThirdParty\rapidjson\include\rapidjson\document.h>
#include <bits/stdc++.h>
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
    Document doc;
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
            json = NULL;
            json = subStr.c_str();
            doc.Parse(json);
            // Dat gia tri cho bien Student
            Student sv = NULL;
            sv.id = doc['id'].GetString();
            sv.name = doc['name'].GetString();
            sv.old = doc['old'].GetString();
            sv.mssv = doc['mssv'].GetString();
            cout << subStr << "\n";
            currIndex += 1;  
            startIndex = endIndex + 1; 
            }
            i++;
        }
        // cout << split(rawData, ";");
        // json = rawData.c_str();
    }
    ifs.close();
    static int index = datas.size();
    return datas;
}

public: void setData(){

}


};

