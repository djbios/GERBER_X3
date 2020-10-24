/*******************************************************************************
*                                                                              *
* Author    :  Damir Bakiev                                                    *
* Version   :  na                                                              *
* Date      :  01 February 2020                                                *
* Website   :  na                                                              *
* Copyright :  Damir Bakiev 2016-2020                                          *
*                                                                              *
* License:                                                                     *
* Use, modification & distribution is subject to Boost Software License Ver 1. *
* http://www.boost.org/LICENSE_1_0.txt                                         *
*                                                                              *
*******************************************************************************/
#pragma once
#include "formsutil/formsutil.h"

namespace Ui {
class PocketOffsetForm;
}

class PocketOffsetForm : public FormsUtil {
    Q_OBJECT

public:
    explicit PocketOffsetForm(QWidget* parent = nullptr);
    ~PocketOffsetForm() override;

private slots:
    void on_sbxSteps_valueChanged(int arg1);
    void on_leName_textChanged(const QString& arg1);

private:
    Ui::PocketOffsetForm* ui;

    int direction = 0;
    void updatePixmap();
    void rb_clicked();
    const QStringList names;
    const QStringList pixmaps;
    // QWidget interface
protected:
    void resizeEvent(QResizeEvent* event) override;
    void showEvent(QShowEvent* event) override;

    // FormsUtil interface
protected:
    void createFile() override;
    void updateName() override;

public:
    void editFile(GCode::File* file) override;
};
