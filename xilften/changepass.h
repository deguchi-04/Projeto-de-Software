#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include <QDialog>

namespace Ui {
class ChangePass;
}

class ChangePass : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePass(QWidget *parent = nullptr);
    ~ChangePass();

private slots:
    void on_Back_clicked();

    void on_Confirm_clicked();

private:
    Ui::ChangePass *ui;
};

#endif // CHANGEPASS_H
