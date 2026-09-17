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
