#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QDialog>

namespace Ui {
class RegisterPage;
}

class RegisterPage : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();

private slots:
    void on_LogBut_clicked();

    void on_BackButton_clicked();

private:
    Ui::RegisterPage *ui;
};

#endif // REGISTERPAGE_H
