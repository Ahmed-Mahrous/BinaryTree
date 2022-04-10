#ifndef LinkedQueue_
#define LinkedQueue_
#include <iostream>
template <class T>
class SingleNode
{
    public:
	T data;
	SingleNode<T> *next;

	SingleNode(){ next = nullptr;}

	~SingleNode(){}
};

template<class T>
class LinkedQueue
{
public:
    // constructor
	LinkedQueue();
	// destructor
	~LinkedQueue();

	// basic methods
	bool IsEmpty() const;
	bool IsFull() const;
	T First() const; // return first element
	T Last() const; // return last element
	LinkedQueue<T>& Add(const T& x);
	LinkedQueue<T>& Delete(T& x);

private:
	SingleNode<T> *front;  // pointer to first node
	SingleNode<T> *rear;   // pointer to last node
	int length;
};

#endif
