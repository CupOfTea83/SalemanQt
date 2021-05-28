#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QMainWindow>

namespace Ui {
class InfoWindow;
}

class InfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfoWindow(QWidget *parent = nullptr);
    ~InfoWindow();

private slots:
    void on_Calculate_Button_clicked();

private:
    Ui::InfoWindow *ui;
    int matrix[6][6]={
        {0, 14, 0, 0, 0, 0},
        {0, 0, 0, 0, 42, 23},
        {19, 0, 0, 9, 0, 0},
        {0, 0, 0, 0, 0, 31},
        {0, 0, 18, 0, 0, 0},
        {28, 23, 0, 0, 0, 0}
    };
    void fillTable();
};

#endif // INFOWINDOW_H
