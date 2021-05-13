#ifndef GAME_H
#define GAME_H
#include "question.h"
#include <QVector>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include "dialogquestion.h"
#include "finalwindow.h"
#include <QRandomGenerator>
#include <QThread>
// #include <shmadagen>

class Game
{
private:
    QVector <Question> questionsList;   // Vector to hold questions to play with
    QVector <Question> FullQuestionList;    // Vector to hold all the questions from the file
    void readQuestionList(QString filename); // Function to read data from text and to fill FullQuestionList
    const int numQuestions = 10;    // amount of question to be played with (size of questionsList)

public:
    Game(QString filename); // constructor calls readQuestionList function
    void start(DialogQuestion &dialog); // To start the game (loop through all the questios)

    // Functions to radomly fill questionsList from FullQuestionList
    void CreateGameQuestions();
    bool IsNumInVector(QVector <int> &vect, int num);
};

#endif // GAME_H
