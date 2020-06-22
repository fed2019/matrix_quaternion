#include "calculate.h"

Calculate::Calculate(QObject *parent) : QObject(parent)
{

}

bool Calculate::matrix2quaternion(const QList<double> &matrix,QList<double> &quaternion)
{
    //探测四元数中最大的项
    double fourWSquaredMinusl = matrix[0]+matrix[4]+matrix[8];
    double fourXSquaredMinusl = matrix[0]-matrix[4]-matrix[8];
    double fourYSquaredMinusl = matrix[4]-matrix[0]-matrix[8];
    double fourZSquaredMinusl = matrix[8]-matrix[0]-matrix[4];

    int biggestIndex = 0;
    double fourBiggestSqureMinus1 = fourWSquaredMinusl;
    if(fourXSquaredMinusl>fourBiggestSqureMinus1){
        fourBiggestSqureMinus1 = fourXSquaredMinusl;
        biggestIndex =1;
    }
    if(fourYSquaredMinusl>fourBiggestSqureMinus1){
        fourBiggestSqureMinus1 = fourYSquaredMinusl;
        biggestIndex =2;
    }
    if(fourZSquaredMinusl>fourBiggestSqureMinus1){
        fourBiggestSqureMinus1 = fourZSquaredMinusl;
        biggestIndex =3;
    }

    //计算平方根和除法
    double biggestVal = sqrt(fourBiggestSqureMinus1+1.0f)*0.5f;
    double mult = 0.25f/biggestVal;

    //计算四元数的值
    switch(biggestIndex){
        case 0:
            quaternion[3]=biggestVal;
            quaternion[0]=(matrix[5]-matrix[7])*mult;
            quaternion[1]=(matrix[6]-matrix[2])*mult;
            quaternion[2]=(matrix[1]-matrix[3])*mult;
            break;
        case 1:
            quaternion[0] = biggestVal;
            quaternion[3] =(matrix[5]-matrix[7])*mult;
            quaternion[1] =(matrix[1]+matrix[3])*mult;
            quaternion[2] =(matrix[6]+matrix[2])*mult;
            break;
        case 2:
            quaternion[2] =biggestVal;
            quaternion[3] =(matrix[6]-matrix[2])*mult;
            quaternion[0] =(matrix[1]+matrix[3])*mult;
            quaternion[1] =(matrix[5]+matrix[7])*mult;
            break;
        case 3:
            quaternion[2] =biggestVal;
            quaternion[3] =(matrix[1]-matrix[3])*mult;
            quaternion[0] =(matrix[6]+matrix[2])*mult;
            quaternion[1] =(matrix[5]+matrix[7])*mult;
        break;
    }
    return true;

}

bool Calculate::matrix2rpy(const QList<double> &matrix,QList<double> &rpy)
{

}

bool Calculate::matrix2euler(const QList<double> &matrix,QList<double> &euler)
{

}

bool Calculate::quaternion2matrix(const QList<double> &quaternion, QList<double> &matrix)
{
    matrix[0]=1-2*quaternion[1]*quaternion[1]-2*quaternion[2]*quaternion[2];
    matrix[1]=2*quaternion[0]*quaternion[1]+2*quaternion[3]*quaternion[2];
    matrix[2]=2*quaternion[0]*quaternion[2]-2*quaternion[3]*quaternion[1];
    matrix[3]=2*quaternion[0]*quaternion[1]-2*quaternion[3]*quaternion[2];
    matrix[4]=1-2*quaternion[0]*quaternion[0]-2*quaternion[2]*quaternion[2];
    matrix[5]=2*quaternion[1]*quaternion[2]+2*quaternion[3]*quaternion[0];
    matrix[6]=2*quaternion[0]*quaternion[2]+2*quaternion[3]*quaternion[1];
    matrix[7]=2*quaternion[1]*quaternion[2]-2*quaternion[3]*quaternion[0];
    matrix[8]=1-2*quaternion[0]*quaternion[0]-2*quaternion[1]*quaternion[1];
    return true;
}

bool Calculate::rpy2matrix(const QList<double> &rpy, QList<double> &matrix)
{

}

bool Calculate::euler2matrix(const QList<double> &euler, QList<double> &matrix)
{
    double c1=cos(euler[0]);
    double c2=cos(euler[1]);
    double c3=cos(euler[2]);
    double s1=sin(euler[0]);
    double s2=sin(euler[1]);
    double s3=sin(euler[2]);
    matrix[0]=c1*c2;
    matrix[1]=c1*s2*s3-c3*s1;
    matrix[2]=s1*s3+c1*c3*s2;
    matrix[3]=c2*s1;
    matrix[4]=c1*c3+s1*s2*s3;
    matrix[5]=c3*s1*s2-c1*s3;
    matrix[6]=-s2;
    matrix[7]=c2*s3;
    matrix[8]=c2*c3;
    return true;
}
