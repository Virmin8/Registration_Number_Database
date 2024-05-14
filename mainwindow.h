#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_Add_pushButton_clicked();

    void on_Edit_pushButton_clicked();

    void on_Remove_pushButton_clicked();

    void refresh();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_Add_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
