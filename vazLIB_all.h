#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <math.h>
#include <vector>

#ifndef vazLIB_ALL
#define vazLIB_ALL

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
			Complex operator * (Complex two) {
				Complex x;
				x.r = (r*two.r-i*two.i);
				x.i = (r*two.i+i*two.r);
				return x;
			};

			/* Add two complex numbers */
			Complex operator + (Complex two) {
				Complex x;
				x.r = (r+two.r);
				x.i = (i+two.i);
				return x;
			};
			
		};
		/* Insert complex number into stream */
		std::ostream & operator<<(std::ostream &out, Complex &c) {
			out<<std::to_string(c.r)<<"+"<<std::to_string(c.i)<<"i";
			return out;
		};
	}

	namespace utils 
	{
		/* Terminal Manipulation */
		void setTextColor(int r = 255, int g = 255, int b = 255) {
		  std::string s = "\033[38;2;";
		  s += std::to_string(r) + ";";
		  s += std::to_string(g) + ";";
		  s += std::to_string(b);
		  s += "m";
		  std::cout << s;
		};
		void setBackgroundColor(int r = 0, int g = 0, int b = 0) {
		  std::string s = "\033[48;2;";
		  s += std::to_string(r) + ";";
		  s += std::to_string(g) + ";";
		  s += std::to_string(b);
		  s += "m";
		  std::cout << s;
		};
		void moveCursor(int x, int y) {
			std::string s = "\033[";
			s+=std::to_string(x)+";";
			s+=std::to_string(y)+"H";
			std::cout<<s;
		}

		/* Getch Functions */
		static struct termios old, current;
		
		void initTermios(int echo) {
		  tcgetattr(0, &old);         /* grab old terminal i/o settings */
		  current = old;              /* make new settings same as old settings */
		  current.c_lflag &= ~ICANON; /* disable buffered i/o */
		  if (echo) {
		    current.c_lflag |= ECHO; /* set echo mode */
		  } else {
		    current.c_lflag &= ~ECHO; /* set no echo mode */
		  }
		  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
		}
		
		/* Restore old terminal i/o settings */
		void resetTermios(void) { tcsetattr(0, TCSANOW, &old); }
		
		/* Read 1 character - echo defines echo mode */
		char getch_(int echo) {
		  char ch;
		  initTermios(echo);
		  ch = getchar();
		  resetTermios();
		  return ch;
		}
		
		/* Read 1 character without echo */
		char getch(void) { return getch_(0); }
		
		/* Read 1 character with echo */
		char getche(void) { return getch_(1); };

		/* Tristate Getch */
		char cGetch(char fillChar = '\0') {
		  char s;
		  if (fillChar == '\0') {
		    s = getche();
		  } else {
		    s = getch();
		    std::cout << fillChar;
		  }
		  return s;
		};

		/* Getch a std::string */
		std::string bulkGetch(int count, char fillChar = '\0') {
		  std::string str;
		  char bufferChar;
		  for (int i = 0; i < count; i++) {
		    bufferChar = cGetch(fillChar);
		    if (bufferChar == '\n') {
		      break;
		    } else {
		      str += bufferChar;
		    }
		  };
		  return str;
		};

		/* Seperate a std::string */
		std::vector<std::string> seperate(std::string str, char delim) {
		  std::string word = "";
		  std::vector<std::string> words;
		  for (auto x : str) {
		    if (x == delim) {
		      words.push_back(word);
		      word = "";
		    } else {
		      word += x;
		    }
		  }
		  words.push_back(word);
		  return words;
		};
		/* Seperate a char* */
		std::vector<std::string> seperate(char *str, char delim) {
			std::string s = str;
		  std::string word = "";
		  std::vector<std::string> words;
		  for (auto x : s) {
		    if (x == delim) {
		      words.push_back(word);
		      word = "";
		    } else {
		      word += x;
		    }
		  }
		  words.push_back(word);
		  return words;
		};

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

		/* Complex number literal */
		data_types::Complex operator"" _c(const char *g, size_t size ) {
			std::vector<std::string> words = utils::seperate(g, '+');
			data_types::Complex x;
			x.r=std::stof(words[0]);
			std::string imaginary = utils::seperate(words[1], 'i')[0];
			x.i=std::stof(imaginary);
			return x;
		};
	}
}

#endif // vazLIB_ALL