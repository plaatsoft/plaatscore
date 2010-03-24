#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
    class HighScore;
}

class HighScore : public QMainWindow {
    Q_OBJECT

public:
    HighScore(QWidget *parent = 0);
    ~HighScore();

private slots:
    void on_actionAbout_triggered();
    void on_actionTowerDefense_triggered();
    void on_actionSpaceBubble_triggered();
    void on_actionRedSquare_triggered();
    void on_actionBibleQuiz_triggered();
    void on_actionPong2_triggered();
    void on_actionExit_triggered();
    void fetch();
    void replyFinished(QNetworkReply*);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::HighScore *ui;
    QNetworkAccessManager *manager;
    QString address;

    void parseXML(QString response);
    void closeEvent(QCloseEvent *event);
    void readSettings();
    void writeSettings();
};

#endif // HIGHSCORE_H
