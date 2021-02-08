// klasa _24_bit_pixel przecowywuje kolor pixela w rozdzielczoœæi true collor
// czyli na ka¿dy pixel na zdjêciu poœwiêcane s¹ 3 bajty informacji 
// pozwala to na uzyskanie 16777216 kolorów 
//
//
//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//
#pragma once
#ifndef _24BIT_PIXEL_H
#define _24BIT_PIXEL_H
#include <cmath>

#include<iostream>
class pixel_24bit
{
public:

	pixel_24bit() :r(NULL), g(NULL), b(NULL) {};

	pixel_24bit(unsigned char r, unsigned char g, unsigned char b) :r(r), g(g), b(b) {};


	// konstruktor kopiujacy i operator = sa tworzone za nas 

	pixel_24bit(const pixel_24bit& other)
	{
		r = other.r;
		g = other.g;
		b = other.b;
	};

	//pixel_24bit& operator=(const pixel_24bit&);
	// gen_hash przelicza kombinajê liczb r, g ,b i generuje pojedyñcz¹ wartoœæ unikaln¹ dla tej kombinacji

	unsigned gen_hash(const unsigned&);
	

	unsigned char get_r() { return r; }

	unsigned char get_g() { return g; }

	unsigned char get_b() { return b; }


	void set_all(const unsigned char& r, const unsigned char& g, const unsigned char& b) {
		this->r = r; 
		this->g = g;
		this->b = b;
	}

	void set_r(unsigned char r) { this->r = r; }

	void set_g(unsigned char g) { this->g = g; }

	void set_b(unsigned char b) { this->b = b; }

	friend std::ostream& operator << (std::ostream& out, const pixel_24bit& color)
	{
		out << (int)color.r<<' '<< (int)color.g<<' '<< (int)color.b;
		return out;
	}
	bool operator==(const pixel_24bit& rhs) const { return r * 256 * 256 + g * 256 + b == rhs.r*256*256+rhs.g*256+rhs.b; };
	bool operator!=(const pixel_24bit& rhs) const { return r * 256 * 256 + g * 256 + b != rhs.r*256*256+rhs.g*256+rhs.b; };
	bool operator< (const pixel_24bit& rhs) const { return r * 256 * 256 + g * 256 + b <  rhs.r*256*256+rhs.g*256+rhs.b; };
	bool operator> (const pixel_24bit& rhs) const { return r * 256 * 256 + g * 256 + b >  rhs.r*256*256+rhs.g*256+rhs.b; };
	bool operator<=(const pixel_24bit& rhs) const { return r * 256 * 256 + g * 256 + b <= rhs.r*256*256+rhs.g*256+rhs.b; };
	bool operator>=(const pixel_24bit& rhs) const { return r * 256 * 256 + g * 256 + b >= rhs.r*256*256+rhs.g*256+rhs.b; };

protected:
	unsigned char r, g, b;
	// wartoœæi r,g,b w jakoœci true collor mog¹ nale¿eæ do zakresu 0 - 255 



};

#endif // !_24BIT_PIXEL_H