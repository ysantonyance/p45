#include <iostream>
#include <windows.h> 
#include <locale>
#include <codecvt>
using namespace std;

int main()
{

	/*
	Задачі на if-else:
	1.	Користувач задає координати верхнього лівого та нижнього правого кута прямокутника, а також координати точки (X,Y).
	Перевірити, чи належить точка цьому прямокутнику.
	2.	Ввести з клавіатури шестизначний номер трамвайного (або тролейбусного) квитка і визначити,
	чи є він щасливим (сума трьох перших цифр дорівнює сумі трьох останніх).
	Задачі на switch:
	1.	Реалізувати калькулятор. Вводяться 2 будь-яких дійсних числа. Виводиться меню з пунктами для виконання операцій: додавання,
	віднімання, множення, ділення, залишок від ділення. Має бути перевірка ділення на 0.
	Задачі на тернарний оператор:
	1.	Ввести з клавіатури число і перевірити, чи належить це число діапазону від 0 до 100 (включно).
	2.	Перевірити, чи має введене число дробову частину.
	Задачa на випадкові числа:
	1.	Реалізувати програму «Мольфар-3000». Програма дає випадкову відповідь на запитання користувача з заздалегідь визначених варіантів.
	Задачі iз зірочкою* (виконувати необов’язково):
	1.	Ввести будь-яку дату (день, місяць, рік) і перевірити коректність введених значень. Вивести дату наступного дня.
	2.	Написати гру "Перший мiльон". Появляються питання та 4 варіанти відповідей, при неправильному виборі гра закінчується,
	при правильному — переходимо до наступного питання. Мінімум 5 питань на різні теми.
	*/

	//if-else
	//1
	/*
	int x, x1, x2, y, y1, y2;
	cout << "set the coordinates of the upper left corner(x, y) of the rectangle: \n";
	cin >> x1 >> y1;
	cout << "now set coordinated of the bottom right corner(x, y) of the rectangle: \n";
	cin >> x2 >> y2;
	cout << "and for the last set your point coordinates(x, y): \n";
	cin >> x >> y;

	if ((x2 >= x && x >= x1) && (y1 >= y && y >= y2)) // 3 > 1 > -3 && 2 > 1 < -2
	{
		cout << "congrats! your point belongs to the rectangle!\n";
	}
	else
	{
		cout << "sorry, unfortunately your point doesn't belong to the rectangle:(\n";
	}
	*/

	//2
	/*
	int num;
	cout << "please, enter streetcar ticket number(6-digits): ";
	cin >> num; //123321

	int digit1 = num / 100000; //1
	int digit2 = num / 10000 % 10; //2
	int digit3 = num / 1000 % 10; //3
	int digit4 = num / 100 % 10;
	int digit5 = num / 10 % 10;
	int digit6 = num % 10;

	if ((digit1 + digit2 + digit3) == (digit4 + digit5 + digit6))
		cout << "congrats! you got a happy ticket!\n";
	else
		cout << "you didn't get a happy ticket, but I wish you luck for the next time!\n";
	*/

	//switch
	//1
	/*
	int choice, num1, num2;
	cout << "haii, this is a your small calculator, first of all input 2 numbers:\n";
	cin >> num1 >> num2;
	cout << "now let me now what do you want me to do with them\n";
	cout << "1. addition (+)\n2. subtraction (-)\n3. multiplication (*)\n4. division (/)\n5. modulation (%)\n(choose a number)\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
		break;
	case 2:
		cout << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
		break;
	case 3:
		cout << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
		break;
	case 4:
		if (num2 == 0)
		{
			cout << "did you really think you could divide by 0 :P\n";
		}
		break;
		cout << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
		break;
	case 5:
		cout << num1 << " % " << num2 << " = " << num1 % num2 << "\n";
		break;
	default:
		cout << "there's not such operation on the list, sorry\n";
	}
	*/

	//тернарный оператор
	//1
	/*
	int num;
	cout << "enter num: ";
	cin >> num;

	string res = (100 >= num && num >= 0) ? "this number is in range from 0 to 100\n" : "this number is NOT in range from 0 to 100\n";
	cout << res;
	*/
	
	//2
	/*
	double num;
	cout << "please enter your number: ";
	cin >> num;

	string res = (num - (int)num != 0) ? "this number is fractional\n" : "this number is NOT fractional\n";
	cout << res;
	*/
	
	//rand
	//1
	/*
	string question;
	cout << "enter your question:\n";
	cin >> question;
	srand(time(0));
	int num = rand() % 6;

	switch (num)
	{
	case 0:
		cout << "yes\n";
		break;
	case 1:
		cout << "no\n";
		break;
	case 2:
		cout << "50/50\n";
		break;
	case 3:
		cout << "most likely NO\n";
		break;
	case 4:
		cout << "most likely\n";
		break;
	case 5:
		cout << "i don't know\n";
		break;
	}
	*/

	/*
	int day, month, year;
	cout << "hii, enter day.month.year: \n";
	cin >> day >> month >> year;

	if (day == 31 && month == 1 || day == 31 && month == 3 || day == 31 && month == 5 || day == 31 && month == 7 || day == 31 && month == 8 || day == 31 && month == 10) // 1 3 5 7 8 10 12
	{
		day = 1;
		month++;
	}
	else if (day == 30 && month == 4 || day == 30 && month == 6 || day == 30 && month == 9 || day == 30 && month == 11) // 4 6 9 11
	{
		day = 1;
		month++;
	}
	else if (day == 29 && month == 2 && year % 4 == 0 || day == 28 && month == 2 && year % 4 != 0)
	{
		day = 1;
		month++;
	}
	else if (day == 31 && month == 12)
	{
		day = 1;
		month++;
		year++;
	}
	else
	{
		day++;
	}

	cout << "tomorrow will be " << day << '.' << month << '.' << year << "\n";
	*/

	/*
	SetConsoleOutputCP(65001);
    wcout.imbue(locale(".UTF-8"));
	int choice;
	wcout << L"1ый вопрос:\nКакого газа больше в атмосфере Земли?\n"
		<< L"1.Кислород\n2.Водорода\n3.Углекислого газа\n4.Азота\n";
	cin >> choice;

	if (choice == 4)
		wcout << L"Правильно! Перейдем к следующему вопросу\n\n";
	else
		return 0;

	wcout << L"2\nКакой город считается родиной джаза?\n"
		<< L"1.Новый Орлеан\n2.Чикаго\n3.Нью-Йорк\n4.Сан-Франциско\n";
	cin >> choice;

	if (choice == 1)
		wcout << L"Правильно! Перейдем к следующему вопросу\n\n";
	else
		return 0;

	wcout << L"3\nСколько кубиков в кубике Рубика?\n"
		<< L"1.22\n2.24\n3.26\n4.28\n";
	cin >> choice;

	if (choice == 3)
		wcout << L"Правильно! Перейдем к следующему вопросу\n\n";
	else
		return 0;

	wcout << L"4\nСколько морей омывают Балканский полуостров?\n"
		<< L"1.3\n2.4\n3.5\n4.6\n";
	cin >> choice;

	if (choice == 4)
		wcout << L"Правильно! Перейдем к следующему вопросу\n\n";
	else
		return 0;
	
	wcout << L"4\nЧто означает гавайское слово «вики», которое дало название интернет-энциклопедии «Википедия»?\n"
		<< L"1.Простой\n2.Быстрый\n3.Изученный\n4.Маленький\n";
	cin >> choice;

	if (choice == 2)
		wcout << L"Правильно! Перейдем к следующему вопросу\n\n";
	else
		return 0;
	*/

		
}
		