#include "question.h"

Question::Question(QString question, QVector<QString> ans, int correct) :   //initializing in the constructor
    theQuestion(question),                                                  //all members of question
    answers(ans),
    correctAnswer(correct)
{
}
