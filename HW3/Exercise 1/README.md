In domeniul transmisiunii informatiei, una din cele mai utilizate mecanisme matematice este acela al vectorului n-dimensional. Vom considera n>1.

# Cerință
Să se creeze clasa Vector, implementând conținutul acesteia astfel:

- Clasa trebuie să conțină 1 atribut privat numite mDim. Acesta este dimensiunea matricii, iar tipul acestuia este număr întreg fără semn pe 16 biți.
- Clasa trebuie să conțină 1 atribut privat numit mValues. Acesta este un pointer la numere fracționare pe dublă precizie, iar memoria pentru acest pointer va fi alocată în constructor.
- Un constructor ce ia ca argument un numar intreg fără semn ce reprezintă dimensiunea vectorului și să aloce memorie pentru a stoca aceste valori.
- Un al doilea constructor care să nu ia niciun argument. Acesta doar va inițializa atributele întregi cu valoarea 0.
- Un al treilea constructor, care va fi constructorul de copiere. Acesta primește ca argument un obiect de tip const Vector & și rolul lui este de a copia toate valorile atributelor obiectului dat ca parametru în obiectul curent (this).
- Operatorul binar + care sa adune doi vectori, element cu element si sa intoarca valoarea vecotrului suma. In cazul in care dimensiunile vectorilor difera, se va returna un obiect de tip Vector gol.
- Operatorul binar * care sa calculeze produsul scalar al vectorilor. Produsul scalar se poate calcula utilizand formula a⃗ =(a1,a2,...,an) b⃗ =(b1,b2,...,bn) a⃗ ⋅b⃗ =∑ai⋅bi. Acest operator va lua ca argument un obiect de tip const Vector&. Operatorul "*" va intoarce un numar fractionar, in dubla precizie. In cazul a 2 vectori cu dimensiuni diferite, se vor ignora acele valori ale vectorului cu dimensiune mai mare ce depasesc dimensiunea vectorului mic.
- Operatorul unar ! care calculeaza modulul vectorului.
- Operatorul binar ^ care sa calculeze produsul vectorial al celor 2 vectori. Produsul vectorial se poate calcula utilizand formulele urmatoare. In cazul in care dimensiunea este 2, formula de calcul este: a⃗ =(a1,a2) b⃗ =(b1,b2) c⃗ =a⃗ ×b⃗ =(0,0,a1⋅b2−a2⋅b1). In cazul in care dimensiunea este 3, formula de calcul este: a⃗ =(a1,a2,a3)  b⃗ =(b1,b2,b3)  c⃗ =a⃗ ×b⃗ =(a2⋅b3−a3⋅b2,a1⋅b3−a3⋅b1,a1⋅b2−a2⋅b1)  Acest operator va lua ca argument un obiect de tip const Vector&. Operatorul "^" va intoarce un alt vector, reprezentat de vectorul produs vectorial. Produsul vectorial se va calcula DOAR pentru dimensiunile 2 si 3 ale vectorului. In cazul in care dimensiunea depaseste valoarea 3, se va intoarce vectorul ce are pe fiecare pozitie valoarea 1 de dimensiunea respectiva. In cazul in care cei doi vectori au dimensiuni diferite, se va returna vectorul de dimensiune 0.
- O metodă de tip getter numită getValue care să ia ca argumente o valoare intreaga fără semn ce reprezintă coordonata valorii din vector ce trebuie întoarsă. Tipul de dată returnat trebuie să îl deduceți voi.
- O metodă de tip setter numită setValue care să ia ca argumente un numar intreg fara semn ce reprezinta coordonata valorii din vector ce trebuie întoarsă și o valoare ce trebuie plasată în vector pe poziția respectivă. Tipul de dată returnat trebuie să îl deduceți voi.
- Destructorul care să elibereze memoria alocată de constructor.
- În funcția main se vor citi 2 vectori (A si B), de dimensiuni oarecare. In cazul in care cei 2 vectori au aceeasi dimensiune si dimensiunea este 2 sau 3, se va calcula produsul vectorial al celor 2 vectori. La produsul acesta se va aduna vectorul A si se va imparti fiecare element din vectorul rezultat la modulul sau. In cazul in care vectorii au dimensiunea 2, rezultatul produsului vectorial va avea dimensiunea 3. Se va crea un vector cu dimensiunea 3, ce are pe primele 2 pozitii valorile din vectorul A, iar pe a 3-a are valoarea 0. Daca cei 2 vectori au dimensiuni diferite sau au dimensiuni egale si dimensiunea mai mare ca 3, se va calcula produsul lor scalar, se va construi un vector ce are dimensiunea vectorului mai mare si are pe fiecare pozitie valoarea produsului scalar al celor 2 vectori. Se va aduna vectorul cu dimensiunea mai mare la acesta, apoi se va imparti fiecare element la modulul vectorului.

# Date de intrare
Pe prima linie se află 2 valori întregi fără semn: dim_vector_1 dim_vector_2;<br>
Pe următoarea linie se vor gasi dim_vector_1 valori fractionare, reprezentate in dubla precizie;<br>
Pe urmatoarea linie se vor gasi dim_vector_2 valori fractionare, reprezentate in dubla precizie;
# Date de ieșire
Se va afișa un singur număr cu două zecimale reprezentand media aritmetica a elementelor din vectorul calculat.
# Observații
Alocați memorie dinamic pentru pentru mValues, folosind operatorul new. Cel mai simplu (și eficient) este să alocați un array de mDim locații de memorie.