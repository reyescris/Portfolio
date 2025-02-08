
#include <iostream>
#include <map>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <utility>
#include <algorithm>
#include "wordscanner.h"

using namespace std;


void wordscanner::get_words(std::map<std::string, int>& word_map)
{
    std::string word;

    while (std::cin >> word)
    {
        std::string cleaned_word;

        clean_words(word, cleaned_word);

        if (!cleaned_word.empty())
        {
            word_map[cleaned_word]++;
        }
    }
}


void wordscanner::print_words(const std::map<std::string, int>& word_map)
const
{
    std::cout << "Number of non empty words: " << word_map.size()
    << std::endl;

    std::cout << "Number of distinct words: " << word_map.size()
    << std::endl;

    int total_words = 0;
    for (const auto& entry : word_map)
    {
        total_words += entry.second;
    }

    const int num_items = 4;
    const int item_word_width = 14;
    const int item_count_width = 3;

    int count = 0;

    for (const auto& entry : word_map)
    {
        std::cout << std::left << std::setw(item_word_width)
        << entry.first << ":" << std::setw(item_count_width)
        << entry.second;

        count++;
    

        if(count % num_items == 0)
        {
            std::cout << std::endl;
        }
    }

    if (count % num_items != 0)
    {
        std::cout << std::endl;
    }
    
    std::cout << "Number of words in input stream: " << total_words
    << std::endl;

    std::cout << "Number of words in output stream: " <<
    word_map.size() << std::endl;
}

void wordscanner::clean_words(const std::string& original, std::string&
cleaned)
{
    auto start = std::find_if(original.begin(), original.end(),
    [](unsigned char c) {return std::isalnum(c); });

    auto end = std::find_if(start, original.end(),[](unsigned char c) 
    { return !std::isalnum(c); });

    cleaned = std::string(start, end);

    std::for_each(cleaned.begin(), cleaned.end(), [](char& c)
    {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    });
}




int main ()
{
    wordscanner scanner;

    std::map<std::string, int> word_map;

    scanner.get_words(word_map);

    scanner.print_words(word_map);

    return 0;




}
