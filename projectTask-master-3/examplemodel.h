#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <QAbstractTableModel>
#include <vector>
#include <string>

class ExampleModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ExampleModel(QList<QList<QString > >& dt, QObject *parent = nullptr);
    explicit ExampleModel(std::string path, QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    void appendData( QList<QString>& x );

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList<QList<QString > > dataTable;
};

#endif // EXAMPLEMODEL_H
