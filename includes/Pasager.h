#ifndef PASAGER_H
#define PASAGER_H

#include <iostream> 
#include <string>
#include <vector>

#include "Persoana.h"
#include "Bilet.h"
#include "Zbor.h"

namespace Transport_Aerian {

    class Pasager : public Persoana, public Interfete::IAfisabil {

    public:
        Pasager(); 
        Pasager(const std::string& nume, const std::string& prenume, const std::string& cnp);
        Pasager(const Pasager& other);
        ~Pasager();

        void AdaugaZborIstoric(Zbor* zbor); //adaug un pointer la Zbor in lista de zboruri ale pasagerului
        const Bilet& GetBilet() const;
        const std::vector<Zbor*>& GetIstoricZboruri() const; //getter pt lista de zboruri
        void SetBilet(const Bilet& b);

        Pasager operator+(Zbor* zbor) const; //supraincarcare operator + pt a adauga un zbor

        friend std::ostream& operator<<(std::ostream& out, const Pasager& pasager);

        std::string DescriereText() const override;
        std::string GetIdText() const override;
        void Afisare() const override;

    private:
        Bilet m_bilet; //obiect de tip bilet asociat pasagerului
        std::vector<Zbor*> m_istoric_zboruri;  //lsita de zboruri ale unui pasager - obiecte pe heap, gestionate dinamic
    };

}

#endif 