#include <iostream>
#include "tree.h"

// --------------tests--------------

namespace tree_test {


	void search();
	void end();
	void next();
	void append_or_replace();
	void acces_or_asign();
	void copy_constructor();
	void copy_operator();


	void run_all() {
		search();
		end();
		next();
		append_or_replace();
	//	acces_or_asign();
	//	copy_constructor();
	//	copy_operator();
	}

	void search() {
		std::clog << "search :";
		bool pass = true;
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		if (t.give_root()->search(1)->get_value() != 1) pass = false;
		if (t.give_root()->search(100)->get_value() != 100) pass = false;
		if (t.give_root()->search(0) != nullptr) pass = false;
		if (t.give_root()->search(6)->get_value() != 6) pass = false;
		if (pass) std::clog << " [ ok ]\n";
		else std::clog << " [ fail ]\n";

	}
	void end() {
		std::clog << "end :";
		bool pass = true;
		tree<int> t(6);
		if (t.give_root()->end()->get_value() != 6) pass = false;
		t.append(4);
		if (t.give_root()->end()->get_value() != 6) pass = false;
		t.append(7);
		if (t.give_root()->end()->get_value() != 7) pass = false;
		t.append(8);
		if (t.give_root()->end()->get_value() != 8) pass = false;
		t.append(10);
		if (t.give_root()->end()->get_value() != 10) pass = false;
		t.append(9);
		if (t.give_root()->end()->get_value() != 9) pass = false;
		t.append(11);
		if (t.give_root()->end()->get_value() != 11) pass = false;
		if (pass) std::clog << " [ ok ]\n";
		else std::clog << " [ fail ]\n";

	}
	void next() {
		std::clog << "next :\t";
		bool pass = true;
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		t.append(11);
		if (t.give_root()->next( t.give_root()->get_value() )->get_value() != 2) pass = false;
		
		if (t.give_root()->search(4)->next( t.give_root()->get_value() )->get_value() != 5) pass = false;
		if (t.give_root()->search(5)->next( t.give_root()->get_value() )->get_value() != 100) pass = false;
		if (pass) std::clog << " [ ok ]\n";
		else std::clog << " [ fail ]\n";

	}
	void in_order() {
		std::clog << "in_order :";
		bool pass = true;
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		t.append(11);

		if (t.give_root()->in_order(3)->get_value() != 4) pass = false;

		if (t.give_root()->in_order(2)->get_value() != 1) pass = false;
		if (t.give_root()->in_order(6)->get_value() != 10) pass = false;
		if (t.give_root()->in_order(7)->get_value() != 11) pass = false;

		if (t.give_root()->in_order(8) != nullptr) pass = false;

		if (pass) std::clog << " [ ok ]\n";
		else std::clog << " [ fail ]\n";

	}
	void append_or_replace() {

		std::clog << "append_or_replace :\t";
		bool pass = true;
		tree<int> t(6);
		t.append(2);
		t.append(1);
		t.append(4);
		t.append(4);
		t.append(100);
		t.append(10);
		t.append(5);
		if (t.give_root()->search(1)->get_value() != 1) pass = false;
		if (t.give_root()->search(100)->get_value() != 100) pass = false;
		t.give_root()->append_or_replace(100);
		if (t.give_root()->search(100)->get_value() != 100) pass = false;

		

		if (t.give_root()->search(0) != nullptr) pass = false;
		std::clog << "\n"<< t.size()<<"\n";
		
		//for (auto i : t) std::cout << i.get_value();

		if (pass) std::clog << " [ ok ]\n";
		else std::clog << " [ fail ]\n";

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

	tree_test::run_all();
	return 0;
}


