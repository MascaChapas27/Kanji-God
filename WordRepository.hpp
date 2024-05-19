#ifndef __WORD_REPOSITORY_HPP__
#define __WORD_REPOSITORY_HPP__

#include "Word.hpp"
#include "Exercise.hpp"
#include "Utilities.hpp"
#include <map>
#include <vector>

/*
    This class contains all words and their progress, meaning
    and pronunciation
*/
class WordRepository{
    private:
        // Constructor and destructor are made private
        // because the controller is a Singleton
        WordRepository(){}
        ~WordRepository(){}

        // Only instance
        static WordRepository * wordRepository;

        // Map that stores word information based on the hash code for that word.
        // This map is the main container for words, it stores real objects
        std::map<hash_t,Word> words;

        // Vectors that store information about words that were never learnt. They only
        // store the hash code for that word
        std::map<int,std::vector<hash_t>> newWords;

        // Vectors that store information about words that are being practiced. They only
        // store the hash code for that word
        std::map<int,std::vector<hash_t>> practicingWords;

        // Vectors that store information about words that were mastered. They only
        // store the hash code for that word
        std::map<int,std::vector<hash_t>> masteredWords;

        // This is just temporary
        void classifyWords();

    public:
        // NEVER CLONE A SINGLETON
        WordRepository(WordRepository &other) = delete;

        // NEVER ASSIGN A SINGLETON
        void operator=(const WordRepository &) = delete;

        // Singleton-specific method to get the one and only instance
        static WordRepository * getInstance();

        // Operation that loads all words and progress for words
        void loadAllWords();

        // Returns the amount of words that were mastered in that grade 
        int getMasteredWords(int wordGrade);

        // Returns the amount of total words in that grade
        int getTotalWords(int wordGrade);

        // Returns an exercise with a word of the given grade. It defaults to a non-mastered
        // exercise but can return a mastered exercise
        Exercise getExercise(int grade, bool mastered = false);

        // Returns an exercise with a word that has been mastered (all stats reached 100%)
        Exercise getMasteredExercise();

        // Returns a tutorial for the word with the given hash code
        Exercise getTutorial(hash_t hashCode);

        // Checks if the given answer is valid for the current exercise
        bool checkAnswer(Exercise &exercise, std::wstring answer);

        // Checks if all answeres were answered for a word
        bool allAnswered(Exercise &exercise, unsigned int answers);

        // Saves all data
        void save();
};

#endif
