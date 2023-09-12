#include <iostream>

typedef struct Node
{
	Node* next;
	int data;
}Node;

class List
{
private:
	Node* head;
	int len;
public:
	List()
	{
		this->head = NULL;
		this->len = 0;
		std::cout << "List created" << std::endl;
	}

	void insertElem(int value)
	{
		Node* node = new Node;
		node->data = value;
		if (this->head == NULL)
		{
			this->head = node;
			node->next = NULL;
		}
		else
		{
			Node* cur = this->head;
			while (cur->next != NULL)
			{
				cur = cur->next;
			}
			cur->next = node;
			node->next = NULL;
		}
		this->len++;
		return;
	}

	void deleteElement(int value)
	{
		if (this->head == NULL) return;
		if (this->head->data == value)
		{
			Node* tmp = head;
			head = tmp->next;
			delete tmp;
			this->len--;
			std::cout << "Element " << value << " deleted" << std::endl;
			return;
		}

		Node* cur = this->head;
		while (cur->next != NULL)
		{
			if (cur->next->data == value)
			{
				Node* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
				this->len--;
				std::cout << "Element " << value << " deleted" << std::endl;
				return;
			}
			cur = cur->next;
		}
	}

	void printList()
	{
		std::cout << "List:\t";
		if (this->len == 0)
			std::cout << "No elements in the list" << std::endl;
		Node* cur = this->head;
		while (cur != NULL)
		{
			std::cout << cur->data << " ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}

	int getLength()
	{
		return this->len;
	}

	~List()
	{
		Node* cur = this->head;
		while (cur != NULL)
		{
			Node* tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		std::cout << "List deleted" << std::endl;
	}
};

int main()
{
	List a;
	for (int i = 0; i < 1000; i++)
	{
		a.insertElem(5);
		a.insertElem(6);
		a.insertElem(7);
		a.printList();
		a.deleteElement(5);
		a.deleteElement(7);
		a.printList();
	}
	a.insertElem(5);
	a.insertElem(6);
	a.insertElem(7);
	a.printList();
	a.deleteElement(5);
	a.deleteElement(7);
	a.printList();
	
	return 0;
}