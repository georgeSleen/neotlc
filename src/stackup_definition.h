//
// Created by george-sleen on 08/05/25.
//

#ifndef STACKUP_DEFINITION_H
#define STACKUP_DEFINITION_H

#include <QWidget>

/**
 * @class StackupDefinitionWidget
 * @brief A QWidget that defines the PCB stackup configuration.
 *
 * This widget allows the user to define the layer structure, material properties,
 * and dimensions of a PCB stackup.
 */
class StackupDefinition : public QWidget {
    Q_OBJECT

public:
    explicit StackupDefinition(QWidget *parent = nullptr);
};


#endif //STACKUP_DEFINITION_H
