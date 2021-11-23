#pragma once
#ifndef ORDERED_H
#define ORDERED_H
#include "linkedList.h"

using namespace std;

template <class T>
class orderedLinkedList: public linkedList<T>
{
	public:
		bool search(const T& searchItem) const;
		void sortedInsert(const T& newData);
		void deleteNode(const T& deleteItem);
};

template <class T>
void orderedLinkedList<T>::sortedInsert(const T& newData)
{
  node<T> *newNode;
  node<T> *current;
  newNode = new node<T>;
  newNode->info = newData;
  newNode->link = this->head;

  if (this->head == NULL || (this->head)->info >= newNode-> info)
  {
    newNode->link = this->head;
    this->head = newNode;
  }

  else 
  {
    current = this->head;

    while (current->link != NULL && current->link->info < newNode->info)
    {
      current = current->link;
    }

    newNode->link = current->link;
    current->link = newNode;
  }

} //ends sortedInsert

template <class T>
void orderedLinkedList<T>::deleteNode(const T& deleteItem)
{
	node<T> *current;
	node<T> *trailCurrent;
	bool found;
	if(this->isEmptyList())
	{
		cout << "Cannot delete from an empty list" << endl;
	}
	else
	{
		if(this->head->info == deleteItem)
		{
			current = this->head;
			this->head = this->head->link;
			this->count--;
			if(this->head == nullptr)
				this->tail = nullptr;
				
			delete current;
		}
		else 
		{
			found = false;
			trailCurrent = this->head;
			current = this->head->link;
			
			while(current != nullptr && !found)
			{
				if(current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else 
				{
					found = true;
				}
			}
			if(found)
			{
				trailCurrent->link = current->link;
				this->count--;
				if(this->tail == current)
					this->tail = trailCurrent;
				delete current;
			}
			else
			{
				cout << "The item to be deleted is not in the list." << endl;
			}
		}
	}
}

template <class T>
bool orderedLinkedList<T>::search(const T& searchItem) const
{
	node<T> *current;
	bool found = false;
	current = this->head;
	while(current != nullptr && !found)
	{
		if(current->info == searchItem)
			found = true;
		else 
			current = current->link;
	}
	return found;
}


#endif