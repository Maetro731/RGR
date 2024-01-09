#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "entry.h"
using namespace std;

class Orders
{
    private:
        entry *orders;
        int num;
    public:
        Orders()
        {
            num = 1;
            orders = new entry[num];
            entry neworder;
            for(int i=0;i<num;i++)
            {
                neworder.create_order();
                orders[i] = neworder;
            }
        }
        void append_order()
        {
            entry zapros;
            zapros.create_order();
            entry* newzapros = new entry[num + 1];
            for(int i=0;i<num;i++)
            {
                newzapros[i] = orders[i];
            }
            newzapros[num] = zapros;
            orders = newzapros;
            num++;
        }
        void change_order(int num)
        {
            orders[num - 1].change();
            cout << "«аказ успешно изменен." << endl;
        }
        void pop_order(int n)
        {
            entry * newzapros = new entry[num - 1];
            for (int i=0,k=0;i < num;i++,k++)
            {
                if (i==(n-1))i++;
                if (i<num)newzapros[k] = orders[i];
            }
            n--;
            orders = newzapros;
        }
        void print()
        {
            for(int i=0;i<num;i++)
            {
                entry all_entry = orders[i];
                cout << "[" << i + 1 << "] ";
                all_entry.print();
            }
        }
        int getNum(){return num;}
        void append_orders_to_file()
        {
            ofstream out;
            out.open("orders.txt", ios::app);
            if (out.is_open())
            {
                for (int i=0;i<num;i++)
                {
                    entry object = orders[i];
                    out << object.getSender().getName() << " Ч " << object.getSender().getSurname() << " Ч " << object.getSender().getNumber() <<  " Ч ";
                    out << object.getSender_adres() << " Ч " << object.getRecipient().getName() << " Ч " << object.getRecipient().getSurname()<<" Ч "<<object.getRecipient().getNumber()<< " Ч ";
                    out << object.getRecipient_adres() << " Ч " << object.getTransport() << " Ч " << object.getWeight() <<  " Ч " << object.getVolume() << " Ч " << object.getDate() <<":";
                }
            }
            out.close();
        }
        void load_orders()
        {
            ifstream in;
            in.open("orders.txt");
            if (in.is_open())
            {
                string str;
                while (getline(in, str))
                {
                    string s_name = str.substr(0, str.find(" Ч "));
                    str = str.substr(str.find(" Ч ") + 3);
                    string s_surname = str.substr(0, str.find(" Ч "));
                    str = str.substr(str.find(" Ч ") + 3);
                    string s_number = str.substr(0, str.find(" Ч "));
                    str = str.substr(str.find(" Ч ") + 3);
                    string s_adres = str.substr(0, str.find(" Ч "));
                    str = str.substr(str.find(" Ч ") + 3);
                    string r_name = str.substr(0, str.find(" Ч "));
                    str = str.substr(str.find(" Ч ") + 3);
                    string r_surname = str.substr(0, str.find(" Ч "));
                    str = str.substr(str.find(" Ч ") + 3);
                    string r_number = str.substr(0, str.find(" Ч "));
                    str = str.substr(str.find(" Ч ") + 3);
                    string r_adres = str.substr(0, str.find(" Ч "));
                    str = str.substr(str.find(" Ч ") + 3);
                    string transport = str.substr(0, str.find(" Ч "));
                    str = str.substr(str.find(" Ч ") + 3);
                    int weight = stoi(str.substr(0, str.find(" Ч ")));
                    str = str.substr(str.find(" Ч ") + 3);
                    int volume = stoi(str.substr(0, str.find(" Ч ")));
                    str = str.substr(str.find(" Ч ") + 3);
                    string date = str.substr(0, str.find(":"));
                    entry* str = new entry(s_name,s_surname,s_number,s_adres,r_name,r_surname,r_number,r_adres,transport,weight,volume,date);
                    entry* newzapros = new entry[num + 1];
                    for(int i=0;i<num;i++)
                    {
                        newzapros[i] = orders[i];
                    }
                    newzapros[num] = *str;
                    num++;
                    orders = newzapros;
                }
            }
            in.close();
        }
        
};