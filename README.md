# HUS - C Uebungen

Loesungen der C-Uebungen (Terminal-Anwendungen, kompiliert mit clang/gcc).

## Uebung 1 - Ein- und Ausgabe

| Ordner | Inhalt |
| --- | --- |
| `00_Librarys` | Wiederverwendbare Hilfsfunktionen (`ClearInputBuffer`, `GetValidInt`, `PressEnterToContinue`) |
| `01_Library_Tests` | Testprogramm zu den Hilfsfunktionen |
| `aufgabe_1_1a` ... `aufgabe_1_7z` | Aufgaben 1.1 bis 1.7 |

## Uebung 2 - Funktionen

| Ordner | Inhalt |
| --- | --- |
| `aufgabe_2_1` | Winkelumrechnung Grad <-> Rad |
| `aufgabe_2_2` | Radian in Grad, Minuten, Sekunden |
| `aufgabe_2_3` | Trigonometrische Funktionen ueber enum |
| `aufgabe_2_4` | Zeichen mehrfach ausgeben |
| `aufgabe_2_5` | Ratespiel |
| `aufgabe_2_6` | Fakultaet (rekursiv) |
| `aufgabe_2_7` | Zinseszins - Anzahl Jahre |

## Uebung 3 - Arrays

| Ordner | Inhalt |
| --- | --- |
| `aufgabe_3_0` | Durchschnittstemperatur aus Array |
| `aufgabe_3_1` | Multiplikationstabelle (2D-Array) |
| `aufgabe_3_2` | 3 Zahlen sortieren (`sortIntegerArray`, 3 Verzweigungen) |
| `aufgabe_3_3` | Bis zu 200 Zahlen sortieren (BubbleSort, Eingabe-Ende mit 9999) |
| `aufgabe_3_3z` | Zusatz: BubbleSort gegen `qsort` mit Zeitmessung |

### Zusatz 3.3z - Laufzeitvergleich

`aufgabe_3_3z` sortiert dieselben Zahlen mit BubbleSort und mit `qsort` aus
der Standardbibliothek und misst beide Zeiten. Die Datenquelle wird oben im
Programm mit `DATENQUELLE` gewaehlt:

| Wert | Bedeutung |
| --- | --- |
| `0` | Zahlen von Hand eingeben (Ende mit 9999) |
| `1` | festes Test-Array (10 Werte) |
| `2` | 200 Zufallszahlen - Standard, fuer den Zeitvergleich am aussagekraeftigsten |

Ein einzelner Sortiervorgang von 200 Zahlen dauert nur wenige Mikrosekunden und
waere damit so kurz wie die Messungenauigkeit von `clock()` selbst. Darum wird
jedes Verfahren `WIEDERHOLUNGEN` mal ausgefuehrt. Da jeder Durchgang eine frische
unsortierte Kopie braucht, wird die Zeit fuer das reine Kopieren separat gemessen
und abgezogen.

Messung mit 200 Zufallszahlen, 10000 Wiederholungen:

| Verfahren | pro Durchgang |
| --- | --- |
| BubbleSort | 27.32 us |
| `qsort` | 2.55 us |

`qsort` ist damit rund 10x schneller. Mit nur 10 Werten (`DATENQUELLE 1`) schrumpft
der Unterschied auf etwa Faktor 1.1 - der Vorteil von O(n log n) gegenueber O(n^2)
zeigt sich erst bei groesseren Datenmengen.

## Kompilieren

```bash
gcc -g aufgabe_3_3.c -o aufgabe_3_3
./aufgabe_3_3
```

Aufgaben, die Hilfsfunktionen aus `Uebung1_Ein_Ausgabe/00_Librarys` verwenden,
werden zusammen mit der jeweiligen `.c`-Datei kompiliert:

```bash
gcc -g aufgabe_1_6.c ../00_Librarys/GetValidInt.c -I../00_Librarys -o aufgabe_1_6
```
