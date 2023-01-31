#include <iostream>
#include <unistd.h>
#include <termios.h>

#ifndef vazLIB_TERMINAL
#define vazLIB_TERMINAL

namespace vazLIB
{
	namespace utils
	{
		/* Terminal Manipulation */
		inline void setTextColor(int r = 255, int g = 255, int b = 255) {
		  std::string s = "\033[38;2;";
		  s += std::to_string(r) + ";";
		  s += std::to_string(g) + ";";
		  s += std::to_string(b);
		  s += "m";
		  std::cout << s;
		};
		inline void setBackgroundColor(int r = 0, int g = 0, int b = 0) {
		  std::string s = "\033[48;2;";
		  s += std::to_string(r) + ";";
		  s += std::to_string(g) + ";";
		  s += std::to_string(b);
		  s += "m";
		  std::cout << s;
		};
		inline void moveCursor(int x, int y) {
			std::string s = "\033[";
			s+=std::to_string(x)+";";
			s+=std::to_string(y)+"H";
			std::cout<<s;
		}

		/* Getch Functions */
		inline static struct termios old, current;
		
		inline void initTermios(int echo) {
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
		inline void resetTermios(void) { tcsetattr(0, TCSANOW, &old); }
		
		/* Read 1 character - echo defines echo mode */
		inline char getch_(int echo) {
		  char ch;
		  initTermios(echo);
		  ch = getchar();
		  resetTermios();
		  return ch;
		}
		
		/* Read 1 character without echo */
		inline char getch(void) { return getch_(0); }
		
		/* Read 1 character with echo */
		inline char getche(void) { return getch_(1); };

		/* Tristate Getch */
		inline char cGetch(char fillChar = '\0') {
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
		inline std::string bulkGetch(int count, char fillChar = '\0') {
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
	};
}

#endif // vazLIB_TERMINAL