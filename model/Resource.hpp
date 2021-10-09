#ifndef __MODEL_RESOURCE_HPP__
#define __MODEL_RESOURCE_HPP__

#include "Stream.hpp"

namespace model {

enum Resource : int {
    NO_RES    =-1,
    STONE     = 0, //!< Камень
    ORE       = 1, //!< Руда
    SAND      = 2, //!< Песок
    ORGANICS  = 3, //!< Органика
    METAL     = 4, //!< Металл
    SILICON   = 5, //!< Кремний
    PLASTIC   = 6, //!< Пластик
    CHIP      = 7, //!< Чипы
    ACCUM     = 8, //!< Аккум
    MY_WORKER = 9, //!< Рабочие
    EN_WORKER =10, //!< Противник
    RES_SIZE
};

// Read Resource from input stream
Resource readResourceIndex(InputStream& stream);
std::string resourceToString(int value);

struct Resources {
    std::vector<int> res;
    int summ { 0 };

    Resources() { res.resize(RES_SIZE, 0); }

    int& operator[](int val) { if (val < RES_SIZE) return res[val]; else exit(0); }

    /// очистить только ресурсы
    void clearRes() {
        memset(&res[0], 0, sizeof(int)*MY_WORKER);
    }
    /// очистить ВСЕ ресурсы
    void fill0() {
        memset(&res[0], 0, sizeof(int)*RES_SIZE);
    }

    /// добавить ресурсы
    void addRes(const Resources &needRes, int mng = 1) {
        for (int r = 0; r < MY_WORKER; ++r) {
            addRes(r, needRes.res[r] * mng);
        }
    }
    /// добавить ресурс
    void addRes(int type, int val) {
        if (val > 0)
            res[type] += val;
    }
    /// добавить ресурсы не больше чем
    void addCheckRes(const Resources &needRes, int mng = 5) {
        for (int r = 0; r < MY_WORKER; ++r) {
            if (res[r] < needRes.res[r] * mng)
                addRes(r, needRes.res[r] * mng - res[r]);
        }
    }

    /// вычесть ресурсы
    void lowRes(const Resources &hasRes, int mng = 1) {
        for (int r = 0; r < MY_WORKER; ++r) {
            lowRes(r, hasRes.res[r] * mng);
        }
    }
    /// вычесть ресурсы
    void lowRes(const std::vector<int> &hasRes, int mng = 1) {
        for (int r = 0; r < MY_WORKER; ++r) {
            lowRes(r, hasRes[r] * mng);
        }
    }
    /// вычесть ресурс
    void lowRes(int type, int val) {
        res[type] -= val;
        if (res[type] < 0)
            res[type] = 0;
    }

    /// Хватает ли ресурсов
    bool isHasRes(const Resources &needRes) {
        for (int r = 0; r < MY_WORKER; ++r) {
            if (res[r] < needRes.res[r])
                return false;
        }
        return true;
    }

    int summa() {
        summ = 0;
        for (int r = STONE; r < MY_WORKER; ++r)
            summ += res[r];
        return summ;
    }
};


}

#endif
