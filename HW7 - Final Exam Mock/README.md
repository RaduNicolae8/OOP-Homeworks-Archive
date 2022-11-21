# Descriere
Aţi fost aleşi de către o platformă de social-media pentru a efectua un studiu asupra scorurilor videoclipurilor postate.

Pentru fiecare videoclip se cunosc următoarele informaţii:

ID - un șir ce caracterizează în mod unic fiecare videoclip;<br>
Categorie - categoriile existente sunt ”Animale”, ”Sport” și ”Studiu”<br>
Numărul de like-uri, notat ”L”<br>
Numărul de dislike-uri, notat ”D”<br>
Numărul de vizualizări, notat ”V”<br>
Pentru fiecare videoclip se pot calcula două scoruri: unul simplu și unul avansat. Scorul simplu se calculează pentru fiecare videoclip conform formulei LD+1−1V<br>
Scorul avansat (SA) se calculează în funcție de scorul simplu (SS) și categorie, astfel:<br>

Categoria ”Studiu” -  SA = SS x 2 <br>
Categoria ”Animale” - SA = SS x 0.75<br>
Categoria ”Sport” -  SA = SS x 0.5<br>
# Cerinţe
Structură<br>
Să se creeze următoarele elemente:<br>
(7p) Clasa abstractă Video cu următorii membri:<br>
<br>Un câmp mVideoId de tip std::string, și trei câmpuri mLikes, mDislikes și mViews, toate de tip uint32_t.
<br>Un constructor protejat care să aibă argumente de tip const std::string &, uint32_t, uint32_t, uint32_t corespunzătoare câmpurilor clasei, în aceeași ordine ca mai sus, care să inițializeze câmpurile.
<br>O metodă publică, apelabilă pentru obiecte const, numită getId, care să întoarcă id-ul videclipului.
<br>O metodă publică, apelabilă pentru obiecte const, numită getDislikes, care să întoarcă numărul de dislike-uri (D).
<br>O metodă publică, apelabilă pentru obiecte const, numită getSimpleScore, care să calculeze și să întoarcă scorul simplu.
<br>O metodă publică, pur virtuală, apelabilă pentru obiecte const, numită getAdvancedScore, care să întoarcă scorul avansat.
<br>O metodă publică void print(bool simple) const care să afișeze pe ecran ID-ul videoclipului și, dacă simple e true, scorul simplu, iar dacă e false, scorul avansat, așa cum se cere la ieșire (valoarea scorului cu două zecimale), iar la final un caracter newline.
<br>(2p) Clasa StudyVideo care să extindă clasa Video cu următorii membri:
<br>Un constructor public care să aibă argumente de tip const std::string &, uint32_t, uint32_t, uint32_t corespunzătoare câmpurilor superclasei, în aceeași ordine ca mai sus, care să apeleze constructorul superclasei.
<br>Implementarea metodei pur virtuale din superclasă care să întoarcă calculeze și să întoarcă scorul avansat pentru acest tip de video.
<br>(2p) Clasa AnimalVideo care să extindă clasa Video cu următorii membri:
<br>Un constructor public care să aibă argumente de tip const std::string &, uint32_t, uint32_t, uint32_t corespunzătoare câmpurilor superclasei, în aceeași ordine ca mai sus, care să apeleze constructorul superclasei.
<br>Implementarea metodei pur virtuale din superclasă care să întoarcă calculeze și să întoarcă scorul avansat pentru acest tip de video.
<br>(2p) Clasa SportsVideo care să extindă clasa Video cu următorii membri:
<br>Un constructor public care să aibă argumente de tip const std::string &, uint32_t, uint32_t, uint32_t corespunzătoare câmpurilor superclasei, în aceeași ordine ca mai sus, care să apeleze constructorul superclasei.
<br>Implementarea metodei pur virtuale din superclasă care să întoarcă calculeze și să întoarcă scorul avansat pentru acest tip de video.
<br>(2p) Clasa VideoFactory care să extindă clasa Video cu următorii membri:
<br>Constructorul implicit șters (inaccesibil).
<br>O metodă statică createVideo care să primească ca argumente const std::string & id, const std::string & type, uint32_t likes, uint32_t dislikes, uint32_t views unde type este tipul video-ului, așa cum este citit de la tastatură, și care întoarce un obiect nou creat corespunzător, ca pointer la Video. Dacă tipul este necunoscut, metoda trebuie să arunce o excepție de tip std::invalid_argument.

Cerinţa (a) - 3p
<br>Să se sorteze crescător videoclipurile în funcţie de scorul simplu. Videoclipurile cu acelaşi scor vor fi sortate descrescător în funcţie de parametrul D.
<br>În urma sortării, se vor afişa separate prin spaţiu ID-ul şi scorul fiecărui videoclip. După fiecare pereche se afişează newline. Scorul va fi afişat cu exact două zecimale!

Cerinţa (b) - 3p
<br>Să se calculeze scorul simplu mediu al videoclipurilor. Se vor afişa doar videoclipurile cu scorul simplu mai mare decât media calculată, în ordniea în care au fost citite de la tastatură.

Cerinţa (c) - 4p
<br>Se vor citi în continuare videoclipuri până la EOF.
<br>Dacă exista deja un videoclip cu acelaşi ID, se vor actualiza informatiile existente cu cele citite. Dacă nu există un videoclip cu acelaşi ID, acesta va fi adaugat.

La final se vor afişa videoclipurile ordonate în același fel ca la punctul a).

Cerinţa (d) - 4p
<br>Să se ordoneze crescător videoclipurile în funcţie de scorul avansat.
<br>Afişarea va cuprinde ID si scorul avansat (afişat cu două zecimale) 

Bonus - 1p
<br>Dacă tipul oricărui video este necunoscut, atunci se va afişa mesajul ”EROARE” şi se va opri execuţia programului.

# Date de intrare
Pe prima linie se află un număr întreg n, reprezentând numărul de videoclipuri ce urmează a fi citite.
<br>Pe următoarele n linii se află informaţii despre videoclip, în formatul:

<br><ID film> <Tip Videoclip> <numar de vizionari> <numar de like-uri> <numar de dislike-uri>

Pe ultima linie se află un caracter din intervalul [a-d] ce reprezintă cerinţa care va fi tratată.

# Exemple

Date de intrare<br>

5<br>
5YJewme Studiu 9307 3166 3290<br>
6sAZPP6 Animale 8372 5462 1602<br>
QlQefVK Studiu 8665 5472 2282<br>
vcyIv9Z Sport 7599 3667 3264<br>
df9QA2u Studiu 9581 4266 4777<br>
a	<br>

Date de iesire<br>
df9QA2u 1.89<br>
5YJewme 1.96<br>
vcyIv9Z 2.12<br>
QlQefVK 3.40<br>
6sAZPP6 4.41<br>

Explicații<br>
Conform cerinţei a), au fost calculate scorurile simple pentru fiecare videoclip<br>
Datele de ieşire conţin ID-ul şi scorul simplu pentru fiecare videoclip, sortate crescător în funcţie de scorul simplu<br>

Exemplu de calcul al scorului simplu:<br>
   5YJewme Studiu 9307 3166 3290<br>
   SS = 31663290+1−19307 = 1.96<br>

Date de intrare<br>
5<br>
Atzyryf Animale 6819 527 3997<br>
l6tI1lP Sport 8559 7008 1338<br>
7Re9PQH Studiu 10154 8281 2581<br>
vKlTqJT Animale 9454 3717 3317<br>
Ka11ezw Sport 9995 8542 1109<br>
b	<br>

Date de iesire<br>
l6tI1lP 6.24<br>
Ka11ezw 8.70<br>

Explicații<br>
Se calculează media tuturor scorurilor simple, rezultând 4.48.<br>
Datele afişate reprezintă videoclipurile cu scorul simplu mai mare decât media calculată.<br>

Date de intrare<br>
5 <br>
nAJNe8X Sport 9835 4887 4317<br>
QiLI6v2 Animale 8860 6954 515<br>
PSWz0xo Sport 9502 3179 4149<br>
TJbZHZj Studiu 10022 7181 3645<br>
MhNQQkU Sport 5587 1308 3935<br>
c<br>
zV3WmUl Animale 9474 4881 3889<br>
9pOPG6B Studiu 9941 4572 4472<br>
PSWz0xo Sport 9631 7925 1374<br>
XGPmRu1 Animale 10045 8808 1422<br>

Date de iesire<br>
MhNQQkU 1.33<br>
9pOPG6B 2.02<br>
nAJNe8X 2.13<br>
zV3WmUl 2.25<br>
TJbZHZj 2.97<br>
PSWz0xo 6.77<br>
XGPmRu1 7.19<br>
QiLI6v2 14.50<br>

Explicații<br>
Datele de intrare conţin numărul n, urmat de n linii cu informaţii despre videoclipuri şi o linie cu litera ce indica subiectul.<br>
Conform cerinţei c), datele de intrare conţin în continuare un număr necunoscut de linii cu informaţii despre videoclipuri.<br>

Se observă că videoclipul cu ID-ul PSWz0xo se afla printre cele care au fost citite şi în prima etapa. Astfel, informaţiile acestuia<br>
vor fi actualizate cu cele citite în a doua etapă.<br>
Restul videoclipurilor sunt descrise de ID-uri unice, aşadar vor fi memorate.<br>

La final, se va afişa secvenţa de videoclipuri sortată crescător in funcţie de scorul simplu.<br>

Date de intrare<br>
 5<br>
FxvKeBw Animale 4696 1140 1390<br>
zZXTZDF Studiu 7762 2946 3524<br>
ZMlkEhz Animale 6777 3372 326<br>
uIq2TYy Sport 8744 6715 1239<br>
R8jzXWf Sport 8826 3211 2127<br>
d	<br>

Date de iesire<br>
R8jzXWf 1.25<br>
FxvKeBw 1.36<br>
uIq2TYy 3.21<br>
zZXTZDF 3.67<br>
ZMlkEhz 8.51<br>

Explicații<br>
Conform cerinţei d), se calculează scorurile avansate. Datele de ieşire conţin ID-urile videoclipurilor împreună cu scorurile avansate, sortate crescător în funcţie de scorul avansat.<br>

Exemplu de calcul al scorului avansat:<br>
    FxvKeBw Animale 4696 1140 1390<br>
   SS = 11401390+1−14696 = 1.82<br>
   SA = SS x 0.75 = 1.36<br>

Date de intrare<br>
3<br>
zDYegrW Animatie 9471 1776 4692<br>
OQT1b8Y Studiu 9844 2766 733<br>
0TzWXJP Animale 9929 4414 4878<br>
a<br>

Date de iesire<br>
 EROARE	<br>

Explicații<br>
Tipul "Animatie" al primului video nu este valid, astfel se afişează mesajul EROARE.<br>