#include<iostream>
 
template <typename T>
class Node{
public:
	T _data; 
	Node* _next; 
	Node(int data) {
		_data = data;
		_next = nullptr;
	}

	Node<T>* GetNext() {
		if (_next != nullptr)
			return _next;
		return nullptr;
	}

	void SetNext(Node<T>* next) {
		_next = next;
	}

	T GetData() {
		return _data;
	}
};
template <typename T>
class List{
private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
	int count = 0;
public:
    Node<T>* Find(int index){
		Node<T>* ptr = _tail;
		int count1 = count - index;
		//index = count;
		while (count1 > 0) {
			ptr = ptr->GetNext();
			count1--;
		}
		return ptr;
    }
	void Push_back(int data) {
		Node<T>* newNode = new Node<T>(data);
		count++;
		if (_head == nullptr) {
			_head = newNode;
			_tail = newNode;
			return;
		}
		newNode->SetNext(_tail);
		_tail = newNode;
	}
	void Show() {
		for (Node<T>* ptr = _tail; ptr != _head->GetNext(); ptr = ptr->GetNext())
			std::cout << ptr->GetData() << '\n';
	}
	void AddIndex(int data, int index) {
		Node<T>* newNode = new Node<T>(data);
		count++;
		Node<T>* elementIndex = Find(index);
		Node<T>* element = Find(index + 1);
		element->SetNext(newNode);
		newNode->SetNext(elementIndex);
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	List<int> list1;
	list1.Push_back(4674);
	list1.Push_back(67676);
	list1.Push_back(777);
	list1.Push_back(767);
	list1.Push_back(12121);
	list1.Push_back(555);

	list1.Show();

	std::cout << list1.Find(2)->GetData() << "\n\n";  

	list1.AddIndex(0, 2);
	list1.Show();

	return 0;
}