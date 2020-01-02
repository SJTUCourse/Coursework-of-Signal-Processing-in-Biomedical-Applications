#include "mainproject.h"
#include "ui_mainproject.h"
#include "QProcess"
MainProject::MainProject(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainProject)
{
    ui->setupUi(this);
    connect(ui->AI, SIGNAL(clicked()), this, SLOT(ButtonAIClicked()));
    connect(ui->AO, SIGNAL(clicked()), this, SLOT(ButtonAOClicked()));
    connect(ui->DI, SIGNAL(clicked()), this, SLOT(ButtonDIClicked()));
    connect(ui->DO, SIGNAL(clicked()), this, SLOT(ButtonDOClicked()));
}

MainProject::~MainProject()
{
    delete ui;
}

void MainProject::ButtonAIClicked()
{
    QString a = QCoreApplication::applicationDirPath();
    QProcess *myProcess = new QProcess();
    myProcess->startDetached(a+"/AI_InstantAI.exe");
}

void MainProject::ButtonAOClicked()
{
     QString a = QCoreApplication::applicationDirPath();
    QProcess *myProcess = new QProcess();
    myProcess->startDetached(a+"/AO_StaticAO.exe");
}

void MainProject::ButtonDIClicked()
{
     QString a = QCoreApplication::applicationDirPath();
    QProcess *myProcess = new QProcess();
    myProcess->startDetached(a+"/DI_StaticDI.exe");
}

void MainProject::ButtonDOClicked()
{
     QString a = QCoreApplication::applicationDirPath();
    QProcess *myProcess = new QProcess();
    myProcess->startDetached(a+"/DO_StaticDO.exe");
}
