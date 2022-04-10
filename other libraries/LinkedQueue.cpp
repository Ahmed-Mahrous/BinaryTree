#include "LinkedQueue.h"
template<class T>
LinkedQueue<T>::LinkedQueue()
{
	front = rear = nullptr;
	length = 0;
}

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
	// destructor to Delete the nodes.
	SingleNode<T> *it;
	while (front != nullptr)
	{
		it = front->next;
		delete front;
		front = it;
	}
}

template<class T>
inline bool LinkedQueue<T>::IsEmpty() const
{
	return (front == nullptr);
}

template<class T>
bool LinkedQueue<T>::IsFull() const
{
	// Is the queue full?
	SingleNode<T> *p;
	try
	{
		p = new SingleNode<T>;
		delete p;
		return false;
	}
	catch (std::exception)
	{
		return true;
	}
}

template<class T>
T LinkedQueue<T>::First() const
{
	// Return first element of queue.  Throw OutOfBounds exception if the queue is empty.
	if (IsEmpty()) throw std::out_of_range("Empty Queue!");
	return front->data;
}

template<class T>
T LinkedQueue<T>::Last() const
{
	// Return last element of queue.  Throw OutOfBounds exception if the queue is empty.
	if (IsEmpty()) throw std::out_of_range("Empty Queue!");
	return rear->data;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x)
{
	// Add x to rear of queue.  Do not catch possible NoMem exception thrown by new.
	// create node for new element
	SingleNode<T> *newNode = new SingleNode<T>();
	newNode->data = x;

	// add new node to rear of queue
	if (front != nullptr)
		rear->next = newNode; // queue not empty
	else
		front = newNode; // queue empty
	rear = newNode;
	length++;
	return *this;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x)
{
	// Delete first element and put it in x.  Throw OutOfBounds exception if the queue is empty.

	if (IsEmpty()) throw std::out_of_range("Empty Queue!");

	// save element in first node
	x = front->data;

	// delete first node
	SingleNode<T> *temp = front;
	front = front->next;
	delete temp;
	length--;
	return *this;
}

