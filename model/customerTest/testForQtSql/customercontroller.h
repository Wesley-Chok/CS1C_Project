#ifndef CUSTOMERCONTROLLER_H
#define CUSTOMERCONTROLLER_H

#include <QObject>
#include <QtSql>
#include "customerentry.h"


class CustomerController : public QObject
{
    Q_OBJECT
public:
    explicit CustomerController(QObject *parent = nullptr);

    //* This Function help us to create an customer table *//
    void static createTable();

    //*********************** READ ***********************//                                            *//
    //* Read the customer information from the database. *//
    //* And store them in QSqlQueryModel* object.        *//
    QSqlQueryModel* loadEntries();

    QSqlQueryModel* loadKeyEntries();

    //* Read one customer information from the database, *//
    //* according to the giving name.                    *//
    //* And store them in CustomerEntry* object.         *//
    CustomerEntry* getEntryFromName(QString name);

    //* Read the customer name from the database,        *//
    //* according to QModelIndex object                  *//
    QString getCustomerNameFromQModelIndex(const QModelIndex &index);

    //********************** CREATE **********************//
    void createEntry(QString        name,
                     QString        address,
                     QString        username,
                     QString        password,
                     QString        credit,
                     QString        phone,
                     QString        rating,
                     QString        key,
                     QStringList products,
                     QString        maintainPlan,
                     bool           getPamphlet);

    //********************** DELETE **********************//
    void deleteEntry(QString name);

    //********************** UPDATE **********************//
    void updateEntry(QString        name,
                     QString        address,
                     QString        username,
                     QString        password,
                     QString        credit,
                     QString        phone,
                     QString        rating,
                     QString        key,
                     QStringList products,
                     QString        maintainPlan,
                     bool           getPamphlet);

signals:

public slots:

private:
    QSqlDatabase         m_database;
    QList<CustomerEntry> m_entries;

    //******************* Helper Function ********************//
    QString convertProductsToString(QStringList products);
    QStringList convertProductsFromString(QString productsStr);
};




#endif // CUSTOMERCONTROLLER_H
