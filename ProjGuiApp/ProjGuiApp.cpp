#include "ProjGuiApp.h"
#include <QDebug>
ProjGuiApp::ProjGuiApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.comboBox->addItem("Transverse Mercator");
    ui.comboBox->addItem("Lambert");
    ui.comboBox->addItem("Mercator Variant C");

    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_btn_clicked()));
    connect(ui.action, SIGNAL(triggered()), this, SLOT(on_btn_clicked()));
    connect(ui.action_3, SIGNAL(triggered()), this, SLOT(close()));
}

void ProjGuiApp::on_btn_clicked()
{
    int w = ui.label_picture->width();
    int h = ui.label_picture->height();

    QPixmap pix(":/res/img/tmerc.png");

    if (ui.comboBox->currentIndex() == 0)
    {
        ui.statusBar->showMessage("Projection: Transverse Mercator", 5000);
        qDebug() << "Transv. merc";
        QPixmap pix2(":/res/img/tmerc.png");
        pix = pix2;
    }
    else if (ui.comboBox->currentIndex() == 1)
    {
        ui.statusBar->showMessage("Projection: Lambert", 5000);
        qDebug() << "Lambert";
        QPixmap pix2(":/res/img/lcc.png");
        pix = pix2;
    }
    else if (ui.comboBox->currentIndex() == 2)
    {
        ui.statusBar->showMessage("Projection: Marcator Variant C", 5000);
        qDebug() << "Merc var C";
        QPixmap pix2(":/res/img/merc.png");
        pix = pix2;
    }

    ui.label_picture->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}
