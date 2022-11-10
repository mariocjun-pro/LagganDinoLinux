#pragma once

#include "stdafx.h"

class Ent {
public:
    Ent();

    virtual ~Ent();

    __attribute__((unused)) int getId() const { return id; }

protected:
    int id;
    static int cont;
};