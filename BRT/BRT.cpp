#include <iostream>
#include "tree.h"
#include <assert.h>

// --------------tests--------------

namespace tree_test {


	void search();
	void end();
	void next();
	void append_or_replace();
	void acces_or_asign();
	void copy_constructor();
	void copy_operator();
	void in_order();
	void no_parameter_constructor();


	void run_all() {
		search();
		end();
		next();
		append_or_replace();
		in_order();
		acces_or_asign();
		copy_constructor();
		copy_operator();
		no_parameter_constructor();
	}

	void search() {
		std::clog << "search :\t\t";
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		assert(t.give_root()->search(1)->get_value() == 1);
		assert(t.give_root()->search(100)->get_value() == 100);
		assert(t.give_root()->search(0) == nullptr);
		assert(t.give_root()->search(6)->get_value() == 6);
		std::clog << " [ ok ]\n";

	}
	void end() {
		std::clog << "end :\t\t\t";

		tree<int> t(6);

		assert(t.give_root()->end()->get_value() == 6);
		t.append(4);
		assert(t.give_root()->end()->get_value() == 4);
		t.append(7);
		assert(t.give_root()->end()->get_value() == 7);
		t.append(8);
		assert(t.give_root()->end()->get_value() == 8);
		t.append(10);
		assert(t.give_root()->end()->get_value() == 10);
		t.append(9);
		assert(t.give_root()->end()->get_value() == 9);
		t.append(11);
		assert(t.give_root()->end()->get_value() == 11);

		std::clog << " [ ok ]\n";

	}
	void next() {
		std::clog << "next :\t\t\t";
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		t.append(11);

		assert(
			t.give_root()
			->next(
				t.give_root()->get_value()
			)
			->get_value() == 2
		);
		int temp_debug = t.give_root()->search(4)->next(t.give_root()->search(4)->get_value())->get_value();
		assert(temp_debug == 5);

		auto fifth = t.give_root()->search(5);
		temp_debug = fifth->next(fifth->get_value())->get_value();

		assert(temp_debug == 100);
		std::clog << " [ ok ]\n";


	}
	void in_order() {
		std::clog << "in_order :\t\t";

		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		t.append(11);

		unsigned counter = 3;
		assert(t.give_root()->in_order(counter)->get_value() == 4);

		counter = 2;
		assert(t.give_root()->in_order(counter)->get_value() == 1);

		counter = 6;
		assert(t.give_root()->in_order(counter)->get_value() == 10);

		counter = 7;
		assert(t.give_root()->in_order(counter)->get_value() == 11);
		counter = 8;
		assert(t.give_root()->in_order(counter) == nullptr);

		std::clog << " [ ok ]\n";


	}

	void append_or_replace() {

		std::clog << "append_or_replace :\t";

		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);

		assert(t.give_root()->search(1)->get_value() == 1);

		assert(t.give_root()->search(100)->get_value() == 100);
		t.give_root()->append_or_replace(100);
		assert(t.give_root()->search(100)->get_value() == 100);
		assert(t.give_root()->search(0) == nullptr);

		std::clog << " [ ok ]\n";


	}
	void acces_or_asign() {

		std::clog << "acces_or_asign :\t";
		using pair = std::pair<int, std::string>;
		tree<pair> t;

		t.append(pair(2, "a"));
		t.append(pair(1, "b"));
		t.append(pair(4, "c"));
		t.append(pair(4, "d"));
		t.append(pair(100, "c"));
		t.append(pair(10, "e"));
		t.append(pair(5, "f"));
		
		pair search(1, "NO");
		
		pair temo_debug = t[search];
		assert(temo_debug.second == "b");
		
		search.first = 100;
		search.second = "no";
		assert(t[search].second == "c");

		t.give_root()->append_or_replace((pair(100, "y")));
		
		assert(t[search].second == "y");
		search.first = 0;
		search.second = "s";

		assert(t[search].second == "s");
		search.first = 6;
		search.second = "f";

		assert(t[search].second == "f");
		std::clog << " [ ok ]\n";


	}
	void no_parameter_constructor() {
		std::clog << "no_param_constructor :\t";

		tree<int> t;
		t.append(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		t.append(11);

		unsigned counter = 3;
		assert(t.give_root()->in_order(counter)->get_value() == 4);


		counter = 2;
		assert(t.give_root()->in_order(counter)->get_value() == 1);

		counter = 6;
		assert(t.give_root()->in_order(counter)->get_value() == 10);
		counter = 7;
		assert(t.give_root()->in_order(counter)->get_value() == 11);

		counter = 8;
		assert(t.give_root()->in_order(counter) == nullptr);


		std::clog << " [ ok ]\n";




	}
	void copy_constructor() {
		std::clog << "copy_constructor :\t";

		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		tree<int> g(t);

		assert(t[1] == 1);
		assert(t[100] == 100);
		t.give_root()->append_or_replace(100);
		assert(t[100] == 100);
		assert(t[0] == 0);
		assert(t[6] == 6);
		std::clog << " [ ok ]\n";

	}
	void copy_operator() {
		std::clog << "copy_operator :\t\t";

		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		tree<int> g = t;

		assert(t[1] == 1);
		assert(t[100] == 100);
		t.give_root()->append_or_replace(100);
		assert(t[100] == 100);
		assert(t[0] == 0);
		assert(t[6] == 6);
		std::clog << " [ ok ]\n";

	}


}


int main()
{
	// nie wiem czy mi się uda 
	tree_test::run_all();

	return 0;
}


