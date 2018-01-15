#include "List.h"
int main()
{
	setlocale(0, "rus");
	LinkedList <int> list;
	int a;
	int ch;
	while (1)
	{
		system("cls");
		cout << "Please, select preffer number...\n";
		cout << "1. Push_front\n";
		cout << "2. delete" << endl;
		cout << "3. swap" << endl;
		cout << "4. push_back" << endl;
		cout << "5. pop_front" << endl;
		cout << "0. Exit\n\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter your elements: \n";
			for (unsigned int i = 0; i < 3; ++i)
			{
				cin >> a;
				list.push_front(a);
			}
			cout << "Number of elements: " << list.size() << endl;
			list.dump();
			_getch();
			break;
		case 2:
			list.pop_back();
			cout << "element is deleted!\n";
			list.dump();
			_getch();
			break;
		case 3:
			int a, b;
			cout << "Enter first element: \n";
			cin >> a;
			cout << "Enter second element: \n";
			cin >> b;
			swap(a,b);
			_getch();
			break;
		case 4:
			cout << "Enter your elements: \n";
			for (unsigned int i = 0; i < 3; ++i)
			{
				cin >> a;
				list.push_back(a);
			}
			cout << "Number of elements: " << list.size() << endl;
			list.dump();
			_getch();
			break;
		case 5:
			list.pop_front();
			cout << "element is deleted!\n";
			list.dump();
			_getch();
			break;
		case 0:
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}