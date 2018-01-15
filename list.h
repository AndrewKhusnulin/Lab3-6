#include "List.cpp"
#include <conio.h>
void swap(int a, int b)
{
	cout << "Обмен значениями unique_ptr ptr1 и  shared_ptr ptr2" << endl;
	unique_ptr<int> ptr1(new int(a));
	shared_ptr<int> ptr2(new int(b));
	cout << boolalpha << "ptr1= " << *ptr1 << endl << "ptr2= " << boolalpha << *ptr2 << endl;
	shared_ptr<int> temp(move(ptr1));
	cout << "Swap : \n";
	swap(temp, ptr2);
	cout << boolalpha << "ptr1= " << *temp << endl << boolalpha << "ptr2= " << *ptr2 << endl;
}