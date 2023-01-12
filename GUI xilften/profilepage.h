#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QDialog>

namespace Ui {
class ProfilePage;
}

class ProfilePage : public QDialog
{
    Q_OBJECT

public:
    explicit ProfilePage(QWidget *parent = nullptr);
    ~ProfilePage();

private slots:
    void on_Back_clicked();

    void on_Donate_clicked();

    void on_DelProf_clicked();

    void on_change_clicked();

    void on_LogOut_clicked();

private:
    Ui::ProfilePage *ui;
};

#endif // PROFILEPAGE_H
