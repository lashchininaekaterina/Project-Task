#include "examplemodel.h"
#include <fstream>
#include <string>
#include <sstream>

ExampleModel::ExampleModel(QList<QList<QString> >& dt, QObject *parent) // passing data to the model from a QList
    : QAbstractTableModel(parent)
{
    //dataTable.resize(dt.size());
    for(int i = 0; i < dt.size(); i++)
    {
        for(int j = 0; j < dt[i].size(); j++)
        {
            dataTable[i].append(dt[i][j]);
        }
    }
}

ExampleModel::ExampleModel(std::string path, QObject *parent) // path - leads to a file with data
    : QAbstractTableModel(parent)
{
    std::ifstream in(path);
    if (in.is_open() == false)
    {
        throw std::runtime_error("invalid path");
    }

    std::string line;
    getline(in, line); // title
    const char* delim = " ";

    for(int i = 0; getline(in, line); i++)
    {
        QList<QString> dataRow;

        for (QString& item : QString::fromStdString(line).split(delim))
        {
            dataRow.append(item);
        }
        dataTable.append(dataRow);
    }
}

int ExampleModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return  dataTable.size();
}

int ExampleModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return  dataTable[0].size();
}

QVariant ExampleModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return dataTable[index.row()][index.column()];
    }

    return QVariant();
}


void ExampleModel::appendData( QList<QString>& x )
{
    int row = dataTable.count();
    QList<QString>* cur = (new QList<QString>());

    for(int i = 0; i < x.size(); i++)
        cur->append(x[i]);

    beginInsertRows( QModelIndex(), row, row );
    dataTable.append( *cur );
    endInsertRows();
}

