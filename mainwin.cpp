#include "mainwin.h"
#include "ui_mainwin.h"
#include <QMessageBox>


MainWIn::MainWIn(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWIn)
{
    ui->setupUi(this);
    captr=new Calculate();//cannot set a parent object
    cal_thread=new QThread(this);//start a new thread for calcuate
    captr->moveToThread(cal_thread);
    cal_thread->start();
}

MainWIn::~MainWIn()
{
    delete ui;
}

void MainWIn::closeEvent(QEvent *e)
{
    if (cal_thread->isRunning()==true)
    {
        cal_thread->quit();
        cal_thread->wait();
    }
    delete captr;
}

bool MainWIn::getMatrix(QList<double> &matrix)
{
    bool isTranslateOk;
    double data;
    //h11
    if (ui->le_h11->text().isEmpty()) return false;
    data=ui->le_h11->text().toDouble(&isTranslateOk);
    if (isTranslateOk) matrix[0]=data;
    else return false;
    //h12
    if (ui->le_h12->text().isEmpty()) return false;
    data=ui->le_h12->text().toDouble(&isTranslateOk);
    if (isTranslateOk) matrix[1]=data;
    else return false;
    //h13
    if (ui->le_h13->text().isEmpty()) return false;
    data=ui->le_h13->text().toDouble(&isTranslateOk);
    if (isTranslateOk) matrix[2]=data;
    else return false;
    //h21
    if (ui->le_h21->text().isEmpty()) return false;
    data=ui->le_h21->text().toDouble(&isTranslateOk);
    if (isTranslateOk) matrix[3]=data;
    else return false;
    //h22
    if (ui->le_h22->text().isEmpty()) return false;
    data=ui->le_h22->text().toDouble(&isTranslateOk);
    if (isTranslateOk) matrix[4]=data;
    else return false;
    //h23
    if (ui->le_h23->text().isEmpty()) return false;
    data=ui->le_h23->text().toDouble(&isTranslateOk);
    if (isTranslateOk) matrix[5]=data;
    else return false;
    //h31
    if (ui->le_h31->text().isEmpty()) return false;
    data=ui->le_h31->text().toDouble(&isTranslateOk);
    if (isTranslateOk) matrix[6]=data;
    else return false;
    //h32
    if (ui->le_h32->text().isEmpty()) return false;
    data=ui->le_h32->text().toDouble(&isTranslateOk);
    if (isTranslateOk) matrix[7]=data;
    else return false;
    //h33
    if (ui->le_h33->text().isEmpty()) return false;
    data=ui->le_h33->text().toDouble(&isTranslateOk);
    if (isTranslateOk) matrix[8]=data;
    else return false;
    //If all right
    return true;
}

bool MainWIn::getQuaternion(QList<double> &quaternion)
{
    bool isTranslateOk;
    double data;
    //X
    if (ui->le_X->text().isEmpty()) return false;
    data=ui->le_X->text().toDouble(&isTranslateOk);
    if (isTranslateOk) quaternion[0]=data;
    else return false;
    //Y
    if (ui->le_Y->text().isEmpty()) return false;
    data=ui->le_Y->text().toDouble(&isTranslateOk);
    if (isTranslateOk) quaternion[1]=data;
    else return false;
    //Z
    if (ui->le_Z->text().isEmpty()) return false;
    data=ui->le_Z->text().toDouble(&isTranslateOk);
    if (isTranslateOk) quaternion[2]=data;
    else return false;
    //W
    if (ui->le_W->text().isEmpty()) return false;
    data=ui->le_W->text().toDouble(&isTranslateOk);
    if (isTranslateOk) quaternion[3]=data;
    else return false;
    //if all right
    return true;
}

bool MainWIn::getRpy(QList<double> &rpy)
{
    bool isTranslateOk;
    double data;
    //Roll
    if (ui->le_Roll->text().isEmpty()) return false;
    data=ui->le_Roll->text().toDouble(&isTranslateOk);
    if (isTranslateOk) rpy[0]=data;
    else return false;
    //Pitch
    if (ui->le_Pitch->text().isEmpty()) return false;
    data=ui->le_Pitch->text().toDouble(&isTranslateOk);
    if (isTranslateOk) rpy[1]=data;
    else return false;
    //Yaw
    if (ui->le_Yaw->text().isEmpty()) return false;
    data=ui->le_Yaw->text().toDouble(&isTranslateOk);
    if (isTranslateOk) rpy[2]=data;
    else return false;
    //if all right
    return true;
}

bool MainWIn::getEuler(QList<double> &euler)
{
    bool isTranslateOk;
    double data;
    //Roll
    if (ui->le_a->text().isEmpty()) return false;
    data=ui->le_a->text().toDouble(&isTranslateOk);
    if (isTranslateOk) euler[0]=data;
    else return false;
    //Pitch
    if (ui->le_b->text().isEmpty()) return false;
    data=ui->le_b->text().toDouble(&isTranslateOk);
    if (isTranslateOk) euler[1]=data;
    else return false;
    //Yaw
    if (ui->le_c->text().isEmpty()) return false;
    data=ui->le_c->text().toDouble(&isTranslateOk);
    if (isTranslateOk) euler[2]=data;
    else return false;
    //if all right
    return true;
}

bool MainWIn::setMatrix(QList<double> &matrix)
{
    if (matrix.length()<9) return false;
    ui->le_h11->setText(QString::number(matrix.at(0)));
    ui->le_h12->setText(QString::number(matrix.at(1)));
    ui->le_h13->setText(QString::number(matrix.at(2)));
    ui->le_h21->setText(QString::number(matrix.at(3)));
    ui->le_h22->setText(QString::number(matrix.at(4)));
    ui->le_h23->setText(QString::number(matrix.at(5)));
    ui->le_h31->setText(QString::number(matrix.at(6)));
    ui->le_h32->setText(QString::number(matrix.at(7)));
    ui->le_h33->setText(QString::number(matrix.at(8)));
    return true;
}

bool MainWIn::setQuaternion(QList<double> &quaternion)
{
    if (quaternion.length()<4) return false;
    ui->le_X->setText(QString::number(quaternion.at(0)));
    ui->le_Y->setText(QString::number(quaternion.at(1)));
    ui->le_Z->setText(QString::number(quaternion.at(2)));
    ui->le_W->setText(QString::number(quaternion.at(3)));
    return true;
}

bool MainWIn::setRpy(QList<double> &rpy)
{
    if (rpy.length()<3) return false;
    ui->le_Roll->setText(QString::number(rpy.at(0)));
    ui->le_Pitch->setText(QString::number(rpy.at(1)));
    ui->le_Yaw->setText(QString::number(rpy.at(2)));
    return true;
}

bool MainWIn::setEuler(QList<double> &euler)
{
    if (euler.length()<3) return false;
    ui->le_a->setText(QString::number(euler.at(0)));
    ui->le_b->setText(QString::number(euler.at(1)));
    ui->le_c->setText(QString::number(euler.at(2)));
    return true;
}

ROUTE MainWIn::calcalateRoute()
{
    ROUTE rst;
    if (getMatrix(matrix_))
    {
        rst=BEGIN_FROM_MATRIX;
        return rst;
    }
    if(getQuaternion(quaternion_))
    {
        rst=BEGIN_FROM_QUATER;
        return rst;
    }
    if(getRpy(rpy_))
    {
        rst=BEGIN_FROM_RPY;
        return rst;
    }
    if(getEuler(euler_))
    {
        rst=BEGIN_FROM_EULER;
        return rst;
    }
    rst=CANNOT_BEGIN;
    return rst;
}

void MainWIn::onCalculate()
{
    bool rtn;
    ROUTE r=calcalateRoute();
    switch (r){
    case BEGIN_FROM_MATRIX:
    {
        //matrix->rpy
        rtn=captr->matrix2rpy(this->matrix_,this->rpy_);
        if (!rtn)
        {
            QMessageBox::critical(this,"Error","matrix->rpy calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setRpy(this->rpy_);
        //matrix->quaternion
        rtn=captr->matrix2quaternion(this->matrix_,this->quaternion_);
        if (!rtn)
        {
            QMessageBox::critical(this,"Error","matrix->quaternion calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setQuaternion(this->quaternion_);
        //matrix->euler
        rtn=captr->matrix2euler(this->matrix_,this->euler_);
        if (!rtn)
        {
            QMessageBox::critical(this,"Error","matrix->euler calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setEuler(this->euler_);
    };
    case BEGIN_FROM_QUATER:
    {
        //quaternion->matrix
        rtn=captr->quaternion2matrix(this->quaternion_,this->matrix_);
        if(!rtn)
        {
            QMessageBox::critical(this,"Error","quaternion->matrix calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setMatrix(this->matrix_);
        //matrix->rpy
        rtn=captr->matrix2rpy(this->matrix_,this->rpy_);
        if (!rtn)
        {
            QMessageBox::critical(this,"Error","matrix->rpy calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setRpy(this->rpy_);
        //matrix->euler
        rtn=captr->matrix2euler(this->matrix_,this->euler_);
        if (!rtn)
        {
            QMessageBox::critical(this,"Error","matrix->euler calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setEuler(this->euler_);
    };
    case BEGIN_FROM_RPY:
    {
        //rpy->matri
        rtn=captr->rpy2matrix(this->rpy_,this->matrix_);
        if(!rtn)
        {
            QMessageBox::critical(this,"Error","rpy->matrix calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setMatrix(this->matrix_);
        //matrix->quaternion
        rtn=captr->matrix2quaternion(this->matrix_,this->quaternion_);
        if (!rtn)
        {
            QMessageBox::critical(this,"Error","matrix->quaternion calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setQuaternion(this->quaternion_);
        //matrix->euler
        rtn=captr->matrix2euler(this->matrix_,this->euler_);
        if (!rtn)
        {
            QMessageBox::critical(this,"Error","matrix->euler calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setEuler(this->euler_);

    };
    case BEGIN_FROM_EULER:
    {
        //euler->matrix
        rtn=captr->euler2matrix(this->euler_,this->matrix_);
        if(!rtn)
        {
            QMessageBox::critical(this,"Error","euler->matrix calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setMatrix(this->matrix_);
        //matrix->quaternion
        rtn=captr->matrix2quaternion(this->matrix_,this->quaternion_);
        if (!rtn)
        {
            QMessageBox::critical(this,"Error","matrix->quaternion calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setQuaternion(this->quaternion_);
        //matrix->rpy
        rtn=captr->matrix2rpy(this->matrix_,this->rpy_);
        if (!rtn)
        {
            QMessageBox::critical(this,"Error","matrix->rpy calculate failed!",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        setRpy(this->rpy_);
    };
    case CANNOT_BEGIN:
    {
        QMessageBox::critical(this,"Error","message inputed is incomplete,so cannot begin calcuate!",
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    };
    }
}

void MainWIn::onReset()
{
    ui->le_h11->clear();
    ui->le_h12->clear();
    ui->le_h13->clear();
    ui->le_h21->clear();
    ui->le_h22->clear();
    ui->le_h23->clear();
    ui->le_h31->clear();
    ui->le_h32->clear();
    ui->le_h33->clear();
    ui->le_X->clear();
    ui->le_Y->clear();
    ui->le_Z->clear();
    ui->le_W->clear();
    ui->le_Roll->clear();
    ui->le_Pitch->clear();
    ui->le_Yaw->clear();
    ui->le_a->clear();
    ui->le_b->clear();
    ui->le_c->clear();
}

void MainWIn::onradioButtonChanged_1()
{

}

void MainWIn::onradioButtonChanged_2()
{

}
