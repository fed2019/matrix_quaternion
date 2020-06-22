#ifndef CALCULATE_H
#define CALCULATE_H

#include <QObject>


class Calculate : public QObject
{
    Q_OBJECT
public:
    explicit Calculate(QObject *parent = nullptr);
    bool matrix2quaternion(const QList<double> &,QList<double> &);
    bool matrix2rpy(const QList<double> &,QList<double> &);
    bool matrix2euler(const QList<double> &,QList<double> &);
    bool quaternion2matrix(const QList<double> &,QList<double> &);
    bool rpy2matrix(const QList<double> &,QList<double> &);
    bool euler2matrix(const QList<double> &,QList<double> &);

signals:

};

#endif // CALCULATE_H
