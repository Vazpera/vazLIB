#include <unistd.h>

#ifndef vazLIB_TIME
#define vazLIB_TIME 

namespace vazLIB {
	namespace utils {
		void d_sleep(int microseconds) {
			usleep(microseconds);
		};
	}

	namespace literals 
	{
		/* Microsecond literal */
		long int operator"" _mcs(unsigned long long in) {
			return in;
		} /* microseconds to microseconds */

		/* Millisecond literals */
		long int operator"" _ms(long double in) {
			return in * 1000;
		} /* milliseconds to microseconds */
		
		long int operator"" _ms(unsigned long long in) {
			return in * 1000;
		} /* milliseconds to microseconds */

		/* Second Literals */
		long int operator"" _s(long double in) {
			return in * 1000000;
		}; /* seconds to microseconds */
		
		long int operator"" _s(unsigned long long in) {
			return in * 1000000;
		}; /* seconds to microseconds */
	}
}

#endif // vazLIB_TIME 
