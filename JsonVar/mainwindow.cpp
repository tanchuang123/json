#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtDebug>
#include<QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    json=new JsonRead;
    QString filePath1 = "RoPlugins.json";
    QString filePath2 = "config.json";
    QFile file(filePath1);
   if(file.exists())
   {
      qDebug()<<"yes";
   }
   else
   {
       qDebug()<<"no";
   }
   QVariant var;
   var= json->getJsonVarian(filePath2);

   qDebug()<<var<<"";
   qDebug()<<var.toMap().value("pluginName").toString()<<"xxxxxxxxxx";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QString path=ui->lineEdit->text();
   json->addFolderImages(path);
}
