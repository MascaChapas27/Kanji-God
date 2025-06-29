#ifndef __ENUMS_HPP__
#define __ENUMS_HPP__

/*
    This file contains enums
*/

// Type of texture for the sprites
enum class TextureID{
    Title, Background,
    MenuArrowLeftBottom, MenuArrowLeftTop, MenuArrowRightBottom, MenuArrowRightTop, BigMenuButtonBottom, BigMenuButtonTop,
    SaveBottom, SaveTop, HelpBottom, HelpTop, UndoArrowBottom, UndoArrowTop,
    ShortExerciseButtonBottom, ShortExerciseButtonTop, LongExerciseButtonBottom, LongExerciseButtonTop,
    WordTutorialSign, QuestionSign, InstructionsSign,
    MeaningSign, KunOnSign, ReadingSign,
    DrawingBoard
};

// Type of font for the text
enum class FontID{
    MoboFont, ShipporiFont
};

// Type of sound
enum class SoundID{
    CorrectAnswer, HoverOverButton, IncorrectAnswer, PressButton, ReleaseButton
};

// Type of action for the program (each action makes the program
// behave differently, so I could use a State Pattern, but I don't
// really know how to make it work in this situation)
enum class ProgramState{
    TitleScreen,
    KanjiKun, KanjiOn, KanjiMean, WordPron, WordMean, KanjiStroke,
    KanjiTutor, WordTutor, StrokeTutor
};

#endif
