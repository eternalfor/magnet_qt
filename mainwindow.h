#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include "XTTableView.h"
#include <QMenu>
#include <QMenuBar>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QDir>
#include <QUrl>
#include <QApplication>
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <iostream>
#include <windows.h>

//#ifdef Q_OS_WIN32

//#include <libxml2/libxml/parser.h>
//#include <libxml2/libxml/xpath.h>
//#include <libxml2/libxml/HTMLparser.h>

//#elif

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/HTMLparser.h>

//#endif


#include <QtCore/QUrl>
#include <QWidget>
#include "sidemodel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMutex mutex;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply;
//    static QString getHtml(QString url)
//    {
//        QNetworkAccessManager *manager = new QNetworkAccessManager();
//        QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(url)));
//        QByteArray responseData;
//        QEventLoop eventLoop;
//        connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
//        eventLoop.exec();
///*block until finish*/
//        responseData = reply->readAll();
//        return QString(responseData);
//    }

private slots:

    void on_searchButton_clicked();
    void initTableView();
    void initListTableView();

    void clickListTableView();
    void clickDownloadButton();
    void testSlot();
    void clicked_rightMenu(const QPoint &pos);  //右键信号槽函数
    void onShowOrHideColumn(QAction *action);

    void htmlFinished(QNetworkReply *reply);
    QList<sideModel*> queryHTML(const QString &html, sideModel * model);
    //清除规则中的点
    QString clearDot(QString str);
    //清除空格
    QString clearSpace(QString str);
    QString clearMagnet(QString str);
    //刷新结果列表的数据
    void reloadTableData(QList<sideModel*>list);

private:
    Ui::MainWindow *ui;



    //记录当前选择网站序号
    int currentListSelect;
    int currentPage;
    //保存网站列表的list
    QList<sideModel*>jsonModelList;
    //保存查询到的结果
    QList<sideModel*>resultList;

    QMenu *rightMenu;  //右键菜单

    QAction *copyAction;  //复制
    QAction *downloadAction;  //下载

};

#endif // MAINWINDOW_H












