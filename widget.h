#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QGridLayout>
#include <QTimer>

#include "runner.h"

#include <cmath>

#include <QSpinBox>
#include <QComboBox>

class MoveCmd : public QWidget {
    Q_OBJECT
public :
    QSpinBox  sb_from;
    QSpinBox  sb_to  ;
    QSpinBox  sb_numb;
    QComboBox cb_res ;
    MoveCmd(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        sb_from.setRange(0, _gs.planetsSize);
        sb_to.setRange(0, _gs.planetsSize);
        sb_numb.setRange(0, 10000);
        for (int r = -1; r < model::MY_WORKER; ++r)
            cb_res.addItem(model::resourceToString(r).data());

        QGridLayout *gl = new QGridLayout;
        gl->setContentsMargins(1, 1, 1, 1);
        gl->setSpacing(1);

        gl->addWidget(&sb_from, 0, 0);
        gl->addWidget(&sb_to  , 0, 1);
        gl->addWidget(&sb_numb, 0, 2);
        gl->addWidget(&cb_res , 0, 3);

        setLayout(gl);

        adjustSize();
        setFixedSize(size());
    }
};
class BuildCmd : public QWidget {
    Q_OBJECT
public :
    QSpinBox  sb_planet;
    QComboBox cb_building;
    BuildCmd(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        sb_planet.setRange(0, _gs.planetsSize);
        for (int r = 0; r < model::BUILDING_SIZE; ++r)
            cb_building.addItem(model::buildingTypeToString(r).data());

        QGridLayout *gl = new QGridLayout;
        gl->setContentsMargins(1, 1, 1, 1);
        gl->setSpacing(1);

        gl->addWidget(&sb_planet  , 0, 0);
        gl->addWidget(&cb_building, 0, 1);

        setLayout(gl);

        adjustSize();
        setFixedSize(size());
    }
};

class Map : public QWidget {
    Q_OBJECT
public:

    QVector<MoveCmd *> v_move;
    QVector<BuildCmd *> v_build;

    QPushButton *pb_send { nullptr };
    QPushButton *pb_auto { nullptr };

    Runner runner;

    int timer_id;

    explicit Map(const std::string& host,
                 int port,
                 const std::string& token,
                 QWidget *parent = nullptr)
        : QWidget(parent), runner(host, port, token)
    {
        setWindowTitle("RAIC 2021 mouseGame");

        runner.listen();

        pb_send = new QPushButton("Send answer");
        connect(pb_send, &QPushButton::released, this, &Map::send);

        pb_auto = new QPushButton("Auto");
        pb_auto->setCheckable(true);
        connect(pb_auto, &QPushButton::toggled, this, &Map::start);

        QGridLayout *gl = new QGridLayout;
        gl->setContentsMargins(1, 1, 1, 1);
        gl->setSpacing(1);

        v_move.resize(15);
        for (int i = 0; i < 15; ++i) {
            v_move[i] = new MoveCmd;
            gl->addWidget(v_move[i], i, 0);
        }

        v_build.resize(5);
        for (int i = 0; i < 5; ++i) {
            v_build[i] = new BuildCmd;
            gl->addWidget(v_build[i], i, 1);
        }

        gl->addWidget(pb_send, 20, 0);
        gl->addWidget(pb_auto, 20, 1);
        setLayout(gl);

        adjustSize();
        setFixedSize(size());

        show();
    }
    ~Map() {  }

protected:
    void timerEvent(QTimerEvent *event) override {
        pb_send->released();
        QWidget::timerEvent(event);
    }
signals:

public slots:
    void start(bool is) {
        if (is)
            timer_id = startTimer(100);
        else
            killTimer(timer_id);
    }

    void send() {
        model::Action actions;

        for (auto &move : v_move) {
            if (move->sb_numb.value()) {
                if (move->cb_res.currentIndex()) {
                    actions.moves.push_back(model::MoveAction(move->sb_from.value(),
                                                              move->sb_to.value(),
                                                              move->sb_numb.value(),
                                                              model::Resource(move->cb_res.currentIndex() -1)
                                                             )
                                            );
                } else {
                    actions.moves.push_back(model::MoveAction(move->sb_from.value(),
                                                              move->sb_to.value(),
                                                              move->sb_numb.value(),
                                                              model::NO_RES
                                                             )
                                            );
                }

                move->sb_numb.setValue(0);
            }
        }
        for (auto &build: v_build) {
            if (build->sb_planet.value()) {
                actions.buildings.push_back(model::BuildingAction(build->sb_planet.value(),
                                                                  (model::BuildingType)build->cb_building.currentIndex()));

                build->sb_planet.setValue(0);
            }
        }

        runner.send(actions);
    }
};

#endif // TORMAP_H
