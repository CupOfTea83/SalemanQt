#include "infowindow.h"
#include "ui_infowindow.h"
#include "citymap.h"

InfoWindow::InfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);

    this->fillTable();
}

InfoWindow::~InfoWindow()
{
    delete ui;
}

void InfoWindow::fillTable()
{
    QStringList headers;

    for(int i=1;i<=6;i++)
    {
        QString str;
        str.setNum(i);
        headers << str;
    }

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for(int i=0;i<6;i++)
    {
        ui->tableWidget->insertRow(i);

        for(int j=0;j<6;j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            QString str;
            str.setNum(matrix[i][j]);
            item->setText(str);
            ui->tableWidget->setItem(i,j, item);
        }
    }

    ui->tableWidget->resizeColumnsToContents();
}

void InfoWindow::on_Calculate_Button_clicked()
{
   int n = 6;
    int map [6][6]= {
        {-1, 14, -1, -1, -1, -1},
        {-1, -1, -1, -1, 42, 23},
        {19, -1, -1, 9, -1, -1},
        {-1, -1, -1, -1, -1, 31},
        {-1, -1, 18, -1, -1, -1},
        {28, 23, -1, -1, -1, -1}
    };

    int **mapptr = new int* [n];
    for(int i=0;i<n;i++)
    {
        mapptr[i] = new int [n];

        for(int j=0;j<n;j++)
        {
            mapptr[i][j] = map[i][j];
        }

    }


    CityMap counter(mapptr, n);

    counter.f_rez();

    QString length;
    length.setNum(counter.sum);

    ui->LineEdit_lenght->setText(length);

    QString path;
    path = counter.path.c_str();

    ui->LineEdit_shotr_path->setText(path);
}
