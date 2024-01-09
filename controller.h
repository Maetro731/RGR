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
                cout << "Введите вариант: ";
                cin >> var;
            }

            if (var == 1) {
                n.append_order();
                cout<<"Заказ успешно отправлен!"<<endl;
            }
            if (var == 2) {
                cout<<"Выберите номер заказа, который вы хотите изменить"<<endl;
                int nom;
                while(nom < 1 || nom > n.getNum() + 1)
                {
                    n.print();
                    cout << "[" << n.getNum() + 1 << "] " << "Вернуться назад." << endl;
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
                cout<<"Выберите номер заказа, который вы хотите отменить"<<endl;
                int num; cin >> num;
                n.pop_order(num);
            }
            if (var == 4) {
                n.print();
            }
            if (var == 5) {
               n.append_orders_to_file();
               cout << "Заказы успешно добавлены в базу!" << endl;
            }
            if (var == 6) {
                n.load_orders();
                cout<<endl<<"Заказы загружены"<<endl;
            }
            if (var == 7) {
                runner = 0;
            }

        }
    }

    void menu() {
        cout << "Команды: " << endl;
        cout << "[1] Добавить заказ" << endl;
        cout << "[2] Изменить заказ" << endl;
        cout << "[3] Отменить заказ" << endl;
        cout << "[4] Показать все заказы" << endl;
        cout << "[5] Выгрузить заказы в базу" << endl;
        cout << "[6] Загрузить заказы из базы" << endl;
        cout << "[7] Выход из программы" << endl;
    }
};