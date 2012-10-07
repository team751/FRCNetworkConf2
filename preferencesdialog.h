#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT

private slots:

    void textChanged(const QString &text);

protected:

    int teamNumber;
    
public:
    explicit PreferencesDialog(QWidget *parent = 0);
    ~PreferencesDialog();

    int getTeamNumber();
    void setTeamNumber(int teamNumber);
    
private:
    Ui::PreferencesDialog *ui;
};

#endif // PREFERENCESDIALOG_H
