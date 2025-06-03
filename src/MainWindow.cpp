#include "MainWindow.hpp"
#include "ResourceHolder.hpp"
#include "Controller.hpp"
#include "Kanji.hpp"
#include "KanjiRepository.hpp"
#include <string>
#include <iostream>
#include <optional>

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

MainWindow::MainWindow() :
    background(TextureHolder::getInstance()->get(TextureID::Background)),
    title(TextureHolder::getInstance()->get(TextureID::Title))
{

    // Initial grade JLPT N5
    grade = 5;

    // Initial state is Title Screen
    programState = ProgramState::TitleScreen;

    // Create the window
    window.create(sf::VideoMode({WINDOW_WIDTH,WINDOW_HEIGHT}),WINDOW_TITLE,sf::Style::Close);
    window.setFramerateLimit(FPS);
    sf::Image iconImage;

    if(!iconImage.loadFromFile(ICON_PATH)){
        std::cerr << "ERROR: couldn't load the icon. Is it located at " << ICON_PATH << " and has the right permissions?" << std::endl;
    }

    window.setIcon(iconImage.getSize(), iconImage.getPixelsPtr());

    // Background and title for the title screen
    background.setScale({2.0, 2.0});
    
    title.setPosition({TITLE_X, TITLE_Y});
    title.setOrigin({title.getTextureRect().size.x/2.f,title.getTextureRect().size.y/2.f});
}

void MainWindow::start(){

    // Put it in a pointer so that it's easier to use
    TextureHolder * textureHolder = TextureHolder::getInstance();

    // Menu buttons
    Button gradeSelector(textureHolder->get(TextureID::BigMenuButtonBottom),textureHolder->get(TextureID::BigMenuButtonTop));
    gradeSelector.setPosition(GRADE_MENU_BUTTON_X,GRADE_MENU_BUTTON_Y);
    gradeSelector.setTextColor(TEXT_COLOR);
    gradeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    Button leftArrow(textureHolder->get(TextureID::MenuArrowLeftBottom),textureHolder->get(TextureID::MenuArrowLeftTop));
    leftArrow.setPosition(MENU_ARROW_LEFT_X,MENU_ARROW_LEFT_Y);
    leftArrow.setButtonColor(BUTTON_COLOR_NORMAL);
    leftArrow.setPressedButtonAction([&](Button &button){
        grade++;
        if(grade == 6) grade = 1;
        this->updateMasteredCount(gradeSelector);
    });

    Button rightArrow(textureHolder->get(TextureID::MenuArrowRightBottom),textureHolder->get(TextureID::MenuArrowRightTop));
    rightArrow.setPosition(MENU_ARROW_RIGHT_X,MENU_ARROW_RIGHT_Y);
    rightArrow.setButtonColor(BUTTON_COLOR_NORMAL);
    rightArrow.setPressedButtonAction([&](Button &button){
        grade--;
        if(grade == 0) grade = 5;
        this->updateMasteredCount(gradeSelector);
    });

    Button godModeSelector(textureHolder->get(TextureID::BigMenuButtonBottom),textureHolder->get(TextureID::BigMenuButtonTop));
    godModeSelector.setPosition(GODMODE_MENU_BUTTON_X,GODMODE_MENU_BUTTON_Y);
    godModeSelector.setText("God Mode");
    godModeSelector.setTextColor(TEXT_COLOR);
    godModeSelector.setButtonColor(BUTTON_COLOR_NORMAL);

    menuButtons.push_back(&leftArrow);
    menuButtons.push_back(&rightArrow);
    menuButtons.push_back(&gradeSelector);
    menuButtons.push_back(&godModeSelector);

    // Sign for the kanji/word that is being asked/taught
    Sign kanjiWordSign(textureHolder->get(TextureID::QuestionSign));
    kanjiWordSign.setPosition(KANJI_WORD_SIGN_X, KANJI_WORD_SIGN_Y);
    kanjiWordSign.setTextColor(TEXT_COLOR);
    kanjiWordSign.setSignColor(BUTTON_COLOR_NORMAL);
    kanjiWordSign.setFont(FontHolder::getInstance()->get(FontID::ShipporiFont));
    kanjiWordSign.setMaxTextSize(INITIAL_FONT_SIZE*2);

    // Sign for the current progress of the kanji/word
    Sign progressSign(textureHolder->get(TextureID::InstructionsSign));
    progressSign.setPosition(PROGRESS_SIGN_X,PROGRESS_SIGN_Y);
    progressSign.setTextColor(TEXT_COLOR);
    progressSign.setSignColor(BUTTON_COLOR_NORMAL);

    // Sign for the instructions for the current exercise
    Sign instructionsSign(textureHolder->get(TextureID::InstructionsSign));
    instructionsSign.setPosition(INSTRUCTIONS_SIGN_X,INSTRUCTIONS_SIGN_Y);
    instructionsSign.setTextColor(TEXT_COLOR);
    instructionsSign.setSignColor(BUTTON_COLOR_NORMAL);

    // Sign for the kanji meaning in the tutorial
    Sign tutorialKanjiMeaning(textureHolder->get(TextureID::MeaningSign));
    tutorialKanjiMeaning.setPosition(KANJI_MEANING_SIGN_X,KANJI_MEANING_SIGN_Y);
    tutorialKanjiMeaning.setTextColor(TEXT_COLOR);
    tutorialKanjiMeaning.setSignColor(BUTTON_COLOR_NORMAL);

    // Sign for the word meaning in the tutorial
    Sign tutorialWordMeaning(textureHolder->get(TextureID::WordTutorialSign));
    tutorialWordMeaning.setPosition(WORD_MEANING_SIGN_X,WORD_MEANING_SIGN_Y);
    tutorialWordMeaning.setTextColor(TEXT_COLOR);
    tutorialWordMeaning.setSignColor(BUTTON_COLOR_NORMAL);

    // Sign that says "Kunyomi"
    Sign kunyomiSign(textureHolder->get(TextureID::KunOnSign));
    kunyomiSign.setPosition(KUNYOMI_SIGN_X,KUNYOMI_SIGN_Y);
    kunyomiSign.setTextColor(TEXT_COLOR);
    kunyomiSign.setSignColor(BUTTON_COLOR_NORMAL);
    kunyomiSign.setText(L"Kunyomi\nreadings:");

    // Sign that says "Onyomi"
    Sign onyomiSign(textureHolder->get(TextureID::KunOnSign));
    onyomiSign.setPosition(ONYOMI_SIGN_X,ONYOMI_SIGN_Y);
    onyomiSign.setTextColor(TEXT_COLOR);
    onyomiSign.setSignColor(BUTTON_COLOR_NORMAL);
    onyomiSign.setText(L"Onyomi\nreadings:");

    // Signs for the Kunyomi readings
    Sign readingSign(textureHolder->get(TextureID::ReadingSign));
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

    // Short answer buttons
    Button shortAnswerButton(textureHolder->get(TextureID::ShortExerciseButtonBottom),textureHolder->get(TextureID::ShortExerciseButtonTop));
    shortAnswerButton.setTextColor(TEXT_COLOR);
    shortAnswerButton.setButtonColor(BUTTON_COLOR_NORMAL);
    shortAnswerButton.setPressedButtonAction([&progressSign](Button &thisButton){
        int meanProgress,kunProgress,onProgress,drawProgress;
        if(Controller::getInstance()->checkAnswer(thisButton.getText(),meanProgress,kunProgress,onProgress,drawProgress)){
            thisButton.setButtonColor(sf::Color::White);
            thisButton.setFinalColor(BUTTON_COLOR_CORRECT);
        } else {
            thisButton.setButtonColor(sf::Color::Black);
            thisButton.setFinalColor(BUTTON_COLOR_INCORRECT);
        }
        progressSign.setText("Meaning: " + std::to_string(meanProgress) + "%\n\nKunyomi: " + std::to_string(kunProgress) + "%\n\nOnyomi: " + std::to_string(onProgress) + "%\n\nDrawing: " + std::to_string(drawProgress) + "%");
    });
    shortAnswerButton.setReleasedButtonAction([&](Button &thisButton){
        if(Controller::getInstance()->allAnswered()){
            getExercise(thisButton);
        }
    });

    for(int i=0;i<9;i++){
        shortAnswerButton.setPosition(SHORT_EXERCISE_BUTTON_X[i],SHORT_EXERCISE_BUTTON_Y[i]);
        shortExerciseButtons.push_back(shortAnswerButton);
    }

    // Long answer buttons
    Button longAnswerButton(textureHolder->get(TextureID::LongExerciseButtonBottom),textureHolder->get(TextureID::LongExerciseButtonTop));
    longAnswerButton.setTextColor(TEXT_COLOR);
    longAnswerButton.setButtonColor(BUTTON_COLOR_NORMAL);
    longAnswerButton.setPressedButtonAction([&progressSign](Button &thisButton){
        std::wstring answer = util::trimLineFeeds(thisButton.getText());
        if(Controller::getInstance()->getCurrentExercise().getExerciseType() == ProgramState::KanjiMean){
            int meanProgress,kunProgress,onProgress,drawProgress;
            if(Controller::getInstance()->checkAnswer(answer,meanProgress,kunProgress,onProgress,drawProgress)){
                thisButton.setButtonColor(sf::Color::White);
                thisButton.setFinalColor(BUTTON_COLOR_CORRECT);
            } else {
                thisButton.setButtonColor(sf::Color::Black);
                thisButton.setFinalColor(BUTTON_COLOR_INCORRECT);
            }
            progressSign.setText("Meaning: " + std::to_string(meanProgress) + "%\n\nKunyomi: " + std::to_string(kunProgress) + "%\n\nOnyomi: " + std::to_string(onProgress) + "%\n\nDrawing: " + std::to_string(drawProgress) + "%");
        } else {
            int pronProgress, meanProgress;
            if(Controller::getInstance()->checkAnswer(answer,pronProgress,meanProgress)){
                thisButton.setButtonColor(sf::Color::White);
                thisButton.setFinalColor(BUTTON_COLOR_CORRECT);
            } else {
                thisButton.setButtonColor(sf::Color::Black);
                thisButton.setFinalColor(BUTTON_COLOR_INCORRECT);
            }
            progressSign.setText("Pronunciation: " + std::to_string(pronProgress) + "%\n\nMeaning: " + std::to_string(meanProgress) + "%");
        }

    });
    longAnswerButton.setReleasedButtonAction([&](Button &thisButton){
        if(Controller::getInstance()->allAnswered()){
            getExercise(thisButton);
        }
    });

    for(int i=0;i<6;i++){
        longAnswerButton.setPosition(LONG_EXERCISE_BUTTON_X[i],LONG_EXERCISE_BUTTON_Y[i]);
        longExerciseButtons.push_back(longAnswerButton);
    }

    // Sign for the word pronunciation in the tutorial
    Sign tutorialPronunciation(textureHolder->get(TextureID::WordTutorialSign));
    tutorialPronunciation.setPosition(WORD_PRON_SIGN_X,WORD_PRON_SIGN_Y);
    tutorialPronunciation.setTextColor(TEXT_COLOR);
    tutorialPronunciation.setSignColor(BUTTON_COLOR_NORMAL);

    // Board that tells the user what strokes to draw during the tutorial
    ShowingBoard strokeTutorialBoardShow(textureHolder->get(TextureID::DrawingBoard));
    strokeTutorialBoardShow.setBoardColor(BOARD_TUTORIAL_SHOW_COLOR);
    strokeTutorialBoardShow.setStrokeColor(STROKE_TUTORIAL_SHOW_COLOR);
    strokeTutorialBoardShow.setPosition(BOARD_TUTORIAL_SHOW_X,BOARD_TUTORIAL_SHOW_Y);

    // Board that lets the user practice during the tutorial
    DrawingBoard strokeTutorialBoardDraw(textureHolder->get(TextureID::DrawingBoard));
    strokeTutorialBoardDraw.setBoardColor(BOARD_DRAW_COLOR);
    strokeTutorialBoardDraw.setStrokeColor(STROKE_DRAW_COLOR);
    strokeTutorialBoardDraw.setPosition(BOARD_TUTORIAL_DRAW_X,BOARD_TUTORIAL_DRAW_Y);

    // Board that lets the user draw in stroke exercises
    DrawingBoard strokeExerciseBoard(textureHolder->get(TextureID::DrawingBoard));
    strokeExerciseBoard.setBoardColor(BOARD_DRAW_COLOR);
    strokeExerciseBoard.setStrokeColor(STROKE_DRAW_COLOR);
    strokeExerciseBoard.setPosition(BOARD_EXERCISE_DRAW_X,BOARD_EXERCISE_DRAW_Y);

    // Button that lets you undo a stroke in the stroke tutorial
    Button strokeTutorialUndoButton(textureHolder->get(TextureID::UndoArrowBottom),textureHolder->get(TextureID::UndoArrowTop));
    strokeTutorialUndoButton.setButtonColor(UNDO_BUTTON_COLOR);
    strokeTutorialUndoButton.setPosition(UNDO_BUTTON_X, UNDO_BUTTON_Y);

    // Button to continue in the tutorial
    Button continueButton(textureHolder->get(TextureID::ShortExerciseButtonBottom),textureHolder->get(TextureID::ShortExerciseButtonTop));
    continueButton.setPosition(PROGRESS_SIGN_X,PROGRESS_SIGN_Y);
    continueButton.setText(L"Continue");
    continueButton.setButtonColor(CONTINUE_COLOR);
    continueButton.setPressedButtonAction([](Button &button){});

    // Button to go back to the main menu
    Button mainMenuButton(textureHolder->get(TextureID::MenuArrowLeftBottom),textureHolder->get(TextureID::MenuArrowLeftTop));
    mainMenuButton.setPosition(BACK_MENU_BUTTON_X, BACK_MENU_BUTTON_Y);
    mainMenuButton.setButtonColor(BUTTON_COLOR_NORMAL);
    mainMenuButton.setPressedButtonAction([](Button &button){});
    mainMenuButton.setReleasedButtonAction([&](Button &button){
        Controller::getInstance()->save();
        this->programState = ProgramState::TitleScreen;
        for(Button * button : menuButtons) button->resetPosition();
        updateMasteredCount(gradeSelector);
    });

    // Button to save the progress
    Button saveButton(textureHolder->get(TextureID::SaveBottom),textureHolder->get(TextureID::SaveTop));
    saveButton.setPosition(SAVE_BUTTON_X, SAVE_BUTTON_Y);
    saveButton.setButtonColor(SAVED_COLOR);
    saveButton.setPressedButtonAction([](Button &button){});
    saveButton.setReleasedButtonAction([](Button &button){
        Controller::getInstance()->save();
        button.setButtonColor(SAVED_COLOR);
    });

    // Button that shows the tutorial page for the following exercise
    Button helpButton(textureHolder->get(TextureID::HelpBottom),textureHolder->get(TextureID::HelpTop));
    helpButton.setPosition(HELP_BUTTON_X, HELP_BUTTON_Y);
    helpButton.setButtonColor(HELP_COLOR);
    helpButton.setPressedButtonAction([](Button &button){});

    // Function used to get an exercise (can be a tutorial for a new kanji/word)
    getExercise = [&] (Button& button){

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
            progressSign.setText("Meaning: " + std::to_string(exercise.getMeaningProgress()) + "%\n\nKunyomi: " + std::to_string(exercise.getKunyomiProgress()) + "%\n\nOnyomi: " + std::to_string(exercise.getOnyomiProgress()) + "%\n\nDrawing: " + std::to_string(exercise.getDrawingProgress()) + "%");

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
        case ProgramState::KanjiStroke:

            if(oldState != ProgramState::KanjiStroke){
                helpButton.resetPosition();
            }

            // Set sign with progress
            progressSign.setText("Meaning: " + std::to_string(exercise.getMeaningProgress()) + "%\n\nKunyomi: " + std::to_string(exercise.getKunyomiProgress()) + "%\n\nOnyomi: " + std::to_string(exercise.getOnyomiProgress()) + "%\n\nDrawing: " + std::to_string(exercise.getDrawingProgress()) + "%");
            strokeExerciseBoard.clearBoard();

            break;
        case ProgramState::KanjiTutor:
        {

            if(oldState != ProgramState::WordTutor ||
               oldState != ProgramState::KanjiTutor ||
               oldState != ProgramState::StrokeTutor){
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
                progressSign.setText("Meaning: " + std::to_string(exercise.getMeaningProgress()) + "%\n\nKunyomi: " + std::to_string(exercise.getKunyomiProgress()) + "%\n\nOnyomi: " + std::to_string(exercise.getOnyomiProgress()) + "%\n\nDrawing: " + std::to_string(exercise.getDrawingProgress()) + "%");
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
            if(oldState != ProgramState::WordTutor ||
               oldState != ProgramState::KanjiTutor ||
               oldState != ProgramState::StrokeTutor){
                continueButton.resetPosition();
            }

            tutorialWordMeaning.setText(exercise.getTutorialMeaning());

            tutorialPronunciation.setText(exercise.getWordPronunciation());
        }
            break;
        case ProgramState::StrokeTutor:
        {
            if(oldState != ProgramState::WordTutor ||
               oldState != ProgramState::KanjiTutor ||
               oldState != ProgramState::StrokeTutor){
                continueButton.resetPosition();
            }

            strokeTutorialBoardShow.setStrokes(exercise.getStrokes());
            strokeTutorialBoardDraw.clearBoard();
        }
        case ProgramState::TitleScreen:

            this->updateMasteredCount(gradeSelector);

            break;
        default:
            break;
        }
    };

    gradeSelector.setPressedButtonAction([&](Button &button){
        Controller::getInstance()->setGrade(grade);
        mainMenuButton.resetPosition();
        saveButton.resetPosition();
        helpButton.resetPosition();
    });

    godModeSelector.setPressedButtonAction([&](Button &button){
        Controller::getInstance()->setGodMode(true);
        mainMenuButton.resetPosition();
        saveButton.resetPosition();
        helpButton.resetPosition();
    });

    gradeSelector.setReleasedButtonAction(getExercise);
    godModeSelector.setReleasedButtonAction(getExercise);
    continueButton.setReleasedButtonAction(getExercise);

    helpButton.setReleasedButtonAction([&](Button& button){

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
        case ProgramState::StrokeTutor:
        {
            if(oldState != ProgramState::WordTutor ||
               oldState != ProgramState::KanjiTutor ||
               oldState != ProgramState::StrokeTutor){
                continueButton.resetPosition();
            }

            strokeTutorialBoardShow.setStrokes(exercise.getStrokes());
            strokeTutorialBoardDraw.clearBoard();
        }
        default:
            break;
        }
    });

    // Action for the stroke exercise board
    strokeExerciseBoard.setFinishedStrokeAction([&](DrawingBoard &thisBoard){

        sf::VertexArray latestStroke = thisBoard.getLatestStroke();

        thisBoard.undo();

        if(Controller::getInstance()->checkStroke(latestStroke)){
            thisBoard.addStroke(latestStroke);
        } else {
            Kanji k = KanjiRepository::getInstance()->getKanji(Controller::getInstance()->getCurrentExercise().getHashCode());
            progressSign.setText("Meaning: " + std::to_string(k.getMeaningProgress()) + "%\n\nKunyomi: " + std::to_string(k.getKunyomiProgress()) + "%\n\nOnyomi: " + std::to_string(k.getOnyomiProgress()) + "%\n\nDrawing: " + std::to_string(k.getDrawingProgress()) + "%");
        }

        if(Controller::getInstance()->strokesCompleted(thisBoard.getNumStrokes())){
            // For some reason i forgor :skull: this function needs to be passed a button even though it
            // doesn't even need to use a button so i'll just make a button out of thin air and pass it
            // TODO: I need to get rid of this
            Button aaa(textureHolder->get(TextureID::BigMenuButtonBottom),textureHolder->get(TextureID::BigMenuButtonTop));
            getExercise(aaa);
        }
    });

    // Action for the stroke tutorial board
    strokeTutorialBoardDraw.setFinishedStrokeAction([&](DrawingBoard &thisBoard){
        sf::VertexArray stroke = thisBoard.getLatestStroke();

        thisBoard.undo();

        if(Controller::getInstance()->checkStrokeTutorial(stroke,thisBoard.getNumStrokes())){
            thisBoard.addStroke(stroke);
            strokeTutorialBoardShow.nextStroke();
        }
    });

    // Action for the undo button
    strokeTutorialUndoButton.setReleasedButtonAction([&](Button &thisButton){
        strokeTutorialBoardDraw.undo();
        strokeTutorialBoardShow.undo();
    });

    // Before starting, update the content of the grade selector
    updateMasteredCount(gradeSelector);

    programState = ProgramState::TitleScreen;

    while(window.isOpen()){

        // Event handling phase
        std::optional<sf::Event> event;
        while(event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
                Controller::getInstance()->saveAndExit();
            } else {
                switch(programState){
                case ProgramState::TitleScreen:
                    for(Button * button : menuButtons) button->notify(event.value());
                    break;
                case ProgramState::KanjiKun:
                case ProgramState::KanjiOn:
                    for(Button &button : shortExerciseButtons) button.notify(event.value());
                    mainMenuButton.notify(event.value());
                    saveButton.notify(event.value());
                    helpButton.notify(event.value());
                    break;
                case ProgramState::KanjiStroke:
                    strokeExerciseBoard.notify(event.value());
                    mainMenuButton.notify(event.value());
                    saveButton.notify(event.value());
                    helpButton.notify(event.value());
                    break;
                case ProgramState::WordPron:
                case ProgramState::WordMean:
                case ProgramState::KanjiMean:
                    for(Button &button : longExerciseButtons) button.notify(event.value());
                    mainMenuButton.notify(event.value());
                    saveButton.notify(event.value());
                    helpButton.notify(event.value());
                    break;
                case ProgramState::StrokeTutor:
                    strokeTutorialBoardDraw.notify(event.value());
                    strokeTutorialUndoButton.notify(event.value());
                    // No break (C++ trick)
                case ProgramState::KanjiTutor:
                case ProgramState::WordTutor:
                    continueButton.notify(event.value());
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
            // No break (C++ trick)
        case ProgramState::KanjiStroke:
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
        case ProgramState::StrokeTutor:
            strokeTutorialUndoButton.update();
            // No break (C++ trick)
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
        case ProgramState::KanjiStroke:
            window.draw(kanjiWordSign);
            window.draw(instructionsSign);
            window.draw(progressSign);
            window.draw(strokeExerciseBoard);
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
        case ProgramState::StrokeTutor:
            window.draw(kanjiWordSign);
            window.draw(instructionsSign);
            window.draw(continueButton);
            window.draw(strokeTutorialBoardDraw);
            window.draw(strokeTutorialBoardShow);
            window.draw(strokeTutorialUndoButton);
            break;
        }

        window.display();
    }

}
