#ifndef __ENUMS_HPP__
#define __ENUMS_HPP__

/*
    This file contains enums
*/

// Type of texture for the sprites
enum class TextureID{
    Title, Background, SmallMenuButtonBottom, SmallMenuButtonTop
};

// Type of font for the text
enum class FontID{
    MoboFont
};

// Type of sound
enum class SoundID{

};

// Type of action for the program (each action makes the program
// behave differently, so I could use a State Pattern, but I don't
// really know how to make it work in this situation)
enum class ProgramState{
    TitleScreen,
    KanjiKun, KanjiOn, KanjiMean, WordPron, WordMean,
    KanjiTutor, WordTutor,
    SavingAndExiting
};

#endif
