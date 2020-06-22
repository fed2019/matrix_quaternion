#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include "calculate.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWIn; }
QT_END_NAMESPACE

typedef enum calculateRoute{BEGIN_FROM_MATRIX,BEGIN_FROM_QUATER,
                           BEGIN_FROM_RPY,BEGIN_FROM_EULER,CANNOT_BEGIN} ROUTE;

class MainWIn : public QMainWindow
{
    Q_OBJECT

public:
    MainWIn(QWidget *parent = nullptr);
    ~MainWIn();
    void onCalculate();
    void onReset();
    void onradioButtonChanged_1();
    void onradioButtonChanged_2();
    ROUTE calcalateRoute();
    bool getMatrix(QList<double> &);
    bool getQuaternion(QList<double> &);
    bool getRpy(QList<double> &);
    bool getEuler(QList<double> &);
    bool setMatrix(QList<double> &);
    bool setQuaternion(QList<double> &);
    bool setRpy(QList<double> &);
    bool setEuler(QList<double> &);
    void closeEvent(QEvent *);

private:
    Ui::MainWIn *ui;
    Calculate *captr;
    QList<double> matrix_;
    QList<double> quaternion_;
    QList<double> rpy_;
    QList<double> euler_;
    QThread *cal_thread;

};
#endif // MAINWIN_H
