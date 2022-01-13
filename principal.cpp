#include "principal.h"
#include "ui_principal.h"



#include <QDebug>
Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{

    ui->setupUi(this);
    setWindowTitle("CONVERSOR - TEMPERATURA"); //Titulo del programa
    //conectar el dial de centigrados con el slot de esta clase
   connect(ui->inCent,SIGNAL(valueChanged(int)),
            this,SLOT(cent2fahr(int)));
    //conectar el dial de fahrenheit con el slot de esta clase
    connect(ui->inFahr,SIGNAL(valueChanged(int)),
            this,SLOT(fahr2cent(int)));

    //conectar el dial de Kelvin con el slot de esta clase
    connect(ui->inKel,SIGNAL(valueChanged(int)),
            this,SLOT(kel2fahr(int)));

}

Principal::~Principal()
{
    delete ui;
}

void Principal::cent2fahr(int cent)
{
    if (ui->inCent->hasFocus()){  //hasFocus: el usuario esta sobre esa ventana
        int fahr =(cent*9.0/5)+32;
        ui->inFahr->setValue(fahr);
        int k = cent + 273;
        ui->inKel->setValue(k);
    }
}


void Principal::fahr2cent(int i)
{
    if(ui->inFahr->hasFocus()){
        int c = (i-32)*5.0/9;

        ui->inCent->setValue(c);
        int r=(i-32)*5.0/9 + 273.15;
        ui->inKel->setValue(r);
    }
}

void Principal::kel2fahr(int i)
{
    if(ui->inKel->hasFocus()){
        int l = (i-273.15)*9/5.0+32;
        ui->inFahr->setValue(l);
        int c = i-273.15;
        ui->inCent->setValue(c);
    }
}



