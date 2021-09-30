#include <iostream>
#include <bitset>
#include <climits>

using namespace std;



int main(){

	cout << "Insert size of mask - /";
	int i;
	cin >> i;
    cout << bitset<8> ((ULONG_MAX << (32-i)) >> 24) << "." << bitset<8> ((ULONG_MAX << (32-i)) >> 16) << "." << bitset<8> ((ULONG_MAX << (32-i)) >> 8) << "." << bitset<8> (ULONG_MAX << (32-i)) << endl;

	return 0;
}

