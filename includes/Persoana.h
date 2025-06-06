#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include <string>
#include <stdexcept> // pt throw invalid_argument
#include "Calendar.h"
#include "Date.h"
#include "Utils.h"
#include "I_Afisabil.h"

namespace Transport_Aerian {

    class Persoana {
    public:
        Persoana(); //constructor defautl
        Persoana(const std::string& nume, const std::string& prenume, const std::string& cnp); ///constructor cu parametri si validare cnp fara varsta
        Persoana(const Persoana& other); //constructor de copiere
        virtual ~Persoana(); //destructor virtual

        std::string GetNume() const;
        std::string GetPrenume() const;
        std::string GetCNP() const;
        int GetVarsta() const;
        Utilitati::Date GetDataNasterii() const;

        void SetNume(const std::string& nume);
        void SetPrenume(const std::string& prenume);
        void SetCNP(const std::string& cnp);
        static bool ValidareCNP(const std::string& cnp);

    private:
        std::string m_nume;
        std::string m_prenume;
        std::string m_cnp;
        int m_varsta;
        Utilitati::Date m_data_nasterii;
        
        static Utilitati::Date _ExtrageDataNasterii(const std::string& cnp);
    };

}

#endif 