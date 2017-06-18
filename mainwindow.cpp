#include "mainwindow.h"
#include "ui_mainwindow.h"
//--------------------------------------
MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_lblMessage(Q_NULLPTR)
{
    ui->setupUi(this);

//    QPalette p = ui->txtedtConsole->palette();

//    p.setColor(QPalette::Base, QColor(Qt::black));
//    p.setColor(QPalette::Text, QColor(Qt::green));

//    ui->txtedtConsole->setPalette(p);

    m_lblMessage = new QLabel(ui->statusBar);
    ui->statusBar->addWidget(m_lblMessage);
}
//-----------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//--------------------------------------------------
void MainWindow::showMessage(const QString& message)
{
    m_lblMessage->setText(message);
}
