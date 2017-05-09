#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include "translationxml.h"


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

QString MainWindow::openFile()
{
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Open Document",
          QDir::currentPath(),
          "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");

    if( !filename.isNull() )
    {
      qDebug() << "selected file path : " << filename.toUtf8();
      return filename;
    }
    return NULL;
}

QString srcFile = "";
QString transFile = "";

// Chọn file cần dịch
void MainWindow::on_pushButton_clicked()
{
    srcFile = openFile();
}


void MainWindow::on_pushButton_2_clicked()
{
    transFile = openFile();
}

void MainWindow::on_pushButton_3_clicked()
{
    if ((srcFile != NULL) && (transFile != NULL) ) {
        qDebug() << "src: " << srcFile << "\ntrans: " << transFile;
        TranslationXML ts;
        ts.XMLTranslate(srcFile, transFile);
    }
}
