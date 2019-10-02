#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customercontroller.h"
#include "QMessageBox"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(CustomerController* controller,QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void createEntry();
    void deleteEntry();
    void updateEntry();
    void changedatabasePage();
    void changePageCreatePage();
    void changetoadminpage();
    void changetologinpage();
    void on_tableView_activated(const QModelIndex &index);
    void changepageToContactUs();
    void changePageToHome();
    void setupconnections();
    void changepagetobuynow();
    void changetocartpage();
    void changetoGuaranteepage();
    void changetocustomerreviewspage();
    void changetohelppage();
    void changeToPamphletPages();
    void pamphletSent(); // After submitting, we update existing customer's pamphletSent or if they don't exist, we add a new customer
    void buyingProduct();


private:
    Ui::MainWindow *ui;
    CustomerController *m_controller;

    void showCustomerList(QSqlQueryModel *model);



};

#endif // MAINWINDOW_H
