#include <iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

class List
{
private:

	class Node
	{
	public:
		Node* Pnext;
		int data;

		Node(int data, Node* Pnext = nullptr)
		{
			this->data = data;
			this->Pnext = Pnext;
		}
	};

	int Size;
	Node* head;

public:

	List()
	{
		Size = 0;
		this->MAKENULL();
	}
	~List()
	{
		clear();
	}

	void push_back(int data)
	{
		if (head == nullptr)
		{
			head = new Node(data);
		}
		else
		{
			Node* pattern = this->head;
			while (pattern->Pnext != nullptr)
			{
				pattern = pattern->Pnext;
			}
			pattern->Pnext = new Node(data);
		}

		Size++;
	}
	void pop_front()
	{
		Node* temp = head;

		head = head->Pnext;
		delete temp;

		Size--;

	}
	void push_front(int data)
	{
		head = new Node(data, head);
		Size++;
	}
	void INSERT(int data, int index)
	{
		if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Node* previous = this->head;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->Pnext;
			}

			Node* newNode = new Node(data, previous->Pnext);
			previous->Pnext = newNode;

			Size++;
		}
	}
	void DeLeTe(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Node* temp = this->head;

			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->Pnext;
			}

			Node* Delete_temp = temp->Pnext;
			temp->Pnext = Delete_temp->Pnext;
			delete Delete_temp;

			Size--;
		}
	}
	void pop_back()
	{
		DeLeTe(Size - 1);
	}

	int RETRIEVE(int index)
	{
		if (index > Size - 1)
		{
			cout << "Елемент під індексом " << index << " не знайдено!" << endl;
		}
		else
		{
			Node* pattern = this->head;

			for (int i = 0; i < Size; i++)
			{
				if (i == index)
				{
					return pattern->data;
				}
				pattern = pattern->Pnext;
			}
		}
	}
	int LOCATE(int data)
	{
		int temp_size = 0;
		Node* pattern = this->head;

		while (pattern != nullptr)
		{
			if (pattern->data == data)
			{
				return temp_size;

			}
			pattern = pattern->Pnext;
			temp_size++;
		}
	}
	Node* FIRST()
	{
		return head;
	}

	Node* END()
	{
		Node* pattern = this->head;
		while (pattern != nullptr)
		{
			pattern = pattern->Pnext;
		}
		return pattern;
	}

	Node* Pnext(int index)
	{
		int temp_size = 0;
		Node* pattern = this->head;

		while (pattern != nullptr)
		{
			if (temp_size == index)
			{
				return pattern->Pnext;
			}
			pattern = pattern->Pnext;
			temp_size++;
		}
		return nullptr;
	}
	void PRINTLIST()
	{
		int A = Size;
		Node* pattern = this->head;

		while (A)
		{
			cout << pattern->data << "; ";
			pattern = pattern->Pnext;
			A--;
		}
		cout << endl << endl;
	}
	void clear()
	{
		while (Size)
		{
			pop_front();
		}
	}
	void MAKENULL()
	{
		head = nullptr;
	}
	int Get_Size()
	{
		return Size;
	}

private:

};

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List Number;
	int A, B;

	for (int i = 0; i < 5; i++)
	{
		Number.push_back(rand() % 10);
	}

	cout << "Кількість елементів в списку: " << Number.Get_Size() << endl << endl;

	cout << "Виведення списку:" << endl;
	Number.PRINTLIST();

	cout << "Введіть елемет та його індекс який хочете вставити у список: ";
	cin >> A >> B;
	Number.INSERT(A, B);

	cout << "Виведення списку:" << endl;
	Number.PRINTLIST();

	cout << "Введіть елемент позицію якого хочете знайти: ";
	cin >> A;
	cout << "Позиція елемента: " << Number.LOCATE(A) << endl;

	cout << "Введіть індекс елемета який хочете знайти: ";
	cin >> B;
	cout << "Елемент: " << Number.RETRIEVE(B) << endl << endl;

	cout << "Введіть індекс елемета який хочете видалити: ";
	cin >> B;
	Number.DeLeTe(B);

	cout << "Виведення списку:" << endl;
	Number.PRINTLIST();

	return 0;
}