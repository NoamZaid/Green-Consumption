#include "RegistrationWindow.h"
#include "game.h"
#include "question.h"
#include <QApplication>
#include <fstream>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include "dialogquestion.h"
#include <QDialog>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RegistrationWindow w;
    w.show();

    return a.exec();
}



