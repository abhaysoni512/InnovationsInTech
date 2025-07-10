/*
    The associated object (member) is otherwise unrelated to the object (class)
    The associated object (member) can belong to more than one object (class) at a time
    The associated object (member) does not have its existence managed by the object (class)
    The associated object (member) may or may not know about the existence of the object (class)

    The relationship between doctors and patients is a great example of an association. The doctor clearly has a relationship with his patients, but conceptually it’s not a part/whole (object composition) relationship. A doctor can see many patients in a day, and a patient can see many doctors (perhaps they want a second opinion, or they are visiting different types of doctors). Neither of the object’s lifespans are tied to the other.

    We can say that association models as “uses-a” relationship. The doctor “uses” the patient (to earn income). The patient uses the doctor (for whatever health purposes they need).
*/

#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Patient;
class Doctor{
private:
    string m_name{};
    std::vector<std::reference_wrapper<const Patient>> m_patient;
public:
    Doctor(string_view name):m_name(name){}
    // adding patient
    void addPatient(Patient &Patient);
    // getting doctor's name
    const std::string &getDoctorName() const{
        return m_name;
    }
    // << operator overloading
    friend std::ostream &operator<<(std::ostream &out, const Doctor &doctor);
};

class Patient{
private:
    string m_name{};
    std::vector<std::reference_wrapper<const Doctor>> m_doctor;

    void addDoctor(const Doctor &doctor){
        m_doctor.push_back(doctor);
    }
public:
    Patient(string_view name):m_name(name){}

    friend std::ostream &operator<<(std::ostream &out, const Patient &patient);

    const std::string &getPatientName() const{
        return m_name;
    }

    friend void Doctor::addPatient(Patient &patient);
};

void Doctor::addPatient(Patient &patient){
    // Our doctor will add this patient
    m_patient.push_back(patient);
    // and the patient will also add this doctor
    patient.addDoctor(*this);
}

std::ostream &operator<<(std::ostream &out, const Doctor &doctor)
{
    if(doctor.m_patient.empty()){
        out<<doctor.m_name<<" Currently doesn't seeking anyone";
        return out;
    }
    out << doctor.m_name << " is seeing patients: ";
    for (auto const &patient : doctor.m_patient){
        out<<patient.get().getPatientName()<<" ,";
    }
    return out;
}

std::ostream &operator<<(std::ostream &out, const Patient &patient)
{
    if(patient.m_doctor.empty()){
        out<<patient.m_name<<" has no doctor right now";
        return out;
    }

    out<<patient.m_name<<" is examined by: ";
    for(auto const &doctor : patient.m_doctor){
        out<<doctor.get().getDoctorName()<<" ";
        
    }
    return out;
}

int main(){
    // Create a Patient outside the scope of the Doctor
    Patient dave{"Dave"};
    Patient frank{"Frank"};
    Patient betsy{"Betsy"};

    Doctor james{"James"};
    Doctor scott{"Scott"};

    cout<<dave<<endl;

    james.addPatient(dave);
    cout << dave << endl;
    cout << james << endl;

    james.addPatient(frank);
    cout << james << endl;
}