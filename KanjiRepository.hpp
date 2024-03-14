#ifndef __KANJI_REPOSITORY_HPP__
#ifndef __KANJI_REPOSITORY_HPP__

#include "Kanji.hpp"
#include <map>

/*
    This class contains all kanjis and their progress, meaning
    and pronunciations
*/
class KanjiRepository{
    private:
        // Constructor and destructor are made private
        // because the controller is a Singleton
        KanjiRepository(){}
        ~KanjiRepository(){}

        // Only instance
        static KanjiRepository * kanjiRepository;

        // Map that stores kanji information based on the wstring for that kanji
        std::map<std::wstring,Kanji> kanjis;

    public:
        // NEVER CLONE A SINGLETON
        KanjiRepository(KanjiRepository &other) = delete;

        // NEVER ASSIGN A SINGLETON
        void operator=(const KanjiRepository &) = delete;

        // Singleton-specific method to get the one and only instance
        static KanjiRepository * getInstance();
        

}

#endif