#include <vector>

#ifndef vazLIB_base
#define vazLIB_base

namespace vazLIB 
{

	namespace utils 
	{
		/* Seperate a std::string */
		inline std::vector<std::string> seperate(std::string str, char delim) {
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
		inline std::vector<std::string> seperate(char *str, char delim) {
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
	}
}

#endif // vazLIB_base