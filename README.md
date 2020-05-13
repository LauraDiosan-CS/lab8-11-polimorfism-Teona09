Fabrica de gadget-uri

Operatorii unei fabrici de gadget-uri folosesc un soft pentru a gestiona seriile de dispozitive.
Operatorul are la dispozitie functionalitatile:
    1. Login. Dupa autentificarea cu success, sunt afisate toate seriile:
de tip Telefon(numeProducator, numeModel, unitatiProduse, listaOperatoriGSMCompatibili) si Drona(numeProducator, numeModel, unitatiProduse, numarRotoare)
Un producator poate avea mai multe serii chiar si pentru acelasi model.
    2. Operare (dupa autentificarea cu success)
           Cautare dupa numeProducator -> Se vor afisa toate informatiile seriilor acelui producator (indiferent de ce tip sunt)
           Adaugare. Operatorul poate introduce noi serii cu urmatorii validatori: unitatiProduse > 100 si un telefon trebuie sa aiba cel putin un operator in lista listaOperatoriGSMCompatibili;
    3. Logout

Precizări:
   1. la un moment dat, o singură persoană folosește aplicația (deci nu trebuie acces concurent)
   2. Datele de intrare se vor stoca în fișiere text. La pornirea aplicației, entitățile din fișiere vor fi citite din fișier(e). Modificările pe parcursul derulării aplicației se vor salva în aceste fișiere. Toate operațiile de citire și scriere se vor realiza folosind biblioteca iostream.
   3. La pornirea aplicației utilizatorul poate alege tipul fișierului/fișierelor pe baza carora se vizualizeaza datele (CSV sau HTML – aplicatia trebuie sa ofere posibilitatea lucrului cu ambele tipuri de fisiere ). În funcție de acest tip ales de utilizator, salvarea datelor în fișier(e) se va face respectând formatul corect. De ex., dacă avem o entitate Student(id, cnp, nume, medie) o linie dintr-un fișier csv ar putea conține atributele unei entiăți separate prin virgulă
           – 2, 2800429010309, Ana, 9.80
           – 9, 1860808010391, George, 9.90
Implementarea acestei cerințe se va realiza folosind structuri polimorfice.
   4. Se vor folosi excepții pentru semnalarea posibilelor erori. Pentru aceasta se vor defini și folosi clase de tip Excepție.
   5. Se vor valida datele preluate în aplicație.
   6. Se va crea diagrama UML a aplicației folosind un instrument specializat (de ex StarUML).
