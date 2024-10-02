

//#include "Array.h"
//#include "Stack.h"
#include "SimpleQueue.h"

int main()
{
    /*Array arr;

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);
    arr.Append(4);
    arr.Append(5);

    cout << arr.isSorted() << endl;*/ 

    //Stack newStack;

    //newStack.peek();

    //newStack.Display();

    SimpleQueue queue(5);

    queue.dequeue();
    queue.Display();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.Display();

    queue.enqueue(6);

    queue.dequeue();

    queue.Display();

    return 0;
}


