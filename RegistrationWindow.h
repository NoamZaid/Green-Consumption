#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class RegistrationWindow; }
QT_END_NAMESPACE

class RegistrationWindow : public QMainWindow
{
    Q_OBJECT

public:
    RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

private slots:


    void on_sustainability_clicked();

    void on_Exit_clicked();

    void on_greenConsumption_released();

private:


    Ui::RegistrationWindow *ui;
};
#endif // RegistrationWindow
