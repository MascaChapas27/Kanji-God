#include "MainWindow.hpp"
#include "ResourceHolder.hpp"

void MainWindow::start(){

    programState = ProgramState::TitleScreen;

    window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),WINDOW_TITLE,sf::Style::Close);
    window.setFramerateLimit(FPS);

    background.setTexture(TextureHolder::getTextureInstance()->get(TextureID::Background));
    background.setScale(2.0, 2.0);
    title.setTexture(TextureHolder::getTextureInstance()->get(TextureID::Title));

    title.setPosition(TITLE_X, TITLE_Y);

    Button menuButtonKanjiGrade1;
    menuButtonKanjiGrade1.setBottomTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonBottom));
    menuButtonKanjiGrade1.setTopTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonTop));
    menuButtonKanjiGrade1.setPosition(GRADE_1_KANJI_X,GRADE_1_KANJI_Y);
    menuButtonKanjiGrade1.setText("Grade 1 Kanji");
    menuButtonKanjiGrade1.setTextColor(TEXT_COLOR);
    menuButtonKanjiGrade1.setButtonColor(GRADE_1_COLOR);

    Button menuButtonKanjiGrade2;
    menuButtonKanjiGrade2.setBottomTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonBottom));
    menuButtonKanjiGrade2.setTopTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonTop));
    menuButtonKanjiGrade2.setPosition(GRADE_2_KANJI_X,GRADE_2_KANJI_Y);
    menuButtonKanjiGrade2.setText("Grade 2 Kanji");
    menuButtonKanjiGrade2.setTextColor(TEXT_COLOR);
    menuButtonKanjiGrade2.setButtonColor(GRADE_2_COLOR);

    Button menuButtonKanjiGrade3;
    menuButtonKanjiGrade3.setBottomTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonBottom));
    menuButtonKanjiGrade3.setTopTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonTop));
    menuButtonKanjiGrade3.setPosition(GRADE_3_KANJI_X,GRADE_3_KANJI_Y);
    menuButtonKanjiGrade3.setText("Grade 3 Kanji");
    menuButtonKanjiGrade3.setTextColor(TEXT_COLOR);
    menuButtonKanjiGrade3.setButtonColor(GRADE_3_COLOR);

    Button menuButtonKanjiGrade4;
    menuButtonKanjiGrade4.setBottomTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonBottom));
    menuButtonKanjiGrade4.setTopTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonTop));
    menuButtonKanjiGrade4.setPosition(GRADE_4_KANJI_X,GRADE_4_KANJI_Y);
    menuButtonKanjiGrade4.setText("Grade 4 Kanji");
    menuButtonKanjiGrade4.setTextColor(TEXT_COLOR);
    menuButtonKanjiGrade4.setButtonColor(GRADE_4_COLOR);

    Button menuButtonKanjiGrade5;
    menuButtonKanjiGrade5.setBottomTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonBottom));
    menuButtonKanjiGrade5.setTopTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonTop));
    menuButtonKanjiGrade5.setPosition(GRADE_5_KANJI_X,GRADE_5_KANJI_Y);
    menuButtonKanjiGrade5.setText("Grade 5 Kanji");
    menuButtonKanjiGrade5.setTextColor(TEXT_COLOR);
    menuButtonKanjiGrade5.setButtonColor(GRADE_5_COLOR);

    Button menuButtonKanjiGrade6;
    menuButtonKanjiGrade6.setBottomTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonBottom));
    menuButtonKanjiGrade6.setTopTexture(TextureHolder::getTextureInstance()->get(TextureID::SmallMenuButtonTop));
    menuButtonKanjiGrade6.setPosition(GRADE_6_KANJI_X,GRADE_6_KANJI_Y);
    menuButtonKanjiGrade6.setText("Grade 6 Kanji");
    menuButtonKanjiGrade6.setTextColor(TEXT_COLOR);
    menuButtonKanjiGrade6.setButtonColor(GRADE_6_COLOR);

    menuButtons.push_front(menuButtonKanjiGrade1);
    menuButtons.push_front(menuButtonKanjiGrade2);
    menuButtons.push_front(menuButtonKanjiGrade3);
    menuButtons.push_front(menuButtonKanjiGrade4);
    menuButtons.push_front(menuButtonKanjiGrade5);
    menuButtons.push_front(menuButtonKanjiGrade6);

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
