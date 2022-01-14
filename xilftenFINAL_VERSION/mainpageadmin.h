#ifndef MAINPAGEADMIN_H
#define MAINPAGEADMIN_H

#include <QDialog>

namespace Ui {
class mainpageadmin;
}

class mainpageadmin : public QDialog
{
    Q_OBJECT

public:
    explicit mainpageadmin(QWidget *parent = nullptr);
    ~mainpageadmin();

private slots:
    void on_TopMovies_clicked();

    void on_AddMov_clicked();

    void on_Catalog_clicked();

    void on_AllUsers_clicked();

    void on_GoButton_3_clicked();

    void on_LogOut_clicked();

    void on_DeleteMov_clicked();

    void on_evalbutton_5_clicked();

    void on_delete_4_clicked();

    void on_back_3_clicked();

    void on_back_4_clicked();

    void on_delete_5_clicked();




    void on_movieTitle_clicked();

    void on_movieTitle_2_clicked();

    void on_movieTitle_3_clicked();

    void on_movieTitle_4_clicked();

    void on_movieTitle_5_clicked();

    void on_movieTitle_6_clicked();

    void on_movieTitle_7_clicked();

    void on_movieTitle_8_clicked();

    void on_movieTitle_9_clicked();

    void on_movieTitle_10_clicked();

    void on_refresh_clicked();

private:
    Ui::mainpageadmin *ui;
};

#endif // MAINPAGEADMIN_H
