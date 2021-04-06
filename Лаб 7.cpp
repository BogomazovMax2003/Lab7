// Лаб 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Stack
{
	struct Element
	{
		Element* next = nullptr;
		int value;
	};
	Element* head;
};


void construct_Stack(Stack& stack)
{
	stack.head = nullptr;
}

void destructor_Stack(Stack& stack) {
	while (stack.head != nullptr) {
		Stack::Element* q = new Stack::Element;
		q = stack.head->next;
		delete stack.head;
		stack.head = q;
		delete q;
	}
}

unsigned int size_Stack( Stack& stack) {
	Stack::Element* q = new Stack::Element;
	int k = 0;
	q = stack.head;
	while (stack.head != nullptr) {
		stack.head = stack.head->next;
		k++;
	}
	stack.head = q;
	delete q;
	std::cout << k << std::endl;
}

void push_Stack(Stack& stack,int value) {
	Stack::Element* new_element = new Stack::Element{ stack.head, value };
	stack.head = new_element;
}

void pop_Stack(Stack& stack) {
	Stack::Element* q = new Stack::Element;
	q = stack.head->next;
	delete stack.head;
	stack.head = q;
	delete q;
}

void print_Stack(Stack& stack) {
	Stack::Element* q = new Stack::Element;
	q = stack.head;
	while (stack.head != nullptr) {
		std::cout << stack.head->value<<std::endl;
		stack.head = stack.head->next;
	}
	stack.head = q;
	delete q;
}

// Очередь.
struct Queue
{
	struct Elementv2
	{
		Elementv2* next = nullptr;
		int value2;
	};
	Elementv2* first;
	Elementv2* second;
};

void construct_Queue(Queue& Queue)
{
	Queue.first = nullptr;
	Queue.second = nullptr;
}

void destructor_Queue(Queue& Queue) 
{
	while (Queue.first!=nullptr)
	{
		Queue::Elementv2* q = new Queue::Elementv2;
		q = Queue.first->next;
		delete Queue.first;
		Queue.first = q;
		delete q;
	}
}

unsigned int size_Queue(Queue& Queue) {
	Queue::Elementv2* q = new Queue::Elementv2;
	q = Queue.first->next;
	int k = 0;
	while (Queue.first != nullptr)
	{
		k++;
		Queue.first = Queue.first->next;
	}
	std::cout << k << std::endl;
	Queue.first = q;
	delete q;
}

void push_Queue(Queue& Queue,int value) {
	Queue::Elementv2* new_element = new Queue::Elementv2{ Queue.second, value };
	if (Queue.first == nullptr) {
		Queue.first = new_element;
	}
	else {


		Queue.second->next = new_element;
		Queue.second = new_element;
		new_element->value2 = value;
	}
}

void pop_Queue(Queue& Queue) {
	Queue::Elementv2* q = new Queue::Elementv2;
	q = Queue.first->next;
	delete Queue.first;
	Queue.first = q;
	delete q;
}

void print_Queue(Queue& Queue) {
	Queue::Elementv2* q = new Queue::Elementv2;
	q = Queue.first->next;
	while (Queue.first!=nullptr)
	{
		std::cout << Queue.first->value2 << std::endl;
		Queue.first = Queue.first->next;
	}
	Queue.first = q;
	delete q;
}



int main()
{
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
