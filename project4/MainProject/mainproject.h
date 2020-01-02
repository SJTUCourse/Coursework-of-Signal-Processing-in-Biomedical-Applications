#ifndef MAINPROJECT_H
#define MAINPROJECT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainProject; }
QT_END_NAMESPACE

class MainProject : public QDialog
{
    Q_OBJECT

public:
    MainProject(QWidget *parent = nullptr);
    ~MainProject();

private:
    Ui::MainProject *ui;

private slots:

    void ButtonAIClicked();
    void ButtonAOClicked();
    void ButtonDIClicked();
    void ButtonDOClicked();

};
#endif // MAINPROJECT_H
