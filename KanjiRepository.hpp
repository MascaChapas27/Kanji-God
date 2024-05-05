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

        // Map that stores kanji information based on the meaning for that kanji.
        // This map is the main container for kanjis, it stores real objects
        std::map<std::wstring,Kanji> kanjis;

        // Vectors that store information about kanjis that were never learnt. They only
        // store the meaning for that kanji
        std::map<int,std::vector<std::wstring>> newKanjis;

        // Vectors that store information about kanjis that are being practiced. They only
        // store the meaning for that kanji
        std::map<int,std::vector<std::wstring>> practicingKanjis;

        // Vectors that store information about kanjis that were mastered. They only
        // store the meaning for that kanji
        std::map<int,std::vector<std::wstring>> masteredKanjis;

    public:
        // NEVER CLONE A SINGLETON
        KanjiRepository(KanjiRepository &other) = delete;

        // NEVER ASSIGN A SINGLETON
        void operator=(const KanjiRepository &) = delete;

        // Singleton-specific method to get the one and only instance
        static KanjiRepository * getInstance();

        // Operation that loads all kanji and progress for kanji
        void loadAllKanjis();

        // Returns the kanji specified by its meaning
        Kanji getKanji(std::wstring meaning);

        // Returns the amount of kanji that were mastered in that grade 
        int getMasteredKanji(int kanjiGrade);

        // Returns the amount of total kanji in that grade 
        int getTotalKanji(int kanjiGrade);

        // Returns an exercise with a kanji of the given grade. It defaults to a non-mastered
        // exercise but can return a mastered exercise
        Exercise getExercise(int grade, bool mastered = false);

        // Returns an exercise with a kanji that has been mastered (all stats reached 100%)
        Exercise getMasteredExercise();

        // Returns the tutorial for the given kanji
        Exercise getTutorial(std::wstring kanji);

        // Checks if the given answer is valid for the current exercise
        bool checkAnswer(Exercise &exercise, std::wstring answer);

        // Checks if all answeres were answered for a kanji
        bool allAnswered(Exercise &exercise, unsigned int answers);

        // Saves all data
        void save();

};

#endif
