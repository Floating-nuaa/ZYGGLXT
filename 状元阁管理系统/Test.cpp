#include <iostream>
#include "Date.h"
#include "People.h"
#include "DEFINE.cpp"
#include "Purpose.h"
#include "Student.h"
using namespace std;
int main() {
	char nam[20]="¿œ∞À∫∫±§";
	Purpose subject('E');
	char phone[20] = "15832513211";
	People std(nam,'F',phone);
	std.display();
	return 0;
}