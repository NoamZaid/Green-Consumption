#ifndef FINALWINDOW_H
#define FINALWINDOW_H
#include <QDialog>
#include <QWidget>
#include "question.h"
#include "game.h"
#include "RegistrationWindow.h"
#include "dialogquestion.h"
#include <QDebug>

namespace Ui {
class FinalWindow;
}

class FinalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FinalWindow(QDialog *parent = nullptr);
    ~FinalWindow();
    void setFeedback(); // function to print the user's score along with feedback

    //  to copy the Dialog object into the finalwindow in order to access the score
    void setDialog(DialogQuestion *dial);
private slots:

    void on_tryAgain_released(); // start over

    void on_Exit_released();    //exit

private:
    Ui::FinalWindow *ui;
    DialogQuestion *mainDialog;
};

#endif // FINALWINDOW_H
