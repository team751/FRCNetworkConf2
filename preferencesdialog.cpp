#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"


PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);
    connect(ui->teamNumberField, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));

    //Default team number. Should be overriden with setTeamNumber(int)
    teamNumber = 0;

    ui->teamNumberField->setText(QString::number(teamNumber));
}

int PreferencesDialog::getTeamNumber() {
    return teamNumber;
}

void PreferencesDialog::setTeamNumber(int teamNumber) {
    this->teamNumber = teamNumber;
    ui->teamNumberField->setText(QString::number(teamNumber));
}

void PreferencesDialog::textChanged(const QString &text) {
    bool ok = false;
    int newTeamNumber = text.toInt(&ok);

    if(ok == true) {
        teamNumber = newTeamNumber;
    }
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}
