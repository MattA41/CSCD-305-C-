#ifndef COLORBLOB_H
#define COLORBLOB_H
#include "Color.h"
using namespace std;

class ColorBlob
{
	int width, height;
	Color** data;
public:
	ColorBlob();
	ColorBlob(int w, int h, const Color& c);
	ColorBlob(int w, int h, Color** c);
	ColorBlob(const ColorBlob& cBlob);
	ColorBlob& operator=(const ColorBlob& cBlob);
	ColorBlob(ColorBlob&& cBlob);
	ColorBlob& operator=(ColorBlob&& cBlob);
	ColorBlob :: ~ColorBlob();

	friend bool operator==(const ColorBlob&, const ColorBlob&);
	friend ColorBlob operator+(const ColorBlob& cBlobOne, const ColorBlob& cBlobTwo);
	friend ColorBlob operator-(const ColorBlob& cBlobOne, const ColorBlob& cBlobTwo);
	friend ColorBlob operator*(const ColorBlob& cBlobOne, const Color& c);
	friend bool operator! (const ColorBlob& cBlob);
	friend ostream& operator<<(ostream&, const ColorBlob&);
	friend istream& operator>>(istream&, ColorBlob&);
};



#endif

