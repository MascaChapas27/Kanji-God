#include "MainWindow.hpp"
#include "ResourceHolder.hpp"
#include "Controller.hpp"
#include <string>
#include <iostream>

MainWindow::MainWindow(){

    // Initial kanji and word grades are JLPT N5
    kanjiGrade = 5;
    wordGrade = 5;

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
    title.setOrigin(title.getTextureRect().width/2,title.getTextureRect().height/2);
}

void MainWindow::start(){

    // Put it in a pointer so that it's easier to use
    TextureHolder * textureHolder = TextureHolder::getTextureInstance();

    // Menu buttons
    Button kanjiGradeSelector;
    kanjiGradeSelector.setBottomTexture(textureHolder->get(TextureID::BigMenuButtonBottom));
    kanjiGradeSelector.setTopTexture(textureHolder->get(TextureID::BigMenuButtonTop));
    kanjiGradeSelector.setPosition(KANJI_MENU_BUTTON_X,KANJI_MENU_BUTTON_Y);
    kanjiGradeSelector.setText(L"Kanji\nJLPT N5");
    kanjiGradeSelector.setTextColor(TEXT_COLOR);
    kanjiGradeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    Button leftArrowKanji;
    leftArrowKanji.setBottomTexture(textureHolder->get(TextureID::MenuArrowLeftBottom));
    leftArrowKanji.setTopTexture(textureHolder->get(TextureID::MenuArrowLeftTop));
    leftArrowKanji.setPosition(KANJI_MENU_ARROW_LEFT_X,KANJI_MENU_ARROW_LEFT_Y);
    leftArrowKanji.setButtonColor(BUTTON_COLOR_NORMAL);
    leftArrowKanji.setPressedButtonAction([this, &kanjiGradeSelector](Button &button){
        kanjiGrade++;
        if(kanjiGrade == 6) kanjiGrade = 1;
        kanjiGradeSelector.setText("Kanji\nJLPT N" + std::to_string(kanjiGrade),true);
    });

    Button rightArrowKanji;
    rightArrowKanji.setBottomTexture(textureHolder->get(TextureID::MenuArrowRightBottom));
    rightArrowKanji.setTopTexture(textureHolder->get(TextureID::MenuArrowRightTop));
    rightArrowKanji.setPosition(KANJI_MENU_ARROW_RIGHT_X,KANJI_MENU_ARROW_RIGHT_Y);
    rightArrowKanji.setButtonColor(BUTTON_COLOR_NORMAL);
    rightArrowKanji.setPressedButtonAction([this, &kanjiGradeSelector](Button &button){
        kanjiGrade--;
        if(kanjiGrade == 0) kanjiGrade = 5;
        kanjiGradeSelector.setText("Kanji\nJLPT N" + std::to_string(kanjiGrade), true);
    });

    /* Button wordGradeSelector;
    wordGradeSelector.setBottomTexture(textureHolder->get(TextureID::BigMenuButtonBottom));
    wordGradeSelector.setTopTexture(textureHolder->get(TextureID::BigMenuButtonTop));
    wordGradeSelector.setPosition(WORD_MENU_BUTTON_X,WORD_MENU_BUTTON_Y);
    wordGradeSelector.setText("Words\nJLPT N5");
    wordGradeSelector.setTextColor(TEXT_COLOR);
    wordGradeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    Button leftArrowWord;
    leftArrowWord.setBottomTexture(textureHolder->get(TextureID::MenuArrowLeftBottom));
    leftArrowWord.setTopTexture(textureHolder->get(TextureID::MenuArrowLeftTop));
    leftArrowWord.setPosition(WORD_MENU_ARROW_LEFT_X,WORD_MENU_ARROW_LEFT_Y);
    leftArrowWord.setButtonColor(BUTTON_COLOR_NORMAL);
    leftArrowWord.setPressedButtonAction([this, &wordGradeSelector](Button &button){
        wordGrade++;
        if(wordGrade == 6) wordGrade = 1;
        wordGradeSelector.setText("Words\nJLPT N" + std::to_string(wordGrade), true);
    });

    Button rightArrowWord;
    rightArrowWord.setBottomTexture(textureHolder->get(TextureID::MenuArrowRightBottom));
    rightArrowWord.setTopTexture(textureHolder->get(TextureID::MenuArrowRightTop));
    rightArrowWord.setPosition(WORD_MENU_ARROW_RIGHT_X,WORD_MENU_ARROW_RIGHT_Y);
    rightArrowWord.setButtonColor(BUTTON_COLOR_NORMAL);
    rightArrowWord.setPressedButtonAction([this, &wordGradeSelector](Button &button){
        wordGrade--;
        if(wordGrade == 0) wordGrade = 5;
        wordGradeSelector.setText("Words\nJLPT N" + std::to_string(wordGrade), true);
    }); */

    Button godModeSelector;
    godModeSelector.setBottomTexture(textureHolder->get(TextureID::BigMenuButtonBottom));
    godModeSelector.setTopTexture(textureHolder->get(TextureID::BigMenuButtonTop));
    godModeSelector.setPosition(GODMODE_MENU_BUTTON_X,GODMODE_MENU_BUTTON_Y);
    godModeSelector.setText("God Mode");
    godModeSelector.setTextColor(TEXT_COLOR);
    godModeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    menuButtons.push_back(&leftArrowKanji);
    menuButtons.push_back(&rightArrowKanji);
    menuButtons.push_back(&kanjiGradeSelector);
    /*
    menuButtons.push_back(&leftArrowWord);
    menuButtons.push_back(&rightArrowWord);
    menuButtons.push_back(&wordGradeSelector);
    */
    menuButtons.push_back(&godModeSelector);

    // Short answer buttons
    Button shortAnswerButton;
    shortAnswerButton.setBottomTexture(textureHolder->get(TextureID::ShortExerciseButtonBottom));
    shortAnswerButton.setTopTexture(textureHolder->get(TextureID::ShortExerciseButtonTop));
    shortAnswerButton.setTextColor(TEXT_COLOR);
    shortAnswerButton.setButtonColor(BUTTON_COLOR_NORMAL);
    shortAnswerButton.setPressedButtonAction([this](Button &thisButton){
        int meanProgress,kunProgress,onProgress;
        if(Controller::getInstance()->checkAnswer(thisButton.getText(),meanProgress,kunProgress,onProgress)){
            thisButton.setButtonColor(sf::Color::White);
            thisButton.setFinalColor(BUTTON_COLOR_CORRECT);
        } else {
            thisButton.setButtonColor(sf::Color::Black);
            thisButton.setFinalColor(BUTTON_COLOR_INCORRECT);
        }
        this->progressSign.setText("Meaning: " + std::to_string(meanProgress) + "%\n\nKunyomi: " + std::to_string(kunProgress) + "%\n\nOnyomi: " + std::to_string(onProgress) + "%");
    });
    shortAnswerButton.setReleasedButtonAction([this](Button &thisButton){
        if(Controller::getInstance()->allAnswered()){
            getExercise(thisButton);
        }
    });

    for(int i=0;i<9;i++){
        shortAnswerButton.setPosition(SHORT_EXERCISE_BUTTON_X[i],SHORT_EXERCISE_BUTTON_Y[i]);
        shortExerciseButtons.push_back(shortAnswerButton);
    }

    // Sign for the kanji/word that is being asked/taught
    kanjiWordSign.setSignTexture(textureHolder->get(TextureID::QuestionSign));
    kanjiWordSign.setPosition(KANJI_WORD_SIGN_X, KANJI_WORD_SIGN_Y);
    kanjiWordSign.setTextColor(TEXT_COLOR);
    kanjiWordSign.setSignColor(BUTTON_COLOR_NORMAL);

    // Sign for the current progress of the kanji/word
    progressSign.setSignTexture(textureHolder->get(TextureID::InstructionsSign));
    progressSign.setPosition(PROGRESS_SIGN_X,PROGRESS_SIGN_Y);
    progressSign.setTextColor(TEXT_COLOR);
    progressSign.setSignColor(BUTTON_COLOR_NORMAL);

    // Sign for the instructions for the current exercise
    instructionsSign.setSignTexture(textureHolder->get(TextureID::InstructionsSign));
    instructionsSign.setPosition(INSTRUCTIONS_SIGN_X,INSTRUCTIONS_SIGN_Y);
    instructionsSign.setTextColor(TEXT_COLOR);
    instructionsSign.setSignColor(BUTTON_COLOR_NORMAL);

    // Sign for the meaning in the tutorial
    tutorialMeaning.setSignTexture(textureHolder->get(TextureID::MeaningSign));
    tutorialMeaning.setPosition(MEANING_SIGN_X,MEANING_SIGN_Y);
    tutorialMeaning.setTextColor(TEXT_COLOR);
    tutorialMeaning.setSignColor(BUTTON_COLOR_NORMAL);

    // Sign that says "Kunyomi"
    kunyomiSign.setSignTexture(textureHolder->get(TextureID::KunOnSign));
    kunyomiSign.setPosition(KUNYOMI_SIGN_X,KUNYOMI_SIGN_Y);
    kunyomiSign.setTextColor(TEXT_COLOR);
    kunyomiSign.setSignColor(BUTTON_COLOR_NORMAL);
    kunyomiSign.setText(L"Kunyomi\nreadings:");

    // Sign that says "Onyomi"
    onyomiSign.setSignTexture(textureHolder->get(TextureID::KunOnSign));
    onyomiSign.setPosition(ONYOMI_SIGN_X,ONYOMI_SIGN_Y);
    onyomiSign.setTextColor(TEXT_COLOR);
    onyomiSign.setSignColor(BUTTON_COLOR_NORMAL);
    onyomiSign.setText(L"Onyomi\nreadings:");

    // Signs for the Kunyomi readings
    Sign readingSign;
    readingSign.setSignTexture(textureHolder->get(TextureID::ReadingSign));
    readingSign.setTextColor(TEXT_COLOR);
    readingSign.setSignColor(BUTTON_COLOR_NORMAL);

    for(int i=0;i<6;i++){
        readingSign.setPosition(KUN_READING_X[i],KUN_READING_Y[i]);
        tutorialKunyomis.push_back(readingSign);
    }

    // Buttons for the Onyomi readings
    for(int i=0;i<6;i++){
        readingSign.setPosition(ON_READING_X[i],ON_READING_Y[i]);
        tutorialOnyomis.push_back(readingSign);
    }

    // Button to continue in the tutorial
    continueButton.setBottomTexture(textureHolder->get(TextureID::ShortExerciseButtonBottom));
    continueButton.setTopTexture(textureHolder->get(TextureID::ShortExerciseButtonTop));
    continueButton.setPosition(PROGRESS_SIGN_X,PROGRESS_SIGN_Y);
    continueButton.setText(L"Continue");
    continueButton.setButtonColor(CONTINUE_COLOR);
    continueButton.setPressedButtonAction([](Button &button){});

    // Button to go back to the main menu
    mainMenuButton.setBottomTexture(textureHolder->get(TextureID::MenuArrowLeftBottom));
    mainMenuButton.setTopTexture(textureHolder->get(TextureID::MenuArrowLeftTop));
    mainMenuButton.setPosition(BACK_MENU_BUTTON_X, BACK_MENU_BUTTON_Y);
    mainMenuButton.setButtonColor(BUTTON_COLOR_NORMAL);
    mainMenuButton.setPressedButtonAction([](Button &button){});
    mainMenuButton.setReleasedButtonAction([this](Button &button){
        Controller::getInstance()->save();
        this->programState = ProgramState::TitleScreen;
        for(Button * button : menuButtons) button->resetPosition();
    });

    // Button to save the progress
    saveButton.setBottomTexture(textureHolder->get(TextureID::SaveBottom));
    saveButton.setTopTexture(textureHolder->get(TextureID::SaveTop));
    saveButton.setPosition(SAVE_BUTTON_X, SAVE_BUTTON_Y);
    saveButton.setButtonColor(SAVED_COLOR);
    saveButton.setPressedButtonAction([](Button &button){});
    saveButton.setReleasedButtonAction([](Button &button){
        Controller::getInstance()->save();
        button.setButtonColor(SAVED_COLOR);
    });

    // Function used to get an exercise (can be a tutorial for a new kanji/word)
    getExercise = [this](Button& button){

        saveButton.setButtonColor(SAVE_COLOR);

        Exercise exercise = Controller::getInstance()->getExercise();

        ProgramState oldState = this->programState;

        // Set program state
        this->programState = exercise.getExerciseType();

        // Set sign with question
        kanjiWordSign.setText(exercise.getQuestion());

        // Set sign with instructions
        instructionsSign.setText(exercise.getHelp());

        // Fill answer buttons depending on the exercise type
        switch(programState){
        case ProgramState::KanjiKun:
        case ProgramState::KanjiOn:
        case ProgramState::KanjiMean:
        {
            // Reset the buttons
            if(oldState != ProgramState::KanjiKun &&
               oldState != ProgramState::KanjiOn &&
               oldState != ProgramState::KanjiMean){

                for(Button &b : shortExerciseButtons){
                    b.setButtonColor(BUTTON_COLOR_NORMAL);
                    b.resetPosition();
                }
            }

            // Set sign with progress
            progressSign.setText("Meaning: " + std::to_string(exercise.getMeaningProgress()) + "%\n\nKunyomi: " + std::to_string(exercise.getKunyomiProgress()) + "%\n\nOnyomi: " + std::to_string(exercise.getOnyomiProgress()) + "%");

            std::set<std::wstring> answers = exercise.getAnswers();
            std::set<std::wstring>::iterator iterAns = answers.begin();
            // Sets can be very predictable so let's randomly advance the iterator
            std::advance(iterAns,rand()%9);
            std::list<Button>::iterator iterBut = shortExerciseButtons.begin();

            while(iterBut != shortExerciseButtons.end()){
                iterBut->setText(*iterAns);
                iterBut->setButtonColor(BUTTON_COLOR_NORMAL);

                iterBut++;
                iterAns++;
                if(iterAns == answers.end()) iterAns = answers.begin();
            }
        }
            break;
        case ProgramState::KanjiTutor:

            if(oldState != ProgramState::KanjiTutor){
                continueButton.resetPosition();
            }

            tutorialMeaning.setText(L"Meaning: " + exercise.getId());

            int index = 0;
            for(std::wstring kunReading : exercise.getKunyomiPronunciations()){
                tutorialKunyomis[index].setText(kunReading);
                index++;
            }
            for(int i=index;i<6;i++){
                tutorialKunyomis[i].setText(L"");
            }

            index = 0;

            for(std::wstring onReading : exercise.getOnyomiPronunciations()){
                tutorialOnyomis[index].setText(onReading);
                index++;
            }
            for(int i=index;i<6;i++){
                tutorialOnyomis[i].setText(L"");
            }
            break;
        }
    };

    kanjiGradeSelector.setPressedButtonAction([this](Button &button){
        Controller::getInstance()->setGradeAndMode(kanjiGrade,true);
        mainMenuButton.resetPosition();
        saveButton.resetPosition();
    });

    /* wordGradeSelector.setPressedButtonAction([this](Button &button){
        Controller::getInstance()->setGradeAndMode(wordGrade,false);
        mainMenuButton.resetPosition();
        saveButton.resetPosition();
    }); */

    godModeSelector.setPressedButtonAction([this](Button &button){
        Controller::getInstance()->setGodMode(true);
        mainMenuButton.resetPosition();
        saveButton.resetPosition();
    });

    kanjiGradeSelector.setReleasedButtonAction(getExercise);
    //wordGradeSelector.setReleasedButtonAction(getExercise);
    godModeSelector.setReleasedButtonAction(getExercise);
    continueButton.setReleasedButtonAction(getExercise);

    while(window.isOpen()){

        // Event handling phase
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                Controller::getInstance()->saveAndExit();
            } else {
                switch(programState){
                case ProgramState::TitleScreen:
                    for(Button * button : menuButtons) button->notify(event);
                    break;
                case ProgramState::KanjiKun:
                case ProgramState::KanjiOn:
                case ProgramState::KanjiMean:
                    for(Button &button : shortExerciseButtons) button.notify(event);
                    mainMenuButton.notify(event);
                    saveButton.notify(event);
                    break;
                case ProgramState::KanjiTutor:
                    continueButton.notify(event);
                    break;
                }
            }
        }

        // Update phase
        switch(programState){
        case ProgramState::TitleScreen:
            for(Button * button : menuButtons) button->update();
            break;
        case ProgramState::KanjiKun:
        case ProgramState::KanjiOn:
        case ProgramState::KanjiMean:
            for(Button &button : shortExerciseButtons) button.update();
            mainMenuButton.update();
            saveButton.update();
            break;
        case ProgramState::KanjiTutor:
            continueButton.update();
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
        case ProgramState::KanjiOn:
        case ProgramState::KanjiMean:
            window.draw(kanjiWordSign);
            window.draw(instructionsSign);
            window.draw(progressSign);
            for(Button &button : shortExerciseButtons) window.draw(button);
            window.draw(mainMenuButton);
            window.draw(saveButton);
            break;
        case ProgramState::KanjiTutor:
            window.draw(kanjiWordSign);
            window.draw(instructionsSign);
            window.draw(tutorialMeaning);
            window.draw(kunyomiSign);
            window.draw(onyomiSign);
            for(Sign s : tutorialKunyomis) if(s.getText().toWideString() != L"") window.draw(s);
            for(Sign s : tutorialOnyomis) if(s.getText().toWideString() != L"") window.draw(s);
            window.draw(continueButton);
            break;
        }

        window.display();
    }

}
