#include "finalwindow.h"
#include "ui_finalwindow.h"
#include <QPixmap>

FinalWindow::FinalWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::FinalWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Game Over");
    QPixmap background("/Users/noamzaid/earth.jpeg");   //window background image
    ui->Background_Label->setPixmap(background);
}

FinalWindow::~FinalWindow()
{
    delete ui;
}

void FinalWindow::setFeedback()     //Print feedback based on the score
{
    QString feedback;
    if (mainDialog->getScore() >= 90)
    {
        feedback = "Wow, Great Job!\n";
    }

    else if (mainDialog->getScore() >= 80 && mainDialog->getScore() < 90 )
    {
        feedback = "good job!\n";
    }

    else if (mainDialog->getScore() >= 70 && mainDialog->getScore() < 80 )
    {
        feedback = "Pretty good, you know you can do better than than...\n";
    }

    else if (mainDialog->getScore() < 70 )
    {
        feedback = "I still have faith in you...\n";
    }

    QString score = QString::number(mainDialog->getScore());
    ui->FeedbackLabel->setText(feedback + "Your final score is " + score );
}

void FinalWindow::setDialog(DialogQuestion *dial)
{
    mainDialog = dial;
    setFeedback();
}



void FinalWindow::on_tryAgain_released()
{
    hide();
}




void FinalWindow::on_Exit_released()
{
    exit(0);
}
