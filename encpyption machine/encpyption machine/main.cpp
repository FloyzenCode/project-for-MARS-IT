/*
	При запуска проекта возможно необработанное исключение:
	Необработанное исключение по адресу 0x00007FF8F7EA7A41 (ucrtbased.dll) 
	в encpyption machine.exe: 0xC0000005:
	нарушение прав доступа при чтении по адресу 0x0000000000000000.
	======================================================================
	Код работает, в дальнейшем пофиксим
*/

// Библиотеки
#include <iostream>
#include <string>
#include <tchar.h>
#include <Windows.h>
#if !defined(__cplusplus)
#error C++ compiler required
#endif
// Команды препроцессору
#define _STD_USE_ using namespace std;

_STD_USE_

// Структура функции SetWindowsPos с официального сайта Microsoft
/*
BOOL SetWindowPos(

HWND hWnd,            // дескриптор окна
HWND hWndInsertAfter, // дескриптор порядка размещения
int x,                // позиция по горизонтали
int y,                // позиция по вертикали
int cx,               // ширина
int cy,               // высота
UINT uFlags           // флажки позиционирования окна

);
*/

// конфигурация для проекта
void _config(void) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
	LPCWSTR title_window = L"Encryption Application";
	SetConsoleTextAttribute(console, color);
	SetConsoleTitle(title_window);
	setlocale(NULL, "");
	system("chcp 1251 > null");
}

void MoveWindow(int posx, int posy)
{
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void MoveCenter()
{
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	int posx, posy;
	posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
		posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2,

		MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

// Функции
void start() {
	string hello = "\t\t\t\tПроект Шифровальная машина методом замены букв через массивы.";
	for (int i = 0; i < hello.size(); i++) {
		cout << hello[i];
		Sleep(100);
	}
}

// Шифрование и дешифрование
string encryption() {
	cout << "\nВвод только с маленькой буквы!\n";
	char rualf[] = { 'а','б','в','г','д','е','ё','ж','з','и', 'й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ь', 'ы', 'ъ', 'э','ю','я',' ' };
	char rualf1[] = { 'х','ц','э','ъ','ы','ь','щ','ш','ч','ю','я','ф','п','н','с','р','у','т','о','м','б','к','й','ё','з','ж', 'и', 'е','д','г','а','л','в',' ' };
	char str_user[32];

	int k = 0, n = 0, m = 0;

	cout << "Введите строку: "; //Ввод
	cin.getline(str_user, 32);

	cout << "Начинаем шифрование...\n";
	Sleep(1000);

	for (k = 0; k < strlen(str_user); k++)
	{
		for (n = 0; n < strlen(rualf); ++n)
		{
			if (str_user[k] == rualf[n])
			{
				str_user[k] = rualf1[n];
				break;
			}
		}
	}

	cout << "Зашифрованное сообщение: " << str_user << endl;
	Sleep(1000);
	cout << "Начинаем дешифрование...\n";
	Sleep(1000);
	for (k = 0; k < strlen(str_user); k++)
	{

		for (n = 0; n < strlen(rualf1); ++n)
		{
			if (str_user[k] == rualf1[n])
			{
				str_user[k] = rualf[n];
				break;
			}
		}

	}
	cout << "Дешифрование окончено.\nРезультат: ";
	cout << str_user << endl;
	return 0;
}

// Точка входа
INT _tmain(INT argc, CHAR *argv[]) {
	_config(); // применяем конфигурацию проекта
	MoveWindow(450, 300); // x, y - WinAPI, координаты запуска консоли для центрирования на мониторе
	start();
	encryption();
	return NULL;
}