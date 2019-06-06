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
    scene->setSceneRect(0,0,200,200);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.9), qreal(0.9));

    isCreatingEdges = false;
    this->isDeletingOrders = false;
    this->counter = 0;
    this->bufNode = new Node(this, generateId(), false);
    this->nodes = QList<Node*>();
    this->edges = QList<Edge*>();
    this->bigraph = new BigraphProject::Bigraph<std::string, BigraphProject::AllocatorContainer<std::string>>();
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

void GraphWidget::addNode(QString carName, bool isCar)
{
    // Физически создать узел графа
    int id = this->bigraph->addVertex(BigraphProject::Vertex<std::string>(carName.toStdString(), isCar));

    // Получаем сцену графа
    QGraphicsScene *scene = this->scene();
    // Создаем объект узла
    Node* node = new Node(this, id, true, carName, isCar);
    // Добавляем узел на сцену
    scene->addItem(node);
    // Задаем узлу позицию в центр виджета
    node->setPos(0, 0);
    // Добавляем узел в список узлов графа
    this->nodes.append(node);
}

void GraphWidget::toggleCreateEdgesMode()
{
    this->isCreatingEdges = !this->isCreatingEdges;
    // Если вдруг вышли из состояния создания ребер..
    // Нужно очистить возможно хранящийся буферный узел
    if (!this->isCreatingEdges){
        if(this->bufNode->isValid())
            this->bufNode->setSelected(false);
        this->bufNode = new Node(this, generateId(),false);
    }
}

void GraphWidget::toggleDeleteOrdersMode()
{
    this->isDeletingOrders = !this->isDeletingOrders;
}

void GraphWidget::checkPressedNode(Node* pressedNode)
{
    // Если находимся в режиме создания ребер..
    if(this->isCreatingEdges&&!this->isDeletingOrders){
        // Если еще нет узла-источника..
        if(!this->bufNode->isValid())
            // Считаем полученный узел таковым
            this->bufNode = pressedNode;
        else{
            // Создаем ребро в контейнере
            int id1 = this->bufNode->getId();
            int id2 = pressedNode->getId();
            int edgeId = this->bigraph->addEdge(bigraph->getVertexById(id1), bigraph->getVertexById(id2));


            // Иначе создаем ребро
            Edge* newE = new Edge(this->bufNode, pressedNode, edgeId);
            // Получаем сцену графа
            QGraphicsScene *scene = this->scene();
            // Добавляем ребро на сцену
            scene->addItem(newE);
            // Добавляем ребро в список ребер
            this->edges.append(newE);
            // Изменяем окрас на узлов на стандартный
            this->bufNode->setSelected(false);
            pressedNode->setSelected(false);
            // Очищаем узел-источник
            this->bufNode = new Node(this, generateId(), false);
        }
    }
    // Если находимся в режиме удаления узлов..
    else if(!this->isCreatingEdges&&this->isDeletingOrders){
        // Проверяем, является ли текущий узел заказом, а не машиной
        // Если да, то..
        if(!pressedNode->getIsCar()){
            // Удаляем узел из контейнера
            int id = pressedNode->getId();
            this->bigraph->delVertex(id);


            // Удаляем все ребра, связанные с ним
            QList<Edge *> e = pressedNode->edges();
            QList<int> ids = QList<int>();
            for(int i=0; i<e.length(); i++){
                ids.append(e.at(i)->getId());
            }
            // Для каждого ребра данной вершины..
            for(int i=0; i<ids.length(); i++){
                // Обходим список ребер в графе, так как вершина возвращает const
                // И ищем текущее ребро, удаляем его
                for(int j=0; j<this->edges.length(); j++){
                    if(ids.at(i)==this->edges.at(j)->getId()){
                        // Удаляем из ребер
                        this->edges.at(j)->sourceNode()->deleteEdge(ids.at(i));
                        this->edges.at(j)->destNode()->deleteEdge(ids.at(i));
                        // Удаляем из контейнера
                        Edge* edge = this->edges.takeAt(j);
                        // Удаляем из памяти
                        delete edge;
                    }
                }
            }
            // Удаляем узел
            for(int i=0; i<this->nodes.length();i++){
                if(this->nodes.at(i)->getId()==pressedNode->getId()){
                    // Удаляем из контейнера
                    Node* node = this->nodes.takeAt(i);
                    // Удаляем из памяти
                    delete node;
                    break;
                }
            }
        }
    }
    else
        pressedNode->setSelected(!(pressedNode->getIsSelected()));
}

void GraphWidget::clearEverything(){
    this->bigraph->clear();


    // Сначала удаляем ребра
    int currentId = 0;
    while(!this->edges.isEmpty()){
        currentId = this->edges.last()->getId();
        // Удаляем из узлов
        this->edges.last()->sourceNode()->deleteEdge(currentId);
        this->edges.last()->destNode()->deleteEdge(currentId);
        // Удаляем из контейнера
        Edge* edge = this->edges.takeLast();
        // Удаляем из памяти
        delete edge;
    }
    // Затем удаляем узлы
    while(!this->nodes.isEmpty()){
        // Удаляем из контейнера
        Node* node = this->nodes.takeLast();
        // Удаляем из памяти
        delete node;
    }
}

bool GraphWidget::containsOrders(){
    for(int i=0; i<this->nodes.length(); i++){
        if(!this->nodes.at(i)->getIsCar())
            return true;
    }
    return false;
}

void GraphWidget::saveNodes()
{
    // Записываем данные из контейнера в файл
    try
    {
        std::ofstream myfile2;
        myfile2.open("bigraphContainer.json");
        myfile2 << *(this->bigraph);
        myfile2.close();
    }
    catch(BigraphProject::ParsingJsonException json)
    {
        cout << *(this->bigraph);
    }

    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }
    else{
        QJsonObject json;
        QJsonArray nodesList;
        for(int i=0; i<this->nodes.length(); i++){
            QJsonObject jNode;
            this->nodes.at(i)->toJson(jNode);
            nodesList.append(jNode);
        }
        json["nodes"] = nodesList;

        QJsonDocument saveDoc(json);
        saveFile.write(saveDoc.toJson());

        saveFile.close();
    }
}

void GraphWidget::loadNodes()
{
    // Создаем контейнер и организуем в него считывание данных
    try
    {
        std::ifstream myfile2;
        myfile2.open("bigraphContainer.json");
        this->bigraph = new BigraphProject::Bigraph<std::string, BigraphProject::AllocatorContainer<std::string>>();
        myfile2 >> &(this->bigraph);
        myfile2.close();
    }
    catch(BigraphProject::ParsingJsonException json)
    {
        cout << json.getJson();
    }
    if(!this->bigraph->isEmpty()){
        QFile loadFile(QStringLiteral("save.json"));

        if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
        }
        else{
            QByteArray saveData = loadFile.readAll();

            QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

            QJsonObject nodesPoses = loadDoc.object();
            if(!nodesPoses.isEmpty() && nodesPoses.contains("nodes")){
                QJsonArray nodesList = nodesPoses["nodes"].toArray();
                this->nodes = QList<Node*>();
                for(int i=0; i<nodesList.size(); i++){
                    QJsonObject jNode = nodesList[i].toObject();
                    if(jNode.contains("id")&&jNode.contains("x")&&jNode.contains("y")){
                        int id = jNode["id"].toInt();
                        // эксепшен
                        BigraphProject::Vertex<std::string> v = this->bigraph->getVertexById(id);

                        Node* node = new Node(this, v.getId(), true, QString::fromStdString(v.getType()), v.getPart());
                        // Получаем сцену графа
                        QGraphicsScene *scene = this->scene();
                        // Добавляем узел на сцену
                        scene->addItem(node);
                        node->setPos(qreal(jNode["x"].toDouble()), qreal(jNode["y"].toDouble()));
                        // Добавляем узел в список узлов графа
                        this->nodes.append(node);

                    }
                }
                std::vector<BigraphProject::Edge<std::string>, BigraphProject::AllocatorContainer<std::string>> vList = this->bigraph->getEdges();
                for(auto it = vList.begin(); it != vList.end(); it++){
                    int edgeId = (*it).getId();
                    int sourceId = (*it).getX().getId();
                    int destId = (*it).getY().getId();

                    // Иначе создаем ребро
                    Edge* newE = new Edge(getNodewithId(sourceId), getNodewithId(destId), edgeId);
                    // Получаем сцену графа
                    QGraphicsScene *scene = this->scene();
                    // Добавляем ребро на сцену
                    scene->addItem(newE);
                    // Добавляем ребро в список ребер
                    this->edges.append(newE);
                }
            }
            loadFile.close();
        }
    }
}

Node* GraphWidget::getNodewithId(int id)
{
    for(int i=0; i<this->nodes.length(); i++){
        if(this->nodes.at(i)->getId() == id)
            return this->nodes.at(i);
    }
    return NULL;
}
Edge* GraphWidget::getEdgewithId(int id)
{
    for(int i=0; i<this->edges.length(); i++){
        if(this->edges.at(i)->getId() == id)
            return this->edges.at(i);
    }
    return NULL;
}

/*void GraphWidget::initializeGraph(QGraphicsScene *scene)
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
}*/
