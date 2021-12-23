#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjGuiApp.h"

class ProjGuiApp : public QMainWindow
{
    Q_OBJECT

public:
    ProjGuiApp(QWidget *parent = Q_NULLPTR);

public slots:
    void on_btn_clicked();

private:
    Ui::ProjGuiAppClass ui;
};
