#include <string>
#include <iostream>
#include <chrono>
#include <Windows.h>

using namespace std;
#define INT_MAX 32767 
#define NUM 13

struct arr
{
	string str = "\0";
	int num = 0;
	arr* next = NULL;
};

int hash_f(string str, int* rand8)
{
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
		sum += str[i];
	return sum % NUM;
}
void output(arr* tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr* ptr = &tab[i];
		cout << "уровень #" << i << ":\n";
		do
		{
			if (ptr->str[0] == '\0')
			{
				cout << "Пусто\n";
				break;
			}
			else
			{
				cout << "строка: " << ptr->str << " номер: " << ptr->num << "---";
			}
		} while (ptr = ptr->next);
	}
}
void dlt(arr* tab, int size, int num, int* rand8)
{
	int k = hash_f(to_string(num), rand8);
	while (k > size - 1) k -= size;
	arr* ptr = &tab[k];
	arr* prev = NULL;

	while (ptr != NULL && ptr->num != num)
	{
		prev = ptr;
		ptr = ptr->next;
	}

	if (ptr == NULL)
	{
		cout << "Элемента нет\n";
		return;
	}

	if (prev == NULL)
	{
		if (ptr->next)
		{
			tab[k] = *ptr->next;
			delete ptr->next;
		}
		else
		{
			ptr->num = 0;
			ptr->str = '\'\0\'';
			ptr->next = NULL;
		}
	}
	else
	{
		prev->next = ptr->next;
		delete ptr;
	}
}
void input(arr* tab, int size, string str, int num, int* rand8)
{
	int k = hash_f(to_string(num), rand8);
	while (k > size - 1) k -= size;
	arr* ptr = &tab[k];
	if (!ptr->num)
	{
		ptr->next = NULL;
		ptr->str = str;
		ptr->num = num;
	}
	else
	{
		while (ptr->next) ptr = ptr->next;
		arr* p = new arr;
		p->next = NULL;
		p->str = str;
		p->num = num;
		ptr->next = p;
	}
}
void search(arr* tab, int size, int num, int* rand8)
{
	int k = hash_f(to_string(num), rand8);
	cout << k;
	while (k > size - 1) k -= size;
	arr* ptr = &tab[k];
	if (ptr->num)
	{
		while (ptr->next && ptr->num != num)
		{
			ptr = ptr->next;
		}
		if (ptr->num == num)
		{
			cout << "ключ: " << ptr->num << " ФИО: " << ptr->str << endl;
			return;
		}
		cout << "ошибка\n";
		exit(1);
	}
	cout << "Элемента нет\n";
	return;
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 7;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> size;
	int clearMas[256] = { 0 };
	arr* mas = new arr[size];
	int choise;
	do
	{
		system("cls");
		cout << "1 - Вывод хеш-таблицы\n2 - Добавление элемента\n3 - Поиск элемента\n4 - Удаление\n0 - Выход\n";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			output(mas, size);
			break;
		}
		case 2:
		{
			string str;
			int num;
			cout << "Введите ФИО: ";
			cin.ignore();
			getline(cin, str);
			cout << "Введите номер телефона: ";
			cin >> num;
			if (0 < num < INT_MAX)
			{
				input(mas, size, str, num, clearMas);
			}
			else cout << "Некорректный номер\n";
			break;
		}
		case 3:
		{
			cout << "Введите ключ: ";
			int num;
			cin >> num;
			cin.ignore();
			auto start = chrono::high_resolution_clock::now();
			search(mas, size, num, clearMas);
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float>duration = end - start;
			cout << "Расчетное время: " << duration.count() << " секунд" << endl;
			break;
		}
		case 4:
		{
			cout << "Введите ключ: ";
			int num;
			cin >> num;
			dlt(mas, size, num, clearMas);
			break;
		}
		default:
			break;
		}
		system("pause");
	} while (choise);
}
