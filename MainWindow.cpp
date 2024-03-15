#include "MainWindow.hpp"
#include "ResourceHolder.hpp"

void MainWindow::start(){

    kanjiGrade = 1;
    wordGrade = 1;

    programState = ProgramState::TitleScreen;

    TextureHolder * textureHolder = TextureHolder::getTextureInstance();

    window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),WINDOW_TITLE,sf::Style::Close);
    window.setFramerateLimit(FPS);

    background.setTexture(textureHolder->get(TextureID::Background));
    background.setScale(2.0, 2.0);
    title.setTexture(textureHolder->get(TextureID::Title));

    title.setPosition(TITLE_X, TITLE_Y);

    Button kanjiGradeSelector;
    kanjiGradeSelector.setBottomTexture(textureHolder->get(TextureID::BigMenuButtonBottom));
    kanjiGradeSelector.setTopTexture(textureHolder->get(TextureID::BigMenuButtonTop));
    kanjiGradeSelector.setPosition(KANJI_MENU_BUTTON_X,KANJI_MENU_BUTTON_Y);
    kanjiGradeSelector.setText(L"Kanji\nGrade 1");
    kanjiGradeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    Button leftArrowKanji;
    leftArrowKanji.setBottomTexture(textureHolder->get(TextureID::MenuArrowLeftBottom));
    leftArrowKanji.setTopTexture(textureHolder->get(TextureID::MenuArrowLeftTop));
    leftArrowKanji.setPosition(KANJI_MENU_ARROW_LEFT_X,KANJI_MENU_ARROW_LEFT_Y);
    leftArrowKanji.setButtonColor(BUTTON_COLOR_NORMAL);

    Button rightArrowKanji;
    rightArrowKanji.setBottomTexture(textureHolder->get(TextureID::MenuArrowRightBottom));
    rightArrowKanji.setTopTexture(textureHolder->get(TextureID::MenuArrowRightTop));
    rightArrowKanji.setPosition(KANJI_MENU_ARROW_RIGHT_X,KANJI_MENU_ARROW_RIGHT_Y);
    rightArrowKanji.setButtonColor(BUTTON_COLOR_NORMAL);

    Button wordGradeSelector;
    wordGradeSelector.setBottomTexture(textureHolder->get(TextureID::BigMenuButtonBottom));
    wordGradeSelector.setTopTexture(textureHolder->get(TextureID::BigMenuButtonTop));
    wordGradeSelector.setPosition(WORD_MENU_BUTTON_X,WORD_MENU_BUTTON_Y);
    wordGradeSelector.setText(L"Words\nGrade 1");
    wordGradeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    Button leftArrowWord;
    leftArrowWord.setBottomTexture(textureHolder->get(TextureID::MenuArrowLeftBottom));
    leftArrowWord.setTopTexture(textureHolder->get(TextureID::MenuArrowLeftTop));
    leftArrowWord.setPosition(WORD_MENU_ARROW_LEFT_X,WORD_MENU_ARROW_LEFT_Y);
    leftArrowWord.setButtonColor(BUTTON_COLOR_NORMAL);

    Button rightArrowWord;
    rightArrowWord.setBottomTexture(textureHolder->get(TextureID::MenuArrowRightBottom));
    rightArrowWord.setTopTexture(textureHolder->get(TextureID::MenuArrowRightTop));
    rightArrowWord.setPosition(WORD_MENU_ARROW_RIGHT_X,WORD_MENU_ARROW_RIGHT_Y);
    rightArrowWord.setButtonColor(BUTTON_COLOR_NORMAL);

    menuButtons.push_back(leftArrowKanji);
    menuButtons.push_back(rightArrowKanji);
    menuButtons.push_back(kanjiGradeSelector);
    menuButtons.push_back(leftArrowWord);
    menuButtons.push_back(rightArrowWord);
    menuButtons.push_back(wordGradeSelector);

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
                    for(Button &button : menuButtons) button.notify(event);
                    break;
                }
            }
        }

        // Update phase
        switch(programState){
        case ProgramState::TitleScreen:
            for(Button &button : menuButtons) button.update();
            break;
        }

        // Drawing phase
        window.clear();

        window.draw(background);

        switch(programState){
        case ProgramState::TitleScreen:
            window.draw(title);
            for(Button &button : menuButtons) window.draw(button);
            break;
        }

        window.display();
    }

}
