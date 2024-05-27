#ifndef __FUCK_WINDOWS_HPP__
#define __FUCK_WINDOWS_HPP__

#include <map>
#include <string>

/*
    Linux can parse the kanji data files properly but Windows can't just
    be normal and won't read characters other than ASCII from files
    so this is the only way to make it work
*/
class FuckWindows{
    public:
        // For the kanjis
        static std::map<int,std::wstring> kanjisForWindows;

        // For the words
        static std::map<int,std::wstring> wordsForWindows;

        // For the strokes
        static std::map<int,std::wstring> strokesForWindows;
};

#endif
