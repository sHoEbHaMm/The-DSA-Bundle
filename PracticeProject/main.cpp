

#include "Array.h"

int main()
{
    Array arr;

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);
    arr.Append(4);
    arr.Append(5);

    cout << arr.isSorted() << endl;

    return 0;
}


