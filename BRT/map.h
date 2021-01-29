#pragma once

#ifndef MAP_H
#define MAP_H
#include "tree.h"
#include"pair.h"

namespace my {
	template<class KEY, class VAL>
	class map {
		using tree = tree<pair<KEY, VAL>>;
		using map = map<KEY, VAL>;

		map() : storage();
		map(const KEY,const VAL);


	private:
		tree storage;

	};





}




#endif // !MAP_H


