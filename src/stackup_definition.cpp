//
// Created by george-sleen on 08/05/25.
//

#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>

#include "stackup_definition.h"


StackupDefinition::StackupDefinition(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QToolButton *buttonMicrostrip = new QToolButton(this);
    buttonMicrostrip->setIcon(QIcon("../img/microstrip.svg"));
    buttonMicrostrip->setIconSize(QSize(256, 128));
    buttonMicrostrip->setText("Microstrip");
    buttonMicrostrip->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QPushButton *buttonMicrostripEdgeCoupled = new QPushButton("Edge-Coupled Microstrip");

    // buttonMicrostrip->

    layout->addWidget(buttonMicrostrip);
    layout->addWidget(buttonMicrostripEdgeCoupled);

    setLayout(layout);
}
