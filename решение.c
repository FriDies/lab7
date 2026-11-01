#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int determine_char_type(char c);
float calculator(float x, char op, float y);
void print_day(int day_num);

int main()
{
	setlocale(LC_CTYPE, "RUS");
	printf("=== Задание 1 ===\n");
	char input_char;
	printf("Введите символ: ");
	scanf(" %c", &input_char);

	int char_type = determine_char_type(input_char);

	switch (char_type)
	{
	case 1:
		printf("Это цифра\n");
		break;
	case 2:
		printf("Это буква\n");
		break;
	default:
		printf("Неизвестный символ\n");
		break;
	}

	printf("\n=== Задание 2 ===\n");
	float a, b;
	char operation;
	printf("Введите выражение (например, 3+3 или 6.7*2): ");
	scanf("%f %c %f", &a, &operation, &b);

	if (operation == '/' && b == 0.0f)

	{
		printf("Ошибка: деление на ноль\n");
	}

	else if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '^')

	{
		printf("Ошибка: неизвестная операция\n");
	}

	else

	{
		float result = calculator(a, operation, b);
		printf("=%.2f\n", result);
	}

	printf("\n=== Домашнее задание ===\n");
	int day;
	printf("Введите номер дня недели (1-7): ");
	scanf("%d", &day);
	print_day(day);

	return 0;
}

int determine_char_type(char c)
{
	int ans;
	switch (c)
	{
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		ans = 1;
		break;
	default:
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

		{
			ans = 2;
		}

		else

		{
			ans = 0;
		}

		break;

	}

	return ans;

}

float calculator(float x, char op, float y)

{
	float ans = 0.0f;
	switch (op) 
	
	{
	case '+': ans = x + y; break;
	case '-': ans = x - y; break;
	case '*': ans = x * y; break;
	case '/': ans = x / y; break;
	case '^': ans = powf(x, y); break;

	default: ans = 0.0f; break;
	}

	return ans;

}

void print_day(int day_num)

{

	switch (day_num) 
	{

	case 1:
		printf("Понедельник. До воскресенья осталось 6 дней\n");
		break;
	case 2:
		printf("Вторник. До воскресенья осталось 5 дней\n");
		break;
	case 3:
		printf("Среда. До воскресенья осталось 4 дня\n");
		break;
	case 4:
		printf("Четверг. До воскресенья осталось 3 дня\n");
		break;
	case 5:
		printf("Пятница. До воскресенья осталось 2 дня\n");
		break;
	case 6:
		printf("Суббота. До воскресенья осталось 1 день\n");
		break;
	case 7:
		printf("Воскресенье. Воскресенье сегодня\n");
		break;
	default:
		printf("Ошибка: неверный номер дня недели (должно быть 1-7)\n");
		break;
	}

}