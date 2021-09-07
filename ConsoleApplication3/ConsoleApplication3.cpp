#include <iostream>
#include<stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;
int main()
{
	
	int intRead = 0;

	SIZE_T bytesRead = 0;

	cout << "PID: ";

	int pid;

	cin >> pid;
	
	
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	uintptr_t memoryAddress;
	//cout << "Memory location: ";
	memoryAddress = 0x0E34DC8C; //HARDCODED because i couldnt get the line underneath to work. THIS NEEDS TO BE CHANGED OR GET THE LINE UNDERNEATH TO WORK FOR THIS TO WORK WITH PART1
	//cin >> hex >> memoryAddress;
	
	BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)memoryAddress, &intRead, sizeof(int), NULL);

	if (rpmReturn == FALSE) {

		cout << "ReadProcessMemory failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	
		//printf("the value of varINT is %d\n", intRead);
	
	if (rpmReturn == TRUE) {
		int intToWrite;
		cout << "intToWrite: ";
		
		cin >>dec>> intToWrite;
		BOOL wpmReturn = WriteProcessMemory(hProcess, (LPVOID)memoryAddress, &intToWrite, sizeof(int), NULL);
		
		if(wpmReturn==true) {
			do {
				printf("overwrite successful");
				uintptr_t memoryAddress = 0x0E34DC8C;
				printf("the value of varINT is %d\n", intToWrite);
			} while (getchar());
		}


	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
