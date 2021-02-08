#pragma once
#ifndef FC_H
#define FC_H

#include "map.h"
#include <fstream>
#include <stdio.h>
#include "ppm.h"
template<class T>
class fc {
public:

	fc<T>();
	fc<T>(const fc<T>&);

	void create(const std::string&);
	void gen_img(const size_t&, const size_t&, const std::string&);
	unsigned& operator[](const T&);
	iterator<fc<T>> begin();
	iterator<fc<T>> end();
	size_t size();
	void add_data(T);




protected:
	my::map<T, unsigned> image;

};

#endif // !FC_H

template<class T>
inline void fc<T>::create(const std::string& path )
{
	std::fstream plik;
	plik.open(path, std::ios::out);
	for (auto i : image) {
		plik << i.get_value().first << "\t" << i.get_value().second << "\n";
	}
	plik.close();
}
template<>
inline void fc<std::wstring>::create(const std::string& path)
{
	std::wfstream plik;
	plik.open(path, std::ios::out);
	for (auto i : image) {
		for (auto j : i.get_value().first) plik << j;
		plik << "\t" << i.get_value().second << "\n";
	}
	plik.close();
}
template<>
inline void fc<std::string>::create(const std::string& path)
{
	std::fstream plik;
	plik.open(path, std::ios::out);
	for (auto i : image) {
		for (auto j : i.get_value().first) plik << j;
		plik << "\t" << i.get_value().second << "\n";
	}
	plik.close();
}




template<>
inline void fc<int>::gen_img(const size_t& img_x, const size_t& img_y, const std::string& file_path)
{
	pixel_24bit red(255, 0, 0);
	ppm graph(img_x, img_y);
	size_t x_position = 0;
	for (auto i : image) {
		for (unsigned j = 0; j < i.get_value().second; j++) {
			graph.set_pixel(x_position, j, red);


		}
		x_position++;

	}
	graph.save_data_to_file(file_path);
}

template<class T>
inline unsigned& fc<T>::operator[](const T& key)
{

	return image[key];

}

template<class T>
inline iterator<fc<T>> fc<T>::begin()
{
	return iterator<fc<T>>(image.begin());
}

template<class T>
inline iterator<fc<T>> fc<T>::end()
{
	return iterator<fc<T>>(image.end());
}

template<class T>
inline size_t fc<T>::size()
{
	return image.size();
}

template<class T>
inline void fc<T>::add_data(T key)
{
	unsigned count = 1;
	try {
		count += image.find(key);
	}
	catch (const out_of_range&) {
		// in this case we ignore out_of_range statement
	}
	image.insert_or_assign(key, count);



}


template<class T>
inline fc<T>::fc()
{
	image;
}

template<class T>
inline fc<T>::fc(const fc<T>& other)
{
	image = other.image;
}

template<class T>
void get_characters(std::string path, fc<T>& counter) {

	T temp;

	std::ifstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		assert(0);
		return;
	}
	while (plik.good()) {
		plik >> temp;
		counter.add_data(temp);

	}
	plik.close();

}
template<>
void get_characters(std::string path, fc<wchar_t>& counter) {

	wchar_t temp;

	std::wifstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		assert(0);
		return;
	}
	while (plik.good()) {
		plik >> temp;
		counter.add_data(temp);

	}
	plik.close();

}
template<>
void get_characters(std::string path, fc<std::wstring>& counter) {

	wchar_t temp;
	std::wstring sentence;
	std::wifstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		assert(0);
		return;
	}
	while (plik.good()) {
		while (2 > 1) {
			plik >> temp;
			if (temp == ' ' || temp == '\n' || temp == '\t') break;
			sentence.push_back(temp);
		}
		counter.add_data(sentence);
		sentence.clear();
	}
	plik.close();

}

template<>
void get_characters(std::string path, fc<std::string>& counter) {

	char temp;
	std::string sentence;
	std::ifstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		assert(0);
		return;
	}
	while (plik.good()) {
		while (2 > 1) {
			plik >> temp;
			if (temp == ' ' || temp == '\n' || temp == '\t') break;
			sentence.push_back(temp);
		}
		counter.add_data(sentence);
		sentence.clear();
	}
	plik.close();

}