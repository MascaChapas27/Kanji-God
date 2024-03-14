#ifndef __ENUMS_HPP__
#define __ENUMS_HPP__

/*
    This file contains enums
*/

enum class TextureID{
    Title, Background
};

// Type of font for the text
enum class FontID{
    MoboFont
};

// Type of sound
enum class SoundID{
    
};

// Type of exercise
enum class ExerciseType{
    TitleScreen,
    KanjiKun, KanjiOn, KanjiMean, WordPron, WordMean,
    KanjiTutor, WordTutor
};

#endif