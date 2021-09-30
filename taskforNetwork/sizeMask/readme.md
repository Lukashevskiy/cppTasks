# Вычисление маски подсети по заданному размеру

## Код
```cpp
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
```
## пример работы кода

![Image alt](https://github.com/Lukashevskiy/cppTasks/raw/master/taskforNetwork/sizeMask/example1.png)

![Image alt](https://github.com/Lukashevskiy/cppTasks/raw/master/taskforNetwork/sizeMask/example2.png)

