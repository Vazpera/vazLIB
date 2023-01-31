# vazLIB
## Description
vazLIB is a library that contains stuff that most peopel can't be bothered to rewrite for every program. It also contains  basic complex number calculation.
## Getting Started
There are two ways to use vazLIB. For each, please include the following in your main `.cpp` file.
```c++
using namepsace vazLIB
using namepsace vazLIB::utils
using namepsace vazLIB::literals
using namepsace vazLIB::data_types
```
___
### Module-centric
To use vazLIB modules, put the modules you wish to use inside the same folder as your `.cpp` file, and `#include "vazLIB_<module>.h`.
___
### Module Folder
First, add a folder to your project `vazLIB_modules`, or download the one provided. Then, if no module are inside, put the all the modules inside. Outside the folder, add the file `vazLIB.h`, include this file inside the main `.cpp` file with the `#include` keyword.
___
### All at Once
Add the file `vazLIB_all.h` to your project folder than include it in your main file using the `#include` keyword.
## Contents
### Literals
Each one of these is contained within `vazLIB::literals`
___
`_c` creates a Complex Number. It must be a suffix to a string. `"x1+x2i"_c`, were x1 and x2 are floats.
___
`_msc` returns an integer. It is microsecond notation. Example: `300_msc`
___
`_ms` converts to integer number of microseconds. It is millisecond notation. Example: `300_ms`
___
`_s` converts to integer number of microseconds. It is second notation. Example: `600_s`

## Functions
Each one of these is within `vazLIB::utils`
___
`getch()` returns a character inputted to the terminal without echo.  
___
`getche()` does the same thing as `getch()` but echos input.
___
`cGetch(char fillChar)` returns a character inputted from the terminal, but echoes the `fillChar`, if no fillchar is provided, then it echoes input.
___
`bulkGetch(int count, char fillChar)` repeats cGetch `count` number of times, same fillchar rules apply.
___
`d_sleep(int microseconds)` sleeps for `microseconds` microseconds. Examples: 
```c++
int main() {
	d_sleep(1000000_mcs); /* Sleeps for 1 second */	
	d_sleep(1000_ms);     /* Sleeps for 1 second */
	d_sleep(1_s);         /* Sleeps for 1 second */
}
```
___
`setTextColor(int r, int g, int b)` sets the terminal output text color to the specified color in rgb color space.
___
`setBackgroundColor(int r, int g, int b)` sets the terminal output background color to the specified color in rgb color space.
___
`seperate(text, char delim)` Seperates text into chunks in between the delim, which must be a character. String can either be a `char *`, `char[]` or `string`;
## Structs/Classes
### Complex

`Complex` is a struct that defines a complex number with real compenent `r` and imaginary component `i`.
Two `Complex`s can be multiplied or added together using the `*` and `+` operators respectively.
It is in the `vazLIB::data_types` namespace

## Demos

### Complex Numbers
Mutliply two complex numbers
```c++
int main() {
	Complex C1 = "1+0i"_c;
	Complex C2 = "0+1i"_c;
	Complex C3 = C1*C2;
	cout<<C3<<endl;
}
```
### Red 'Hello World'
Print Hello World to the terminal, but red.
```c++
int main() {
	setTextColor(255,0,0);
	cout<<"Hellow World"<<endl;
	cout<<"\033[0;AmHello Word";
};
```