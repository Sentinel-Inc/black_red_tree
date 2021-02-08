// rozszerzenie funkcjonalnosci klasy obraz
// pozwala na odczyt plików .ppm
// informacje o poszczegulnych pixelach buduj¹cych wczytywany obraz
// znajduj¹ siê w polu image 

//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//


#pragma once 
#ifndef PPM_H
#define PPM_H

#include "pixel_24bit.h"
#include <string>
#include <vector>
#include <fstream>

#include "file_exception.h"
extern bool is_comment(const char&);
const enum format {
	ascii = 0,
	binary = 1
};
class ppm
{
public:

	ppm() = delete;

	ppm(std::string);
	ppm(size_t, size_t);
	ppm(const ppm&);

	ppm& operator=(const ppm&);


	void read_data_from_file(std::string);
	void save_data_to_file(std::string);
	size_t get_x() { return  x; }
	size_t get_y() { return  y; }
	size_t size() { return x * y; }
	unsigned number_of_color_dimentions() { return 3; } // numer wymiarów potrzebnych do zapisania pojedyñczego koloru
	unsigned get_max_color() { return max_color; }
	unsigned get_pixel_hash(unsigned position) { return image[position].gen_hash(max_color); }

	void set_pixel(const size_t& x, const size_t& y, const pixel_24bit& new_pixel);

private:

	unsigned char check_color(int);
	format read_header(std::fstream&);


protected:

	std::vector<pixel_24bit> image;
	size_t x; // height
	size_t y; // width
	unsigned max_color; // max_color veluestored by one pixel 

};
#endif
