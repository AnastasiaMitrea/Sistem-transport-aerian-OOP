#ifndef PILOT_H
#define PILOT_H

#include "Persoana.h"
#include "../includes/calendar.h" 

namespace Transport_Aerian {

    class Pilot : public Persoana, public Interfete::IAfisabil {
    public:
        Pilot();
        Pilot(const std::string& nume, const std::string& prenume, const std::string& cnp, int an_incepere);

        int GetExperientaAni() const;
        int GetAnIncepere() const;

        void Afisare() const override;
        std::string DescriereText() const override;
        std::string GetIdText() const override;


    private:
        int m_an_incepere;
        int m_experienta_ani;

        void _CalculeazaExperienta(); 
    };

} 

#endif 
