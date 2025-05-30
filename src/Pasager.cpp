#include <iostream>
#include "../includes/Pasager.h"

using namespace std;
using namespace Transport_Aerian;


//constructorul default
Pasager::Pasager() : Persoana(), m_bilet(Bilet()){}    //m_bilet(Bilet()) - initializeaza m_bilet cu un obiect de tip Bilet temporar
                                                    //m_bilet = Bilet() ar fi o initializare gresita pt ca ar apela constructorul de copiere

//constructor parametrizat
Pasager::Pasager(const std::string& nume, const std::string& prenume, const std::string& cnp)
    : Persoana(nume, prenume, cnp) {}

//copy constructor
Pasager::Pasager(const Pasager& other)
    : Persoana(other), m_bilet(other.m_bilet), m_istoric_zboruri(other.m_istoric_zboruri){}

//destructtor
Pasager::~Pasager() {} //vectorul de zboruri se va goli automat la distrugerea obiectului Pasager

void Pasager::SetBilet(const Bilet& b) {
    m_bilet = b;
}

std::string Pasager::DescriereText() const {
    return "Pasager " + GetNume() + " " + GetPrenume() + " (CNP: " + GetCNP() + ")";  //concatenare de string uri cu + din c++
}

std::string Pasager::GetIdText() const {
    return GetCNP();            //id ul specific pasagerului
}

void Pasager::Afisare() const {
    std::cout << DescriereText() << std::endl;
    std::cout << "Varsta: " << GetVarsta() << std::endl;
    std::cout << GetBilet() << std::endl;

    std::cout << "Zboruri asociate:\n";
    for(const auto& zbor : m_istoric_zboruri) {
        if(zbor)
            std::cout << *zbor << std::endl;
    }
}

//metoda care adauga un zbor in lista de zboruri a pasagerului
void Pasager::AdaugaZborIstoric(Zbor* zbor) {
    if(zbor != nullptr) {          //verific daca pointerul este valid
        m_istoric_zboruri.push_back(zbor); 
    }
}

const Bilet& Pasager::GetBilet() const {
    return m_bilet; //returnez biletul asociat pasagerului
}

//getter pt vectorul de zboruri
const vector<Zbor*>& Pasager::GetIstoricZboruri() const {
    return m_istoric_zboruri; 
}

//supraincarcare operator + pt a adauga un zbor
Pasager Pasager::operator+(Zbor* zbor) const {
    Pasager nou(*this);         //creez un nou pasager care este o copie a obiectului curent
    if(zbor!=nullptr) {        //verific daca pointerul este valid
        nou.AdaugaZborIstoric(zbor);  
    }
    return nou; 
}

