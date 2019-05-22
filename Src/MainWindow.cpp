#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <windows.h>
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_send1(new QNetworkAccessManager(this)),
    m_send2(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    
    connect(m_send1, SIGNAL(finished(QNetworkReply*)), this, SLOT(NetworkReplySend1(QNetworkReply*)));
    connect(m_send2, SIGNAL(finished(QNetworkReply*)), this, SLOT(NetworkReplySend2(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_send1_clicked()
{
    QNetworkRequest request;

    request.setUrl(QUrl("http://" + ui->lineEdit_IP->text() + ":" + ui->lineEdit_port->text() + ui->lineEdit_package1->text()));
    QString str =  ui->lineEdit_userName->text() + ":" + ui->lineEdit_password->text();
    request.setRawHeader("Authorization", "Basic " + str.toLocal8Bit().toBase64());
    request.setRawHeader("Content-Length", QString::number(ui->textEdit_body1->toPlainText().toUtf8().length()).toLocal8Bit());
    request.setRawHeader("Content-Type", "application/json; charset=utf-8");

    m_send1->post(request, ui->textEdit_body1->toPlainText().toUtf8());

    return;
}

void MainWindow::on_toolButton_send2_clicked()
{
    QNetworkRequest request;

    request.setUrl(QUrl("http://" + ui->lineEdit_IP->text() + ":" + ui->lineEdit_port->text() + ui->lineEdit_package2->text()));
    QString str =  ui->lineEdit_userName->text() + ":" + ui->lineEdit_password->text();
    request.setRawHeader("Authorization", "Basic " + str.toLocal8Bit().toBase64());
    request.setRawHeader("Content-Length", QString::number(ui->textEdit_body2->toPlainText().toUtf8().length()).toLocal8Bit());
    request.setRawHeader("Content-Type", "application/json; charset=utf-8");

    m_send1->post(request, ui->textEdit_body2->toPlainText().toUtf8());

    return;
}

void MainWindow::NetworkReplySend1(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QString str = reply->readAll();
        ui->textBrowser_show->setText(str);
    }
    else
    {
        ui->textBrowser_show->setText("error");
    }

    return;
}

void MainWindow::NetworkReplySend2(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QString str = reply->readAll();
        ui->textBrowser_show->setText(str);
    }
    else
    {
        ui->textBrowser_show->setText("error");
    }

    return;
}

void MainWindow::on_toolButton_cyclicSend_clicked()
{
    m_Timer = startTimer(2000);
    m_count = 0;

    return;
}

void MainWindow::on_toolButton_killSend_clicked()
{
    killTimer(m_Timer);
    m_count = 0;

    return;
}

void MainWindow::timerEvent(QTimerEvent *Event)
{
    QCoreApplication::processEvents();
    on_toolButton_send1_clicked();
    ui->lcdNumber_count->display(m_count++);

    QElapsedTimer t;
    t.start();
    while(t.elapsed() < 2000)
    {
        QCoreApplication::processEvents();
    }

    on_toolButton_send2_clicked();
    ui->lcdNumber_count->display(m_count++);

    return;
}
