/*
6. Дан двумерный массив размерностью 5х5, заполненный
случайными числами из диапазона от 0 до 100. Поменять местами
последний столбец массива со столбцом, в котором находится
максимальный элемент.
*/

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw; // setw(4) - Задает ширину поля отображения для следующего элемента в потоке.

int main()
{
	setlocale(LC_ALL, ""); // Работает только с потоком вывода.
	srand(time(0));
	/*
		Функция srand() используется для установки начала последовательности,
	генерируемой функ­цией rand() (функция rand() возвращает псевдослучайные числа).
		Функция srand() позволяет запускать программу несколько раз	с различными
	последователь­ностями псевдослучайных чисел.
	*/

	int min{ 0 }; // Минимальное значение диапазона.
	int max{ 100 }; // Максимальное значение диапазона.
	const int row{ 5 }; // Количество строк (рядов).
	const int col{ 5 }; // Количество колонок (столбцов).

	int arr[row][col]{ 0 }; // Инициализируем массив.
	
	for (int i = 0; i < row; i++) // Заполняем массив псевдослучайными числами и выводим.
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//Ищем максимальный елемент в массиве.
	int maxi{ arr[0][0] };
	int q = 0;
	int e = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] > maxi)
			{
				maxi = arr[i][j];
				q = i;
				e = j;
			}
		}
	}
	cout << "Максимальный елемент массива : " << maxi << " (" << q << ", " << e << ")" << endl << endl;

	for (int i = 0; i < row; i++) // Обрабатываем массив. 
	{
		for (int j = 0; j < col; j++)
		{
			if (e == j)
			{
				int temp = arr[i][j];
				arr[i][j] = arr[i][col - 1];
				arr[i][col - 1] = temp;
			}
		}
	}

	for (int i = 0; i < row; i++) // Выводим массив.
	{
		for (int j = 0; j < col; j++)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
	cout << endl;

	return 0;
}