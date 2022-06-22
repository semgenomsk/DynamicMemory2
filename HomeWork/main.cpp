#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

template<typename T> void FillRand(T arr[], const int n);
template<typename T> void Print(T arr[], const int n);
template<typename T> T* push_back(T arr[], int& n, int value);
template<typename T> T* push_front(T arr[], int& n, int value);
template<typename T> T* insert(T arr[], int& n, int index, int value);
template<typename T> T* pop_back(T arr[], int& n);
template<typename T> T* pop_front(T arr[], int& n);

template<typename T> T* erase(T arr[], int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	char* arr = new char[n];

	FillRand(arr, n);
	cout << "Исходный массив:\n";
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс, который вы хотите добавить: "; cin >> index;
	cout << "Введите вставляемый элемент: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);

	cout << "Удаление последнего элемента массива: ";
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Удаление нулевого элемента массива: ";
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;

}

template<typename T> void FillRand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;
	}

}

template<typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - опереатор индексирования (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template<typename T> T* push_back(T arr[], int& n, int value)
{
	//1) создаем буферный массив
	T* buffer = new T[n + 1]{};
	//2) копируем все элементы из исходного в буферный массив
	for (int i = 0; i < n; i++)
	{
		//элементы копируются соответственно
		buffer[i] = arr[i];
	}
	//3) удаляем исходный массив
	delete[] arr;
	//4) подменяем адрес исходного массива адресом нового массива
	arr = buffer;
	//только теперь в массив arr можно добавлять значение, поскольку там появилася 
	// ячейка для нового значения
	//5) добавляем значение в конец массива
	arr[n] = value;
	//6) после того как в массиве добавился элемент, количество его элементов увеличивается на 1
	n++;
	//всё !!!
	return arr;
}

template<typename T> T* push_front(T arr[], int& n, int value)
{
	//1) объявляем буферный массив нужного размера
	T* buffer = new T[n + 1]{};
	//2) копируем все элементы из исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		//элементы копируются со смещением на один элемент вправо
		buffer[i+1] = arr[i];
	}
	//3) удаляем исходный массив
	delete[] arr;
	//4) подменяем адрес
	arr = buffer;
	//5) добавляем значение в нулевой элемент
	arr[0] = value;
	//6) после того как в нулевой элемент присвоили значение, количество его элементов увеличивается на 1
	n++;
	//7) вернем новый массив
	return arr;
}

template<typename T> T* insert(T arr[], int& n, int index, int value)
{
	//1) объявляем буферный массив нужного размера
	T* buffer = new T[n + 1]{};
	//2) копируем все элементы из исходного массива в буферный
	for (int i = 0; i < index; i++)
	{
		//элементы копируются без смещения
		buffer[i] = arr[i];
	}
	//3) вставляем элемент в динамиечский массив
	buffer[index] = value;
	for (int i = index; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	//4) удаляем исходный массив
	delete[] arr;
	//5) подменяем адрес
	arr = buffer;
	//6) после того как элемент с индексом index присвоили значение, количество его элементов увеличивается на 1
	n++;
	//7) вернем новый массив
	return arr;
}

template<typename T> T* pop_back(T arr[], int& n)
{
	//1) обьявляем буферный массив нужного размера
	T* buffer = new T[n-1]{};
	//2) копируем все элементы из исходного массива в буферный
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	//3) удаляем исходный массив
	delete[] arr;
	//4) подменяем адрес
	arr = buffer;
	//5) ставим дикремент чтобы счетчик начинался с последнего элемента массива
	n--;
	return arr;
}

template<typename T> T* pop_front(T arr[], int& n)
{
	//1) обьявляем буферный массив нужного размера
	T* buffer = new T[n - 1]{};
	//2) копируем все элементы из исходного массива в буферный
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//3) удаляем исходный массив
	delete[] arr;
	//4) подменяем адрес
	arr = buffer;
	//5) 
	n--;
	return arr;
}

template<typename T> T* erase(T arr[], int& n, int index)
{
	//1) объявляем буферный массив нужного размера
	T* buffer = new T[n - 1]{};
	//2) копируем все элементы из исходного массива в буферный
	for (int i = 0; i < index; i++)
	{
		//элементы копируются без смещения
		buffer[i] = arr[i];
	}
	//3) удаляем значение из динамиечского массива
	
	for (int i = index; i < n-1; i++)
	{
		buffer[i] = arr[i+1];
	}
	//4) удаляем исходный массив
	delete[] arr;
	//5) подменяем адрес
	arr = buffer;
	//6) после того как элемент с индексом index присвоили значение, количество его элементов увеличивается на 1
	n--;
	//7) вернем новый массив
	return arr;
}