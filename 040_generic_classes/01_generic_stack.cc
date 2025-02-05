// This function demonstrates a generic stack.
#include <iostream>
#include<vector>
using namespace std;

// Create a generic stack class
template <class StackType>
class stack
{
    int stack_size;
    StackType *stack_array;
    int tos; // index of top-of-stack

public:
    stack(int stack_size)
    {
        stack_array = new StackType[stack_size];
        tos = 0;
        this->stack_size = stack_size;
    }

    void push(StackType ob)
    {
        if (tos == stack_size)
        {
            cout << "Stack is full.\n";
            return;
        }
        stack_array[tos++] = ob;
    }

    StackType pop()
    {
        if (tos == 0)
        {
            cout << "Stack is empty.\n";
            return 0; // return null on empty stack
        }
        return stack_array[--tos];
    }
};

int main()
{
    // Demonstrate character stacks.
    stack<char> s1(10), s2(10); // create two character stacks
    int i;
    s1.push('a');
    s2.push('x');
    s1.push('b');
    s2.push('y');
    s1.push('c');
    s2.push('z');
    
    for (i = 0; i < 3; i++)
        cout << "Pop s1: " << s1.pop() << "\n";
    for (i = 0; i < 3; i++)
        cout << "Pop s2: " << s2.pop() << "\n";

    // demonstrate double stacks
    stack<double> ds1(10), ds2(10); // create two double stacks
    ds1.push(1.1);
    ds2.push(2.2);
    ds1.push(3.3);
    ds2.push(4.4);
    ds1.push(5.5);
    ds2.push(6.6);

    for (i = 0; i < 3; i++)
        cout << "Pop ds1: " << ds1.pop() << "\n";
    for (i = 0; i < 3; i++)
        cout << "Pop ds2: " << ds2.pop() << "\n";

    return 0;
}

// Note : You can store pointer as well by "stack<char *> chrptrQ;"