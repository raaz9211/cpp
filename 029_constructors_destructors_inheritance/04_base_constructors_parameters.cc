// derived-constructor(arg-list) : base1(arg-list),
//                                 base2(arg-list),
//                                 // ...
//                                 baseN(arg-list)
// {
// // body of derived constructor
// }

#include <iostream>
using namespace std;
class base
{
protected:
    int i;

public:
    base(int x)
    {
        i = x;
        cout << "Constructing base\n";
    }
    ~base() { cout << "Destructing base\n"; }
};

class derived : public base
{
    int j;

public:
    // derived uses x; y is passed along to base.
    derived(int x, int y) : base(y)
    {
        j = x;
        cout << "Constructing derived\n";
    }
    ~derived() { cout << "Destructing derived\n"; }
    void show() { cout << i << " " << j << "\n"; }
};

int main(){
    derived ob(3, 4);
    ob.show(); // displays 4 3

    return 0;
}

// Note : derived class' constructor must declare both the parameter(s) that it requires 