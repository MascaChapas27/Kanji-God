#include "KanjiRepository.hpp"
#include "Exercise.hpp"
#include "Utilities.hpp"
#include "FuckWindows.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include <chrono>

KanjiRepository * KanjiRepository::kanjiRepository = nullptr;

KanjiRepository * KanjiRepository::getInstance()
{
    if(kanjiRepository == nullptr) {
        kanjiRepository = new KanjiRepository;
        kanjiRepository->loadAllKanjis();
    }
    return kanjiRepository;
}

// Operation that loads all kanji and progress for kanji in one file
void KanjiRepository::loadAllKanjis(){

    for(int i=1;i<=5;i++){

        // Open the readings/meanings file
        #ifdef __linux__
        std::wfstream file("files/JLPTN" + std::to_string(i) + "kanji.txt");

        if(!file.is_open()){
            std::cerr << "ERROR: file " << "files/JLPTN" << std::to_string(i) << "kanji.txt" <<" not found" << std::endl;
            exit(EXIT_FAILURE);
        }

        file.imbue(std::locale("C.UTF-8"));
        #else
        std::wstringstream file(FuckWindows::kanjisForWindows[i]);
        #endif
        std::wstring data;

        // Line that should be a kanji symbol (or "#")
        getline(file,data);

        while(data != L"#"){
            Kanji k;

            k.setGrade(i);

            k.setKanji(data);

            // Read the meaning
            getline(file,data);

            k.setMeaning(data);

            std::set<std::wstring> onyomi;
            // Read the onyomi readings
            getline(file,data);

            while( data != L""){
                onyomi.insert(data);
                getline(file,data);
            }

            k.setOnyomiReadings(onyomi);

            std::set<std::wstring> kunyomi;
            // Read the onyomi readings
            getline(file,data);
            while(data != L"ーーーー"){
                kunyomi.insert(data);
                getline(file,data);
            }

            k.setKunyomiReadings(kunyomi);

            k.setKunyomiProgress(-1);
            k.setOnyomiProgress(-1);
            k.setMeaningProgress(-1);

            hash_t hash = util::hash(k.getKanji());

            if(!kanjis.count(hash)) {
                newKanjis[i].push_back(hash);
            } else {
                std::wcerr << "WARNING: Found hash collision between " << k.getMeaning() << " and " << kanjis[hash].getMeaning() << " (" << hash << ")" << std::endl;
            }

            kanjis[hash] = k;

            // Kanji symbol or "#"
            getline(file,data);
        }

        #ifdef __linux__
        file.close();
        #endif

        // Open the progress file
        std::wfstream fileprogress("save/JLPTN" + std::to_string(i) + "kanjiprogress.txt");

        if(!fileprogress.is_open()){
            // The file doesn't exist: let's create it
            fileprogress.open("save/JLPTN" + std::to_string(i) + "kanjiprogress.txt",std::fstream::out);

            for(hash_t hashCode : newKanjis[i]){
                fileprogress << hashCode << "\n-1\n-1\n-1\n-1\n";
                kanjis[hashCode].setMeaningProgress(-1);
                kanjis[hashCode].setKunyomiProgress(-1);
                kanjis[hashCode].setOnyomiProgress(-1);
                kanjis[hashCode].setDrawingProgress(-1);
            }

            fileprogress << "#";
        } else {

            // First line, can be a "#" or a hash code
            getline(fileprogress,data);

            while(data != L"#"){

                hash_t hashCode = std::stoul(data);

                if(!kanjis.count(hashCode))
                    std::wcerr << "WARNING: In grade " << i << " found saved data for kanji with hash code " << hashCode << " but no kanji was found" << std::endl;

                // Get the kanji and assign it the progress numbers
                Kanji &k = kanjis[hashCode];

                getline(fileprogress,data);
                int meaningProgress = std::stoi(data);

                getline(fileprogress,data);
                int kunyomiProgress = std::stoi(data);

                getline(fileprogress,data);
                int onyomiProgress = std::stoi(data);

                getline(fileprogress,data);
                int drawingProgress = std::stoi(data);

                k.setMeaningProgress(meaningProgress);
                k.setKunyomiProgress(kunyomiProgress);
                k.setOnyomiProgress(onyomiProgress);
                k.setDrawingProgress(drawingProgress);

                // Classify the kanji depending on the progress numbers
                if (meaningProgress == MAX_PROGRESS && kunyomiProgress == MAX_PROGRESS && onyomiProgress == MAX_PROGRESS && drawingProgress == MAX_PROGRESS){
                    auto position = std::find(newKanjis[i].begin(),newKanjis[i].end(),hashCode);
                    if(position != newKanjis[i].end()){
                        newKanjis[i].erase(position);
                        masteredKanjis[i].push_back(hashCode);
                    }
                // For practicing kanjis don't consider drawing progress because it can be -1 even if the kanji is being practiced
                } else if (meaningProgress != NO_PROGRESS && kunyomiProgress != NO_PROGRESS && onyomiProgress != NO_PROGRESS){
                    auto position = std::find(newKanjis[i].begin(),newKanjis[i].end(),hashCode);
                    if(position != newKanjis[i].end()){
                        newKanjis[i].erase(position);
                        practicingKanjis[i].push_back(hashCode);
                    }
                }

                // Get the next line, which can be a hash code or a "#"
                getline(fileprogress,data);
            }
        }

        fileprogress.close();

        // Open the strokes file
        #ifdef __linux__
        std::wfstream fileStrokes("files/JLPTN" + std::to_string(i) + "strokes.txt");

        if(!fileStrokes.is_open()){
            std::cerr << "ERROR: file " << "files/JLPTN" << std::to_string(i) << "strokes.txt" << " not found" << std::endl;
            exit(EXIT_FAILURE);
        }

        fileStrokes.imbue(std::locale("C.UTF-8"));
        #else
        std::wstringstream fileStrokes(FuckWindows::strokesForWindows[i]);
        #endif

        // Line that should be a kanji or #
        getline(fileStrokes,data);

        while(data != L"#"){
            Kanji &k = kanjis[util::hash(data)];

            std::vector<sf::VertexArray> strokes;

            // Next lines should be lines containing positions of vertices for strokes (one stroke in each line)
            getline(fileStrokes,data);

            while(data != L""){

                sf::VertexArray va;
                va.setPrimitiveType(sf::LineStrip);

                for(std::wstring vertex : util::split(data,L';')){

                    std::vector<std::wstring> coordinates = util::split(vertex,L',');

                    sf::Vertex v;
                    v.position.x = std::stoi(coordinates[0]);
                    v.position.y = std::stoi(coordinates[1]);

                    va.append(v);
                }

                strokes.push_back(va);

                getline(fileStrokes,data);
            }

            // Now we have the strokes for the kanji
            k.setStrokes(strokes);

            // Next line should be a kanji or #
            getline(fileStrokes,data);
        }

        #ifdef __linux__
        fileStrokes.close();
        #endif

        // Shuffle the vectors to make them more unpredictable
        auto rng = std::default_random_engine {};
        rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle(std::begin(newKanjis[i]), std::end(newKanjis[i]), rng);
        std::shuffle(std::begin(practicingKanjis[i]), std::end(practicingKanjis[i]), rng);
        std::shuffle(std::begin(masteredKanjis[i]), std::end(masteredKanjis[i]), rng);
    }
}

Kanji KanjiRepository::getKanji(hash_t hashCode)
{
    if(kanjis.count(hashCode))
        return kanjis[hashCode];

    // If the kanji can't be found, return an empty kanji
    Kanji k;
    k.setKanji(L"");
    return k;
}

int KanjiRepository::getMasteredKanji(int kanjiGrade){
    return masteredKanjis[kanjiGrade].size();
}

int KanjiRepository::getTotalKanji(int kanjiGrade){
    return newKanjis[kanjiGrade].size() + practicingKanjis[kanjiGrade].size() + masteredKanjis[kanjiGrade].size();
}

Exercise KanjiRepository::getExercise(int grade, bool mastered)
{
    Kanji &k = kanjis[util::hash(L"一")];
    Exercise e = makeStrokeExercise(k);
    return e;
    Exercise exercise;

    if(!mastered && newKanjis[grade].size() > 0 && util::shouldLearnNewContent(practicingKanjis[grade].size(),false)){

        hash_t hashCode = newKanjis[grade].back();
        Kanji& chosenKanji = kanjis[hashCode];

        exercise = getTutorial(hashCode);

        chosenKanji.setKunyomiProgress(chosenKanji.getKunyomiReadings().empty() ? 100 : 0);
        chosenKanji.setOnyomiProgress(chosenKanji.getOnyomiReadings().empty() ? 100 : 0);
        chosenKanji.setMeaningProgress(0);

        newKanjis[grade].pop_back();
        practicingKanjis[grade].push_back(hashCode);

    } else if(!mastered && practicingKanjis[grade].size() == 0){
        exercise.setExerciseType(ProgramState::TitleScreen);
    } else {

        // Choose the kanji
        Kanji &chosenKanji = kanjis[mastered
                                    ?
                                    masteredKanjis[grade][rand()%masteredKanjis[grade].size()]
                                    :
                                    practicingKanjis[grade][rand()%practicingKanjis[grade].size()]];

        exercise.setHashCode(util::hash(chosenKanji.getKanji()));

        // Choose the type of question
        int exerciseType = rand()%4;

        bool decided = false;

        while(!decided){
            switch(exerciseType){
            case 0:
                if(!mastered && chosenKanji.getMeaningProgress()==MAX_PROGRESS)
                    exerciseType=(exerciseType+1)%4;
                else decided = true;
                break;

            case 1:
                if((!mastered && chosenKanji.getKunyomiProgress()==MAX_PROGRESS) ||
                   (mastered && chosenKanji.getKunyomiReadings().size() == 0))
                    exerciseType=(exerciseType+1)%4;
                else decided = true;
                break;

            case 2:
                if((!mastered && chosenKanji.getOnyomiProgress()==MAX_PROGRESS) ||
                   (mastered && chosenKanji.getOnyomiReadings().size() == 0))
                    exerciseType=(exerciseType+1)%4;
                else decided = true;
                break;
            case 3:
                if((!mastered && chosenKanji.getDrawingProgress()==MAX_PROGRESS))
                    exerciseType=(exerciseType+1)%4;
                else decided = true;
                break;
            }
        }

        // If the exercise is going to be a stroke exercise, treat it differently
        if(exerciseType == 3){
            return makeStrokeExercise(chosenKanji);
        }

        // Set for the answers that the exercise will have
        std::set<std::wstring> exerciseAnswers;

        // Vector that contains kanjis that will be used to get wrong answers. Get the
        // vector with the most kanjis of this grade
        std::vector<hash_t> &wrongAnswerKanjis =
        newKanjis[grade].size() >= practicingKanjis[grade].size()
        &&
        newKanjis[grade].size() >= masteredKanjis[grade].size()
        ?
        newKanjis[grade]
        :
        practicingKanjis[grade].size() >= newKanjis[grade].size()
        &&
        practicingKanjis[grade].size() >= masteredKanjis[grade].size()
        ?
        practicingKanjis[grade]
        :
        masteredKanjis[grade];

        // Add the correct answers first and then the wrong answers
        switch(exerciseType){
        case 0:
        {
            exercise.setExerciseType(ProgramState::KanjiMean);
            exerciseAnswers.insert(chosenKanji.getMeaning());

            int index = rand()%wrongAnswerKanjis.size();

            while(exerciseAnswers.size() < 6) {
                std::wstring meaning = kanjis[wrongAnswerKanjis[index]].getMeaning();
                if(exerciseAnswers.count(meaning))
                    continue;
                exerciseAnswers.insert(meaning);
                index = (index+1)%wrongAnswerKanjis.size();
            }
        }
            break;
        case 1:
        {
            exercise.setExerciseType(ProgramState::KanjiKun);
            for(std::wstring answer : chosenKanji.getKunyomiReadings())
                exerciseAnswers.insert(answer);

            int index = rand()%wrongAnswerKanjis.size();

            while(exerciseAnswers.size() < 9) {
                for(std::wstring kunyomi : kanjis[wrongAnswerKanjis[index]].getKunyomiReadings()){
                    if(exerciseAnswers.count(kunyomi))
                        continue;
                    if(exerciseAnswers.size() == 9)
                        break;
                    exerciseAnswers.insert(kunyomi);
                }
                index = (index+1)%wrongAnswerKanjis.size();
            }
        }
            break;
        case 2:
        {
            exercise.setExerciseType(ProgramState::KanjiOn);
            for(std::wstring answer : chosenKanji.getOnyomiReadings())
                exerciseAnswers.insert(answer);

            int index = rand()%wrongAnswerKanjis.size();

            while(exerciseAnswers.size() < 9) {
                for(std::wstring onyomi : kanjis[wrongAnswerKanjis[index]].getOnyomiReadings()){
                    if(exerciseAnswers.count(onyomi))
                        continue;
                    if(exerciseAnswers.size() == 9)
                        break;
                    exerciseAnswers.insert(onyomi);
                }
                index = (index+1)%wrongAnswerKanjis.size();
            }
            break;
        }
        }

        exercise.setQuestion(chosenKanji.getKanji());

        exercise.setAnswers(exerciseAnswers);

        exercise.setKunyomiProgress(chosenKanji.getKunyomiProgress());
        exercise.setOnyomiProgress(chosenKanji.getOnyomiProgress());
        exercise.setMeaningProgress(chosenKanji.getMeaningProgress());
        int drawingProgress = chosenKanji.getDrawingProgress();
        exercise.setDrawingProgress(drawingProgress == NO_PROGRESS ? MIN_PROGRESS : drawingProgress);

        switch(exercise.getExerciseType()){
        case ProgramState::KanjiKun:
            exercise.setHelp(L"Choose the\ncorrect kunyomi\nreadings for\nthe kanji shown");
            break;
        case ProgramState::KanjiOn:
            exercise.setHelp(L"Choose the\ncorrect onyomi\nreadings for\nthe kanji shown");
            break;
        case ProgramState::KanjiMean:
            exercise.setHelp(L"Choose the\ncorrect meaning\nfor the\nkanji shown");
            break;
        default:
            break;
        }
    }

    return exercise;
}

Exercise KanjiRepository::getMasteredExercise()
{
    int grade = 1 + rand() % 5;

    int counter = 0;

    while(counter<=5){
        counter++;
        if(masteredKanjis[grade].empty()){
            grade++;
            if (grade == 6) grade = 1;
        } else break;
    }

    if(counter <= 5) return getExercise(grade,true);
    else{
        Exercise e;
        e.setExerciseType(ProgramState::TitleScreen);
        return e;
    }
}

Exercise KanjiRepository::getTutorial(hash_t hashCode)
{
    Exercise exercise;

    exercise.setExerciseType(ProgramState::KanjiTutor);

    Kanji &chosenKanji = kanjis[hashCode];

    exercise.setHelp(L"Memorize the\ninformation\nabout the\nnew kanji");

    exercise.setHashCode(hashCode);

    exercise.setTutorialMeaning(chosenKanji.getMeaning());

    exercise.setKunyomiPronunciations(chosenKanji.getKunyomiReadings());

    exercise.setOnyomiPronunciations(chosenKanji.getOnyomiReadings());

    exercise.setQuestion(chosenKanji.getKanji());

    return exercise;
}

bool KanjiRepository::checkAnswer(Exercise &exercise, std::wstring answer)
{
    Kanji &kanji = kanjis[exercise.getHashCode()];

    bool correct = false;

    switch(exercise.getExerciseType()){
    case ProgramState::KanjiKun:
        correct = kanji.getKunyomiReadings().count(answer);
        if(correct) {
            exercise.setKunyomiProgress(exercise.getKunyomiProgress() + CORRECT_KUN_POINTS/kanji.getKunyomiReadings().size());
            if(exercise.getKunyomiProgress() > MAX_PROGRESS) exercise.setKunyomiProgress(MAX_PROGRESS);
        } else {
            exercise.setKunyomiProgress(exercise.getKunyomiProgress() - INCORRECT_KUN_POINTS);
            if(exercise.getKunyomiProgress() < MIN_PROGRESS) exercise.setKunyomiProgress(MIN_PROGRESS);
        }
        break;
    case ProgramState::KanjiOn:
        correct = kanji.getOnyomiReadings().count(answer);
        if(correct) {
            exercise.setOnyomiProgress(exercise.getOnyomiProgress() + CORRECT_ON_POINTS/kanji.getOnyomiReadings().size());
            if(exercise.getOnyomiProgress() > MAX_PROGRESS) exercise.setOnyomiProgress(MAX_PROGRESS);
        } else {
            exercise.setOnyomiProgress(exercise.getOnyomiProgress() - INCORRECT_ON_POINTS);
            if(exercise.getOnyomiProgress() < MIN_PROGRESS) exercise.setOnyomiProgress(MIN_PROGRESS);
        }
        break;
    case ProgramState::KanjiMean:
        correct = kanji.getMeaning() == answer;
        if(correct) {
            exercise.setMeaningProgress(exercise.getMeaningProgress() + CORRECT_KANJIMEAN_POINTS);
            if(exercise.getMeaningProgress() > MAX_PROGRESS) exercise.setMeaningProgress(MAX_PROGRESS);
        } else {
            exercise.setMeaningProgress(exercise.getMeaningProgress() - INCORRECT_KANJIMEAN_POINTS);
            if(exercise.getMeaningProgress() < MIN_PROGRESS) exercise.setMeaningProgress(MIN_PROGRESS);
        }
        break;
    default:
        return false;
    }

    kanji.setMeaningProgress(exercise.getMeaningProgress());
    kanji.setKunyomiProgress(exercise.getKunyomiProgress());
    kanji.setOnyomiProgress(exercise.getOnyomiProgress());

    if(kanji.getMeaningProgress() == MAX_PROGRESS &&
        kanji.getKunyomiProgress() == MAX_PROGRESS &&
        kanji.getOnyomiProgress() == MAX_PROGRESS){
        auto position = std::find(practicingKanjis[kanji.getGrade()].begin(),practicingKanjis[kanji.getGrade()].end(),exercise.getHashCode());
        if(position != practicingKanjis[kanji.getGrade()].end()){
            practicingKanjis[kanji.getGrade()].erase(position);
            masteredKanjis[kanji.getGrade()].push_back(exercise.getHashCode());
        }
    } else {
        auto position = std::find(masteredKanjis[kanji.getGrade()].begin(),masteredKanjis[kanji.getGrade()].end(),exercise.getHashCode());
        if(position != masteredKanjis[kanji.getGrade()].end()){
            masteredKanjis[kanji.getGrade()].erase(position);
            practicingKanjis[kanji.getGrade()].push_back(exercise.getHashCode());
        }
    }

    return correct;
}

bool KanjiRepository::allAnswered(Exercise &exercise, unsigned int answers)
{
    Kanji &kanji = kanjis[exercise.getHashCode()];

    bool completed = false;

    switch(exercise.getExerciseType()){
    case ProgramState::KanjiKun:
        completed = kanji.getKunyomiReadings().size() == answers;
        break;
    case ProgramState::KanjiOn:
        completed = kanji.getOnyomiReadings().size() == answers;
        break;
    case ProgramState::KanjiMean:
        completed = answers == 1;
        break;
    default:
        return false;
    }

    return completed;
}

bool KanjiRepository::checkStroke(Exercise &exercise, sf::VertexArray &stroke, int strokeNumber){

    sf::VertexArray realStroke = kanjis[exercise.getHashCode()].getStrokes()[strokeNumber];
    std::cerr << "Starting 1a" << std::endl;
    // First check: the size is similar
    double realSize = 0;
    for(unsigned int i=0;i<realStroke.getVertexCount()-1;i++){
        realSize += util::euclideanDistance(realStroke[i].position,realStroke[i+1].position);
    }
    std::cerr << "Starting 1b" << std::endl;
    double mySize = 0;
    for(unsigned int i=0;i<stroke.getVertexCount()-1;i++){
        mySize += util::euclideanDistance(stroke[i].position,stroke[i+1].position);
    }

    double ratio = realSize/mySize;

    if(ratio < MIN_STROKE_SIZE_RATIO || ratio > MAX_STROKE_SIZE_RATIO)
        return false;
    std::cerr << "Starting 2" << std::endl;
    // Second check: positions of first and last vertices are similar enough
    sf::Vector2f myFirstVertex = stroke[0].position;
    sf::Vector2f myLastVertex = stroke[stroke.getVertexCount()-1].position;
    sf::Vector2f realFirstVertex = realStroke[0].position;
    sf::Vector2f realLastVertex = realStroke[realStroke.getVertexCount()-1].position;

    if(util::euclideanDistance(myFirstVertex,realFirstVertex) > MAX_STROKE_VERTEX_DIST ||
       util::euclideanDistance(myLastVertex,realLastVertex) > MAX_STROKE_VERTEX_DIST){
        return false;
    }

    // If you are still here, the stroke is correct
    std::cerr << "Starting 3" << std::endl;
    stroke.clear();

    for(unsigned int i=0;i<realStroke.getVertexCount()-1;i++){std::cerr << "xd" << std::endl;
        stroke.append(realStroke[i]);
    }
    std::cerr << "aaa" << std::endl;
    return true;
}

bool KanjiRepository::strokesCompleted(Exercise &exercise, unsigned int numStrokes){
    return kanjis[exercise.getHashCode()].getStrokes().size() == numStrokes;
}

void KanjiRepository::save(){

    std::map<int,std::wfstream> files;

    for(int i=1;i<=5;i++){
        files[i] = std::wfstream("save/JLPTN"+std::to_string(i)+"kanjiprogress.txt",std::wfstream::trunc | std::wfstream::out);
    }

    for(auto &pair : kanjis){
        files[pair.second.getGrade()] << util::hash(pair.second.getKanji()) << L"\n" << pair.second.getMeaningProgress() << L"\n" << pair.second.getKunyomiProgress() << L"\n" << pair.second.getOnyomiProgress() << L"\n" << pair.second.getDrawingProgress() << L"\n";;
    }

    for(auto &pair : files){
        pair.second << L"#";
        pair.second.close();
    }
}

Exercise KanjiRepository::makeStrokeExercise(Kanji &k){

    Exercise e;

    e.setHashCode(util::hash(k.getKanji()));
    e.setQuestion(k.getMeaning());
    e.setStrokes(k.getStrokes());

    if(k.getDrawingProgress() == NO_PROGRESS){
        k.setDrawingProgress(MIN_PROGRESS);

        e.setExerciseType(ProgramState::StrokeTutor);
        e.setHelp(L"Practice how to draw the kanji");
    } else {
        e.setExerciseType(ProgramState::KanjiStroke);

        e.setMeaningProgress(k.getMeaningProgress());
        e.setKunyomiProgress(k.getKunyomiProgress());
        e.setOnyomiProgress(k.getOnyomiProgress());
        e.setDrawingProgress(k.getDrawingProgress());
        e.setHelp(L"Draw the kanji represented by its meaning");
    }

    return e;
}
