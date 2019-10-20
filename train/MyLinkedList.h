#pragma once

#include <iostream>
#include <functional>

template <class T>
class MyLinkedList
{
private:
	template <class T>
	class MyNode
	{
	private:
		friend class MyLinkedList<T>;
		MyNode(T item, MyNode<T>* prev)
		{
			this->prev = prev;
			this->item = item;
		}

	public:
		MyNode<T>* prev;
		T item;

		friend std::ostream& operator<<(std::ostream& os, const MyNode& node)
		{
			return os << node.item;
		}
	};

	MyNode<T>* head;
	MyNode<T>* tail;

	void recursive_iterate(MyNode<T>* node, std::function<void(T)> f) const
	{
		if (node == nullptr)
		{
			return;
		}

		recursive_iterate(node->prev, f);
		f(node->item);
	}

public:
	MyLinkedList() 
	{
		head = nullptr;
	}

	~MyLinkedList()
	{
		while (head != nullptr)
		{
			MyNode<T>* prev = head->prev;
			delete head;
			head = prev;
		}
	}

	// Appends element to end of the list
	void append(T item)
	{
		head = new MyNode<T>(item, head);
	}

	// Removes an element from end of the list and returns it
	T pop()
	{
		if (head == nullptr)
		{
			throw "out of bounds";
		}

		MyNode<T>* curHead = head;
		head = curHead->prev;
		T item = curHead->item;
		delete curHead;

		return item;
	}

	friend std::ostream& operator<<(std::ostream& os, const MyLinkedList<T>& list)
	{
		MyNode<T>* cur = list.head;
		while (cur != nullptr)
		{
			os << *cur << endl;
			cur = cur->prev;
		}

		return os;
	}

	const MyNode<T>* get_head() const 
	{
		return head;
	}

	// This method allows to iterate over the list in insertion order.
	void for_each(std::function<void (T)> f) const
	{
		recursive_iterate(head, f);
	}

	T operator[](int index)
	{
		if (index < 0)
		{
			throw "out of bounds";
		}

		T res;

		for_each([&](T p) 
		{
			if (index-- == 0) {
				res = p;
			}
		});

		return res;
	}
};
