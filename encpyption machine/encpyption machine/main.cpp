/*
	��� ������� ������� �������� �������������� ����������:
	�������������� ���������� �� ������ 0x00007FF8F7EA7A41 (ucrtbased.dll) 
	� encpyption machine.exe: 0xC0000005:
	��������� ���� ������� ��� ������ �� ������ 0x0000000000000000.
	======================================================================
	��� ��������, � ���������� ��������
*/

// ����������
#include <iostream>
#include <string>
#include <tchar.h>
#include <Windows.h>
#if !defined(__cplusplus)
#error C++ compiler required
#endif
// ������� �������������
#define _STD_USE_ using namespace std;

_STD_USE_

// ��������� ������� SetWindowsPos � ������������ ����� Microsoft
/*
BOOL SetWindowPos(

HWND hWnd,            // ���������� ����
HWND hWndInsertAfter, // ���������� ������� ����������
int x,                // ������� �� �����������
int y,                // ������� �� ���������
int cx,               // ������
int cy,               // ������
UINT uFlags           // ������ ���������������� ����

);
*/

// ������������ ��� �������
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

// �������
void start() {
	string hello = "\t\t\t\t������ ������������ ������ ������� ������ ���� ����� �������.";
	for (int i = 0; i < hello.size(); i++) {
		cout << hello[i];
		Sleep(100);
	}
}

// ���������� � ������������
string encryption() {
	cout << "\n���� ������ � ��������� �����!\n";
	char rualf[] = { '�','�','�','�','�','�','�','�','�','�', '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�', '�', '�', '�','�','�',' ' };
	char rualf1[] = { '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�', '�', '�','�','�','�','�','�',' ' };
	char str_user[32];

	int k = 0, n = 0, m = 0;

	cout << "������� ������: "; //����
	cin.getline(str_user, 32);

	cout << "�������� ����������...\n";
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

	cout << "������������� ���������: " << str_user << endl;
	Sleep(1000);
	cout << "�������� ������������...\n";
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
	cout << "������������ ��������.\n���������: ";
	cout << str_user << endl;
	return 0;
}

// ����� �����
INT _tmain(INT argc, CHAR *argv[]) {
	_config(); // ��������� ������������ �������
	MoveWindow(450, 300); // x, y - WinAPI, ���������� ������� ������� ��� ������������� �� ��������
	start();
	encryption();
	return NULL;
}