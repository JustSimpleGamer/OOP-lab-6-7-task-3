#pragma once

#include "Libraries.h"

class MyStreambuf :public streambuf
{
public:
	MyStreambuf(streambuf* _firstBuf, streambuf* _secondBuf) :firstBuf(_firstBuf), secondBuf(_secondBuf) {}
	streamsize xsputn(const char_type* s, streamsize n)
	{
		firstBuf->sputn(s, n);
		secondBuf->sputn(s, n);
		return n;
	}

	int overflow(int_type c)
	{
		firstBuf->sputc(c);
		secondBuf->sputc(c);
		return c;
	}

	~MyStreambuf();

private:
	streambuf* firstBuf;
	streambuf* secondBuf;
};