#include <iostream>
#include <new>
#include <string>
using namespace std;

class balance
{
    double cur_bal;
    string name;

public:
    void set(double n, string name)
    {
        cur_bal = n;
        this->name = name;
    }
    void get_bal(double &n, string &name)
    {
        n = cur_bal;
        name = this->name;
    }
};

int main()
{
    balance *p;
    string s;
    double n;

    try
    {
        p = new balance;
    }
    catch (bad_alloc xa)
    {
        cout << "Allocation Failure\n";
        return 1;
    }

    p->set(123.2, "Raj");
    p->get_bal(n, s);

    cout << s << "'s balance is: " << n;
    cout << "\n";
    delete p;
    return 0;
}