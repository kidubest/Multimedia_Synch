#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMultimedia>
#include <QMediaPlayer>
#include "assemble_all.h"
#include <QString>
#include <sstream>
#include <QTime>
#include <QDebug>
#include <QFileDialog>
#include <QDir>

//std::string std_str;
void delay( int millisecondsToWait );
QString file_main;
QString file_ref ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QMediaPlayer player;
QMediaPlayer player2;
static std::string std_str;

void MainWindow::on_pushButton_clicked()
{
    player.stop();
    float number;
    std::istringstream iss(std_str);
    iss >> number ;

    int num = number *1000;
    player.setMedia(QUrl::fromLocalFile(QFileInfo(file_main).absoluteFilePath()));
    player.setVolume(100);
    player.play();

    delay(num+2);
    qDebug() << num << endl;
    player2.setMedia(QUrl::fromLocalFile(QFileInfo(file_ref).absoluteFilePath()));
    player2.setVolume(100);
    player2.play();
}

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void out_ () {

    std_str = run_all();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = QString::fromStdString(std_str) ;
    ui->label_2->setText("the delay is " + str);
    player.stop();
    player2.stop();
}

void MainWindow::on_pushButton_3_clicked()
{
   qDebug () << file_main << endl;
    player2.stop();
    float number;
    std::istringstream iss(std_str);
    iss >> number ;

    
    int num = number *1000;
    player.setMedia(QUrl::fromLocalFile(QFileInfo(file_main).absoluteFilePath()));
    player.setVolume(100);
    player.play();


    //qDebug() << num << endl;
    player2.setMedia(QUrl::fromLocalFile(QFileInfo(file_ref).absoluteFilePath()));
    player2.setVolume(100);
    player2.play();
}

void MainWindow::on_pushButton_4_clicked()
{
    file_main = QFileDialog::getOpenFileName(this,
              tr("Open WAV file"), "/home", tr("WAV Files (*.WAV)"));
         ui->label_3->setText(file_main);

         QString filename = "main";

            QFile file(filename);
            if (file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << file_main << endl;
            }

}


void MainWindow::on_pushButton_5_clicked()
{
    file_ref = QFileDialog::getOpenFileName(this,
              tr("Open WAV file"), "/home", tr("WAV Files (*.WAV)"));
         ui->label->setText(file_ref);


         QString filename_2 = "ref";
             QFile file_2(filename_2);
            if (file_2.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file_2);
                stream << file_ref << endl;
            }
}

std::string path1= file_main.toStdString();
std::string path2= file_ref.toStdString();

 //qDebug() << file_main ;//<< "   " << path2 << endl;

void MainWindow::on_pushButton_6_clicked()
{
     out_ ();
}
