#include <iostream>
#include<assert.h>
using namespace std;

//Task
// Class DynamicArray (template<class t>)
// Example: DynamicArray<double> da;
// Copy Constructor, Copy Assignment operator, Default Constructor  +
// [] operator overloading  +
// AddElementToEnd +
// AddElementToHead +
// AddElementByIndex +
// DeleteElementByIndex +
// Print() +

template<class T>
class DynamicArray {
	T* arr = nullptr;
	int size;
public:
	DynamicArray() {
		SetArray(nullptr);
		SetSize(0);
	}

	DynamicArray(const DynamicArray& other) {
		SetArray(other.arr);
		SetSize(other.size);
	}

	DynamicArray& operator=(const DynamicArray& other) {
		SetArray(other.arr);
		SetSize(other.size);
		return *this;
	}

	T& operator[](int index) {
		assert(0 <= index && index < size && "index out of range");
		return arr[index];
		}
#pragma region SetGet
	void SetArray(T* arr) {
		int index = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (i >= 0) {
				index = i;
			}
			else{
				cout << "Index Out Of Range!" << endl;
			}
		}
		if (index >= 0) {
			this->arr = arr;
		}
	}

	void SetSize(int s) {
		if (this->size >= 0) {
			this->size = s;
		}
		else {
			cout << "Size Cannot be less than zero";
		}
	}

	T* GetArray() const{
		return this->arr;
	}

	int GetSize()const {
		return this->size;
	}

#pragma endregion

	void AddElementToEnd(const T& elem) {
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
		}
		temp[size] = elem;
		delete[] arr;
		arr = temp;
		temp = nullptr;
		size++;
		}

	void AddElementToHead(const T&elem) {
		T* temp = new T[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[0] = elem;
		delete[]arr;
		arr = temp;
		temp = nullptr;
		size++
	}
	
	void AddElementByIndex(const T& elem) {
		int index = 0;

		T* temp = new T[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[index] = elem;
		delete[]arr;
		arr = temp;
		temp = nullptr;
		size++;

	}

	void DeleteElementByIndex(const T& elem) {
		int index = -1;

		for (size_t i = 0; i < size; i++)
		{
			if (i==index) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			DynamicArray** temp = new DynamicArray * [size - 1];
			for (size_t i = 0; i < index; i++)
			{
				temp[i] = arr[i];
			}

			for (size_t i = index; i < size; i++) {
				temp[i - 1] = arr[i + 1];
			}
			delete[]arr;
			arr = temp;
			size--;
			temp = nullptr;
		}
	}

	void Print() {
		for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		}
		cout << endl;
	}

	~DynamicArray() {
		delete[]arr;
	}


};


void main() {

	DynamicArray<int>a;
	



}