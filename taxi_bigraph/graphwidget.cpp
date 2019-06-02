/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include "graphwidget.h"
#include "edge.h"
#include "node.h"

#include <QtGui>

#include <math.h>

GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.9), qreal(0.9));

    isCreatingEdges = false;
    this->bufNode = new Node(this,false);
    //initializeGraph(scene);
}

/*void GraphWidget::itemMoved()
{
    if (!timerId)
        timerId = startTimer(1000 / 25);
}*/

/*void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        centerNode->moveBy(0, -20);
        break;
    case Qt::Key_Down:
        centerNode->moveBy(0, 20);
        break;
    case Qt::Key_Left:
        centerNode->moveBy(-20, 0);
        break;
    case Qt::Key_Right:
        centerNode->moveBy(20, 0);
        break;
    case Qt::Key_Plus:
        scaleView(qreal(1.2));
        break;
    case Qt::Key_Minus:
        scaleView(1 / qreal(1.2));
        break;
    case Qt::Key_Space:
    case Qt::Key_Enter:
        foreach (QGraphicsItem *item, scene()->items()) {
            if (qgraphicsitem_cast<Node *>(item))
                item->setPos(-150 + qrand() % 300, -150 + qrand() % 300);
        }
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}*/

void GraphWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}

void GraphWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void GraphWidget::addNode(QString carName)
{
    // Получаем сцену графа
    QGraphicsScene *scene = this->scene();
    // Создаем объект узла
    Node* node = new Node(this, true, carName, true);
    // Добавляем узел на сцену
    scene->addItem(node);
    // Задаем узлу позицию в центр виджета
    node->setPos(0, 0);
    // Добавляем узел в список узлов графа
    this->nodes.append(node);

    // TODO физически создать узел графа
}

void GraphWidget::toggleCreateEdgesMode()
{
    this->isCreatingEdges = !this->isCreatingEdges;
    // Если вдруг вышли из состояния создания ребер..
    // Нужно очистить возможно хранящийся буферный узел
    if (!this->isCreatingEdges){
        this->bufNode = new Node(this, false);
    }
}

void GraphWidget::checkNewEdge(Node* pressedNode)
{
    // Если находимся в режиме создания ребер..
    if(this->isCreatingEdges){
        // Если еще нет узла-источника..
        if(!this->bufNode->isValid())
            // Считаем полученный узел таковым
            this->bufNode = pressedNode;
        else{
            // Иначе создаем ребро
            Edge* newE = new Edge(this->bufNode, pressedNode);
            // Получаем сцену графа
            QGraphicsScene *scene = this->scene();
            // Добавляем ребро на сцену
            scene->addItem(newE);
            // Добавляем ребро в список ребер
            this->edges.append(newE);
            // Очищаем узел-источник
            this->bufNode = new Node(this, false);
        }
    }
}

void GraphWidget::initializeGraph(QGraphicsScene *scene)
{
    Node *node1 = new Node(this, false);
    Node *node2 = new Node(this, false);
    Node *node3 = new Node(this, false);
    Node *node4 = new Node(this, false);
    Node *node5 = new Node(this, false);
    Node *node6 = new Node(this, false);
    Node *node7 = new Node(this, false);
    Node *node8 = new Node(this, false);
    Node *node9 = new Node(this, false);
    scene->addItem(node1);
    scene->addItem(node2);
    scene->addItem(node3);
    scene->addItem(node4);
    scene->addItem(node5);
    scene->addItem(node6);
    scene->addItem(node7);
    scene->addItem(node8);
    scene->addItem(node9);
    scene->addItem(new Edge(node1, node2));
    scene->addItem(new Edge(node2, node3));
    scene->addItem(new Edge(node2, node5));
    scene->addItem(new Edge(node3, node6));
    scene->addItem(new Edge(node4, node1));
    scene->addItem(new Edge(node4, node5));
    scene->addItem(new Edge(node5, node6));
    scene->addItem(new Edge(node5, node8));
    scene->addItem(new Edge(node6, node9));
    scene->addItem(new Edge(node7, node4));
    scene->addItem(new Edge(node8, node7));
    scene->addItem(new Edge(node9, node8));

    node1->setPos(-150, -150);
    node2->setPos(0, -150);
    node3->setPos(150, -150);
    node4->setPos(-150, 0);
    node5->setPos(0, 0);
    node6->setPos(150, 0);
    node7->setPos(-150, 150);
    node8->setPos(0, 150);
    node9->setPos(150, 150);
}