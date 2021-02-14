// Freaquency Counter (licznik czestotliwosci) 
// licznik dziala na podstawie my::map<K,V>
// gdzie K = typ liczonej zmiennej 
//       V = unsigned int licznik wystapien danej zmiennej 
// Freaquency Counter pozwala tez na zapisywanie zebranych danych do pliku 
//
//
// Autor: Piotr Drabik				Data: 04.02.2021

#pragma once
#ifndef FC_H
#define FC_H
#include <fstream>
#include <stdio.h>
#include "map.h"
#include "file_exception.h"
#include "ppm.h"
exception::invalid_path_exception invalid_path_fc;
template<class T>
class FreaquencyCounter {
public:

	FreaquencyCounter<T>();
	FreaquencyCounter<T>(const FreaquencyCounter<T>&);

	void create(const std::string&); // zapisuje zebrane informacje do pliku textowego 
	void gen_img(const size_t&, const std::string&); // tworzy obraz ppm zebranych danych 
	unsigned& operator[](const T&);
	iterator<FreaquencyCounter<T>> begin(); // funkcje iteratora 
	iterator<FreaquencyCounter<T>> end();
	size_t size();
	void add_data(T);




protected:
	my::map<T, unsigned> image;

};

#endif // !FC_H

template<class T>
inline void FreaquencyCounter<T>::create(const std::string& path)
{
	std::fstream plik;
	plik.open(path, std::ios::out);
	for (auto i : image) {
		plik << i.get_value().first << "\t" << i.get_value().second << "\n";
	}
	plik.close();
}
template<>
inline void FreaquencyCounter<wchar_t>::create(const std::string& path)
{
	std::wfstream plik;
	plik.open(path, std::ios::out);
	for (auto i : image) {
		plik << i.get_value().first << "\t" << i.get_value().second << "\n";
	}
	plik.close();
}

inline void FreaquencyCounter<std::wstring>::create(const std::string& path)
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
inline void FreaquencyCounter<std::string>::create(const std::string& path)
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
inline void FreaquencyCounter<int>::gen_img(const size_t& img_y, const std::string& file_path)
{
	pixel_24bit red(255, 0, 0);
	ppm graph(image.size(), img_y);
	size_t x_position = 0;
	for (auto i : image) {

		for (unsigned j = 0; j < i.get_value().second && j < img_y; j++) {

			graph.set_pixel(x_position, j, red);


		}
		x_position++;

	}
	graph.save_data_to_file(file_path);
}

template<class T>
inline unsigned& FreaquencyCounter<T>::operator[](const T& key)
{

	return image[key];

}

template<class T>
inline iterator<FreaquencyCounter<T>> FreaquencyCounter<T>::begin()
{
	return iterator<FreaquencyCounter<T>>(image.begin());
}

template<class T>
inline iterator<FreaquencyCounter<T>> FreaquencyCounter<T>::end()
{
	return iterator<FreaquencyCounter<T>>(image.end());
}

template<class T>
inline size_t FreaquencyCounter<T>::size()
{
	return image.size();
}

template<class T>
inline void FreaquencyCounter<T>::add_data(T key)
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
inline FreaquencyCounter<T>::FreaquencyCounter()
{}

template<class T>
inline FreaquencyCounter<T>::FreaquencyCounter(const FreaquencyCounter<T>& other)
{
	image = other.image;
}

template<class T>
void get_characters(std::string path, FreaquencyCounter<T>& counter) {

	T temp;

	std::ifstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		throw invalid_path_fc;
		return;
	}
	while (plik.good()) {
		plik >> temp;
		counter.add_data(temp);

	}
	plik.close();

}
template<>
void get_characters(std::string path, FreaquencyCounter<wchar_t>& counter) {

	wchar_t temp;

	std::wifstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		throw invalid_path_fc;
		return;
	}
	while (plik.good()) {
		plik >> temp;
		counter.add_data(temp);

	}
	plik.close();

}
template<>
void get_characters(std::string path, FreaquencyCounter<std::wstring>& counter) {

	wchar_t space = ' ';
	wchar_t newline = '\n';
	wchar_t tab = '\t';
	std::wstring sentence;
	std::wifstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		throw invalid_path_fc;
		return;
	}
	while (plik.good()) {


		plik >> sentence;
		if (!sentence.empty()) counter.add_data(sentence);


	}
	plik.close();

}

template<>
void get_characters(std::string path, FreaquencyCounter<std::string>& counter) {

	char temp;
	std::string sentence;
	std::ifstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		throw invalid_path_fc;
		return;
	}
	while (plik.good()) {
		while (2 > 1) {
			plik >> temp;
			if (temp == ' ' || temp == '\n' || temp == '\t' || !plik.good()) break;
			sentence.push_back(temp);
		}
		counter.add_data(sentence);
		sentence.clear();
	}
	plik.close();

}

template<>
void get_characters(std::string path, FreaquencyCounter<pixel_24bit>& counter) {

	ppm picture(path);
	for (size_t i = 0; i < picture.size(); i++)counter.add_data(picture[i]);

}