#pragma once


#ifndef PAIR_H
#define PAIR_H

namespace my {

	template<class KEY, class VAL>

	class pair {
		using Pair = pair<KEY, VAL>;


	public:
		Pair() {
			first = {};
			second = {};
		};

		Pair(const KEY& x, const VAL& y) //:first(x), second(y) {};
		{
		
			first = x;
			second = y;
		
		}
		Pair(const KEY& x) //:first(x), second(y) {};
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

	public:
		KEY first;
		VAL second;


	};


#endif // !PAIR_H











}