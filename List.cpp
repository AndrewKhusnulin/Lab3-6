#include<iostream>
#include<cassert>
#include<memory>
using namespace std;
template <typename T>
class LinkedList
{
private:
	class Node
	{
		friend class LinkedList<T>;
	private:
		T data;
		shared_ptr<Node> next;

	public:
		Node(T d, shared_ptr<Node> n = nullptr) : data(d), next(n) {}
	};
	shared_ptr<Node> head;
	shared_ptr<Node> tail;
	int count;
public:
	LinkedList(const LinkedList<T> &src);
	~LinkedList();
	LinkedList() : head(nullptr), tail(nullptr), count(0) {}
	inline T& front()
	{
		assert(head != nullptr);
		return head->data;
	}
	inline T& back()
	{
		assert(tail != nullptr);
		return tail->data;
	}
	inline int size() noexcept
	{
		return count;
	}
	inline bool empty() noexcept
	{
		return count == 0;
	}
	void  push_front(T);
	void  push_back(T);
	void  pop_front();
	void  pop_back();
	void  dump();
};
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &src) :
	head(nullptr), tail(nullptr), count(0)
{
	shared_ptr<Node> current = src.head;
	while (current != nullptr)
	{
		this->push_back(current->data);
		current = current->next;
	}
}
template <typename T>
LinkedList<T>::~LinkedList() {

	while (!this->empty())
	{
		this->pop_front();
	}
}
template <typename T>
void LinkedList<T>::push_front(T d)
{
	shared_ptr<Node> new_head(new Node(d, head));
	if (this->empty())
	{
		head = new_head;
		tail = new_head;
	}
	else
	{
		head = new_head;
	}
	count++;
}
template <typename T>
void LinkedList<T>::push_back(T d)
{
	shared_ptr<Node> new_tail(new Node(d, nullptr));
	if (this->empty())
	{
		head = new_tail;
	}
	else
	{
		tail->next = new_tail;
	}

	tail = new_tail;
	count++;
}
template <typename T>
void LinkedList<T>::pop_front()
{
	assert(head != nullptr);
	shared_ptr<Node> old_head = head;
	if (this->size() == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
	}
	count--;
}
template <typename T>
void LinkedList<T>::pop_back()
{
	assert(tail != nullptr);
	shared_ptr<Node> old_tail = tail;
	if (this->size() == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else {
		shared_ptr<Node> current = head;
		while (current->next != tail)
		{
			current = current->next;
		}
		current->next = nullptr;
		tail = current;
	}
	count--;
}
template <typename T>
void LinkedList<T>::dump()
{
	cout << "List : { ";
	shared_ptr<Node> current = head;
	if (current != nullptr)
	{

		while (current->next != nullptr)
		{
			cout << current->data << ", ";
			current = current->next;
		}
		cout << current->data;
	}

	cout << " }" << endl;
}