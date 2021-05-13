#include "game.h"
#include "dialogquestion.h"
#include <QDebug>
using namespace std;

Game::Game(QString filename)
{
    readQuestionList(filename);
}

void Game::readQuestionList(QString filename)   // read all the questions from the file into FullQuestionList
{
    QFile infile(filename);
    if(!infile.open(QIODevice::ReadOnly))   //
    {
        QMessageBox::information(0,"info",infile.errorString());    //check if the file can be accessed
        exit(0);
    }
    QTextStream in (&infile);
    QString question;           //to hold first line- the question.
    //QString temp;
    QVector <QString> answers;  //to hold 4 answers
    int correct;                //to hold index for corret answer
    while (!infile.atEnd())
    {
        question = infile.readLine();

        answers.append(infile.readLine());
        answers.append(infile.readLine());
        answers.append(infile.readLine());
        answers.append(infile.readLine());

        correct = infile.readLine().toInt(); // read and convert to int the index for correct answer

        Question q(question,answers,correct);   //creating a question object and fiiling FullQuestionList
        FullQuestionList.append(q);
        answers.clear();
    }
}

void Game::start(DialogQuestion &dialog)    //setting questions to dialog window
{
    CreateGameQuestions();
    for (int i = 0; i < questionsList.size(); i++)
    {
        dialog.setQuestions(questionsList[i]);
        dialog.exec();                              //executing a new dialog window every question
  }
}

void Game::CreateGameQuestions() //Generating random questions from FullQuestionList to questionsList
{
    QVector <int> holdRand; //vector to hold all the random indexes that were generated.
    for (int i = 0 ; i < numQuestions ; i++)
    {
        int num = QRandomGenerator::global()->bounded(FullQuestionList.size());;
        //holdRand.append(num);
        while (IsNumInVector(holdRand, num))    //check if it was generated
        {
            num = QRandomGenerator::global()->bounded(FullQuestionList.size());
        }
        questionsList.append(FullQuestionList[num]);    //fiiling questionsList randomly
        holdRand.append(num);                           //saving the random index in the vector
    }
}

bool Game::IsNumInVector(QVector<int> &vect, int num)   //to check if a random number was generated
{
    for (int i = 0 ; i < vect.size() ; i++)
    {
        if(vect[i] == num)
            return true;
    }
    return false;
}


