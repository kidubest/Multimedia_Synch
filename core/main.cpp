#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // QString str_path = QString::fromStdString(path1) ;
    MainWindow w;


            //bool exists = QFile::exists("/home/bk/Desktop/Zigzan.wav");
     w.show();
   // out_();


    //qDebug () << str_path << endl;

    return a.exec();
}
