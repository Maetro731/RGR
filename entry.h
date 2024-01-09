#include <iostream>
#include "human.h"
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

class entry
{
    private:
        human sender;
        human recipient;
        string date;
        string vid_order[3] = {"Доставка по городу","Доставка по России","Международная доставка"};
        string gorod_type_transport[2] = {"Малогабаритный транспорт","Крупногабаритный транспорт"};
        string rus_type_transport[2] = {"Крупногабаритный транспорт","Авиаперевозка"};
        string mejnarod_type_transport[3] = {"Автотранспортная перевозка","Авиаперевозка","Морская перевозка"};
        string transport;
        string send_adres, recip_adres;
        int weight, volume, view;
    public:
        entry()
        {
            send_adres = "Новосибирск","Ленина","64";
            recip_adres = "Танковая","20";
            date = "01.01.2000";
            transport = "Малогабаритный";
            weight = 20;
            volume = 50;
        }
        entry(string s_name, string s_surname, string s_number,string send_adres,string r_name, string r_surname, string r_number, string recip_adres,string transport, int weight, int volume,string date)
        {
            this->sender = *(new human(s_name, s_surname, s_number));
            this->recipient = *(new human(r_name, r_surname, r_number));
            this->send_adres = send_adres;
            this->recip_adres = recip_adres;
            this->date = date;
            this->weight = weight;
            this->volume = volume;
            this->transport = transport;
        }
        void create_order()
        {
            cout << "???? ?????: " << endl;
            view = 0;
            for (int i=0;i<3;i++)
            {
                cout << "[" << i + 1 << "] " << vid_order[i] << endl;
            }
            while(view < 1 || view > 3)
            {
                cin>>view;
            }
            if (view == 1)// Доставка по городу
            {
                int type1 = 0;
                for (int i=0;i<2;i++)
                {
                    cout << "[" << i + 1 << "] " << gorod_type_transport[i] << endl;
                }
                while(type1 < 1 || type1 > 2)
                {
                    cin>>type1;
                }
                transport = gorod_type_transport[type1 - 1];
                string city,street, house;
                cout << "Укажите адрес отправителя: " << endl;
                cout << "Введите город: ";
                cin >> city;
                cout << "Введите улицу: ";
                cin >> street;
                cout << "Введите номер дома: ";
                cin >> house;
                send_adres = city + ", " + street + " " + house;
                cout << "Укажите адрес получателя: " << endl;
                cout << "Введите улицу: ";
                cin >> street;
                cout << "Введите номер дома: ";
                cin >> house;
                recip_adres = street + " " + house;
            }
            else if (view == 2) // Доставка по России
            {
                int type2 = 0;
                for (int i=0;i<2;i++)
                {
                    cout << "[" << i + 1 << "] " << rus_type_transport[i] << endl;
                }
                while(type2 < 1 || type2 > 2)
                {
                    cin>>type2;
                }
                transport = rus_type_transport[type2 - 1];
                string city;
                cout << "Укажите адрес отправителя: " << endl;
                cout << "Введите город: ";
                cin >> city;
                send_adres = city;
                cout << "Укажите адрес получателя: " << endl;
                cout << "Введите город: ";
                cin >> city;
                recip_adres = city;
            }
            else if (view == 3)// Медународная доставка
            {
                int type3 = 0;
                for (int i=0;i<3;i++)
                {
                    cout << "[" << i + 1 << "] " << mejnarod_type_transport[i] << endl;
                }
                while(type3 < 1 || type3 > 3)
                {
                    cin>>type3;
                }
                transport = mejnarod_type_transport[type3 - 1];
                string country, city;
                cout << "Укажите адрес отправителя: " << endl;
                cout << "Введите страну: ";
                cin >> country;
                cout << "Введите город: ";
                cin >> city;
                send_adres = country + ", " + city;
                cout << "Укажите адрес получателя: " << endl;
                cout << "Введите страну: ";
                cin >> country;
                cout << "Введите город: ";
                cin >> city;
                recip_adres = country + ", " + city;
            }
            cout << "Укажите дату перевозки шаблон(**.**.****)" << endl;
            string data;
            cin >> data;
            while(!proverka_dat(data))
            {
                cin >> data;
            }
            date = data;
            cout << "Укажите вес (кг.): " << endl;
            int ves = 0;
            while(ves < 1)
            {
                cin >> ves;
            }
            weight = ves;
            int vol = 0;
            cout << "Укажите объём (м^3): " << endl;
            while(vol < 1)
            {
                cin >> vol;
            }
            volume = vol;
            cout << "Укажите ФИ отправителя и его номер тел.: " << endl;
            string name, surname, number;
            cout << "Введите фамилию: ";
            cin >> surname;
            cout << "Введите имя: ";
            cin >> name;
            cout << "Введите номер телефона: ";
            cin >> number;
            sender = *(new human(name, surname, number));
            
            cout << "Укажите ФИ получателя и его номер тел.: " << endl;
            cout << "Введите фамилию: ";
            cin >> surname;
            cout << "Введите имя: ";
            cin >> name;
            cout << "Введите номер телефона: ";
            cin >> number;
            recipient = *(new human(name, surname, number));
        }
        void print()
        {
            cout << "отправитель: "<<sender.print() << " Адрес: " << send_adres << "\nПолучатель: "<< recipient.print() << " Адрес: " << recip_adres << endl;
            cout << "Способ доставки: " << transport << " Вес: " << weight << " кг.  Объём: " << volume << " (м^3)  ?? Дата: " << date << "\n" << endl;
        }
        void change()
        {
            cout << "Выберите пункт заказа, который хотите изменить: " << endl;
            int p = 0;
            cout << "[1] Фи отправителя и его номер тел." << endl;
            cout << "[2] Адрес отправителя: " << endl;
            cout << "[3] Способ доставки: " << endl;
            cout << "[4] Вес: "<< endl;
            cout << "[5] Объём: " << endl;
            cout << "[6] Дату:" << endl;
            while (p < 1 || p > 6)
            {
                cin >> p;
            }
            if (p == 1)
            {
                string change_name, change_surname, change_number;
                cout << "Введите фамилию: "; cin >> change_surname;
                cout << "Введите имя: "; cin >> change_name;
                cout << "Введите номер: "; cin >> change_number;
                recipient = *(new human(change_name, change_surname, change_number));
            }
            else if (p == 2)
            {
                if (getView() == 1)
                {
                    string city, street, house;
                    cout << "Укажите новый адрес отправителя: " << endl;
                    cout << "Введите улицу: "; cin >> street;
                    cout << "Введите номер дома: "; cin >> house;
                    recip_adres = street + " " + house;
                }
                else if (getView() == 2)
                {
                    string city;
                    cout << "Укажите новый адрес отправителя: " << endl;
                    cout << "Введите город: "; cin >> city;
                    recip_adres = city;
                }
                else if (getView() == 3)
                {
                    string country, city;
                    cout << "Укажите новый адрес отправителя: " << endl;
                    cout << "Введите страну: "; cin >> country;
                    cout << "Введите город: "; cin >> city;
                    recip_adres = country + ", " + city;
                }
            }
            else if (p == 3)
            {
                if (getView() == 1)
                {
                    int type1 = 0;
                    for (int i=0;i<2;i++)
                    {
                        cout << "[" << i + 1 << "] " << gorod_type_transport[i] << endl;
                    }
                    while(type1 < 1 || type1 > 2)
                    {
                        cin>>type1;
                        if (type1 < 1 || type1 > 2)
                        {
                            cout << "Возникла ошибка, повторите снова! " << endl;
                        }
                    }
                    transport = gorod_type_transport[type1 - 1];
                }
                else if (getView() == 2)
                {
                    int type2 = 0;
                    for (int i=0;i<2;i++)
                    {
                        cout << "[" << i + 1 << "] " << rus_type_transport[i] << endl;
                    }
                    while(type2 < 1 || type2 > 2)
                    {
                        cin>>type2;
                        if (type2 < 1 || type2 > 2)
                        {
                            cout << "Возникла ошибка, повторите снова! " << endl;
                        }
                    }
                    transport = rus_type_transport[type2 - 1];
                }
                else if (getView() == 3)
                {
                    int type3 = 0;
                    for (int i=0;i<3;i++)
                    {
                        cout << "[" << i + 1 << "] " << mejnarod_type_transport[i] << endl;
                    }
                    while(type3 < 1 || type3 > 3)
                    {
                        cin>>type3;
                        if (type3 < 1 || type3 > 3)
                        {
                            cout << "Возникла ошибка, повторите снова! " << endl;
                        }
                    }
                    transport = mejnarod_type_transport[type3 - 1];
                }
            }
            else if (p == 4)
            {
                int ves = 0;
                cout << "Укажите новый вес (кг.): ";
                while (ves < 1)
                {
                    cin >> ves;
                    if (ves < 1)
                    {
                        cout << "Возникла ошибка, повторите снова! " << endl;
                    }
                }
                weight = ves;
            }
            else if (p == 5)
            {
                int vol = 0;
                cout << "Укажите новый объём (м^3): ";
                while (vol < 1)
                {
                    cin >> vol;
                    if (vol < 1)
                    {
                        cout << "Возникла ошибка, повторите снова! " << endl;
                    }
                }
                volume = vol;
                
            }
            else if (p == 6)
            {
                string data;
                cout << "Укажите новую дату: ";
                cin >> data;
                while(!proverka_dat(data))
                {
                    cin >> data;
                    if(!proverka_dat(data))
                    {
                        cout << "Некорректная дата!";
                    }
                }
                date = data;
            }
        }
        bool proverka_year(int y) 
        { 
            if (y %400==0)return true; 
            else{ 
                if (y%100==0) return false; 
                else{ 
                    if (y%4==0)return true; 
                    else return false; 
                } 
            } 
        } 
        bool proverka_dat(string date) 
        {
            int d, m, y = 0;
            int t = date.find(".");
            string day = date.substr(0, t);
            string month = date.substr(t + 1, 2);
            string year = date.substr(t * 2 + 2, 4);
            d = stoi(day);
            m = stoi(month);
            y = stoi(year);
            int * arr30; 
            int * arr31; 
            arr30 = new int[4]{4,6,9,11}; 
            arr31 = new int[7]{1,3,5,7,8,10,12}; 
            for (int k=0;k<4;k++) 
        { 
            if (m == arr30[k] && 0 < d && d < 31)return true; 
        } 
            for (int i;i<7;i++){ 
                if (m == arr31[i] && 0 < d && d < 32)return true; 
            } 
            if (proverka_year(y) && m == 2 && 0 < d && d < 30)return true; 
            else{ 
                if (!(proverka_year(y)) && m == 2 && 0 < d && d < 29)return true; 
                else{ 
                    return false; 
                } 
            } 
        }
        human getSender(){return sender;}
        human getRecipient(){return recipient;}
        string getSender_adres(){return send_adres;}
        string getRecipient_adres(){return recip_adres;}
        string getTransport(){return transport;}
        string getDate(){return date;}
        int getWeight(){return weight;}
        int getVolume(){return volume;}
        int getView(){return view;}
    
};
