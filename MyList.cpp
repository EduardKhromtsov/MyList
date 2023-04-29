
#include <iostream>
#include "List.h"

int main()
{
	setlocale(LC_ALL, "RU");

	List<int> lst;
	
	lst.push_front(5);
	lst.push_front(7);
	lst.push_front(10);

	lst.pop_back();

	for (int i = 0; i < lst.GetSize(); ++i)
	{
		std::cout << lst[i] << " ";
	}
	
}






