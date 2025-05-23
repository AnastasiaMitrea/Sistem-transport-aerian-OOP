#ifndef ORA_H
#define ORA_H

#include <iostream>

namespace Transport_Aerian {

    struct Ora {
        int ora;
        int minut;

        Ora(int ora, int minut) : ora(ora), minut(minut) {}
        //afisare ora in formatul HH:MM
        friend std::ostream& operator<<(std::ostream& os, const Ora& ora) {
            os << ora.ora << ":" << ora.minut;
            return os;
        }
    };

}
#endif