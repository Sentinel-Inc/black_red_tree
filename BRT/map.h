#pragma once

#ifndef MAP_H
#define MAP_H
#include "tree.h"
#include"pair.h"
#include <exception>


// --- iterator over the tree ---


namespace my {
	template<class KEY, class VAL>
	class map {
	public:
		using Tree = tree<pair< KEY, VAL>>;
		using Map = map<KEY, VAL>;

		Map() {
			storage = {};
		}
		Map(const KEY& x, const VAL& y) {

			storage.append(pair<KEY, VAL>(x, y));
		};
		Map(pair<KEY, VAL> x) {

			storage.append(x);
		};

		Map(const Map& other) { storage = other.storage; }; // this is possible due to operator= in tree.h
		Map& operator=(const Map&);

		iterator<Tree> begin();
		iterator<Tree> end() {return nullptr;};

		void insert_or_assign(pair<KEY, VAL>x);
		void insert_or_assign(const KEY&, const VAL&);
		void insert(pair<KEY, VAL>x);
		VAL find(const KEY&);
		void insert(const KEY&, const VAL&);
		void clear();

		size_t size();
		bool empty();

		VAL& at(const KEY&);

		//void erase(const KEY&);
		VAL& operator[](KEY);
		//void pop(const KEY&);
		//void pop(KEY); todo


		~map() = default;

	private:
		Tree storage;

	};
	template<class KEY, class VAL>
	inline map<KEY, VAL>& map<KEY, VAL>::operator=(const map<KEY, VAL>& other)
	{
		if (this == &other)return *this;
		storage = other.storage;
		return *this;


	}


	template<class KEY, class VAL>
	inline iterator<tree<pair< KEY, VAL>>> map<KEY, VAL>::begin()
	{
		return iterator<tree<pair< KEY, VAL>>>(storage.begin());
	}

	template<class KEY, class VAL>
	inline void map<KEY, VAL>::insert_or_assign(pair<KEY, VAL> x)
	{
		storage.append_or_replace(x);

	}

	template<class KEY, class VAL>
	inline void map<KEY, VAL>::insert_or_assign(const KEY& x, const VAL& y)
	{
		storage.append_or_replace(pair<KEY, VAL>(x, y));

	}
	template<class KEY, class VAL>
	inline void map<KEY, VAL>::insert(pair<KEY, VAL> x)
	{
		storage.append(x);
	}
	template<class KEY, class VAL>
	inline VAL map<KEY, VAL>::find(const KEY& key)
	{
		auto temp = storage.search(key);
		if (temp)return temp.second;
		else throw std::out_of_range;
	}
	template<class KEY, class VAL>
	inline void map<KEY, VAL>::insert(const KEY& x, const VAL& y)
	{
		storage.append(pair<KEY, VAL>(x, y));

	}
	template<class KEY, class VAL>
	inline void map<KEY, VAL>::clear()
	{
		storage.clear();

	}
	template<class KEY, class VAL>
	inline size_t map<KEY, VAL>::size()
	{
		return 	storage.size();

	}
	template<class  KEY, class VAL>
	inline bool map<KEY, VAL>::empty()
	{


		return storage.in_order != nullptr;
	}

	template<class KEY, class VAL>
	inline VAL& map<KEY, VAL>::at(const KEY& key)
	{
		auto temp_ptr = storage.search(key);
		if (!temp_ptr)return *temp_ptr.second;
		//
	}
	template<class KEY, class VAL>
	inline VAL& map<KEY, VAL>::operator[](KEY key)
	{


		return	storage
			.search(pair<KEY, VAL>(key))// node<pair<key,val>>* 
			->get_value()	// pair<key,val>&
			.second;	// val



	}

}




#endif // !MAP_H


