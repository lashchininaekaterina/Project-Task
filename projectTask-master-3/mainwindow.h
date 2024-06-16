#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "examplemodel.h"
#include "clusters.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fillTableView(const QString& input);

private slots:

    void on_pushButton_clicked(); // File

    void on_pushButton_2_clicked(); // Clustering

    //void on_mnuFileOpen_triggered(); // open file event

    void on_pushButton_3_clicked(); // Interpreting

    void on_pushButton_4_clicked(); // Reading data

private:
    Ui::MainWindow *ui;
    ExampleModel *exampleModel;
    ExampleModel *exampleModel2;
    QString inputFile;
    QString clusterOutput;
    QString silhouetteOutput;
    std::vector<mycluster::point> points;
    std::vector<mycluster::cluster> clusters;
};
#endif // MAINWINDOW_H
