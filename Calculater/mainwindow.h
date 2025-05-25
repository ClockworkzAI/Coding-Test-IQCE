#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStringListModel>
#include <QMainWindow>

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

private slots:

    void on_btnMultiplay_clicked();

    void on_btnSubtract_clicked();

    void on_btnEquel_clicked();

    void on_btnDevide_clicked();

    void on_btnAdd_clicked();

    void on_btnBreak_clicked();

    void ChackValues();
    // void Calculations();
    void NumPressed();

    void on_btnC_clicked();

    void on_btnCE_clicked();

private:
    void addItem(const QString &newItem);
    Ui::MainWindow *ui;
    QStringList dataList;
    QStringListModel *model;

};
#endif // MAINWINDOW_H
