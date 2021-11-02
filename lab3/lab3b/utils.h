#pragma once
namespace utils {
	char* toBinCode(long num, int size);
	char* toBinCode(char* num, int size);
	char* toBinCode(const char* num, int size);

	unsigned short getPower(long long num, int pow);
	unsigned short getPower(char* num, int pow);
	unsigned short getPower(const char*, int pow);

	unsigned short countBinDigits(char* num, int size);

	bool moreAbs(char* a, int size1, char* b, int size2);
	bool moreAbs(const char* a, int size1, char* b, int size2);
	bool moreAbs(char* a, int size1, const char* b, int size2);
	bool moreAbs(const char* a, int size1, const char* b, int size2);

	char* toAddCode(char*, int);
	char* toAddCode(const char*, int);

	char* invertCode(char*, int);
	char* invertCode(const char*, int);

	char* sumBin(char* a, char* b, int size);
	char* sumBin(const char* a, char* b, int size);
	char* sumBin(char* a, const char* b, int size);
	char* sumBin(const char* a, const char* b, int size);

	long BinToDec(char* num, int size);
	long BinToDec(const char* num, int size);

	char* rightShift(char* a, int oldL, int newL);
	char* rightShift(const char* a, int oldL, int newL);
	char* leftShift(char* a, int oldL, int newL);
	char* leftShift(const char* a, int oldL, int newL);
}