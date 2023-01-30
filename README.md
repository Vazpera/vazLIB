# vazLIB
## Getting Started
To get started using vazLIB, create a folder with `vazLIB	.h` and a file ending in `.cpp`. After this, add the following code to your C++ file.
```cpp
#include "vazLIB.h"

using namespace std;
using namespace vazLIB;
using namespace vazLIB::literals;
using namespace vazLIB::literals::time;
using namespace vazLIB::utils;
using namespace vazLIB::data_types;
```
THen add your own `main()` function and compile and run.

## Demos

### Complex Numbers
Mutliply two complex numbers
```cpp
#include <iostream>

int main() {
	Complex C1 = "1+0i"_c;
	Complex C2 = "0+1i"_c;
	Complex C3 = C1*C2;
	cout<<C3<<endl;
}
```
### Red 'Hello World'
Print Hello World to the terminal, but red.
```cpp
#include <iostream>

int main() {
	setTextColor(255,0,0);
	cout<<"Hello World"<<endl;
	cout<<"\033[0m";
};
```
