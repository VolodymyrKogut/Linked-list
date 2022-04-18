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
		Node* Pprev;
		Node* Pnext;
		int data;

		Node(int data, Node* next = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->Pnext = next;
			this->Pprev = prev;
		}
	};

	int Size;
	Node* head;
	Node* tail;

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
		if (tail == nullptr)
		{
			head = new Node(data);
			tail = head;
		}
		else
		{
			Node* temp = new Node(data);
			tail->Pnext = temp;
			temp->Pnext = nullptr;
			temp->Pprev = this->tail;
			this->tail = temp;
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

			if (index < Size / 2)
			{
				Node* temp = this->head;
				for (int i = 0; i < index - 1; i++)
				{
					temp = temp->Pnext;
				}

				Node* newNode = new Node(data, temp->Pnext, temp->Pprev);
				temp->Pnext = newNode;
				temp->Pprev = newNode->Pprev;
			}
			else
			{
				Node* temp = this->tail;
				for (int i = Size - 1; i > index - 1; i--)
				{
					temp = temp->Pprev;
				}

				Node* newNode = new Node(data, temp->Pnext, temp->Pprev);
				temp->Pnext = newNode;
				temp->Pprev = newNode->Pprev;
			}

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

			if (index < Size / 2)
			{
				Node* temp = this->head;
				for (int i = 0; i < index - 1; i++)
				{
					temp = temp->Pnext;
				}

				Node* Delete_temp = temp->Pnext;
				temp->Pnext = Delete_temp->Pnext;
				delete Delete_temp;

			}
			else
			{
				Node* temp = this->tail;
				for (int i = Size - 1; i > index; i--)
				{
					temp = temp->Pprev;
				}

				Node* Delete_temp = temp->Pnext;
				temp->Pnext = Delete_temp->Pnext;
				delete Delete_temp;
			}

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

			if (index < Size / 2)
			{
				Node* temp = this->head;

				for (int i = 0; i < Size; i++)
				{
					if (i == index)
					{
						return temp->data;
					}
					temp = temp->Pnext;
				}
			}
			else
			{
				Node* temp = this->tail;

				for (int i = Size - 1; i >= 0; i--)
				{
					if (i == index)
					{
						return temp->data;
					}
					temp = temp->Pprev;
				}
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
		return tail;
	}

	Node* Pnext(int index)
	{
		if (index < Size / 2)
		{
			Node* temp = this->head;


			for (int i = 0; i < Size; i++)
			{
				if (i == index)
				{
					return temp->Pnext;
				}
				temp = temp->Pnext;
			}
		}
		else
		{
			Node* temp = this->tail;

			for (int i = Size - 1; i >= 0; i--)
			{
				if (i == index)
				{
					return temp->Pnext;
				}
				temp = temp->Pprev;
			}
		}
	}
	Node* Pprev(int index)
	{
		if (index < Size / 2)
		{
			Node* temp = this->head;


			for (int i = 0; i < Size; i++)
			{
				if (i == index)
				{
					return temp->Pprev;
				}
				temp = temp->Pnext;
			}
		}
		else
		{
			Node* temp = this->tail;

			for (int i = Size - 1; i >= 0; i--)
			{
				if (i == index)
				{
					return temp->Pprev;
				}
				temp = temp->Pprev;
			}
		}
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
		tail = nullptr;
	}
	int Get_Size()
	{
		return Size;
	}

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