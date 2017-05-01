#pragma once

#ifndef BOARDSKELETON_H
#define BOARDSKELETON_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class BoardSkeleton : public QWidget
{
    Q_OBJECT
public:
    BoardSkeleton(QWidget *parent = 0);

private slots:
    void onPlus();
    void onMinus();

private:
    QLabel *lbl;

#endif // BOARDSKELETON_H
