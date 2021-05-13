#include "RegistrationWindow.h"
#include "ui_registrationwindow.h"
using namespace std;
#include <iostream>
#include <string>
#include "game.h"
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QPixmap>


RegistrationWindow::RegistrationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Green Consumption Trivia Game");
    QPixmap background("/Users/noamzaid/Green_Consumption.jpeg");   //window background image
    ui->Background_Label->setPixmap(background);
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_sustainability_clicked()
{
    hide();
    Game game1("/Users/noamzaid/questions.txt");    //creating game object to read all questions from the file
    DialogQuestion dialog;                          //Dialog object to be passed to game.start
    dialog.setModal(true);
    game1.start(dialog);
    //dialog.exportRecords("/Users/noamzaid/records.txt");

    FinalWindow final;
    final.setDialog(&dialog);
    dialog.setModal(true);
    final.exec();                                   //run final window after all question were answered
    show();                                         //return to main window

}

void RegistrationWindow::on_greenConsumption_released()
{
    hide();
    Game game2("/Users/noamzaid/sustainability.txt");
    DialogQuestion dialog1;
    dialog1.setModal(true);
    game2.start(dialog1);

    FinalWindow final;
    final.setDialog(&dialog1);
    dialog1.setModal(true);
    final.exec();
    show();
}

void RegistrationWindow::on_Exit_clicked()
{
    exit(0);
}





