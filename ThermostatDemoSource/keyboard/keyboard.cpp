/*
 * Author: LT Thomas <ltjr@ti.com>
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


#include "keyboard.h"
#include "ui_keyboard.h"
#include <QtGui>

Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);

    setCursor(Qt::BlankCursor);

    connect ( ui->Buttonq, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonw, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttone, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonr, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttont, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttony, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonu, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttoni, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttono, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonp, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );


    connect ( ui->Buttona, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttons, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttond, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonf, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttong, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonh, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonj, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonk, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonl, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );

    connect ( ui->Buttonz, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonx, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonc, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonv, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonb, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonn, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Buttonm, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );

    connect ( ui->Button0, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Button1, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Button2, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Button3, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Button4, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Button5, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Button6, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Button7, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Button8, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );
    connect ( ui->Button9, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );

    connect ( ui->space, SIGNAL( clicked() ), this, SLOT( keyboardHandler() ) );

    outputText = "";
    shift = false;
    ui->lineEdit->setFocus();

}

void Keyboard::keyboardHandler()
{
    QPushButton *button = (QPushButton *)sender();
    //qDebug() << "pressed " << button->text();

    QString inputText = button->text();

    if (inputText == "Space")
    {
        outputText += " ";
    }
    else if(inputText == "&&")
    {
        outputText += "&";
    }
    else if(inputText == "\\")
    {
        outputText += ui->Buttona->text() ;
    }
    else
    {
        if(shift)
        {
            shift = false;
            outputText += inputText.toUpper();
        }
        else
        {
            outputText += inputText;
        }
    }


    ui->lineEdit->setText(outputText);

}

void Keyboard::setLineEdit(QLineEdit * line)
{
    outputLineEdit = line;
}

Keyboard::~Keyboard()
{
    delete ui;
}


void Keyboard::on_shift_clicked()
{
    shift = true;
}


void Keyboard::on_char_2_toggled(bool checked)
{
    if(checked)
    {
        ui->Button0->setText("`");
        ui->Button1->setText("~");
        ui->Button2->setText("!");
        ui->Button3->setText("@");
        ui->Button4->setText("#");
        ui->Button5->setText("$");
        ui->Button6->setText("%");
        ui->Button7->setText("^");
        ui->Button8->setText("&&");// trUtf8("\u0040")
        ui->Button9->setText("*");

        ui->Buttonq->setText("(");
        ui->Buttonw->setText(")");
        ui->Buttone->setText("-");
        ui->Buttonr->setText("_");
        ui->Buttont->setText("=");
        ui->Buttony->setText("+");
        ui->Buttonu->setText("[");
        ui->Buttoni->setText("]");
        ui->Buttono->setText("{");
        ui->Buttonp->setText("}");

        ui->Buttona->setText(trUtf8("\\"));
        ui->Buttons->setText("|");
        ui->Buttond->setText(";");
        ui->Buttonf->setText(":");
        ui->Buttong->setText("'");
        ui->Buttonh->setText("\"");
        ui->Buttonj->setText("/");
        ui->Buttonk->setText("?");
        ui->Buttonl->setText("");

        ui->Buttonz->setText("<");
        ui->Buttonx->setText(">");
        ui->Buttonc->setText(",");
        ui->Buttonv->setText(".");
        ui->Buttonb->setText("");
        ui->Buttonn->setText("");
        ui->Buttonm->setText("");

    }
    else
    {
        ui->Button0->setText("0");
        ui->Button1->setText("1");
        ui->Button2->setText("2");
        ui->Button3->setText("3");
        ui->Button4->setText("4");
        ui->Button5->setText("5");
        ui->Button6->setText("6");
        ui->Button7->setText("7");
        ui->Button8->setText("8");
        ui->Button9->setText("9");

        ui->Buttonq->setText("q");
        ui->Buttonw->setText("w");
        ui->Buttone->setText("e");
        ui->Buttonr->setText("r");
        ui->Buttont->setText("t");
        ui->Buttony->setText("y");
        ui->Buttonu->setText("u");
        ui->Buttoni->setText("i");
        ui->Buttono->setText("o");
        ui->Buttonp->setText("p");

        ui->Buttona->setText("a");
        ui->Buttons->setText("s");
        ui->Buttond->setText("d");
        ui->Buttonf->setText("f");
        ui->Buttong->setText("g");
        ui->Buttonh->setText("h");
        ui->Buttonj->setText("j");
        ui->Buttonk->setText("k");
        ui->Buttonl->setText("l");

        ui->Buttonz->setText("z");
        ui->Buttonx->setText("x");
        ui->Buttonc->setText("c");
        ui->Buttonv->setText("v");
        ui->Buttonb->setText("b");
        ui->Buttonn->setText("n");
        ui->Buttonm->setText("m");
    }
}

void Keyboard::on_clear_clicked()
{
    // turned into cancel button for this application
    this->close();
    //outputText="";
    //ui->lineEdit->setText(outputText);
}



void Keyboard::on_enterButton_clicked()
{
    //qDebug() << "enter";
    outputLineEdit->setText(outputText);
    outputText="";
    ui->lineEdit->setText(outputText);
    close();
}

void Keyboard::on_lineEdit_textChanged(const QString &arg1)
{
    outputText = arg1;
    ui->lineEdit->setText(outputText);

}

void Keyboard::on_lineEdit_returnPressed()
{
    //qDebug() << "enter";
    outputLineEdit->setText(outputText);
    outputText="";
    ui->lineEdit->setText(outputText);
    close();
}

void Keyboard::on_backButton_clicked()
{
    outputText.remove(outputText.length()-1,outputText.length());
    ui->lineEdit->setText(outputText);
}
