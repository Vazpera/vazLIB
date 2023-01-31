#include <iostream>
#include <termios.h>
#include <unistd.h>


#ifndef vazLIB_math
#define vazLIB_math

namespace vazLIB 
{
	namespace data_types 
	{
		/* Complex Number Struct */
		struct Complex {
			float r=0.0f; float i=0.0f;
			float getMag() {
				return std::sqrt(r*r+i*i);
			}
			/* Multiply two complex numbers */
			inline Complex operator * (Complex two) {
				Complex x;
				x.r = (r*two.r-i*two.i);
				x.i = (r*two.i+i*two.r);
				return x;
			};

			/* Add two complex numbers */
			inline Complex operator + (Complex two) {
				Complex x;
				x.r = (r+two.r);
				x.i = (i+two.i);
				return x;
			};
			
		};
		/* Insert complex number into stream */
		inline std::ostream & operator<<(std::ostream &out, Complex &c) {
			out<<std::to_string(c.r)<<"+"<<std::to_string(c.i)<<"i";
			return out;
		};
	}

	namespace literals 
	{
		/* Complex number literal */
		inline data_types::Complex operator"" _c(const char *g, size_t size ) {
			std::vector<std::string> words = utils::seperate(g, '+');
			data_types::Complex x;
			x.r=std::stof(words[0]);
			std::string imaginary = utils::seperate(words[1], 'i')[0];
			x.i=std::stof(imaginary);
			return x;
		};
	}
}

#endif // vazLIB_math