#include <assert.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "ResourceHolder.hpp"

// The static variables that store the only instances of the different Resource Holders
// are initialized as null pointers
template <class Resource, class Identifier>
TextureHolder * ResourceHolder<Resource,Identifier>::textureHolder = nullptr;

template <class Resource, class Identifier>
SoundHolder * ResourceHolder<Resource,Identifier>::soundHolder = nullptr;

template <class Resource, class Identifier>
FontHolder * ResourceHolder<Resource,Identifier>::fontHolder = nullptr;


// These three methods are pure magic. C++ allows you to call a different method depending
// on the specific types of the class that you use to call them. This way, we can have
// three different implementations of getInstance(), depending on the type of Resource
// Holder that we are using
template <>
TextureHolder * TextureHolder::getInstance()
{
    if(textureHolder == nullptr)
        textureHolder = new TextureHolder();
    return textureHolder;
}

template <>
SoundHolder * SoundHolder::getInstance()
{
    if(soundHolder == nullptr)
        soundHolder = new SoundHolder();
    return soundHolder;
}

template <>
FontHolder * FontHolder::getInstance()
{
    if(fontHolder == nullptr)
        fontHolder = new FontHolder();
    return fontHolder;
}

// For some reason, fonts can't be loaded using loadFromFile and must be loaded using openFromFile, so
// it's necessary to change the method if the resource is a font
template <>
void FontHolder::load(FontID id, const std::string& filePath){

    // Unique pointers are great for this case since they can only exist in one place at a time.
    // Since this is a Resource Holder, it will hold resources and return references to them, so there
    // will only be one copy of each resource, and it will be stored here.
    std::unique_ptr<sf::Font> resource = std::make_unique<sf::Font>();

    // If the resource can't be loaded, the process dies horribly
    if(!resource->openFromFile(filePath)){
        std::cerr << "ERROR: tried to load the font at " << filePath << ", but it wasn't possible\n";
        exit(EXIT_FAILURE);
    }

    // If everything went alright, we can store the resource in the Resource Holder. With std::move we
    // tell C++ that the unique pointer now belongs to the Resource Holder until it is moved again (until
    // now, it belonged to this load function)
    resourceMap.insert(std::make_pair(id,std::move(resource)));
}

template <>
void TextureHolder::loadAllResources()
{
    load(TextureID::Title,"sprites/title.png");
    load(TextureID::Background,"sprites/background.png");

    load(TextureID::MenuArrowLeftBottom,"sprites/menu_arrow_left_bottom.png");
    load(TextureID::MenuArrowLeftTop,"sprites/menu_arrow_left_top.png");
    load(TextureID::MenuArrowRightBottom,"sprites/menu_arrow_right_bottom.png");
    load(TextureID::MenuArrowRightTop,"sprites/menu_arrow_right_top.png");
    load(TextureID::BigMenuButtonBottom,"sprites/big_menu_button_bottom.png");
    load(TextureID::BigMenuButtonTop,"sprites/big_menu_button_top.png");

    load(TextureID::SaveBottom,"sprites/save_button_bottom.png");
    load(TextureID::SaveTop,"sprites/save_button_top.png");
    load(TextureID::HelpBottom,"sprites/help_button_bottom.png");
    load(TextureID::HelpTop,"sprites/help_button_top.png");
    load(TextureID::UndoArrowBottom,"sprites/undo_arrow_bottom.png");
    load(TextureID::UndoArrowTop,"sprites/undo_arrow_top.png");

    load(TextureID::ShortExerciseButtonBottom,"sprites/short_exercise_button_bottom.png");
    load(TextureID::ShortExerciseButtonTop,"sprites/short_exercise_button_top.png");
    load(TextureID::LongExerciseButtonBottom,"sprites/long_exercise_button_bottom.png");
    load(TextureID::LongExerciseButtonTop,"sprites/long_exercise_button_top.png");

    load(TextureID::WordTutorialSign,"sprites/word_tutorial_sign.png");
    load(TextureID::QuestionSign,"sprites/question_sign.png");
    load(TextureID::InstructionsSign,"sprites/instructions_sign.png");

    load(TextureID::MeaningSign,"sprites/meaning_sign.png");
    load(TextureID::KunOnSign,"sprites/kun_on_sign.png");
    load(TextureID::ReadingSign,"sprites/reading_sign.png");

    load(TextureID::DrawingBoard,"sprites/drawing_board.png");
}

template <>
void SoundHolder::loadAllResources()
{
    load(SoundID::CorrectAnswer,"sounds/correct_answer.wav");
    load(SoundID::HoverOverButton,"sounds/hover_over_button.wav");
    load(SoundID::IncorrectAnswer,"sounds/incorrect_answer.wav");
    load(SoundID::PressButton,"sounds/press_button.wav");
    load(SoundID::ReleaseButton,"sounds/release_button.wav");
}

template <>
void FontHolder::loadAllResources()
{
    load(FontID::MoboFont,"fonts/MOBO_Bold.otf");
    load(FontID::ShipporiFont,"fonts/ShipporiGothicB2-OTF-Bold.otf");
}