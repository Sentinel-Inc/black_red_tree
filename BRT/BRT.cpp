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

	void run_all() {
		search();
		end();
		next();
		append_or_replace();
		in_order();
		//	acces_or_asign();
		//	copy_constructor();
		//	copy_operator();
	}

	void search() {
		std::clog << "search :";
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
		std::clog << "end :";

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
		std::clog << "next :\t";
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
		std::clog << "in_order :\n";

		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		t.append(11);

		assert(t.give_root()->in_order(3)->get_value() == 4);

		assert(t.give_root()->in_order(2)->get_value() == 1);
		assert(t.give_root()->in_order(6)->get_value() == 10);
		assert(t.give_root()->in_order(7)->get_value() == 11);

		assert(t.give_root()->in_order(8) == nullptr);

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
		bool pass = true;
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		if (t[1] != 1) pass = false;
		if (t[100] != 100) pass = false;
		t.give_root()->append_or_replace(100);
		if (t[100] != 100) pass = false;
		if (t[0] != 0) pass = false;
		if (t[6] != 6) pass = false;
		if (pass) std::clog << " [ ok ]\n";
		else std::clog << " [ fail ]\n";

	}
	void copy_constructor() {
		std::clog << "copy_constructor :\t";
		bool pass = true;
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		tree<int> g(t);

		if (t[1] != 1) pass = false;
		if (t[100] != 100) pass = false;
		t.give_root()->append_or_replace(100);
		if (t[100] != 100) pass = false;
		if (t[0] != 0) pass = false;
		if (t[6] != 6) pass = false;
		if (pass) std::clog << " [ ok ]\n";
		else std::clog << " [ fail ]\n";

	}
	void copy_operator() {
		std::clog << "copy_operator :\t";
		bool pass = true;
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		tree<int> g = t;

		if (t[1] != 1) pass = false;
		if (t[100] != 100) pass = false;
		t.give_root()->append_or_replace(100);
		if (t[100] != 100) pass = false;
		if (t[0] != 0) pass = false;
		if (t[6] != 6) pass = false;
		if (pass) std::clog << " [ ok ]\n";
		else std::clog << " [ fail ]\n";

	}


}


int main()
{
	// nie wiem czy mi się uda 
	tree_test::run_all();
	return 0;
}


