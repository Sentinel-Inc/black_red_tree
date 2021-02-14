// klasa pair opisuje pare liczb w ktorej pierwsza wartosc jest znaczaca, porownywana 
// druga wartosc nie ma zadnych przywilejow
// 
// Autor: Piotr Drabik				Data: 04.02.2021

#pragma once
#ifndef PAIR_H
#define PAIR_H

namespace my {

	template<class KEY, class VAL>

	class pair {
		using Pair = pair<KEY, VAL>;


	public:
		Pair() {
			first = {};  // oszustwo jezyka c 
			second = {}; // poniewaz w parze moga znalezc sie dowolne typy zmiennych zwykly null na wartosc zerowa nie wystarcza
		};		     

		// kostruktor kopiujacy generowany jest automatycznie

		Pair(KEY x, VAL y) 		{

			first = x;
			second = y;

		}


		Pair(const KEY& x) 
		{

			first = x;
			second = {};

		}

		Pair(const Pair& y) {
			first = y.first;
			second = y.second;
		};
		Pair& operator=(const Pair& y) {
			if (this == &y) return *this;
			first = y.first;
			second = y.second;
			return *this;

		}
		bool operator==(const Pair& rhs) const { return first == rhs.first; };
		bool operator!=(const Pair& rhs) const { return first != rhs.first; };
		bool operator< (const Pair& rhs) const { return first < rhs.first; };
		bool operator> (const Pair& rhs) const { return first > rhs.first; };
		bool operator<=(const Pair& rhs) const { return first <= rhs.first; };
		bool operator>=(const Pair& rhs) const { return first >= rhs.first; };
		~pair<KEY, VAL>() = default;

	public: // pola nalezace do tej klasy sa public by imitowac zachowanie std::pair
		// i jest do nich latwiejszy dostep tym sposobem
		KEY first; // key 
		VAL second; // value


	};


#endif // !PAIR_H











}