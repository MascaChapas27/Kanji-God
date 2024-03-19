#ifndef __FUCK_WINDOWS_HPP__
#define __FUCK_WINDOWS_HPP__

#include <map>
#include <string>

/*
    Linux can parse the kanji data file properly but Windows can't just
    be normal and won't read characters other than ASCII from files
    so this is the only way
*/
class FuckWindows{
    public:
        static std::map<int,std::wstring> aaa;

        static void initializeAll();
};

#endif