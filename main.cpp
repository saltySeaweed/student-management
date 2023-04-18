#include <C:\Users\Vu Le\Documents\Github\student-management\src\StudentManagement.cpp>
#include <C:\Users\Vu Le\Documents\Github\student-management\src\Student.cpp>
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
    list<Student> datas = studentManagement.readData("C:\\Users\\Vu Le\\Documents\\Github\\student-management\\data\\du_lieu_don_gian.txt");
    while(true) {
        int key;
        cout << "CHUONG TRINH QUAN LY SINH VIEN C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them sinh vien.                               **\n";
        cout << "**  2. Xoa sinh vien boi MSSV.                       **\n";
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
            if(datas.size() > 0) {
                int mssv;
                cout << "\n3. Xoa sinh vien.";
                cout << "\n Nhap mssv: "; cin >> mssv;
                if (studentManagement.deleteStudent(datas, mssv) == 1) {
                    printf("\nSinh vien co mssv = %d da bi xoa.", mssv);
                }
            } else {
                cout << "\nSanh sach sinh vien trong!";
            }
                pressAnyKey();
                break;
            case 3:
            if(datas.size() > 0) {
                cout << "\n3. Tim kiem sinh vien theo ten.";
                char strTen[30];
                cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                studentManagement.searchStudent(datas, strTen);
            } else {
                cout << "\nSanh sach sinh vien trong!";
            }
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