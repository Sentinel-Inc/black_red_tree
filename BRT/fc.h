#pragma once
#ifndef FC_H
#define FC_H

#include "map.h"
#include <fstream>

template<class T>
class fc {
public:

	fc<T>();
	fc<T>(const fc<T>&);

	void save_to_file(const std::string);
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
inline void fc<T>::save_to_file(const std::string path = "output.txt")
{
	std::fstream plik;
	plik.open(path, std::ios::out);
	for (auto i : image) {
		plik << i.get_value().first << "\t" << i.get_value().second << "\n";
	}
	plik.close();
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
	count += image.find(key);
	


	image.insert_or_assign(key, count);



}


template<class T>
void get_numbers(std::string path,  fc<T>& counter) {

	int temp;

	std::fstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		return;
	}

	while (!plik.eof()) {
		plik >> temp;

		counter.add_data(temp);
	}
	plik.close();
}
template<>
void get_numbers(std::string path, fc<double>& counter) {

	double temp;

	std::fstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		return;
	}

	while (!plik.eof()) {
		plik >> temp;

		counter.add_data(temp);
	}
	plik.close();
}
template<char>
void get_characters(std::string path, fc<char>& counter) {

	char temp;

	std::fstream plik;
	plik.open(path, std::ios::in);
	if (!plik.good()) {
		plik.close();
		return;
	}
	while (plik.good()) {
		plik >> temp;
		counter.add_data(temp);

	}
	plik.close();

}

template<class T>
inline fc<T>::fc<T>()
{
	image;
}

template<class T>
inline fc<T>::fc<T>(const fc<T>&other)
{
	image = other.image;
}

//template<class T>
//void get_numbers(std::string path, fc<T>& counter) {
//
//	int temp;
//
//	std::fstream plik;
//	plik.open(path, std::ios::in);
//	if (!plik.good()) {
//		plik.close();
//		return;
//	}
//
//	while (!plik.eof()) {
//		plik >> temp;
//
//		counter.add_data(temp);
//	}
//	plik.close();
//}
//template<>
//void get_numbers(std::string path, fc<double>& counter) {
//
//	double temp;
//
//	std::fstream plik;
//	plik.open(path, std::ios::in);
//	if (!plik.good()) {
//		plik.close();
//		return;
//	}
//
//	while (!plik.eof()) {
//		plik >> temp;
//
//		counter.add_data(temp);
//	}
//	plik.close();
//}
//template<char>
//void get_characters(std::string path, const fc<char>& counter) {
//
//	char temp;
//
//	std::fstream plik;
//	plik.open(path, std::ios::in);
//	if (!plik.good()) {
//		plik.close();
//		return;
//	}
//	while (plik.good()) {
//		plik >> temp;
//		counter.add_data(temp);
//
//	}
//	plik.close();
//
//}
