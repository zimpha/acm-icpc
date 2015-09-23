#!/usr/bin/env python3

import sys
import fractions

TIMELIMIT = 1000000
MAXFRACTIONS = 50

def usage():
    print('użycie: {name} program'.format(name = sys.argv[0]))

try:
    script_name = sys.argv[1]
except IndexError:
    usage()
    sys.exit(1)

try:
    script = open(script_name)
except OSError:
    print('Błąd podczas otwierania pliku {}'.format(script_name))
    sys.exit(1)

try:
    tokens = list(int(x.strip()) for x in script.read().strip().split())
except ValueError:
    print('Błąd formatu programu')
    sys.exit(1)

N = tokens[0]
if N > MAXFRACTIONS:
    print('Zbyt długi program')
    sys.exit(1)
try:
    ulamki = list(tokens[2*x+1:2*x+3] for x in range(N))
except IndexError:
    print('Błąd formatu programu')
    sys.exit(1)

for l, m in ulamki:
    if fractions.gcd(l, m) != 1:
        print('Ułamek {}/{} jest nie skrócony'.format(l, m))
        sys.exit(1)

script.close()

def interpretuj(wejscie, ulamki):
    stan = wejscie
    sens = True
    czas = 0

    while sens and czas <= TIMELIMIT:
        sens = False
        for l, m in ulamki:
            if stan % m == 0:
                stan = stan * l // m
                sens = True
                czas += 1
                break

    return stan, czas

for wiersz in sys.stdin:
    try:
        wejscie = int(wiersz.strip())
    except ValueError:
        print('Zły format wejścia')
    else:
        wyjscie, czas = interpretuj(wejscie, ulamki)
        print('Wyjscie = {}, liczba wykonanych instrukcji = {}'.format(wyjscie, czas))

