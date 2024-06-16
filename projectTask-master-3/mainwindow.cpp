#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <QFileDialog>
#include "clusters.h"
#include "readWrite.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clusterOutput = "clusters.txt";
    silhouetteOutput = "silhouettes.txt";
}


MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pushButton_clicked() // File - trigers the event "on_mnuFileOpen_triggered"
{
    MainWindow::on_mnuFileOpen_triggered();
}*/

void MainWindow::on_pushButton_clicked()
{
    inputFile = QFileDialog::getOpenFileName(this, "Выберите таблицу (файл формата .csv) для кластеризации", QDir::currentPath());
    ui->textEdit->setText(inputFile);

    std::ifstream in(inputFile.toStdString());
    if (in.is_open() == false)
    {
        ui->lineEdit->setText("input file is not chosen");
        return ;
    }
    in.close();
    ui->lineEdit->setText("input file is opened correctly");
}

void MainWindow::on_pushButton_4_clicked() // ReadingData
{
    std::ifstream in(inputFile.toStdString());
    if (in.is_open() == false)
    {
        ui->lineEdit->setText("input file is not chosen");
        return ;
    }

    ui->lineEdit->setText("reading points in progress");
    QApplication::processEvents();

    try {
        //readpoints(in, points); Implement  this function in readWrite.cpp  UNCOMMENT ME WHEN FIXED
        ui->lineEdit->setText("reading points done");
    } catch (std::exception &ex) {
        ui->lineEdit->setText(ex.what());
    }
}


void MainWindow::on_pushButton_2_clicked() // Clustering
{
    ui->lineEdit->setText("clustering points in progress");
    QApplication::processEvents();

    //clusteringPAM(points); //Implement this function in clusters.cpp, declare this function in clusters.h  UNCOMMENT ME WHEN FIXED

    write_clusters(clusterOutput.toStdString(), points);// Implement  this function in readWrite.cpp  UNCOMMENT ME WHEN FIXED

    exampleModel = new ExampleModel(clusterOutput.toStdString()); //* для лучшей оценки сделать наследование классов points, clusters от базового класса и создать виртуальную функцию, чтобы вместо файлов генерировать модель вторым конструктором из QList<QList<QString> > >
    ui->tableView->setModel(exampleModel);

    ui->lineEdit->setText("clustering done");

    return;
}


void MainWindow::on_pushButton_3_clicked() // Interpreting
{
    ui->lineEdit->setText("interptering points in progress");
    QApplication::processEvents();

    interpreting(points, clusters); //Implement this function in clusters.cpp, declare this function in clusters.h  UNCOMMENT ME WHEN FIXED
    write_siluettes(silhouetteOutput.toStdString(), clusters);// Implement  this function in readWrite.cpp  UNCOMMENT ME WHEN FIXED
    std::cout << silhouetteOutput.toStdString();
    exampleModel2 = new ExampleModel(silhouetteOutput.toStdString()); //* для лучшей оценки  сделать наследование классов points, clusters от базового класса и создать виртуальную функцию, чтобы вместо файлов генерировать модель вторым конструктором из QList<QList<QString> >
    //ui->tableView_2->setModel(exampleModel2);

    //ui->lineEdit->setText("interptering done");
}




