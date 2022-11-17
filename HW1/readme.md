Un tehnician a măsurat un număr mare n de rezistori şi a obţinut n valori de rezistenţe. Tehnicianul ştie că rezistorii sunt de acelaşi fel, dar pentru că sunt vechi şi codul culorilor nu mai este vizibil, doreşte să calculeze valoarea nominală a rezistenţei (R) şi dispersia valorilor, (S). Apoi, având aceste valori, el vrea să determine câte din rezistenţele testate (procentual) se încadrează în intervalul [R – S; R + S]. Rezistenţa nominală se calculează ca media aritmetică a valorilor rezistenţelor, iar formula dispersiei este dată mai jos.

#Cerinţă
Dându-se un număr n de rezistori şi valorile rezistenţelor acestora Ri (i = 1, ..., n), să se determine procentul rezistoarelor care au rezistenţa în intervalul [R– S; R + S].

#Date de intrare
Pe prima linie se află numărul întreg n. Pe următoarea linie, separate printr-un spaţiu, sunt n valori fracţionare de rezistenţe (în ohmi).

#Date de ieşire
Se va afişa o singură valoare fracţionară, cu exact două zecimale reprezentând procentul de rezistori cu rezistenţa în intervalul [R – S; R + S].

Restricţii şi precizări
1 < n < 1000
1.0 <= Ri <= 10000.0 
S=∑ni=1(Ri−R)2n−−−−−−−−−√
