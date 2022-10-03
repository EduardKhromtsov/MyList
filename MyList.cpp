
#include <iostream>

// Реализация односвязного списка

#include "List.h"

int main()
{
	setlocale(LC_ALL, "RU");

	List<int> lst;
	
	lst.push_back(55);

	lst.push_back(11);

	lst.push_back(2);

	for (int i = 0; i < lst.GetSize(); ++i)
	{
		std::cout << lst[i] << " ";
	}

	std::cout << "Элементов в списке " << lst.GetSize() << "\n\n" << "Выполняю метод clear" << "\n\n";

	lst.clear();

	std::cout << "Элементов в списке " << lst.GetSize() << "\n";
	
}

template<typename T>
List<T>::List()
{
	iSize = 0;
	pHead = nullptr;
}

template<typename T>
void List<T>::push_back(const T &Data)
{
	if (pHead == nullptr)
		pHead = new Node<T>(Data);
	else
	{
		Node<T> *pCurrent = this->pHead;

		while (pCurrent->pNext != nullptr)
			pCurrent = pCurrent->pNext;

		pCurrent->pNext = new Node<T>(Data);
	}
	++iSize;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *Temp = pHead;

	pHead = pHead->pNext;

	delete Temp;

	--iSize;
}

template<typename T>
void List<T>::clear()
{
	while (iSize)
		pop_front();
}

template<typename T>
int List<T>::GetSize() const
{
	return iSize;
}

template<typename T>
T& List<T>::operator[](const int kIndex)
{
	int iCounter = 0;

	Node<T> *pCurrent = this->pHead;

	while (pCurrent != nullptr)
	{
		if (iCounter == kIndex)
			return pCurrent->Data;

		pCurrent = pCurrent->pNext;

		++iCounter;
	}
}




