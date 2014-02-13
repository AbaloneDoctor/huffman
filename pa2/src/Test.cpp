#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Min_heap.h"

void basic() {
	Min_heap heap;
	ASSERT_EQUAL(0,heap.count_elements());
	heap.insert('a',1);
	ASSERT_EQUAL('a', heap.get_element(0));
	ASSERT_EQUAL(1,heap.count_elements());

	heap.insert('b',2);
	ASSERT_EQUAL('b', heap.get_element(1));
	ASSERT_EQUAL(2,heap.count_elements());

	heap.insert('c',3);
	ASSERT_EQUAL('c', heap.get_element(2));
	ASSERT_EQUAL(3,heap.count_elements());
}

void basic2() {
	Min_heap heap;
	heap.insert('a',3);
	ASSERT_EQUAL('a', heap.get_element(0));

	heap.insert('b',1);
	ASSERT_EQUAL('b',heap.get_element(0));
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(basic));
	s.push_back(CUTE(basic2));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



