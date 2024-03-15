#include "MainWindow.hpp"
#include "ResourceHolder.hpp"
#include "Controller.hpp"
#include <string>
#include <iostream>

MainWindow::MainWindow(){

    // Initial kanji and word grades are 1
    kanjiGrade = 1;
    wordGrade = 1;

    // Put it in a pointer so that it's easier to use
    TextureHolder * textureHolder = TextureHolder::getTextureInstance();

    // Initial state is Title Screen
    programState = ProgramState::TitleScreen;

    // Create the window
    window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),WINDOW_TITLE,sf::Style::Close);
    window.setFramerateLimit(FPS);

    // Background and title for the title screen
    background.setTexture(textureHolder->get(TextureID::Background));
    background.setScale(2.0, 2.0);
    title.setTexture(textureHolder->get(TextureID::Title));
    title.setPosition(TITLE_X, TITLE_Y);
}

void MainWindow::start(){

    // Put it in a pointer so that it's easier to use
    TextureHolder * textureHolder = TextureHolder::getTextureInstance();

    // Menu buttons
    Button kanjiGradeSelector;
    kanjiGradeSelector.setBottomTexture(textureHolder->get(TextureID::BigMenuButtonBottom));
    kanjiGradeSelector.setTopTexture(textureHolder->get(TextureID::BigMenuButtonTop));
    kanjiGradeSelector.setPosition(KANJI_MENU_BUTTON_X,KANJI_MENU_BUTTON_Y);
    kanjiGradeSelector.setText("Kanji\nGrade 1");
    kanjiGradeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    Button leftArrowKanji;
    leftArrowKanji.setBottomTexture(textureHolder->get(TextureID::MenuArrowLeftBottom));
    leftArrowKanji.setTopTexture(textureHolder->get(TextureID::MenuArrowLeftTop));
    leftArrowKanji.setPosition(KANJI_MENU_ARROW_LEFT_X,KANJI_MENU_ARROW_LEFT_Y);
    leftArrowKanji.setButtonColor(BUTTON_COLOR_NORMAL);
    leftArrowKanji.setPressedButtonAction([this, &kanjiGradeSelector](){
        kanjiGrade--;
        if(kanjiGrade == 0) kanjiGrade = 6;
        kanjiGradeSelector.setText("Kanji\nGrade " + std::to_string(kanjiGrade),true);
    });

    Button rightArrowKanji;
    rightArrowKanji.setBottomTexture(textureHolder->get(TextureID::MenuArrowRightBottom));
    rightArrowKanji.setTopTexture(textureHolder->get(TextureID::MenuArrowRightTop));
    rightArrowKanji.setPosition(KANJI_MENU_ARROW_RIGHT_X,KANJI_MENU_ARROW_RIGHT_Y);
    rightArrowKanji.setButtonColor(BUTTON_COLOR_NORMAL);
    rightArrowKanji.setPressedButtonAction([this, &kanjiGradeSelector](){
        kanjiGrade++;
        if(kanjiGrade == 7) kanjiGrade = 1;
        kanjiGradeSelector.setText("Kanji\nGrade " + std::to_string(kanjiGrade), true);
    });

    Button wordGradeSelector;
    wordGradeSelector.setBottomTexture(textureHolder->get(TextureID::BigMenuButtonBottom));
    wordGradeSelector.setTopTexture(textureHolder->get(TextureID::BigMenuButtonTop));
    wordGradeSelector.setPosition(WORD_MENU_BUTTON_X,WORD_MENU_BUTTON_Y);
    wordGradeSelector.setText("Words\nGrade 1");
    wordGradeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    Button leftArrowWord;
    leftArrowWord.setBottomTexture(textureHolder->get(TextureID::MenuArrowLeftBottom));
    leftArrowWord.setTopTexture(textureHolder->get(TextureID::MenuArrowLeftTop));
    leftArrowWord.setPosition(WORD_MENU_ARROW_LEFT_X,WORD_MENU_ARROW_LEFT_Y);
    leftArrowWord.setButtonColor(BUTTON_COLOR_NORMAL);
    leftArrowWord.setPressedButtonAction([this, &wordGradeSelector](){
        wordGrade--;
        if(wordGrade == 0) wordGrade = 6;
        wordGradeSelector.setText("Words\nGrade " + std::to_string(wordGrade), true);
    });

    Button rightArrowWord;
    rightArrowWord.setBottomTexture(textureHolder->get(TextureID::MenuArrowRightBottom));
    rightArrowWord.setTopTexture(textureHolder->get(TextureID::MenuArrowRightTop));
    rightArrowWord.setPosition(WORD_MENU_ARROW_RIGHT_X,WORD_MENU_ARROW_RIGHT_Y);
    rightArrowWord.setButtonColor(BUTTON_COLOR_NORMAL);
    rightArrowWord.setPressedButtonAction([this, &wordGradeSelector](){
        wordGrade++;
        if(wordGrade == 7) wordGrade = 1;
        wordGradeSelector.setText("Words\nGrade " + std::to_string(wordGrade), true);
    });

    menuButtons.push_back(&leftArrowKanji);
    menuButtons.push_back(&rightArrowKanji);
    menuButtons.push_back(&kanjiGradeSelector);
    menuButtons.push_back(&leftArrowWord);
    menuButtons.push_back(&rightArrowWord);
    menuButtons.push_back(&wordGradeSelector);

    // Sign for the kanji/word that is being asked/taught
    kanjiWordSign.setSignTexture(textureHolder->get(TextureID::BigMenuButtonTop));
    kanjiWordSign.setPosition(KANJI_WORD_SIGN_X, KANJI_WORD_SIGN_Y);
    kanjiWordSign.setTextColor(TEXT_COLOR);
    kanjiWordSign.setSignColor(BUTTON_COLOR_NORMAL);
    
    // Function used to get an exercise (can be a tutorial for a new kanji/word)
    getExercise = [this](){
        Exercise exercise = Controller::getInstance()->getExercise();
        
        this->programState = exercise.getExerciseType();

        switch(exercise.getExerciseType()){
        case ProgramState::KanjiKun:
            kanjiWordSign.setText(exercise.getQuestion());
            break;
        }
    };

    kanjiGradeSelector.setReleasedButtonAction(getExercise);
    wordGradeSelector.setReleasedButtonAction(getExercise);

    while(window.isOpen()){

        // Event handling phase
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                exit(EXIT_SUCCESS);
            } else {
                switch(programState){
                case ProgramState::TitleScreen:
                    for(Button * button : menuButtons) button->notify(event);
                    break;
                case ProgramState::KanjiKun:
                    break;
                }
            }
        }

        // Update phase
        switch(programState){
        case ProgramState::TitleScreen:
            for(Button * button : menuButtons) button->update();
            break;
        }

        // Drawing phase
        window.clear();

        window.draw(background);

        switch(programState){
        case ProgramState::TitleScreen:
            window.draw(title);
            for(Button * button : menuButtons) window.draw(*button);
            break;
        case ProgramState::KanjiKun:
            window.draw(kanjiWordSign);
            break;
        }

        window.display();
    }

}
