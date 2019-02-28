#include "expediteur.h"
#include "ui_expediteur.h"
#include "settingsdialog.h"

#include <QMessageBox>

Expediteur::Expediteur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Expediteur),
    m_status(new QLabel),
    m_settings(new SettingsDialog),
    m_serial(new QSerialPort(this))
{
    ui->setupUi(this);
    ui->statusBar->addWidget(m_status);
    m_status->setText("Déconnecté");
}

Expediteur::~Expediteur()
{
    delete m_settings;
    delete ui;
}

void Expediteur::on_actionNouveau_triggered()
{

}
void Expediteur::on_actionOuvrir_triggered()
{

}

void Expediteur::on_actionEnregistrer_triggered()
{

}

void Expediteur::on_actionEnregistrer_sous_triggered()
{

}

void Expediteur::on_actionPort_serie_triggered()
{
    m_settings->exec();
}

void Expediteur::on_actionConnexion_triggered()
{
    if(ui->actionConnexion->text()=="Connexion")
    {
        const SettingsDialog::Settings p = m_settings->settings();
        m_serial->setPortName(p.name);
        m_serial->setBaudRate(p.baudRate);
        m_serial->setDataBits(p.dataBits);
        m_serial->setParity(p.parity);
        m_serial->setStopBits(p.stopBits);
        m_serial->setFlowControl(p.flowControl);
        if (m_serial->open(QIODevice::WriteOnly))
        {
            ui->actionConnexion->setText("Déconnexion");
            ui->actionPort_serie->setEnabled(false);
            m_status->setText(tr("Connecté à %1 : %2, %3, %4, %5, %6")
                              .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                              .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), m_serial->errorString());
            m_status->setText(tr("Open error"));
        }
    }
    else
    {
        if (m_serial->isOpen())
            m_serial->close();
        ui->actionConnexion->setText("Connexion");
        ui->actionPort_serie->setEnabled(true);
        m_status->setText("Déconnecté");
    }
}
