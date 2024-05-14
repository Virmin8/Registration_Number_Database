#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include "registrationnumber.h"

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

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

RegistrationNumber registrationNum;
QString regReplace;



QRegularExpression newGP;
QRegularExpression oldGP ("\\a");
QRegularExpression WC ("(\\w?[C,N])\\w{1,2}\\d{1,6}");
QRegularExpression personal ("(\\w{1,6})\\w?[GP,MP,EC,FS,NC,NW,L,WP,ZN]");

QValidator *validator = new  QRegularExpressionValidator(personal);

void MainWindow::refresh()
{
    QStringList list = registrationNum.getRegistrationNumber();
    ui->listWidget->clear();
    ui->listWidget->addItems(list);
}

void MainWindow::on_Add_pushButton_clicked()
{
    QString registration = ui->Add_lineEdit->text();

    registrationNum.addRegistrationNumber(registration);

    ui->Add_lineEdit->clear();
    refresh();

}

void MainWindow::on_Edit_pushButton_clicked()
{
    QString change = ui->Registration_lineEdit->text();
    registrationNum.replaceRegistrationNumber(regReplace,change);
    ui->Registration_lineEdit->clear();
    refresh();
}

void MainWindow::on_Remove_pushButton_clicked()
{
    QString selected = ui->listWidget->currentItem()->text();
    registrationNum.removeRegistrationNumber(selected);
    refresh();
}


void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    regReplace = ui->listWidget->currentItem()->text();
    ui->Registration_lineEdit->setText(regReplace);
}


void MainWindow::on_Add_lineEdit_returnPressed()
{
     ui->Add_lineEdit->setValidator(validator);
}
