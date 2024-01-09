#include <iostream>
#include "orders.h"
using namespace std;
class controller {
private:
    Orders n;
public:
    controller(){}
    void execute() {
        int runner = 1;
        while (runner) {
            menu();
            int var = 0;
            while (var < 1 || var > 7) {
                cout << "������� �������: ";
                cin >> var;
            }

            if (var == 1) {
                n.append_order();
                cout<<"����� ������� ���������!"<<endl;
            }
            if (var == 2) {
                cout<<"�������� ����� ������, ������� �� ������ ��������"<<endl;
                int nom;
                while(nom < 1 || nom > n.getNum() + 1)
                {
                    n.print();
                    cout << "[" << n.getNum() + 1 << "] " << "��������� �����." << endl;
                    cin >> nom;
                }
                if ((n.getNum() + 1) != nom)
                {
                    n.change_order(nom);
                }
                else{continue;}
                
            }
            if (var == 3) {
                n.print();
                cout<<"�������� ����� ������, ������� �� ������ ��������"<<endl;
                int num; cin >> num;
                n.pop_order(num);
            }
            if (var == 4) {
                n.print();
            }
            if (var == 5) {
               n.append_orders_to_file();
               cout << "������ ������� ��������� � ����!" << endl;
            }
            if (var == 6) {
                n.load_orders();
                cout<<endl<<"������ ���������"<<endl;
            }
            if (var == 7) {
                runner = 0;
            }

        }
    }

    void menu() {
        cout << "�������: " << endl;
        cout << "[1] �������� �����" << endl;
        cout << "[2] �������� �����" << endl;
        cout << "[3] �������� �����" << endl;
        cout << "[4] �������� ��� ������" << endl;
        cout << "[5] ��������� ������ � ����" << endl;
        cout << "[6] ��������� ������ �� ����" << endl;
        cout << "[7] ����� �� ���������" << endl;
    }
};