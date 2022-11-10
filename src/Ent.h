#pragma once

#include "stdafx.h"

class Ent {
public:
    Ent();

    virtual ~Ent();

    int getId() const { return id; }

protected:
    int id;
    static int cont;
};