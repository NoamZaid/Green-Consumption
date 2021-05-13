#include "dialogquestion.h"
#include "ui_dialogquestion.h"
#include <QPixmap>

DialogQuestion::DialogQuestion(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::DialogQuestion)
{
    ui->setupUi(this);
    this->setWindowTitle("Green Consumption Trivia Game");
    QPixmap background("/Users/noamzaid/Sustainability.jpeg");  //window background image
    ui->Background_Label->setPixmap(background);
    game_timer = QTime(0,0,0);                                  //initialize time to 0:0:0
    t = new QTimer(this);
    connect(t,SIGNAL(timeout()),this,SLOT(timer()));            //connect the time to the function
    t->start(1000);
}

void DialogQuestion::setQuestions(Question &q)                  //initializing every question:
{
        ui->QuestionLabel->setText(q.getQuestion()); //print the question
        ui->PushAns0->setText(q.getAnswer(0));       //print answers:
        ui->PushAns1->setText(q.getAnswer(1));
        ui->PushAns2->setText(q.getAnswer(2));
        ui->PushAns3->setText(q.getAnswer(3));
        correctAnswer = q.getCorrect();              //initializing correctAnswer

    QPalette pal = ui->PushAns0->palette();           //reboot pushbuttons background color
    pal.setColor(QPalette::Button, QColor(Qt::red));
    ui->PushAns0->setAutoFillBackground(false);
    ui->PushAns1->setAutoFillBackground(false);
    ui->PushAns2->setAutoFillBackground(false);
    ui->PushAns3->setAutoFillBackground(false);
    game_timer = QTime(0,0,0);                        //reset to timer
    SecPerQ = 0;                                      //reset int timer
}

void DialogQuestion::updateStats()                    // print user status
{
    QString cor = QString::number(rightcounter);
    QString wor = QString::number(wrongcounter);
    ui->Stats->setText("Correct Answers: " + cor+"\n"+
                       "Wrong Answers:   " + wor+"\n");
}

void DialogQuestion::exportRecords(QString filename)    //export to text file
{
    QString cor = QString::number(rightcounter);
    QString wor = QString::number(wrongcounter);
    QString sco = QString::number(score);
    QFile outfile(filename);
    if(!outfile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QMessageBox::information(0,"info",outfile.errorString());
        exit(0);
    }

    QTextStream stream(&outfile);
    stream << "Correct Answers: " + cor+"\n"+
              "Wrong Answers:   " + wor+"\n"+
              "Final Score: " + sco+"\n";
}



DialogQuestion::~DialogQuestion()
{
    delete ui;
}


void DialogQuestion::on_Exit_clicked()
{
    exit(0);
}

void DialogQuestion::timer()    //function that is connected to the timer object and incrementing seconds
{
    //timer.setHMS(0,0,0);
    game_timer = game_timer.addSecs(1);
    QString time_text = game_timer.toString( "mm : ss");
    ui->Timer_Label->setText(time_text);
    SecPerQ++;    //every second the function is called SecPweQ is incrementing by 1. keep truck of seconcds as an integer.
}

void DialogQuestion::on_PushAns0_released()
{
    selectedAns = 0;
    checkAnswer(ui->PushAns0);
}

void DialogQuestion::on_PushAns1_released()
{
    selectedAns = 1;
    checkAnswer(ui->PushAns1);
}

void DialogQuestion::on_PushAns2_released()
{
    selectedAns = 2;
    checkAnswer(ui->PushAns2);
}

void DialogQuestion::on_PushAns3_released()
{
    selectedAns = 3;
    checkAnswer(ui->PushAns3);
}

void DialogQuestion::checkAnswer(QPushButton *push) // To check user's answers and update score
{

    if (selectedAns == correctAnswer)
    {
        score += 10;
        if (SecPerQ > 5 && SecPerQ < 7)
            score -= 1;
        else if (SecPerQ > 7 && SecPerQ < 10)
            score -= 2;
        else if (SecPerQ > 10)
            score -= 4;

        if (score <0)
            score = 0;
        ui->ErrorLabel->setText("Good Job!");
        rightcounter++;
        updateStats();
        close();
    }


    else if ( selectedAns != correctAnswer)
    {
        score -= 2;
        ui->ErrorLabel->setText("Wrong Answer!");
        wrongcounter++;
        updateStats();

        QPalette pal = push->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        push->setAutoFillBackground(true);
        push->setPalette(pal);
        push->update();
    }
}
