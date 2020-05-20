#include <iostream>
#include"Tests_Domain.h"
#include"Fleet.h"
using namespace std;

int main()
{
    cout << "testing...\n";
    test_Domain();
    cout << "everything is ok :)\n";
	Fleet fleet1;
	fleet1.printSquaresState();
    return 0;
}

