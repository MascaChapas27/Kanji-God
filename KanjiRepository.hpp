#ifndef __KANJI_REPOSITORY_HPP__
#define __KANJI_REPOSITORY_HPP__

#include "Kanji.hpp"
#include "Exercise.hpp"
#include <map>
#include <vector>

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

        // Map that stores kanji information based on the wstring for that kanji.
        // This map is the main container for kanjis, it stores real objects
        std::map<std::wstring,Kanji> kanjis;

        // Vectors that store information about kanjis that were never learnt. They only
        // store the wstring for that kanji
        std::map<int,std::vector<std::wstring>> newKanjis;

        // Vectors that store information about kanjis that are being practiced. They only
        // store the wstring for that kanji
        std::map<int,std::vector<std::wstring>> practicingKanjis;

        // Vectors that store information about kanjis that were mastered. They only
        // store the wstring for that kanji
        std::map<int,std::vector<std::wstring>> masteredKanjis;

    public:
        // NEVER CLONE A SINGLETON
        KanjiRepository(KanjiRepository &other) = delete;

        // NEVER ASSIGN A SINGLETON
        void operator=(const KanjiRepository &) = delete;

        // Singleton-specific method to get the one and only instance
        static KanjiRepository * getInstance();

        // Operation that loads all kanji and progress for kanji in one file
        void loadAllKanjis();

        // Returns an exercise with a kanji of the given grade
        Exercise getExercise(int grade);

        // Updates the progress for a kanji
        void updateKanji(std::wstring kanji, int meaning, int kunyomi, int onyomi);

};

#endif
