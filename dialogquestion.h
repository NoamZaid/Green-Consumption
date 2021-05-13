#ifndef DIALOGQUESTION_H
#define DIALOGQUESTION_H
#include "question.h"
#include <QWidget>
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui {
class DialogQuestion;
}
QT_END_NAMESPACE
class DialogQuestion : public QDialog
{
    Q_OBJECT

public:
    explicit DialogQuestion(QDialog *parent = nullptr); // QT constructor to initialize ui file
    void setQuestions(Question &q); //Function to reboot the dialog for every question
    void updateStats(); //track right and wrong answers
    void exportRecords(QString filename);   //export scores for a text file
    int getScore(){return score;}
    void checkAnswer(QPushButton *);    //To check if the user clicked the correct answer

//    void setDelay(unsigned long sec) {QThread::msleep(sec);}


    ~DialogQuestion();

private slots:

    void on_Exit_clicked();

    void timer();

    void on_PushAns0_released();

    void on_PushAns1_released();

    void on_PushAns2_released();

    void on_PushAns3_released();

private:
    Ui::DialogQuestion *ui;
    int selectedAns = -1;
    int correctAnswer;    //to hold int index from text file
    int rightcounter = 0; //keep truck of right answers
    int wrongcounter = 0; //keep truck of wrong answers
    QTimer *t;
    QTime game_timer;   //count time
    QTime window_counter;
    int SecPerQ = 0;    // hold second pre questions, to calculate score
    int score = 0;  //to build the user's score during the game
};

#endif // DIALOGQUESTION_H
