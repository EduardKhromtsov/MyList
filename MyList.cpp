
#include <iostream>

// Реализация односвязного списка

#include "List.h"

int main()
{
	setlocale(LC_ALL, "RU");

	List<int> lst;
	
	lst.push_front(5);
	lst.push_front(7);

	lst.insert(10, 1);

	for (int i = 0; i < lst.GetSize(); ++i)
	{
		std::cout << lst[i] << " ";
	}
	
}

template<typename T>
List<T>::List()
{
	iSize = 0;
	pHead = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
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
void List<T>::push_front(const T &Data)
{
	pHead = new Node<T>(Data, pHead);

	++iSize;
}

template<typename T>
void List<T>::insert(const T &Data, const int kIndex)
{
	if (kIndex == 0)
		push_front(Data);
	else
	{
		Node<T>* pPrevious = this->pHead;

		for (int i = 0; i < kIndex - 1; ++i)
			pPrevious = pPrevious->pNext;

		pPrevious->pNext = new Node<T>(Data, pPrevious->pNext);

		++iSize;
	}
}

template<typename T>
void List<T>::removeAt(const int kIndex)
{
	if (kIndex == 0)
		pop_front();
	else
	{
		Node<T> *pPrevious = this->pHead;

		for (int i = 0; i < kIndex - 1; ++i)
			pPrevious = pPrevious->pNext;

		Node<T> *pToDelete = pPrevious->pNext;

		pPrevious->pNext = pToDelete->pNext;

		delete pToDelete;

		--iSize;
	}
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




