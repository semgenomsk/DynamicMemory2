#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);

int* insert(int arr[], int& n, int index, int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* erase(int arr[], int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "�������� ������:\n";
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "������� ������, ������� �� ������ ��������: "; cin >> index;
	cout << "������� ����������� �������: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);

	cout << "�������� ���������� �������� �������: ";
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "�������� �������� �������� �������: ";
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "������� ������ ���������� ��������: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������
		*(arr + i) = rand() % 100;
	}

}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - ��������� �������������� (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}int* push_back(int arr[], int& n, int value)
{
	//1) ������� �������� ������
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� � �������� ������
	for (int i = 0; i < n; i++)
	{
		//�������� ���������� ��������������
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������
	delete[] arr;
	//4) ��������� ����� ��������� ������� ������� ������ �������
	arr = buffer;
	//������ ������ � ������ arr ����� ��������� ��������, ��������� ��� ��������� 
	// ������ ��� ������ ��������
	//5) ��������� �������� � ����� �������
	arr[n] = value;
	//6) ����� ���� ��� � ������� ��������� �������, ���������� ��� ��������� ������������� �� 1
	n++;
	//�� !!!
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	//1) ��������� �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n; i++)
	{
		//�������� ���������� �� ��������� �� ���� ������� ������
		buffer[i + 1] = arr[i];
	}
	//3) ������� �������� ������
	delete[] arr;
	//4) ��������� �����
	arr = buffer;
	//5) ��������� �������� � ������� �������
	arr[0] = value;
	//6) ����� ���� ��� � ������� ������� ��������� ��������, ���������� ��� ��������� ������������� �� 1
	n++;
	//7) ������ ����� ������
	return arr;
}

int* insert(int arr[], int& n, int index, int value)
{
	//1) ��������� �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < index; i++)
	{
		//�������� ���������� ��� ��������
		buffer[i] = arr[i];
	}
	//3) ��������� ������� � ������������ ������
	buffer[index] = value;
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//4) ������� �������� ������
	delete[] arr;
	//5) ��������� �����
	arr = buffer;
	//6) ����� ���� ��� ������� � �������� index ��������� ��������, ���������� ��� ��������� ������������� �� 1
	n++;
	//7) ������ ����� ������
	return arr;
}

int* pop_back(int arr[], int& n)
{
	//1) ��������� �������� ������ ������� �������
	int* buffer = new int[n - 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������
	delete[] arr;
	//4) ��������� �����
	arr = buffer;
	//5) ������ ��������� ����� ������� ��������� � ���������� �������� �������
	n--;
	return arr;
}

int* pop_front(int arr[], int& n)
{
	//1) ��������� �������� ������ ������� �������
	int* buffer = new int[n - 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//3) ������� �������� ������
	delete[] arr;
	//4) ��������� �����
	arr = buffer;
	//5) 
	n--;
	return arr;
}
int* erase(int arr[], int& n, int index)
{
	//1) ��������� �������� ������ ������� �������
	int* buffer = new int[n - 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < index; i++)
	{
		//�������� ���������� ��� ��������
		buffer[i] = arr[i];
	}
	//3) ������� �������� �� ������������� �������

	for (int i = index; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//4) ������� �������� ������
	delete[] arr;
	//5) ��������� �����
	arr = buffer;
	//6) ����� ���� ��� ������� � �������� index ��������� ��������, ���������� ��� ��������� ������������� �� 1
	n--;
	//7) ������ ����� ������
	return arr;
}