#include <iostream>
#include <cstdlib>
#include "utils.h"

char* utils::toBinCode(long num, int size)
{
	char* res = new char[size];
	if (num < 0) {
		num = -num;
		res[0] = '1';
	} 
	else res[0] = '0';
	for (int i = size - 1; i > 0; i--) {
		res[i] = (char)((num % 2) + (int)'0');
		num /= 2;
	}
	return res;
}
char* utils::toBinCode(char* num, int size)
{
	char* end = nullptr;
	long long buf = strtol(num, &end, 10);
	char* res = new char[size];
	if (buf < 0) {
		buf = -buf;
		res[0] = '1';
	}
	for (int i = size - 1; i > 0; i--) {
		res[i] = (char)((buf % 2) + (int)'0');
		buf /= 2;
	}
	return res;
}
char* utils::toBinCode(const char* num, int size)
{
	char* end = nullptr;
	long long buf = strtol(num, &end, 10);
	char* res = new char[size];
	if (buf < 0) {
		buf = -buf;
		res[0] = '1';
	}
	for (int i = size - 1; i > 0; i--) {
		res[i] = (char)((buf % 2) + (int)'0');
		buf /= 2;
	}
	return res;
}

unsigned short utils::getPower(long long num, int pow)
{
	unsigned short res = 0;
	if (num < 0) num = -num;
	while (num > 0) {
		res++;
		num /= pow;
	}
	return res;
}
unsigned short utils::getPower(char* num, int pow)
{
	char* end = nullptr;
	long long buf = strtol(num, &end, 10);
	unsigned short res = 0;
	while (buf > 0) {
		res++;
		buf /= pow;
	}
	return res;
}
unsigned short utils::getPower(const char* num, int pow)
{
	char* end = nullptr;
	long long buf = strtol(num, &end, 10);
	unsigned short res = 0;
	while (buf > 0) {
		res++;
		buf /= pow;
	}
	return res;
}

unsigned short utils::countBinDigits(char* num, int size)
{
	unsigned short res = 0;
	for (int i = size - 1; i > 0; i--) {
		if (num[i] == '0') res++;
		else res = 0;
	}
	res = size - res;
	return res;
}

bool utils::moreAbs(char* a, int size1, char* b, int size2)
{
	long _a = utils::BinToDec(a, size1);
	if (_a < 0) _a = -_a;
	long _b = utils::BinToDec(b, size2);
	if (_b < 0) _b = -_b;

	if (_a > _b) return true;
	else return false;
}
bool utils::moreAbs(const char* a, int size1, char* b, int size2)
{
	long _a = utils::BinToDec(a, size1);
	if (_a < 0) _a = -_a;
	long _b = utils::BinToDec(b, size2);
	if (_b < 0) _b = -_b;

	if (_a > _b)
		return true;
	else return false;
}
bool utils::moreAbs(char* a, int size1, const char* b, int size2)
{
	long _a = utils::BinToDec(a, size1);
	if (_a < 0) _a = -_a;
	long _b = utils::BinToDec(b, size2);
	if (_b < 0) _b = -_b;

	if (_a > _b)
		return true;
	else return false;
}
bool utils::moreAbs(const char* a, int size1, const char* b, int size2)
{
	long _a = utils::BinToDec(a, size1);
	if (_a < 0) _a = -_a;
	long _b = utils::BinToDec(b, size2);
	if (_b < 0) _b = -_b;

	if (_a > _b)
		return true;
	else return false;
}

char* utils::toAddCode(char* num, int size)
{
	num = utils::invertCode(num, size);
	if (num[0] == '1') {
		for (int i = 1; i < size; i++) {
			if (num[size] == '0') {
				num[size] = '1';
				break;
			}
			else num[size] = '0';
		}
	}
	return num;
}
char* utils::toAddCode(const char* num, int size)
{
	char* _num = utils::invertCode(num, size);
	if (_num[0] == '1') {
		for (int i = 1; i < size; i++) {
			if (_num[size] == '0') {
				_num[size] = '1';
				break;
			}
			else _num[size] = '0';
		}
	}
	return _num;
}

char* utils::invertCode(char* num, int size)
{
	if (num[0] == '1') {
		for (int i = 1; i < size; i++) {
			num[i] == '1' ? num[i] = '0' : num[i] = '1';
		}
	}
	return num;
}
char* utils::invertCode(const char* num, int size)
{
	char* _num = new char[size];
	for (int i = 0; i < size; i++) {
		_num[i] = num[i];
	}

	if (_num[0] == '1') {
		for (int i = 1; i < size; i++) {
			_num[i] == '1' ? _num[i] = '0' : _num[i] = '1';
		}
	}
	return _num;
}

char* utils::sumBin(char* a, char* b, int size)
{
	char* res = new char[size];
	res[size] = '/';

	int r = 0;
	for (int i = size - 1; i > 0; i--) {
		if (a[i] == '1' && b[i] == '1') {
			if (r == 1) res[i] = '1';
			else {
				res[i] = '0';
				r = 1;
			}
		}
		else if (a[i] == '0' && b[i] == '0') {
			if (r == 1) {
				res[i] = '1';
				r = 0;
			}
			else res[i] = '0';
		}
		else {
			if (r == 1) res[i] = '0';
			else res[i] = '1';
		}
	}

	return res;
}
char* utils::sumBin(char* a, const char* b, int size)
{
	char* res = new char[size];
	res[size] = '/';

	int r = 0;
	for (int i = size - 1; i > 0; i--) {
		if (a[i] == '1' && b[i] == '1') {
			if (r == 1) res[i] = '1';
			else {
				res[i] = '0';
				r = 1;
			}
		}
		else if (a[i] == '0' && b[i] == '0') {
			if (r == 1) {
				res[i] = '1';
				r = 0;
			}
			else res[i] = '0';
		}
		else {
			if (r == 1) res[i] = '0';
			else res[i] = '1';
		}
	}

	return res;
}
char* utils::sumBin(const char* a, char* b, int size)
{
	char* res = new char[size];
	res[size] = '/';

	int r = 0;
	for (int i = size - 1; i > 0; i--) {
		if (a[i] == '1' && b[i] == '1') {
			if (r == 1) res[i] = '1';
			else {
				res[i] = '0';
				r = 1;
			}
		}
		else if (a[i] == '0' && b[i] == '0') {
			if (r == 1) {
				res[i] = '1';
				r = 0;
			}
			else res[i] = '0';
		}
		else {
			if (r == 1) res[i] = '0';
			else res[i] = '1';
		}
	}

	return res;
}
char* utils::sumBin(const char* a, const char* b, int size)
{
	char* res = new char[size];
	res[size] = '/';

	int r = 0;
	for (int i = size - 1; i > 0; i--) {
		if (a[i] == '1' && b[i] == '1') {
			if (r == 1) res[i] = '1';
			else {
				res[i] = '0';
				r = 1;
			}
		}
		else if (a[i] == '0' && b[i] == '0') {
			if (r == 1) {
				res[i] = '1';
				r = 0;
			}
			else res[i] = '0';
		}
		else {
			if (r == 1) res[i] = '0';
			else res[i] = '1';
		}
	}

	return res;
}

long utils::BinToDec(char* num, int size)
{
	/*if (num[0] == '1') num = utils::invertCode(num, size);*/
	long pow2 = 1, res = 0;
	for (int i = size - 1; i > 0; i--) {
		res += (int(num[i]) - int('0')) * pow2;
		pow2 *= 2;
	}
	if (num[0] == '1') {
		/*num = utils::invertCode(num, size);*/
		res = -res;
	}
	return res;
}
long utils::BinToDec(const char* num, int size)
{
	if (num[0] == '1') num = utils::invertCode(num, size);
	long pow2 = 1, res = 0;
	for (int i = size - 1; i > 0; i--) {
		res += (int(num[i]) - int('0')) * pow2;
		pow2 *= 2;
	}
	if (num[0] == '1') {
		num = utils::invertCode(num, size);
		res = -res;
	}
	return res;
}

char* utils::rightShift(char* a, int oldL, int newL) {
	int offset = oldL - newL;
	for (int i = 0; i < oldL; i++) {
		if (i < newL) a[i] = a[i + offset];
		else a[i] = '0';
	}
	return a;
}
char* utils::rightShift(const char* a, int oldL, int newL) {
	char* buf = new char[oldL];
	memset(buf, '0', oldL * sizeof(char));
	for (int i = 0; i < oldL; i++) buf[i] = a[i];
	int offset = oldL - newL;
	for (int i = 0; i < oldL; i++) {
		if (i < newL) buf[i] = a[i + offset];
		else break;
	}
	return buf;
}
char* utils::leftShift(char* a, int oldL, int newL)
{
	int offset = newL - oldL;
	for (int i = newL; i >= 0; --i) {
		if (i > offset) a[i] = a[i - offset];
		else a[i] = '0';
	}
	return a;
}
char* utils::leftShift(const char* a, int oldL, int newL)
{
	char* buf = new char[newL];
	memset(buf, '0', newL*sizeof(char));
	for (int i = 0; i < oldL; i++) buf[i] = a[i];
	int offset = newL - oldL;
	for (int i = newL; i > -1; i--) {
		if (i > offset) buf[i] = a[i - offset];
		else break;
	}
	return buf;
}