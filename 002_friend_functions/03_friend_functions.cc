// A friend of one class may be a member of another.// Here a friend function allows you to generate more efficient code
#include <iostream>
using namespace std;

const int IDLE = 0;
const int INUSE = 1;

class C2; // forward declaration

class C1
{
    int status; // IDLE if off, INUSE if on screen.
public:
    void set_status(int state)
    {
        status = state;
    }
    int idle(C2 b); // now a member of C1
};

class C2
{
    int status; // IDLE if off, INUSE if on screen.
public:
    void set_status(int state)
    {
        status = state;
    }
    friend int C1::idle(C2 b);
};

// idle() is member of C1, but friend of C2
int C1::idle(C2 b)
{
    return !(status || b.status);
}

int main()
{

    C1 x;
    C2 y;

    x.set_status(IDLE);
    y.set_status(IDLE);

    if (x.idle(y))
    {
        cout << "Screen can be used.\n";
    }
    else
    {
        cout << "In use.\n";
    }

    x.set_status(INUSE);

    if (x.idle(y))
    {
        cout << "Screen can be used.\n";
    }
    else
    {
        cout << "In use.\n";
    }
    return 0;
}