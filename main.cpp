#include <C:\Users\Dell\Documents\Github\student-management\src\sinhvien\StudentManagement.cpp>
#include <C:\Users\Dell\Documents\Github\student-management\src\sinhvien\Student.cpp>
#include <list>
#include <conio.h>
using namespace std;
#include <iostream>

    void pressAnyKey() {
        cout << "\n\nBam phim bat ky de tiep tuc...";
        getch();
        system("cls");
    }

int main(){
    StudentManagement studentManagement;
    std::list<Student> datas = studentManagement.readData("C:\\Users\\Dell\\Documents\\Github\\student-management\\data\\du_lieu.txt");
    while(true) {
        int key;
        cout << "CHUONG TRINH QUAN LY SINH VIEN C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them sinh vien.                               **\n";
        cout << "**  2. Xoa sinh vien boi ID.                         **\n";
        cout << "**  3. Tim kiem sinh vien theo ten.                  **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1. Them sinh vien.";
                studentManagement.addStudent(datas);
                pressAnyKey();
                break;
            case 2:
                pressAnyKey();
                break;
            case 3:
                pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}