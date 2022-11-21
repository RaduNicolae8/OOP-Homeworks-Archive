Se dau de la tastatură un număr necunoscut de mare de perchi de două, trei sau patru numere fracționare reprezentabile cu dublă precizie (până la EOF). Aceste perechi reprezintă numere imaginare de forma a + bi, a+bi+cj sau a+bi+cj+dk. Părțile imaginare din numere au propritetățile i2=-1, j2=-1, k2=-1, i*j=j*i=0, j*k=k*j=0, i*k= k*i=0. Astfel, se pot înmulții numere imaginare, chiar dacă ele sunt de tipuri diferite. Însă, această înmulțire nu este comutativă. Astfel, dacă înmulțim un număr imaginar cu 2 componente cu un număr imaginar cu 3 componente rezultatul va fi un număr imaginar cu 2 componente (a treia componentă nu se ia în calcul), însă dacă înmulțim un număr imaginar cu 3 componente cu un număr imaginar cu 2 componente rezultatul va fi un număr imaginar cu 3 componente. Analog pentru toate celelalte tipuri de înmulțiri. Pe lângă acestea, operația de adunare nu este nici ea comutativă, iar regulile se aplică la fel ca la înmulțire.


# Cerințe pentru punctaj maxim
Să se creeze o clasă cu numele Point cu următoarele specificații:
- clasa trebuie să conțină 2 atribute protected numite mCoordinates și mDistance, primul fiind un std::vector de numere fracționare pe dublă precizie, iar al doilea număr fracționar pe dublă precizie. Observație: Dacă vom folosi clasa Point ca și parametru al unei metode în altă clasă nu vom putea accesa atributul mCoordinates deoarece el este protected. Astfel, va trebui să declarăm cele 3 clase se mai jos ca fiind "prietene" clasei noastre, adică friend class Point2D; și așa mai departe în spațiul protected al clasei Point.
- clasa trebuie să fie abstractă. Abstractizarea se va face prin crearea a 4 metode publice pur virtual numite print, calculateDistance, add și multiply. Metodele print și calculateDistance nu vor returna nimic și nu primesc niciun parametru. În schimb, metodele add și multiply vor întoarce un pointer la clasa Point și va primi ca parametru un alt pointer la clasa Point.
- clasa trebuie să conțină o metodă publică fără niciun parametru numită getDistance. Aceasta trebuie să întoarcă valoarea atributului mDistance. Tipul de dată returnat al metodei trebuie să îl deduceți voi.
- clasa trebuie să conțină o metodă publică fără niciun parametru numită getSize. Aceasta trebuie să întoarcă dimensiunea vectorului mCoordinates. Tipul de dată returnat al metodei trebuie să fie număr întreg fără semn pe 64 de biți.

Să se creeze o clasă cu numele Point2D cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Point;
- clasa trebuie să conțină un constructor public cu 2 parametrii care să introducă în vectorul mCoordinates valoarile specificate.
- clasa trebuie să implementeze metodele pur virtuale din clasa de bază. Astfel, metoda print va afișa datele în conformitate cu spusele din cerință, metoda calculateDistance va calcula metrica impusă în cerință și rezultatul se va stoca în atributul mDistance, ,metoda add va întoarce suma dintre punctul 2D curent și un punct dat ca parametru, iar metoda multiply va întoarce produsul dintre punctul 2D curent și un punct dat ca parametru, rezultatul pe care îl va întoarce funcția fiind un punct 2D. Dacă după adunare sau înmulțire se obține un punct cu o dimensiune mai mare, restul dimensiunilor se ignoră.

Să se creeze o clasă cu numele Point3D cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Point;
- clasa trebuie să conțină un constructor public cu 3 parametrii care să introducă în vectorul mCoordinates valoarile specificate.
- clasa trebuie să implementeze metodele pur virtuale din clasa de bază. Astfel, metoda print va afișa datele în conformitate cu spusele din cerință, metoda calculateDistance va calcula metrica impusă în cerință și rezultatul se va stoca în atributul mDistance, ,metoda add va întoarce suma dintre punctul 3D curent și un punct dat ca parametru, iar metoda multiply va întoarce produsul dintre punctul 3D curent și un punct dat ca parametru, rezultatul pe care îl va întoarce funcția fiind un punct 3D. Dacă după adunare sau înmulțire se obține un punct cu o dimensiune mai mare, restul dimensiunilor se ignoră.

Să se creeze o clasă cu numele Point4D cu următoarele specificații:
- clasa trebuie să fie moștenită din clasa Point;
- clasa trebuie să conțină un constructor public cu 4 parametrii care să introducă în vectorul mCoordinates valoarile specificate.
- clasa trebuie să implementeze metodele pur virtuale din clasa de bază. Astfel, metoda print va afișa datele în conformitate cu spusele din cerință, metoda calculateDistance va calcula metrica impusă în cerință și rezultatul se va stoca în atributul mDistance, ,metoda add va întoarce suma dintre punctul 4D curent și un punct dat ca parametru, iar metoda multiply va întoarce produsul dintre punctul 4D curent și un punct dat ca parametru, rezultatul pe care îl va întoarce funcția fiind un punct 4D. Dacă după adunare sau înmulțire se obține un punct cu o dimensiune mai mare, restul dimensiunilor se ignoră.

ATENȚIE! Ultimele 3 clase trebuie să aibă definite și un constructor cu 0 parametrii care să introducă în vectorul mCoordinates coordonatele inițializate cu valoarea 0, iar distanța să aibă și ea de asemenea valoarea 0. <br>

# Cerință
Să se găsească sumele tuturor numerelor imaginare cu 4 coordonate, cu 3 coordonate și cu 2 coordonate. Se vor compara distanțele acestor numere obținute prin sumare cu toate numerele care au atâtea coordonate câte are și suma. Dacă distanța numerelor este mai mare sau egală ca distanța sumei, atunci se va afișa pătratul numărului, conform specificațiilor de la Date de ieșire. Distanța se calculează după următoarele formule:
- 2D: dist = |(a+b)/2|+√|ab|
- 3D: dist = |(a+b+c)/3|+√3|abc|
- 4D: dist = |(a+b+c+d)/4|+√4|abcd|
Date de intrare <br>
Un număr necunoscut de perechi de două, trei sau patru numere fracționare reprezentabile în dublă precizie, numerele dintr-o pereche separate prin punct-și-virgulă, perechile separate prin unul sau mai multe spații.

Date de ieșire <br>
Se vor afișa pătratele numerelor complexe care au distanța mai mare sau egală decât distanța sumei care are același număr de coordonate ca numerele complexe verificate. Se vor afișa componentele pătratelor numerelor, împreună cu părțile lor imaginare, de forma a±bi, a±bi±cj sau a±bi±cj±dk, în funcție de câte componente au numerele. Pe lângă aceasta, se va afișa și distanța numărului (NU a pătratului lui), separată de număr printr-o săgeată de forma " -> ". Pătratele trebuie afișate descrescător în funcție de numărul de coordonate, iar dacă numărul de coordonate este același, se vor afișa descrescător după distanța numărului (NU a pătratului). Coordinatele și distanțele vor fi afișate cu 3 zecimale.

Exemplu<br>
Intrare<br>

3;2  -2;-1;1   -1;-1<br>
3;3;3   2;2   -2;-1<br>
1;1;3;2<br>

Ieșire <br>

-13.000+2.000i+6.000j+4.000k -> 3.315<br>
-9.000+18.000i+18.000j -> 6.000<br>
5.000+12.000i -> 4.949<br>
0.000+8.000i -> 4.000<br>

Explicație <br>

Se vor lua numerele cu 4 coordonate și se va face suma lor:<br>
sum4D = 1+i+3j+2k                                         dist = 3.315 <br>
Se vor lua numerele cu 3 coordonate și se va face suma lor: <br>
sum3D = (-2-i+j) + (3+3i+3j) = 1+2i+4j                    dist = 4.333 <br>
Se vor lua numerele cu 2 coordonate și se va face suma lor: <br>
sum2D = (3+2i) + (-1-i) + (2+2i) + (-2-i) = 2+2i          dist = 4.000 <br>
Vom calcula distanța fiecărui număr: <br>

3+2i        =>      dist = 4.949 <br>
-2-i+j      =>      dist = 1.927<br>
-1-i        =>      dist = 2.000<br>
3+3i+3j     =>      dist = 6.000<br>
2+2i        =>      dist = 4.000<br>
-2-i        =>      dist = 2.914<br>
1+i+3j+2k   =>      dist = 3.315<br>
Există 2 numere cu 2 coordonate care au distanța mai mare sau egală decât distanța sumei sum2D, există 1 număr cu 3 coordonate care are distanța mai mare sau egală decât distanța sumei sum3D și există un număr cu 4 coordonate care are distanța mai mare sau egală cu distanța sumei sum4D. Se vor afișa pătratele acestor numele, descrescător după numărul de coordonate, iar dacă coordonatele sunt egale descrescător după distanță.

-13.000+2.000i+6.000j+4.000k -> 3.315
-9.000+18.000i+18.000j -> 6.000
5.000+12.000i -> 4.949
0.000+8.000i -> 4.000