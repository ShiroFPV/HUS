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
| `aufgabe_3_3zz` | Zusatz: BubbleSort/qsort gegen Multicore- und GPU-Sort (Apple M4) |
| `aufgabe_3_4a` | Satzlaenge bestimmen (`myStrlen`, ohne `strlen()`) |
| `aufgabe_3_4b` | Anzahl Woerter in einem Satz bestimmen |
| `aufgabe_3_5` | Zaehlt, wie oft der Buchstabe 'a' in einem Satz vorkommt |

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

### Zusatz 3.3zz - Multicore und GPU (Apple M4)

`aufgabe_3_3zz` geht einen Schritt weiter als 3.3z und vergleicht vier
Verfahren: BubbleSort und `qsort` (beide 1 Kern), ein selbst geschriebenes
Multicore-Sortieren (Grand Central Dispatch, alle 10 Kerne des M4) und ein
GPU-Sortieren (Bitonic Sort auf einem Metal-Compute-Shader).

Es ist eine `.m`-Datei (Objective-C), keine `.c`-Datei: Multicore braucht
`<dispatch/dispatch.h>`, GPU braucht Apples Metal-Framework - beides laesst
sich aus reinem C nicht ansprechen. Der Metal-Shader wird als String im
Programm mitgeliefert und zur Laufzeit kompiliert, es braucht also keinen
separaten Metal-Compiler:

```bash
clang -fobjc-arc -O2 aufgabe_3_3zz.m -framework Metal -framework Foundation -o aufgabe_3_3zz
```

**Wichtige Erkenntnis beim Messen:** `clock()` misst die CPU-Zeit ueber alle
Threads aufsummiert, nicht die tatsaechlich vergangene Zeit. Bei parallelem
Code wuerde das die Multicore-Messung faelschlicherweise schlechter aussehen
lassen, je mehr Kerne mitarbeiten. Darum misst 3.3zz durchgehend mit
`clock_gettime(CLOCK_MONOTONIC, ...)` die echte Wanduhrzeit.

Ergebnis mit 200 Zahlen (wie in 3.3z, viele Wiederholungen):

| Verfahren | pro Durchgang |
| --- | --- |
| BubbleSort | ~8 us |
| `qsort` | ~2.4 us |
| Multicore (10 Kerne) | ~2.9 us |
| GPU (Metal) | ~267 us |

Bei nur 200 Zahlen verliert die GPU deutlich: das Aufteilen des Sortierauftrags
an die GPU (Command-Buffer erstellen, hinschicken, auf das Ergebnis warten)
kostet um ein Vielfaches mehr als das Sortieren selbst einspart. Multicore
bringt bei so wenigen Zahlen ebenfalls kaum etwas.

Ergebnis mit 4 Millionen Zufallszahlen (1 Durchgang, das ist der Massstab, bei
dem sich Multicore und GPU tatsaechlich lohnen):

| Verfahren | Gesamtzeit | Faktor ggue. `qsort` |
| --- | --- | --- |
| `qsort` (1 Kern) | 0.29 s | 1x |
| Multicore (10 Kerne) | 0.07 s | ~4.4x schneller |
| GPU (Metal) | 0.08 s | ~3.8x schneller |

Kurz gesagt: **wie schnell etwas ist, haengt von der Datenmenge ab.** Fuer
die eigentliche Uebung (200 Zahlen) ist ein einfaches `qsort` auf einem Kern
bereits die schnellste Loesung - Multicore und GPU lohnen sich erst, wenn die
Datenmenge (und damit die Sortierarbeit) gross genug ist, um den Aufwand fuer
das Verteilen der Arbeit wieder hereinzuholen.

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
