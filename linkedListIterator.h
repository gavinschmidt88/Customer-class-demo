#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H

using namespace std;

template <class T>
struct node
{
	T info;
	node<T> *link;
};

template <class T>
class linkedListIterator
{
	public:
		linkedListIterator();
		linkedListIterator(node<T> *ptr);
		T operator*();
		
	private:
		node<T> *current;
		
};

template <class T>
linkedListIterator<T>::linkedListIterator()
{
	current = nullptr;
}

template <class T>
linkedListIterator<T>::linkedListIterator(node<T> *ptr)
{
	current = ptr;
}

template <class T>
T linkedListIterator<T>::operator*()
{
	return current->info;
}

#endif