#pragma once
#ifndef FC_H
#define FC_H

#include "map.h"
#include <fstream>
template<class T>
class fc {


	fc<T>();
	fc<T>(const fc<T>&);
	
	void save_to_file(const std::string);
	unsigned& operator[](const T&);

	size_t size();
	void add_data(T);




protected:
	my::map<T, unsigned> storage;

};

#endif // !FC_H

template<class T>
inline void fc<T>::save_to_file(const std::string path = "output.txt")
{
	std::fstream plik;
	plik.open(path, std::ios::out);


}

template<class T>
inline unsigned& fc<T>::operator[](const T& key)
{

	return storage[key];

}

template<class T>
inline size_t fc<T>::size()
{
	return storage.size();
}

template<class T>
inline void fc<T>::add_data(T data)
{
	unsigned count =0;
	try {
		count = storage.find(data);

	}
	catch (...) {
		count = 0;

	}

	storage.insert_or_assign(my::pair<T, unsigned>(data, count));


}
