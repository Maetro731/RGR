#include <iostream>
#include <cstring>

using namespace std;

class human
{
    public:
        human()
        {
            name = "Иван";
            surname = "Иванов";
            number = "8-880-555-35-55";
        }
        human(string name, string surname, string number)
        {
            this->name = name;
            this->surname = surname;
            this->number = number;
        }
        string print()
        {
            return surname + " " + name + " тел. " + number;
        }
        string getName(){return name;}
        string getSurname(){return surname;}
        string getNumber(){return number;}
        
    private:
        string name, surname, number;
};