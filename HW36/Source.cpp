#include<iostream>
#include<vector>
#include<windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0)); 

	vector<int> a;
	vector<vector<int>> b;
	vector<vector<int>> c;
	vector<vector<int>> vec;
	int M = 0, N = 0,command = 0;

	while (M <= 0 || N <= 0)
	{
	cout << "Введіть кількість рядків:	";
	cin >> M;
	cout << "Введіть кількість стовпців:	";
	cin >> N;
	}
	a.resize(N, 0);
	vec.resize(M, a);
	b.resize(M+1, a);

	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			vec[i][j] = rand() % 10;
		}
	}
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	while (command == 0)
	{
		cout << "Куди ви хочете зсунути рядок(Наприклад: -3 --> на 3 рядка у низ; 3 --> на 3 у верх)?	";
		cin >> command;
	}
	if (command > 0)
	{
		for (size_t i = 0; i < command; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				if (j != M-1)
				{
					b[j].swap(vec[j + 1]);
				}
				else
				{
					b[j].swap(vec[0]);
				}
			}
			vec.clear();
			for (size_t j = 0; j < b.size(); j++)
			{
				vec.push_back(b[j]);
			}
			
		}
	}
	else
	{
		command = command - command - command;

		for (size_t i = 0; i < command; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				if (j != 0)
				{
					b[j-1].swap(vec[j]);
				}
				else
				{
					b[M-1].swap(vec[j]);
				}
			}
			vec.clear();
			for (size_t j = 0; j < b.size(); j++)
			{
				vec.push_back(b[j]);
			}

		}
	}
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}