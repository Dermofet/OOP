#include <cstring>
#include "BigBin.h"
#include "Error.h"

BigBin::BigBin(long num)
{
	_length = utils::getPower(num, 2);
	if (BigBin::get_length() > MAX_SIZE - 1) {
		BigBin::set_length(0);
		throw Error("The number is very big. Please input another number.");
	}
	BigBin::set_bin(utils::toBinCode(num, MAX_SIZE));
}
BigBin::BigBin(char* num)
{
	char* end = nullptr;
	long buf = strtol(num, &end, 10);
	BigBin::set_length(utils::getPower(num, 2));
	if (BigBin::get_length() > MAX_SIZE - 1) {
		BigBin::set_length(0);
		throw Error("The number is very big. Please, input another number.");
	}
	BigBin::set_bin(utils::toBinCode(num, MAX_SIZE));
}
BigBin::BigBin(const char* num)
{
	char* end = nullptr;
	long buf = strtol(num, &end, 10);
	BigBin::set_length(utils::getPower(num, 2));
	if (BigBin::get_length() > MAX_SIZE - 1) {
		BigBin::set_length(0);
		throw Error("The number is very big. Please, input another number.");
	}
	BigBin::set_bin(utils::toBinCode(num, MAX_SIZE));
}

char* BigBin::get_bin() const
{
	char* res = new char[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++) {
		res[i] = BigBin::_bin[i];
	}
	return res;
}

void BigBin::set_length(unsigned short l) {
	char* buf = nullptr;
	if (BigBin::_length >= l) buf = utils::rightShift(BigBin::_bin, BigBin::_length, l);
	else buf = utils::leftShift(BigBin::_bin, BigBin::_length, l);
	for (int i = 0; i < BigBin::_length; i++) {
		BigBin::_bin[i] = buf[i];
	}
	BigBin::_length = l;
}
void BigBin::set_bin(char* b)
{
	memset(b, '0', MAX_SIZE);
	int size = strlen(b);
	for (int i = 0; i < size; i++) _bin[i] = b[i];
	_length = utils::countBinDigits(b, size);
}

char* BigBin::toAddCode()
{
	return utils::toAddCode(BigBin::get_bin(), MAX_SIZE);
}

char* BigBin::sumPosPos(char* a, char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '0';

	return res;
}
char* BigBin::sumPosPos(const char* a, char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '0';

	return res;
}
char* BigBin::sumPosPos(char* a, const char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '0';

	return res;
}
char* BigBin::sumPosPos(const char* a, const char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '0';

	return res;
}

char* BigBin::sumNegMorePos(char* a, char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '1';
	res = utils::invertCode(res, MAX_SIZE);
	for (int i = MAX_SIZE - 1; i > 0; i--) {
		if (res[i] == '1') res[i] = '0';
		else {
			res[i] = '1';
			break;
		}
	}
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");

	return res;
}
char* BigBin::sumNegMorePos(const char* a, char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '1';
	res = utils::invertCode(res, MAX_SIZE);
	for (int i = MAX_SIZE - 1; i > 0; i--) {
		if (res[i] == '1') res[i] = '0';
		else {
			res[i] = '1';
			break;
		}
	}
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");

	return res;
}
char* BigBin::sumNegMorePos(char* a, const char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '1';
	res = utils::invertCode(res, MAX_SIZE);
	for (int i = MAX_SIZE - 1; i > 0; i--) {
		if (res[i] == '1') res[i] = '0';
		else {
			res[i] = '1';
			break;
		}
	}
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");

	return res;
}
char* BigBin::sumNegMorePos(const char* a, const char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '1';
	res = utils::invertCode(res, MAX_SIZE);
	for (int i = MAX_SIZE - 1; i > 0; i--) {
		if (res[i] == '1') res[i] = '0';
		else {
			res[i] = '1';
			break;
		}
	}
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");

	return res;
}

char* BigBin::sumNegLessPos(char* a, char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '0';
	res = utils::invertCode(res, MAX_SIZE);
	for (int i = MAX_SIZE - 1; i > 0; i--) {
		if (res[i] == '1') res[i] = '0';
		else {
			res[i] = '1';
			break;
		}
	}
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");

	return res;
}
char* BigBin::sumNegLessPos(const char* a, char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '0';
	res = utils::invertCode(res, MAX_SIZE);
	for (int i = MAX_SIZE - 1; i > 0; i--) {
		if (res[i] == '1') res[i] = '0';
		else {
			res[i] = '1';
			break;
		}
	}
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");

	return res;
}
char* BigBin::sumNegLessPos(char* a, const char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '0';
	res = utils::invertCode(res, MAX_SIZE);
	for (int i = MAX_SIZE - 1; i > 0; i--) {
		if (res[i] == '1') res[i] = '0';
		else {
			res[i] = '1';
			break;
		}
	}
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");

	return res;
}
char* BigBin::sumNegLessPos(const char* a, const char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '0';
	res = utils::invertCode(res, MAX_SIZE);
	for (int i = MAX_SIZE - 1; i > 0; i--) {
		if (res[i] == '1') res[i] = '0';
		else {
			res[i] = '1';
			break;
		}
	}
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");

	return res;
}

char* BigBin::sumNegNeg(char* a, char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '1';

	return res;
}
char* BigBin::sumNegNeg(const char* a, char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '1';

	return res;
}
char* BigBin::sumNegNeg(char* a, const char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '1';

	return res;
}
char* BigBin::sumNegNeg(const char* a, const char* b)
{
	char* res = utils::sumBin(a, b, MAX_SIZE + 1);
	if (res[MAX_SIZE] != '/') throw Error("The result is very big. It is not recorded.");
	res[0] = '1';

	return res;
}

BigBin BigBin::sum(BigBin b)
{
	char* res = nullptr;
	char* _a = BigBin::toAddCode();
	char* _b = b.toAddCode();

	bool a_more_b = utils::moreAbs(BigBin::get_bin(), MAX_SIZE, b.get_bin(), MAX_SIZE);

	try {
		if (_a[0] == '0' && _b[0] == '0') {
			res = BigBin::sumPosPos(_a, _b);
		}
		else if (_a[0] == '1' && _b[0] == '1') {
			res = BigBin::sumNegNeg(_a, _b);
		}
		else {
			if (_a[0] == '0' && _b[0] == '1' && a_more_b) {
				res = BigBin::sumNegLessPos(_a, _b);
			}
			else if (_a[0] == '0' && _b[0] == '1' && !a_more_b) {
				res = BigBin::sumNegMorePos(_a, _b);
			}
			else if (_a[0] == '1' && _b[0] == '0' && a_more_b) {
				res = BigBin::sumNegMorePos(_b, _a);
			}
			else if (_a[0] == '1' && _b[0] == '0' && !a_more_b) {
				res = BigBin::sumNegLessPos(_b, _a);
			}
		}
	}
	catch (Error& err) {
		std::cerr << err.what() << std::endl;
		return *this;
	}
	
	BigBin result;
	result.set_bin(res);
	delete[] res, _a, _b;

	return result;
}

void BigBin::input(std::istream& in)
{
	char* mas = new char[MAX_SIZE];
	in >> mas;

	char* end = nullptr;
	long buf = strtol(mas, &end, 10);
	if (end && end[0] != '\0') {
		throw Error("Error input!");
	}

	_length = utils::getPower(buf, 2);
	if (BigBin::get_length() > MAX_SIZE - 1) {
		_length = 0;
		throw Error("The number is very big. Please input another number.");
	}

	char* _b = utils::toBinCode(buf, MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++) _bin[i] = _b[i];
	delete[] _b;
}

void BigBin::showInfo()
{
	std::cout << "Number: " << utils::BinToDec(BigBin::get_bin(), MAX_SIZE) << std::endl;
	std::cout << "Binary form: " << BigBin::_bin[0] << ".";
	for (int i = 1; i < MAX_SIZE; i++) {
		std::cout << BigBin::_bin[i];
	}
	std::cout << "\nLength: " << BigBin::_length << std::endl << std::endl;
}

std::istream& operator>>(std::istream &in, BigBin& bin)
{
	try {
		bin.input(in);
	}
	catch (Error& err) {
		std::cerr << err.what() << std::endl;
	}
	return in;
}
std::ostream& operator<<(std::ostream &out, BigBin& bin)
{
	for (int i = 0; i < MAX_SIZE + 1; i++) {
		out << bin._bin[i];
	}
	out << std::endl;
	return out;
}

BigBin operator+(BigBin a, BigBin b)
{
	return a.sum(b);
}
BigBin& BigBin::operator++()
{
	*this = BigBin::sum(BigBin("1"));
	return *this;
}
BigBin& BigBin::operator++(int d)
{
	BigBin tmp(*this);
	BigBin::operator++();
	return tmp;
}
BigBin& BigBin::operator--()
{
	*this = BigBin::sum(BigBin("-1"));
	return *this;
}
BigBin& BigBin::operator--(int d)
{
	BigBin tmp(*this);
	BigBin::operator--();
	return tmp;
}
BigBin& BigBin::operator=(const BigBin d)
{
	char* _d = d.get_bin();
	for (int i = 0; i < MAX_SIZE; i++) this->_bin[i] = _d[i];
	delete[] _d;
	return *this;
}