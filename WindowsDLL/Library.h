#pragma once

#define Library_API __declspec(dllexport)

extern "C" Library_API int asciiBinaryToInt(char* s);

extern "C" Library_API int asciiHEXToInt(char* s);

