#include <assert.h>
#include <iostream>

// Singleton static variables are initialized as null
template <class Resource, class Identifier>
TextureHolder * ResourceHolder<Resource,Identifier>::textureHolder = nullptr;

template <class Resource, class Identifier>
SoundHolder * ResourceHolder<Resource,Identifier>::soundHolder = nullptr;

template <class Resource, class Identifier>
FontHolder * ResourceHolder<Resource,Identifier>::fontHolder = nullptr;

template <class Resource, class Identifier>
void ResourceHolder<Resource,Identifier>::load(Identifier id, const std::string& fileName){
    // Unique pointers are better because they delete themselves when
    // they go out of scope
    std::unique_ptr<Resource> resource(new Resource());

    // We try to load the resource. If there is an error, we die horribly
    if(!resource->loadFromFile(fileName)){
        std::cerr << "ERROR: file " << fileName << " not found" << std::endl;
        exit(EXIT_FAILURE);
    }

    // It's important to std::move the pointer so that it's not destroyed
    // as soon as the function ends.
    resourceMap.insert(std::make_pair(id,std::move(resource)));
}

template <class Resource, class Identifier>
Resource& ResourceHolder<Resource,Identifier>::get(Identifier id){
    // First we find the element in the map (auto means that the
    // type is automatically infered from the context)
    auto found = resourceMap.find(id);

    if(found == resourceMap.end()){
        std::cerr << "ERROR: could not find the desired element in the resource holder" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Once we have the element, which is a pair, we return
    // the texture, which is the second element
    return *(found -> second);
}

template <class Resource, class Identifier>
TextureHolder * ResourceHolder<Resource,Identifier>::getTextureInstance()
{
    if(textureHolder == nullptr){
        textureHolder = new TextureHolder;
        textureHolder->loadAllTextures();
    }
    return textureHolder;
}

template <class Resource, class Identifier>
SoundHolder * ResourceHolder<Resource,Identifier>::getSoundInstance()
{
    if(soundHolder == nullptr){
        soundHolder = new SoundHolder;
        soundHolder->loadAllSounds();
    }
    return soundHolder;
}

template <class Resource, class Identifier>
FontHolder * ResourceHolder<Resource,Identifier>::getFontInstance()
{
    if(fontHolder == nullptr){
        fontHolder = new FontHolder;
        fontHolder->loadAllFonts();
    }
    return fontHolder;
}

template <class Resource, class Identifier>
void ResourceHolder<Resource,Identifier>::loadAllTextures()
{
    load(TextureID::Title,"sprites/title.png");
    load(TextureID::Background,"sprites/background.png");

    load(TextureID::BigMenuButtonBottom,"sprites/big_menu_button_bottom.png");
    load(TextureID::BigMenuButtonTop,"sprites/big_menu_button_top.png");
    load(TextureID::MenuArrowLeftBottom,"sprites/menu_arrow_left_bottom.png");
    load(TextureID::MenuArrowLeftTop,"sprites/menu_arrow_left_top.png");
    load(TextureID::MenuArrowRightBottom,"sprites/menu_arrow_right_bottom.png");
    load(TextureID::MenuArrowRightTop,"sprites/menu_arrow_right_top.png");

    load(TextureID::SaveBottom,"sprites/save_button_bottom.png");
    load(TextureID::SaveTop,"sprites/save_button_top.png");
    load(TextureID::HelpBottom,"sprites/help_button_bottom.png");
    load(TextureID::HelpTop,"sprites/help_button_top.png");

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
}

template <class Resource, class Identifier>
void ResourceHolder<Resource,Identifier>::loadAllSounds()
{
    load(SoundID::CorrectAnswer,"sounds/correct_answer.wav");
    load(SoundID::HoverOverButton,"sounds/hover_over_button.wav");
    load(SoundID::IncorrectAnswer,"sounds/incorrect_answer.wav");
    load(SoundID::PressButton,"sounds/press_button.wav");
    load(SoundID::ReleaseButton,"sounds/release_button.wav");
}

template <class Resource, class Identifier>
void ResourceHolder<Resource,Identifier>::loadAllFonts()
{
    load(FontID::MoboFont,"fonts/MOBO_Bold.otf");
}
