#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolButton_send1_clicked();
    void on_toolButton_send2_clicked();

    void NetworkReplySend1(QNetworkReply *reply);
    void NetworkReplySend2(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *m_send1;
    QNetworkAccessManager *m_send2;
};

#endif // MAINWINDOW_H
