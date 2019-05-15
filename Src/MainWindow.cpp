#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_send1(new QNetworkAccessManager(this)),
    m_send2(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    
    connect(m_send1, SIGNAL(finished(QNetworkReply*)), this, SLOT(NetworkReplySend1(QNetworkReply*)));
    connect(m_send2, SIGNAL(finished(QNetworkReply*)), this, SLOT(NetworkReplySend2(QNetworkReply*)));

    //QNetworkRequest request;
    //request.setUrl(QUrl("http://www.baidu.com"));

    //m_send1->get(request);

    //QByteArray postData;
    //postData.append()
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_send1_clicked()
{
    QNetworkRequest request;

    request.setUrl(QUrl("http://" + ui->lineEdit_IP->text() + ":" + ui->lineEdit_port->text() + ui->lineEdit_package1->text()));
    request.setRawHeader("Accept", "text/html, */*; q=0.01");
    request.setRawHeader("Accept-Encoding", "gzip, deflate");
    request.setRawHeader("Accept-Language", "zh-CN");
    QString str =  ui->lineEdit_userName->text() + ":" + ui->lineEdit_password->text();
    request.setRawHeader("Authorization", "Basic " + str.toLocal8Bit().toBase64());
    request.setRawHeader("Cache-Control", "no-cache");
    request.setRawHeader("Connection", "Keep-Alive");
    request.setRawHeader("Content-Length", "0");
    request.setRawHeader("Content-Type", "application/json; charset=utf-8");
    request.setRawHeader("Cookie", "webserver_username=admin; webserver_is_save=1; Guide=1; webserver_lang_type=0; webserver_password=123456");
    //request.setRawHeader("Host", "172.18.30.19");
    request.setRawHeader("Referer", "http://172.18.30.19/config/general_cfg.html?0.18188755807976964");
    request.setRawHeader("session", "0x1ddd480");
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko Core/1.70.3676.400 QQBrowser/10.4.3505.400");
    request.setRawHeader("X-Requested-With", "XMLHttpRequest");

    m_send1->post(request, ui->textEdit_body1->toPlainText().toUtf8());
}

void MainWindow::on_toolButton_send2_clicked()
{
    QNetworkRequest request;

    request.setUrl(QUrl("http://" + ui->lineEdit_IP->text() + ":" + ui->lineEdit_port->text() + ui->lineEdit_package2->text()));
    request.setRawHeader("Accept", "text/html, */*; q=0.01");
    request.setRawHeader("Accept-Encoding", "gzip, deflate");
    request.setRawHeader("Accept-Language", "zh-CN");
    QString str =  ui->lineEdit_userName->text() + ":" + ui->lineEdit_password->text();
    request.setRawHeader("Authorization", "Basic " + str.toLocal8Bit().toBase64());
    request.setRawHeader("Cache-Control", "no-cache");
    request.setRawHeader("Connection", "Keep-Alive");
    request.setRawHeader("Content-Length", "0");
    request.setRawHeader("Content-Type", "application/json; charset=utf-8");
    request.setRawHeader("Cookie", "webserver_username=admin; webserver_is_save=1; Guide=1; webserver_lang_type=0; webserver_password=123456");
    //request.setRawHeader("Host", "172.18.30.19");
    request.setRawHeader("Referer", "http://172.18.30.19/config/general_cfg.html?0.18188755807976964");
    request.setRawHeader("session", "0x1ddd480");
    request.setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko Core/1.70.3676.400 QQBrowser/10.4.3505.400");
    request.setRawHeader("X-Requested-With", "XMLHttpRequest");

    m_send1->post(request, ui->textEdit_body2->toPlainText().toUtf8());
}

void MainWindow::NetworkReplySend1(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        //ui->textEdit_body1->append(reply->readAll());
        QString str = reply->readAll();
        qDebug() << str << endl;
        ui->textBrowser_show->setText(str);
    }
    else
    {
        qDebug() << "lallalalal" << endl;
    }
}

void MainWindow::NetworkReplySend2(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        //ui->textEdit_body1->append(reply->readAll());
        QString str = reply->readAll();
        qDebug() << str << endl;
        ui->textBrowser_show->setText(str);
    }
    else
    {
        qDebug() << "lallalalal" << endl;
    }
}
