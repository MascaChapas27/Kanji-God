#include "MainWindow.hpp"
#include "ResourceHolder.hpp"
#include "Controller.hpp"
#include <string>
#include <iostream>

void MainWindow::updateMasteredCount(Button &gradeSelector){
    int masteredKanji = Controller::getInstance()->getMasteredKanji(grade);
    int totalKanji = Controller::getInstance()->getTotalKanji(grade);

    int masteredWords = Controller::getInstance()->getMasteredWords(grade);
    int totalWords = Controller::getInstance()->getTotalWords(grade);

    gradeSelector.setText("JLPT N"+std::to_string(grade)+"\nKanji: "+std::to_string(masteredKanji)+"/"+std::to_string(totalKanji)+"\nWords: "+std::to_string(masteredWords)+"/"+std::to_string(totalWords));

    if(masteredWords == totalWords && masteredKanji == totalKanji){
        gradeSelector.setButtonColor(BUTTON_COLOR_CORRECT);
    } else {
        gradeSelector.setButtonColor(BUTTON_COLOR_NORMAL);
    }
}

MainWindow::MainWindow(){

    // Initial grade JLPT N5
    grade = 5;

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
    Button gradeSelector;
    gradeSelector.setBottomTexture(textureHolder->get(TextureID::BigMenuButtonBottom));
    gradeSelector.setTopTexture(textureHolder->get(TextureID::BigMenuButtonTop));
    gradeSelector.setPosition(GRADE_MENU_BUTTON_X,GRADE_MENU_BUTTON_Y);
    gradeSelector.setTextColor(TEXT_COLOR);
    gradeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    Button leftArrow;
    leftArrow.setBottomTexture(textureHolder->get(TextureID::MenuArrowLeftBottom));
    leftArrow.setTopTexture(textureHolder->get(TextureID::MenuArrowLeftTop));
    leftArrow.setPosition(MENU_ARROW_LEFT_X,MENU_ARROW_LEFT_Y);
    leftArrow.setButtonColor(BUTTON_COLOR_NORMAL);
    leftArrow.setPressedButtonAction([this, &gradeSelector](Button &button){
        grade++;
        if(grade == 6) grade = 1;
        this->updateMasteredCount(gradeSelector);
    });

    Button rightArrow;
    rightArrow.setBottomTexture(textureHolder->get(TextureID::MenuArrowRightBottom));
    rightArrow.setTopTexture(textureHolder->get(TextureID::MenuArrowRightTop));
    rightArrow.setPosition(MENU_ARROW_RIGHT_X,MENU_ARROW_RIGHT_Y);
    rightArrow.setButtonColor(BUTTON_COLOR_NORMAL);
    rightArrow.setPressedButtonAction([this, &gradeSelector](Button &button){
        grade--;
        if(grade == 0) grade = 5;
        this->updateMasteredCount(gradeSelector);
    });

    Button godModeSelector;
    godModeSelector.setBottomTexture(textureHolder->get(TextureID::BigMenuButtonBottom));
    godModeSelector.setTopTexture(textureHolder->get(TextureID::BigMenuButtonTop));
    godModeSelector.setPosition(GODMODE_MENU_BUTTON_X,GODMODE_MENU_BUTTON_Y);
    godModeSelector.setText("God Mode");
    godModeSelector.setTextColor(TEXT_COLOR);
    godModeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    menuButtons.push_back(&leftArrow);
    menuButtons.push_back(&rightArrow);
    menuButtons.push_back(&gradeSelector);
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

    // Long answer buttons
    Button longAnswerButton;
    longAnswerButton.setBottomTexture(textureHolder->get(TextureID::LongExerciseButtonBottom));
    longAnswerButton.setTopTexture(textureHolder->get(TextureID::LongExerciseButtonTop));
    longAnswerButton.setTextColor(TEXT_COLOR);
    longAnswerButton.setButtonColor(BUTTON_COLOR_NORMAL);
    longAnswerButton.setPressedButtonAction([this](Button &thisButton){
        std::wstring answer = util::trimLineFeeds(thisButton.getText());
        if(Controller::getInstance()->getCurrentExercise().getExerciseType() == ProgramState::KanjiMean){
            int meanProgress,kunProgress,onProgress;
            if(Controller::getInstance()->checkAnswer(answer,meanProgress,kunProgress,onProgress)){
                thisButton.setButtonColor(sf::Color::White);
                thisButton.setFinalColor(BUTTON_COLOR_CORRECT);
            } else {
                thisButton.setButtonColor(sf::Color::Black);
                thisButton.setFinalColor(BUTTON_COLOR_INCORRECT);
            }
            this->progressSign.setText("Meaning: " + std::to_string(meanProgress) + "%\n\nKunyomi: " + std::to_string(kunProgress) + "%\n\nOnyomi: " + std::to_string(onProgress) + "%");
        } else {
            int pronProgress, meanProgress;
            if(Controller::getInstance()->checkAnswer(answer,pronProgress,meanProgress)){
                thisButton.setButtonColor(sf::Color::White);
                thisButton.setFinalColor(BUTTON_COLOR_CORRECT);
            } else {
                thisButton.setButtonColor(sf::Color::Black);
                thisButton.setFinalColor(BUTTON_COLOR_INCORRECT);
            }
            this->progressSign.setText("Pronunciation: " + std::to_string(pronProgress) + "%\n\nMeaning: " + std::to_string(meanProgress) + "%");
        }

    });
    longAnswerButton.setReleasedButtonAction([this](Button &thisButton){
        if(Controller::getInstance()->allAnswered()){
            getExercise(thisButton);
        }
    });

    for(int i=0;i<6;i++){
        longAnswerButton.setPosition(LONG_EXERCISE_BUTTON_X[i],LONG_EXERCISE_BUTTON_Y[i]);
        longExerciseButtons.push_back(longAnswerButton);
    }

    // Sign for the kanji/word that is being asked/taught
    kanjiWordSign.setSignTexture(textureHolder->get(TextureID::QuestionSign));
    kanjiWordSign.setPosition(KANJI_WORD_SIGN_X, KANJI_WORD_SIGN_Y);
    kanjiWordSign.setTextColor(TEXT_COLOR);
    kanjiWordSign.setSignColor(BUTTON_COLOR_NORMAL);
    kanjiWordSign.setFont(FontHolder::getFontInstance()->get(FontID::ShipporiFont));
    kanjiWordSign.setMaxTextSize(INITIAL_FONT_SIZE*2);

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

    // Sign for the kanji meaning in the tutorial
    tutorialKanjiMeaning.setSignTexture(textureHolder->get(TextureID::MeaningSign));
    tutorialKanjiMeaning.setPosition(KANJI_MEANING_SIGN_X,KANJI_MEANING_SIGN_Y);
    tutorialKanjiMeaning.setTextColor(TEXT_COLOR);
    tutorialKanjiMeaning.setSignColor(BUTTON_COLOR_NORMAL);

    // Sign for the word meaning in the tutorial
    tutorialWordMeaning.setSignTexture(textureHolder->get(TextureID::WordTutorialSign));
    tutorialWordMeaning.setPosition(WORD_MEANING_SIGN_X,WORD_MEANING_SIGN_Y);
    tutorialWordMeaning.setTextColor(TEXT_COLOR);
    tutorialWordMeaning.setSignColor(BUTTON_COLOR_NORMAL);

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

    // Sign for the word pronunciation in the tutorial
    tutorialPronunciation.setSignTexture(textureHolder->get(TextureID::WordTutorialSign));
    tutorialPronunciation.setPosition(WORD_PRON_SIGN_X,WORD_PRON_SIGN_Y);
    tutorialPronunciation.setTextColor(TEXT_COLOR);
    tutorialPronunciation.setSignColor(BUTTON_COLOR_NORMAL);

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
    mainMenuButton.setReleasedButtonAction([this, &gradeSelector](Button &button){
        Controller::getInstance()->save();
        this->programState = ProgramState::TitleScreen;
        for(Button * button : menuButtons) button->resetPosition();
        updateMasteredCount(gradeSelector);
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

    // Button that shows the tutorial page for the following exercise
    helpButton.setBottomTexture(textureHolder->get(TextureID::HelpBottom));
    helpButton.setTopTexture(textureHolder->get(TextureID::HelpTop));
    helpButton.setPosition(HELP_BUTTON_X, HELP_BUTTON_Y);
    helpButton.setButtonColor(HELP_COLOR);
    helpButton.setPressedButtonAction([](Button &button){});

    // Function used to get an exercise (can be a tutorial for a new kanji/word)
    getExercise = [this, &gradeSelector](Button& button){

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
        {
            // Reset the buttons
            if(oldState != ProgramState::KanjiKun &&
               oldState != ProgramState::KanjiOn){

                for(Button &b : shortExerciseButtons){
                    b.setButtonColor(BUTTON_COLOR_NORMAL);
                    b.resetPosition();
                }
                helpButton.resetPosition();
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
        {

            if(oldState != ProgramState::KanjiTutor){
                continueButton.resetPosition();
            }

            tutorialKanjiMeaning.setText(L"Meaning: " + exercise.getTutorialMeaning());

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
        }
            break;
        case ProgramState::WordMean:
        case ProgramState::WordPron:
        case ProgramState::KanjiMean:
        {
            // Reset the buttons
            if(oldState != ProgramState::WordMean &&
               oldState != ProgramState::WordPron &&
               oldState != ProgramState::KanjiMean){

                for(Button &b : longExerciseButtons){
                    b.setButtonColor(BUTTON_COLOR_NORMAL);
                    b.resetPosition();
                }
                helpButton.resetPosition();
            }

            // Set sign with progress
            if(exercise.getExerciseType() == ProgramState::KanjiMean)
                progressSign.setText("Meaning: " + std::to_string(exercise.getMeaningProgress()) + "%\n\nKunyomi: " + std::to_string(exercise.getKunyomiProgress()) + "%\n\nOnyomi: " + std::to_string(exercise.getOnyomiProgress()) + "%");
            else
                progressSign.setText("Pronunciation: " + std::to_string(exercise.getPronunciationProgress()) + "%\n\nMeaning: " + std::to_string(exercise.getMeaningProgress()) + "%");

            std::set<std::wstring> answers = exercise.getAnswers();
            std::set<std::wstring>::iterator iterAns = answers.begin();
            // Sets can be very predictable so let's randomly advance the iterator
            std::advance(iterAns,rand()%6);
            std::list<Button>::iterator iterBut = longExerciseButtons.begin();

            while(iterBut != longExerciseButtons.end()){
                iterBut->setText(*iterAns);
                iterBut->setButtonColor(BUTTON_COLOR_NORMAL);

                iterBut++;
                iterAns++;
                if(iterAns == answers.end()) iterAns = answers.begin();
            }
        }
            break;
        case ProgramState::WordTutor:
        {
            if(oldState != ProgramState::WordTutor){
                continueButton.resetPosition();
            }

            tutorialWordMeaning.setText(exercise.getTutorialMeaning());

            tutorialPronunciation.setText(exercise.getWordPronunciation());
        }
            break;
        case ProgramState::TitleScreen:

            this->updateMasteredCount(gradeSelector);

            break;
        default:
            break;
        }
    };

    gradeSelector.setPressedButtonAction([this](Button &button){
        Controller::getInstance()->setGrade(grade);
        mainMenuButton.resetPosition();
        saveButton.resetPosition();
        helpButton.resetPosition();
    });

    godModeSelector.setPressedButtonAction([this](Button &button){
        Controller::getInstance()->setGodMode(true);
        mainMenuButton.resetPosition();
        saveButton.resetPosition();
        helpButton.resetPosition();
    });

    gradeSelector.setReleasedButtonAction(getExercise);
    godModeSelector.setReleasedButtonAction(getExercise);
    continueButton.setReleasedButtonAction(getExercise);

    helpButton.setReleasedButtonAction([this, &gradeSelector](Button& button){

        saveButton.setButtonColor(SAVE_COLOR);

        Exercise exercise = Controller::getInstance()->getCurrentTutorial();

        ProgramState oldState = this->programState;

        // Set program state
        this->programState = exercise.getExerciseType();

        // Set sign with question
        kanjiWordSign.setText(exercise.getQuestion());

        // Set sign with instructions
        instructionsSign.setText(exercise.getHelp());

        // Fill answer buttons depending on the exercise type
        switch(programState){
        case ProgramState::KanjiTutor:
        {

            if(oldState != ProgramState::KanjiTutor){
                continueButton.resetPosition();
            }

            tutorialKanjiMeaning.setText(L"Meaning: " + exercise.getTutorialMeaning());

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
        }
            break;
        case ProgramState::WordTutor:
        {
            if(oldState != ProgramState::WordTutor){
                continueButton.resetPosition();
            }

            tutorialWordMeaning.setText(exercise.getTutorialMeaning());

            tutorialPronunciation.setText(exercise.getWordPronunciation());
        }
            break;
        case ProgramState::TitleScreen:

            this->updateMasteredCount(gradeSelector);

            break;
        default:
            break;
        }
    });

    // Before starting update the content of the grade selector
    updateMasteredCount(gradeSelector);

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
                    for(Button &button : shortExerciseButtons) button.notify(event);
                    mainMenuButton.notify(event);
                    saveButton.notify(event);
                    helpButton.notify(event);
                    break;
                case ProgramState::WordPron:
                case ProgramState::WordMean:
                case ProgramState::KanjiMean:
                    for(Button &button : longExerciseButtons) button.notify(event);
                    mainMenuButton.notify(event);
                    saveButton.notify(event);
                    helpButton.notify(event);
                    break;
                case ProgramState::KanjiTutor:
                case ProgramState::WordTutor:
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
            for(Button &button : shortExerciseButtons) button.update();
            mainMenuButton.update();
            saveButton.update();
            helpButton.update();
            break;
        case ProgramState::WordPron:
        case ProgramState::WordMean:
        case ProgramState::KanjiMean:
            for(Button &button : longExerciseButtons) button.update();
            mainMenuButton.update();
            saveButton.update();
            helpButton.update();
            break;
        case ProgramState::KanjiTutor:
        case ProgramState::WordTutor:
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
            window.draw(kanjiWordSign);
            window.draw(instructionsSign);
            window.draw(progressSign);
            for(Button &button : shortExerciseButtons) window.draw(button);
            window.draw(mainMenuButton);
            window.draw(saveButton);
            window.draw(helpButton);
            break;
        case ProgramState::WordPron:
        case ProgramState::WordMean:
        case ProgramState::KanjiMean:
            window.draw(kanjiWordSign);
            window.draw(instructionsSign);
            window.draw(progressSign);
            for(Button &button : longExerciseButtons) window.draw(button);
            window.draw(mainMenuButton);
            window.draw(saveButton);
            window.draw(helpButton);
            break;
        case ProgramState::KanjiTutor:
            window.draw(kanjiWordSign);
            window.draw(instructionsSign);
            window.draw(tutorialKanjiMeaning);
            window.draw(kunyomiSign);
            window.draw(onyomiSign);
            for(Sign s : tutorialKunyomis) if(s.getText().toWideString() != L"") window.draw(s);
            for(Sign s : tutorialOnyomis) if(s.getText().toWideString() != L"") window.draw(s);
            window.draw(continueButton);
            break;
        case ProgramState::WordTutor:
            window.draw(kanjiWordSign);
            window.draw(instructionsSign);
            window.draw(tutorialWordMeaning);
            window.draw(tutorialPronunciation);
            window.draw(continueButton);
            break;
        }

        window.display();
    }

}
