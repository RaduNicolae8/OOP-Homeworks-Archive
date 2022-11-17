În multe aplicaţii de procesare a limbajului natural este nevoie să se determine de câte ori apare un anumit cuvânt într-un text. În contextul acestei probleme, se va lucra cu cuvinte şi texte în limba română, iar prin „cuvânt” ne referim la orice secvenţă de litere (şi un caracter special, cratima) care poate fi pronunţată. De exemplu:

textul „Ana are mere” conţine trei cuvinte: „ana”, „are” şi „mere” care apar în text o singură dată fiecare;

textul „Care este baiatul care te-a lovit? Este cel care sta acolo?”

conţine 8 cuvinte distincte: „care”, „este”, „baiatul”, „te-a”, „lovit”, „cel”, „sta”, „acolo”,

care apar in text de 3, 2, 1, 1, 1, 1, 1, 1 ori.

Cuvintele sunt considerate identice chiar dacă apar în text cu literă mare / mică (vezi cuvântul „care” din exemplul de mai sus).

# Cerinţă
Scrieţi un program care determină de câte ori apare fiecare cuvânt într-un text dat şi listează aceste cuvinte în ordinea numărului de apariţii.

# Date de intrare
Textul de intrare va fi introdus de la tastatură (stream-ul stdin) pe o singură linie. Cuvintele sunt separate prin unul sau mai multe spaţii. Textul se încheie cu caracterul newline (\n), prin apăsarea tastei Enter.

# Date de ieşire
Programul trebuie să afişeze la ieşire, în consolă (pe stream-ul stdout), lista de cuvinte distincte identificate în text, în ordinea numărului de apariţii. Dacă o serie de cuvinte apare de acelaşi număr de ori în text, atunci ele vor fi listate succesiv în ordine alfabetică. Lista de ieşire va fi formatată astfel: pe fiecare linie se va găsi câte un cuvânt, urmat de caracterul spaţiu, urmat de un număr întreg reprezentând numărul de apariţii al cuvântului respectiv în textul de intrare. În textul de ieşire cuvintele vor apărea cu toate literele mici (indiferent de modul în care apar ele în textul de intrare).

# Restricţii şi precizări
Textul de intrare garantat poate conţine numai caracterele a, b, ..., z şi A, B, ..., Z (fără diacritice!), cratime şi spaţii. Textul de intrare va avea maxim 1000 de caractere. Cuvintele sunt considerate identice chiar dacă apar în text cu literă mare / mică.

Atenţie: În funcţie de limbajul de programare ales, fişierul ce conţine codul trebuie să aibă una din extensiile .c, .cpp, .java, sau .m. Editorul web nu va adăuga automat aceste extensii şi lipsa lor duce la imposibilitatea de compilare a programului!

# Exemplu
Text de intrare:

Care este BAIATUL care te-a lovit Este cel care sta ACOLO

Text de ieşire:

care 3 <br> 
este 2 <br> 
acolo 1 <br> 
baiatul 1 <br> 
cel 1 <br> 
lovit 1 <br> 
sta 1 <br> 
te-a 1
