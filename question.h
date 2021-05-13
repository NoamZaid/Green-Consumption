#pragma once
#include <QVector>



class Question
{
private:
    QString theQuestion;    //string to hold every question
    QVector<QString> answers;   //Vector to hold all given possible answers
    int correctAnswer;          // to hold index for correct answer

public:
    //Constructor to initialize Question Object
    Question(QString question, QVector<QString> ans, int correct);
//  Question(Question &q); copy constructor not in used right now

    QString getAnswer(int i){return answers[i];}
    QString getQuestion(){return theQuestion; }
    int getCorrect(){return correctAnswer; }
};



