#include <iostream>
#include "utils.h"
#define MAX_SIZE 10

class BigBin
{
private:
	unsigned short _length;
	char _bin[MAX_SIZE];
public:
	BigBin(long num = 0);
	BigBin(char*);
	BigBin(const char*);

	//Getters
	inline unsigned short get_length() const { return _length; };
	char* get_bin() const;

	//Setters
	void set_length(unsigned short l);
	void set_bin(char* b);

	//another functions
	char* toAddCode();

	char* sumPosPos(char* a, char* b);
	char* sumPosPos(const char* a, char* b);
	char* sumPosPos(char* a, const char* b);
	char* sumPosPos(const char* a, const char* b);

	char* sumNegMorePos(char* a, char* b);
	char* sumNegMorePos(const char* a, char* b);
	char* sumNegMorePos(char* a, const char* b);
	char* sumNegMorePos(const char* a, const char* b);

	char* sumNegLessPos(char* a, char* b);
	char* sumNegLessPos(const char* a, char* b);
	char* sumNegLessPos(char* a, const char* b);
	char* sumNegLessPos(const char* a, const char* b);

	char* sumNegNeg(char* a, char* b);
	char* sumNegNeg(const char* a, char* b);
	char* sumNegNeg(char* a, const char* b);
	char* sumNegNeg(const char* a, const char* b);

	BigBin sum(BigBin a);

	void input(std::istream& in);
	void showInfo();

	//operators
	friend std::istream& operator>>(std::istream& in, BigBin& bin);
	friend std::ostream& operator<<(std::ostream& in, BigBin& bin);
	friend BigBin operator+(BigBin a, BigBin b);
	BigBin& operator++();
	BigBin& operator++(int d);
	BigBin& operator--();
	BigBin& operator--(int d);
	BigBin& operator=(const BigBin d);
};