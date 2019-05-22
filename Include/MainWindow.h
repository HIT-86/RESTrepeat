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

protected:
    void timerEvent(QTimerEvent *Event);

private slots:
    void on_toolButton_send1_clicked();
    void on_toolButton_send2_clicked();

    void NetworkReplySend1(QNetworkReply *reply);
    void NetworkReplySend2(QNetworkReply *reply);

    void on_toolButton_cyclicSend_clicked();

    void on_toolButton_killSend_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *m_send1;
    QNetworkAccessManager *m_send2;
    int m_Timer;
    int m_count;
};

#endif // MAINWINDOW_H
