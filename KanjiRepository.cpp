#include "KanjiRepository.hpp"
#include "Exercise.hpp"

KanjiRepository * KanjiRepository::kanjiRepository = nullptr;

KanjiRepository * KanjiRepository::getInstance()
{
    if(kanjiRepository == nullptr) kanjiRepository = new KanjiRepository;
    return kanjiRepository;
}

// Operation that loads all kanji and progress for kanji in one file
void loadAllKanjis();

// Returns an exercise with a kanji of the given grade
Exercise getExercise(int grade);

// Updates the progress for a kanji
void updateKanji(std::wstring kanji, int meaning, int kunyomi, int onyomi);

Exercise KanjiRepository::getExercise(int grade)
{
    Exercise exercise;

    exercise.setExerciseType(ProgramState::KanjiKun);
    exercise.setQuestion(L"音");

    std::list<std::wstring> answers;

    answers.push_back(L"あ");
    answers.push_back(L"おのおの");
    answers.push_back(L"しらべ");
    answers.push_back(L"くすり");
    answers.push_back(L"おとおと");
    answers.push_back(L"みずうみ");
    answers.push_back(L"つる");
    answers.push_back(L"おと");
    answers.push_back(L"ね");

    exercise.setAnswers(answers);

    exercise.setKunyomiProgress(10);
    exercise.setOnyomiProgress(30);
    exercise.setMeaningProgress(50);

    exercise.setHelp(L"Choose the\ncorrect kunyomi\nreadings for\nthe kanji shown");

    return exercise;
}
