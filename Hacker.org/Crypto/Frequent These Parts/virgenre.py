cipher = b'Uvgz ckzzff uhs qxuf hfvuirl vbzyecusczc, iuv xgx tyslu dg uvc tou' \
b'd tbggj ctihuolhlacat. W yt swbw uvya yqe, so oqwitsfh cp wetrsqg yjcqwhmwq' \
b'oef rsdycy, wkvd iotl nq djpizse dbwbygug vrw fbayyrdapb. Uoep igv rm, fow ' \
b'gamz iuoy dzbh Khdcqstqyy iu dzf olzwgb lior dinv tswln yqe lp hfl nghl mst' \
b'll. Vrat qgwhgb at ylvwp kk uvc ciiofffc, hnf sk iilkrgnk pt wlatc gmr. Ga ' \
b'iu ostwjf avdsdyck tjbgvuf mrgamfbaf apkdzggz. Iu dzbh fvw aym bdnyocmzfr g' \
b'a? I\'o wslwln a psuf zmug kxhvh rlxv sf pfblr vy hsctpdg tmth cuowqz eorh ' \
b'fqb qpip hncvqtwq. Ahg Ofhzgzh nkfhiyne ysdm pcarci lis nsakxlflr ahtymhv g' \
b'as qgf qoraetxk.'
key = b'boyhacks'

ki = 0
for ci in cipher:
    if not chr(ci).isalpha(): print(chr(ci), end='')
    elif chr(ci).islower():
        print(chr((ci - key[ki]) % 26 + ord('a')), end='')
        ki = ki + 1 & 0x7
    elif chr(ci).isupper():
        print(chr((ci - key[ki] + 32) % 26 + ord('A')), end='')
        ki = ki + 1 & 0x7
