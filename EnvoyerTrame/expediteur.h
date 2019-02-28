#ifndef EXPEDITEUR_H
#define EXPEDITEUR_H

#include <QMainWindow>
#include <QSerialPort>
#include <QLabel>

namespace Ui {
class Expediteur;
}


class SettingsDialog;

class Expediteur : public QMainWindow
{
    Q_OBJECT

public:
    explicit Expediteur(QWidget *parent = nullptr);
    ~Expediteur();

private slots:

    void on_actionNouveau_triggered();
    void on_actionOuvrir_triggered();
    void on_actionEnregistrer_triggered();
    void on_actionEnregistrer_sous_triggered();
    void on_actionPort_serie_triggered();

    void on_actionConnexion_triggered();

private:
    Ui::Expediteur *ui;
    QLabel *m_status = nullptr;
    SettingsDialog *m_settings;
    QSerialPort *m_serial;
};

#endif // EXPEDITEUR_H
