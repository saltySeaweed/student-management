#include <C:\Users\Dell\Documents\Github\student-management\src\sinhvien\Student.cpp>
#include <list>
using namespace std;
#include <iostream>

class StudentManagement
{
public: void addStudent(list<Student> &listStudent){
    cout << "\n Nhap ten: "; fflush(stdin); gets(sv.ten);
    cout << " Nhap gioi tinh: "; gets(sv.gioiTinh);
    cout << " Nhap tuoi: "; cin >> sv.tuoi;
    cout << " Nhap diem Toan: "; cin >> sv.diemToan;
    cout << " Nhap diem Ly: "; cin >> sv.diemLy;
    cout << " Nhap diem Hoa: "; cin >> sv.diemHoa;

}
public: void searchStudent(string name){
    
}
public: void deleteStudent(string id){
    
}
public: list<Student> readData(string path){
    list<Student> datas;
    return datas;
}


};

