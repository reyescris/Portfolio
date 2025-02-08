
#ifndef H_WORDSCANNER
#define H_WORDSCANNER

#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <utility>
#include <algorithm>
#include <iomanip>



class wordscanner
{
    public:
        void get_words(std::map<std::string, int>& word_map);

        void print_words(const std::map<std::string, int>& word_map) const;
    


    private:
        void clean_words(const  std::string& original, std::string& cleaned);
        
             
        
};




#endif
