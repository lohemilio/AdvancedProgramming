#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <Windows.h>

/*
HMODULE LoadLibraryA(
	LPCSTR P13
);
*/

int main()
{
	HINSTANCE Library;
	typedef int (asciiBinaryToInt)(char*);
	typedef int (asciiHexToInt)(char*);
	
	asciiBinaryToInt* ptrFuncBinToInt = 0;
	asciiHexToInt* ptrFuncHexToInt = 0;
	
	char* s = NULL;
	int iBinToInt = 0;
	int iHexToInt = 0;
	
	if (Library = LoadLibrary("Library.dll")) {
		if (ptrFuncBinToInt = (asciiBinaryToInt*) GetProcAddress(Library, "asciiBinaryToInt")) {
			s = (char*)malloc(sizeof(char) * 9);
			printf("Ingrese el numero binario que desea convertir a decimal: ");
			scanf("%s", s);
			s[8] = '\0';
			iBinToInt = (*ptrFuncBinToInt)(s);
			printf("%d\n", iBinToInt);
			free(s);
		}
		else {
			printf("Error: Routine BIN not found.\n");
		}
		if (ptrFuncHexToInt = (asciiHexToInt*) GetProcAddress(Library, "asciiHEXToInt")) {
			s = (char*)malloc(sizeof(char) * 9);
			printf("Ingrese el numero hexadecimal que desea convertir a decimal: ");
			scanf("%s", s);
			s[8] = '\0';
			iHexToInt = (*ptrFuncHexToInt)(s);
			printf("%d\n", iHexToInt);
			free(s);
		}
		else {
			printf("Error: Routine HEX not found.\n");
		}
	}
	else {
		printf("Error: Library not found.\n");
	}
	FreeLibrary(Library);
	getchar();
	getchar();
	return 0;
}

